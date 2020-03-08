/*
  Copyright (c) 2018.

  Juergen Key. Alle Rechte vorbehalten.

  Weiterverbreitung und Verwendung in nichtkompilierter oder kompilierter Form,
  mit oder ohne Veraenderung, sind unter den folgenden Bedingungen zulaessig:

   1. Weiterverbreitete nichtkompilierte Exemplare muessen das obige Copyright,
  die Liste der Bedingungen und den folgenden Haftungsausschluss im Quelltext
  enthalten.
   2. Weiterverbreitete kompilierte Exemplare muessen das obige Copyright,
  die Liste der Bedingungen und den folgenden Haftungsausschluss in der
  Dokumentation und/oder anderen Materialien, die mit dem Exemplar verbreitet
  werden, enthalten.
   3. Weder der Name des Autors noch die Namen der Beitragsleistenden
  duerfen zum Kennzeichnen oder Bewerben von Produkten, die von dieser Software
  abgeleitet wurden, ohne spezielle vorherige schriftliche Genehmigung verwendet
  werden.

  DIESE SOFTWARE WIRD VOM AUTOR UND DEN BEITRAGSLEISTENDEN OHNE
  JEGLICHE SPEZIELLE ODER IMPLIZIERTE GARANTIEN ZUR VERFUEGUNG GESTELLT, DIE
  UNTER ANDEREM EINSCHLIESSEN: DIE IMPLIZIERTE GARANTIE DER VERWENDBARKEIT DER
  SOFTWARE FUER EINEN BESTIMMTEN ZWECK. AUF KEINEN FALL IST DER AUTOR
  ODER DIE BEITRAGSLEISTENDEN FUER IRGENDWELCHE DIREKTEN, INDIREKTEN,
  ZUFAELLIGEN, SPEZIELLEN, BEISPIELHAFTEN ODER FOLGENDEN SCHAEDEN (UNTER ANDEREM
  VERSCHAFFEN VON ERSATZGUETERN ODER -DIENSTLEISTUNGEN; EINSCHRAENKUNG DER
  NUTZUNGSFAEHIGKEIT; VERLUST VON NUTZUNGSFAEHIGKEIT; DATEN; PROFIT ODER
  GESCHAEFTSUNTERBRECHUNG), WIE AUCH IMMER VERURSACHT UND UNTER WELCHER
  VERPFLICHTUNG AUCH IMMER, OB IN VERTRAG, STRIKTER VERPFLICHTUNG ODER
  UNERLAUBTE HANDLUNG (INKLUSIVE FAHRLAESSIGKEIT) VERANTWORTLICH, AUF WELCHEM
  WEG SIE AUCH IMMER DURCH DIE BENUTZUNG DIESER SOFTWARE ENTSTANDEN SIND, SOGAR,
  WENN SIE AUF DIE MOEGLICHKEIT EINES SOLCHEN SCHADENS HINGEWIESEN WORDEN SIND.
*/

#define AT_HOME 1
#define REGELBETRIEB 1

#include <FS.h> //this needs to be first, or it all crashes and burns...

#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiUdp.h>
//needed for wifimanager
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

//
// Debug messages over the serial console.
//
#include "debug.h"

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <TimeLib.h>
#include <Timezone.h>    // https://github.com/JChristensen/Timezone
#include <stdio.h>
#include <user_interface.h>
#include <ArduinoJson.h>          // https://github.com/bblanchon/ArduinoJson
#include <LEDMatrixDriver.hpp>
#include "wifi_security.h"
#include "clock_font.h"
#include "marquee_font.h"
#include "marquee_form.h"

/**
  Random Number Generator 32bit
  http://esp8266-re.foogod.com/wiki/Random_Number_Generator
 **/
#define RANDOM_REG32  ESP8266_DREG(0x20E44)
 
//ESP8266WebServer* server;
ESP8266WebServer marqueeserver(8080);  // HTTP server will listen at port 8080

bool lamp = 0;

char port[6] = "80";

//flag for saving data
bool shouldSaveConfig = false;

int gpio0Switch = 5;

unsigned long previousMillis = 0;

WiFiUDP ntpUDP;

// By default 'pool.ntp.org' is used with 60 seconds update interval and
// no offset
#ifdef AT_HOME
NTPClient timeClient(ntpUDP, "192.168.10.2");
#else
NTPClient timeClient(ntpUDP, "2.de.pool.ntp.org");
#endif

// You can specify the time server pool and the offset, (in seconds)
// additionaly you can specify the update interval (in milliseconds).
// NTPClient timeClient(ntpUDP, "europe.pool.ntp.org", 3600, 60000);

// Central European Time (Frankfurt, Paris)
TimeChangeRule CEST = {"CEST", Last, Sun, Mar, 2, 120};     // Central European Summer Time
TimeChangeRule CET = {"CET ", Last, Sun, Oct, 3, 60};       // Central European Standard Time
Timezone CE(CEST, CET);

// Define the ChipSelect pin for the led matrix (Dont use the SS or MISO pin of your Arduino!)
// Other pins are arduino specific SPI pins (MOSI=DIN of the LEDMatrix and CLK) see https://www.arduino.cc/en/Reference/SPI
//https://github.com/esp8266/Arduino/issues/1243
const uint8_t LEDMATRIX_CS_PIN = 4;

// Define LED Matrix dimensions (0-n) - eg: 32x8 = 31x7
const int LEDMATRIX_WIDTH = 63;  
const int LEDMATRIX_HEIGHT = 7;
const int LEDMATRIX_SEGMENTS = (LEDMATRIX_WIDTH+1)/8;

// The LEDMatrixDriver class instance
LEDMatrixDriver lmd(LEDMATRIX_SEGMENTS, LEDMATRIX_CS_PIN);

int intensity=0;

int x=0, y=0;   // start top left


// Marquee speed
const int ANIM_DELAY = 60;

char lcdBuf[5];
char lcdBufOld[5];
char timestrbuf[100];

unsigned int counter=0;

char oben[2];
char unten[2];

char fixed[5];
char moving[5];
char mnew[5];

char emm[]="M";

int animcounter;
int animationmode;

int loopcounter=0;

int numberOfHorizontalDisplays = 12;
int numberOfVerticalDisplays = 1;
String decodedMsg;
String msg;
String testMsg = "I LOVE MY HOT ASIAN SWEETNESS!!!!!!";
int wait = 75; // In milliseconds

int spacer = 2;
int width = 5 + spacer; // The font width is 5 pixels
int maxRuns=1;
int runs=0;

long period;
int offset=1,refresh=0;


//callback notifying us of the need to save config
void saveConfigCallback ()
{
  Serial.println("Should save config");
  shouldSaveConfig = true;
}


void setup(void)
{
  randomSeed(RANDOM_REG32);
  animationmode=random(0,5);
  animcounter=random(0,100);
  rst_info *resetInfo;
  resetInfo = ESP.getResetInfoPtr();
  Serial.begin(115200);
  // delay(5000);
  //  Serial.println("");
  //clean FS, for testing
  //SPIFFS.format();
  pinMode(gpio0Switch, INPUT_PULLUP); // Push Button for GPIO0 active LOW

  // init the display
  lmd.setEnabled(true);
  lmd.setIntensity(intensity);   // 0 = low, 10 = high

  String realSize = String(ESP.getFlashChipRealSize());
  String ideSize = String(ESP.getFlashChipSize());
  bool flashCorrectlyConfigured = realSize.equals(ideSize);

  //read configuration from FS json
  Serial.println("mounting FS...");

  //  if(flashCorrectlyConfigured)
  {
    if (SPIFFS.begin())
    {
      Serial.println("mounted file system");
      if (SPIFFS.exists("/config.json"))
      {
        //file exists, reading and loading
        Serial.println("reading config file");
        File configFile = SPIFFS.open("/config.json", "r");
        if (configFile)
        {
          Serial.println("opened config file");
          size_t size = configFile.size();
          // Allocate a buffer to store contents of the file.
          std::unique_ptr<char[]> buf(new char[size]);

          configFile.readBytes(buf.get(), size);
          DynamicJsonBuffer jsonBuffer;
          JsonObject& json = jsonBuffer.parseObject(buf.get());
          json.printTo(Serial);
          if (json.success())
          {
            Serial.println("\nparsed json");
/*            strcpy(port, json["port"]);
            strcpy(host, json["host"]);
            strcpy(path, json["path"]);
*/          }
          else
          {
            Serial.println("failed to load json config");
          }
        }
      }
    }
    else
    {
      Serial.println("failed to mount FS");
    }
    //end read
  }
  //  else
  //    else Serial.println("flash incorrectly configured, SPIFFS cannot start, IDE size: " + ideSize + ", real size: " + realSize);



  WiFi.persistent(true);
  WiFi.mode(WIFI_OFF);
  WiFi.mode(WIFI_STA);
#ifdef REGELBETRIEB
  Serial.println(digitalRead(gpio0Switch) == HIGH ? "HIGH" : "LOW");
  if (digitalRead(gpio0Switch) == HIGH)
    WiFi.begin(WiFi.SSID().c_str(), WiFi.psk().c_str()); // reading data from EPROM, (last saved credentials)
  else
  {
    WiFi.persistent(false);
    WiFi.begin("geht", "nicht");
    WiFi.persistent(true);
  }
#else
#ifdef AT_HOME
  WiFi.begin(wifi_ssid,wifi_pwd); // reading data from EPROM, (last saved credentials)
#else 
  WiFi.begin(wifi_ssid_cell_ap,wifi_pwd_cell_ap); // reading data from EPROM, (last saved credentials)
#endif
#endif
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, lamp);

  // Wait for WiFi
  Serial.println("");
  Serial.print("Verbindungsaufbau mit:  ");
  Serial.println(WiFi.SSID().c_str());

  while (WiFi.status() == WL_DISCONNECTED)            // last saved credentials
  {
    delay(500);
    if (lamp == 0)
    {
      digitalWrite(LED_BUILTIN, 1);
      lamp = 1;
    }
    else
    {
      digitalWrite(LED_BUILTIN, 0);
      lamp = 0;
    }
    Serial.print(".");
  }
  lamp = 0;
  digitalWrite(LED_BUILTIN, 0);

  wl_status_t status = WiFi.status();
  if (status == WL_CONNECTED)
  {
    Serial.printf("\nConnected successful to SSID '%s'\n", WiFi.SSID().c_str());
  }
  else
  {
    WiFi.mode(WIFI_OFF);
    //WiFiManager
    //Local intialization. Once its business is done, there is no need to keep it around
    WiFiManager wifiManager;
    //set config save notify callback
    wifiManager.setSaveConfigCallback(saveConfigCallback);

/*    WiFiManagerParameter custom_port("Port", "Port", port, 5);
    WiFiManagerParameter custom_host("Host", "Host", host, 99);
    WiFiManagerParameter custom_path("Path", "Path", path, 99);
    wifiManager.addParameter(&custom_port);
    wifiManager.addParameter(&custom_host);
    wifiManager.addParameter(&custom_path);
*/
    //reset settings - for testing
    //wifiManager.resetSettings();

    //sets timeout until configuration portal gets turned off
    //useful to make it all retry or go to sleep
    //in seconds
    digitalWrite(LED_BUILTIN, LOW);

    //fetches ssid and pass and tries to connect
    //if it does not connect it starts an access point with the specified name
    //here  "AutoConnectAP_12F647"
    //and goes into a blocking loop awaiting configuration
    if (!wifiManager.autoConnect("AutoConnectAP_ntplmc"))
    {
      WiFi.mode(WIFI_OFF);
      WiFi.mode(WIFI_STA);
      digitalWrite(LED_BUILTIN, HIGH);
      // WPS button I/O setup
      /*      Serial.printf("\nCould not connect to WiFi. state='%d'\n", status);
            Serial.println("Please press WPS button on your router, until mode is indicated.");
            Serial.println("next press the ESP module WPS button, router WPS timeout = 2 minutes");

            while(digitalRead(gpio0Switch) == HIGH)  // wait for WPS Button active
            {
              delay(50);
              if(lamp == 0){
                 digitalWrite(LED_BUILTIN, 1);
                 lamp = 1;
               }else{
                 digitalWrite(LED_BUILTIN, 0);
                 lamp = 0;
              }
              Serial.print(".");
              yield(); // do nothing, allow background work (WiFi) in while loops
            }
            Serial.println("WPS button pressed");
            lamp=0;
            digitalWrite(LED_BUILTIN, 0);

            if(!startWPSPBC()) {
               Serial.println("Failed to connect with WPS :-(");
            } else*/
      {
        WiFi.begin(WiFi.SSID().c_str(), WiFi.psk().c_str()); // reading data from EPROM,
        while (WiFi.status() == WL_DISCONNECTED)            // last saved credentials
        {
          delay(500);
          Serial.print("."); // show wait for connect to AP
        }
      }
    }
    else
    {
  /*    Serial.println(custom_port.getValue());
      Serial.println(custom_host.getValue());
      Serial.println(custom_path.getValue());
      strcpy(port, custom_port.getValue());
      strcpy(host, custom_host.getValue());
      strcpy(path, custom_path.getValue());
*/
      //save the custom parameters to FS
      if (shouldSaveConfig)
      {
        Serial.println("saving config");
        DynamicJsonBuffer jsonBuffer;
        JsonObject& json = jsonBuffer.createObject();
/*        json["host"] = host;
        json["port"] = port;
        json["path"] = path;
*/
        File configFile = SPIFFS.open("/config.json", "w");
        if (!configFile)
        {
          Serial.println("failed to open config file for writing");
        }

        json.printTo(Serial);
        json.printTo(configFile);
        configFile.close();
        //end save
      }

    }
  }




  Serial.println("Verbunden");
  Serial.print("IP-Adresse: ");
  Serial.println(WiFi.localIP());

  Serial.println("Led aus!");
  digitalWrite(LED_BUILTIN, HIGH);

  timeClient.begin();
  Serial.println("NTP client started");
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  unsigned long epoch = timeClient.getEpochTime();
  Serial.println(epoch);

  TimeChangeRule *tcr;
  time_t utc;
  utc = epoch;

  time_t local = CE.toLocal(utc, &tcr);
  Serial.println(local);

  unsigned long h = hour(local);
  unsigned long mi = minute(local);
  unsigned long s = second(local);
  unsigned long y = year(local);
  unsigned long mo = month(local);
  unsigned long d = day(local);

  Serial.print("local: ");
  printTimeToBuffer(local, tcr -> abbrev);
  Serial.println(timestrbuf);
  unsigned long zerohour = local - s - mi * 60 - h * 60 * 60;
  Serial.print("zerohour: ");
  printTimeToBuffer(zerohour, tcr -> abbrev);
  Serial.println(timestrbuf);
  Serial.println(mi);
  Serial.println(resetInfo->reason);
  unsigned long massaged = zerohour + 60 * 58 + (((resetInfo->reason == REASON_DEEP_SLEEP_AWAKE)||(mi>=58))?(h + 1):h) * 60 * 60;
/*  Serial.print("massaged (first start): ");
  printTimeToBuffer(massaged, tcr -> abbrev);
  Serial.println(timestrbuf);
  lastmassaged=10;
  massaged = zerohour + 60 * 58 + (((lastmassaged>0)||(mi>=58))?(h + 1):h) * 60 * 60;
*/  Serial.print("massaged: ");
  printTimeToBuffer(massaged, tcr -> abbrev);
  Serial.println(timestrbuf);
  //
  // Trigger the update of the display.
  //
  //  Serial.println("Setup done!");
  //    char *two = "/Hardware/d1-epaper/wss.pbm";
  if ((hour(local)) > 6 && (hour(local) < 18))
  {
  }
  //Serial.println("Going into deep sleep for 20 seconds");
  //ESP.deepSleep(20e6); // 20e6 is 20 microseconds
  Serial.print("Going into deep sleep - waking up at: ");
  printTimeToBuffer(massaged, tcr -> abbrev);
  Serial.println(timestrbuf);
  Serial.println(massaged - local);
//  ESP.deepSleep((massaged - local) * 1e06); // 20e6 is 20 microseconds
  sprintf(lcdBuf,"    ");
  oben[1]=0;
  unten[1]=0;
  // Set up the endpoints for HTTP server,  Endpoints can be written as inline functions:
  // replay to all requests with same HTML
  marqueeserver.onNotFound([]() {
    marqueeserver.send(200, "text/html", form);
  });
  marqueeserver.on("/msg", handle_msg);
  marqueeserver.begin();
  
// ***************** INITIAL READY & Read stored message from SPIFFS ****************
    File fr = SPIFFS.open("/msgf.txt", "r");
    while(fr.available()) {
    String line = fr.readStringUntil('n');
 //   Serial.println(line);
    decodedMsg = String("IP ")+WiFi.localIP().toString();//line;
    Serial.print("initial message: ");
    Serial.println(decodedMsg.c_str());
    fr.close();
  }
  Serial.println("WebServer ready!   "); 

}
void printTimeToBuffer(time_t t, char *tz)
{
  //this is needed because dayShortStr and monthShortStr obviously use the same buffer so we get
  //20:30:59 Aug 17 Aug 2018 CEST
  //instead of
  //20:30:59 Fri 17 Aug 2018 CEST
  //if we dont do this!
  String wd(dayShortStr(weekday(t)));
  sprintf(timestrbuf, "%02d:%02d:%02d %s %02d %s %d %s", hour(t), minute(t), second(t), wd.c_str(), day(t), monthShortStr(month(t)), year(t), tz);
}
void printTimeToLCDBuffer(time_t t, char *tz)
{
  //this is needed because dayShortStr and monthShortStr obviously use the same buffer so we get
  //20:30:59 Aug 17 Aug 2018 CEST
  //instead of
  //20:30:59 Fri 17 Aug 2018 CEST
  //if we dont do this!
  String wd(dayShortStr(weekday(t)));
  sprintf(lcdBuf, "%02d%02d", hour(t), minute(t));
//  sprintf(lcdBuf, "%04d", loopcounter);
}

void loop(void)
{
  ++loopcounter;
  sprintf(lcdBufOld,"%s",lcdBuf);
  timeClient.update();
  Serial.println(timeClient.getFormattedTime());
  unsigned long epoch = timeClient.getEpochTime();
//  Serial.println(epoch);

  TimeChangeRule *tcr;
  time_t utc;
  utc = epoch;

  time_t local = CE.toLocal(utc, &tcr);
//  Serial.println(local);

  unsigned long h = hour(local);
  unsigned long mi = minute(local);
  unsigned long s = second(local);
  unsigned long y = year(local);
  unsigned long mo = month(local);
  unsigned long d = day(local);

//  Serial.print("local: ");
  printTimeToBuffer(local, tcr -> abbrev);
//  Serial.println(timestrbuf);
  printTimeToLCDBuffer(local, tcr -> abbrev);
  lcdBuf[1]=lcdBuf[1]-15;
//  sprintf(lcdBuf, "%04d", ++counter);
  int changeDetected=0;
//  animationmode=0;
  switch(animationmode)
  {
    case 5:
    {
      int decimal=5;
      for(int i=0;i<4;++i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          changeDetected=1;
          for(int j=3;j>=i;--j)
          {
            int jj=j+(LEDMATRIX_WIDTH+1-32)/2/8;
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBufOld[k];
                moving[k-j+1]=0;
                mnew[k-j]=lcdBuf[k];
                mnew[k-j+1]=0;
                fixed[k]=0;
              }
            }
            byte* sprite=clockfont[moving[0]- 32];
            byte* newsprite=clockfont[mnew[0]- 32];
            byte* destination=clockfont['M'- 32];
            for(int l=0;l<4;++l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=(sprite [m]>>l)&0xF0;
                destination[m]=destination[m]|((sprite [m]<<l)&0x0F);
              }
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
     marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY*2);
            }
            for(int l=4;l>0;--l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=newsprite[m];
              }
              for(int m=1;m<l;++m)
              {
                destination[m+1]|=destination[m];
                destination[m]=0;
                destination[7-m]|=destination[7-m+1];
                destination[7-m+1]=0;
              }
              drawString(clockfont,fixed, i, (s%2)+16, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
             delay(ANIM_DELAY*2);
            }
          }
          break;    
        }
      }
      break;
    }
    case 4:
    {
      int decimal=5;
      for(int i=0;i<4;++i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          changeDetected=1;
          for(int j=3;j>=i;--j)
          {
            int jj=j+(LEDMATRIX_WIDTH+1-32)/2/8;
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBufOld[k];
                moving[k-j+1]=0;
                mnew[k-j]=lcdBuf[k];
                mnew[k-j+1]=0;
                fixed[k]=0;
              }
            }
            byte* sprite=clockfont[moving[0]- 32];
            byte* newsprite=clockfont[mnew[0]- 32];
            byte* destination=clockfont['M'- 32];
            for(int m=0;m<8;++m)
            {
              destination[m]=sprite [m];
            }
            for(int l=1;l<4;++l)
            {
              destination[l+1]|=destination[l];
              destination[l]=0;
              destination[7-l]|=destination[7-l+1];
              destination[7-l+1]=0;
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
             delay(ANIM_DELAY*2);
            }
            for(int l=4;l>0;--l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=newsprite[m];
              }
              for(int m=1;m<l;++m)
              {
                destination[m+1]|=destination[m];
                destination[m]=0;
                destination[7-m]|=destination[7-m+1];
                destination[7-m+1]=0;
              }
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
             delay(ANIM_DELAY*2);
            }
          }
          break;    
        }
      }
      break;
    }
    case 3:
    {
      int decimal=5;
      for(int i=0;i<4;++i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          changeDetected=1;
          for(int j=3;j>=i;--j)
          {
            int jj=j+(LEDMATRIX_WIDTH+1-32)/2/8;
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBufOld[k];
                moving[k-j+1]=0;
                mnew[k-j]=lcdBuf[k];
                mnew[k-j+1]=0;
                fixed[k]=0;
              }
            }
            byte* sprite=clockfont[moving[0]- 32];
            byte* newsprite=clockfont[mnew[0]- 32];
            byte* destination=clockfont['M'- 32];
            for(int m=0;m<8;++m)
            {
              destination[m]=sprite [m];
            }
            for(int l=1;l<4;++l)
            {
              destination[l+1]|=destination[l];
              destination[l]=0;
              destination[7-l]|=destination[7-l+1];
              destination[7-l+1]=0;
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY*2);
            }
            for(int l=3;l>=0;--l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=(newsprite [m]>>l)&0xF0;
                destination[m]=destination[m]|((newsprite [m]<<l)&0x0F);
              }
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY*2);
            }
          }
          break;    
        }
      }
      break;
    }
    case 2:
    {
      int decimal=5;
      for(int i=0;i<4;++i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          changeDetected=1;
          for(int j=3;j>=i;--j)
          {
            int jj=j+(LEDMATRIX_WIDTH+1-32)/2/8;
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBufOld[k];
                moving[k-j+1]=0;
                mnew[k-j]=lcdBuf[k];
                mnew[k-j+1]=0;
                fixed[k]=0;
              }
            }
            byte* sprite=clockfont[moving[0]- 32];
            byte* newsprite=clockfont[mnew[0]- 32];
            byte* destination=clockfont['M'- 32];
            for(int l=0;l<4;++l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=(sprite [m]>>l)&0xF0;
                destination[m]=destination[m]|((sprite [m]<<l)&0x0F);
              }
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY*2);
            }
            for(int l=3;l>=0;--l)
            {
              for(int m=0;m<8;++m)
              {
                destination[m]=(newsprite [m]>>l)&0xF0;
                destination[m]=destination[m]|((newsprite [m]<<l)&0x0F);
              }
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,emm, 1, (s%2)+(jj)*8, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY*2);
            }
          }
          break;    
        }
      }
      break;
    }
    case 1:
    {
      int decimal=5;
      for(int i=0;i<4;++i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          changeDetected=1;
          for(int j=3;j>=i;--j)
          {
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBufOld[k];
                moving[k-j+1]=0;
                fixed[k]=0;
              }
            }
            if(0)
            {
              decimal=i;
              Serial.print("fixed: ");
              Serial.println(fixed);
              Serial.print("moving: ");
              Serial.println(moving);
            }
            
            for(int l=j*8+(LEDMATRIX_WIDTH+1-32)/2;l<32+(LEDMATRIX_WIDTH+1-32);++l)
            {
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,moving, 1, (s%2)+l, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY);
            }
          }
          for(int j=i;j<4;++j)
          {
            for(int k=0;k<4;++k)
            {
              if(k<j)
              {
                fixed[k]=lcdBufOld[k];
              }
              else
              {
                moving[k-j]=lcdBuf[k];
                moving[k-j+1]=0;
                fixed[k]=0;
              }
            }
    //        if(i!decimal)
            {
              decimal=i;
              Serial.print("fixed: ");
              Serial.println(fixed);
              Serial.print("moving: ");
              Serial.println(moving);
            }
            
            for(int l=32+(LEDMATRIX_WIDTH+1-32);l>=j*8+(LEDMATRIX_WIDTH+1-32)/2;--l)
            {
              drawString(clockfont,fixed, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
              drawString(clockfont,moving, 1, (s%2)+l, 0);
              lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
              delay(ANIM_DELAY);
            }
          }
          break;    
        }
      }
      break;
    }
    default:
    {
      for(int i=3;i>-1;--i)
      {
        if(lcdBufOld[i]!=lcdBuf[i])
        {
          ++changeDetected;
          oben[0]=lcdBuf[i];
          unten[0]=lcdBufOld[i];
          int y=-8;
          while(y<2)
          {
          drawString(clockfont,lcdBufOld, i, (s%2)+(LEDMATRIX_WIDTH+1-32)/2, 0);
          
           drawString(clockfont,oben, 1, (s%2)+i*8+(LEDMATRIX_WIDTH+1-32)/2, y);
           drawString(clockfont,unten, 1, (s%2)+i*8+(LEDMATRIX_WIDTH+1-32)/2, y+8);
            lmd.display();
           ++y;
    marqueeserver.handleClient();   // checks for incoming messages
           delay(ANIM_DELAY);
          }
           drawString(clockfont,oben, 1, (s%2)+i*8+(LEDMATRIX_WIDTH+1-32)/2, 0);
    //      drawString(lcdBuf, i, (s%2), 0);
            lmd.display();
    marqueeserver.handleClient();   // checks for incoming messages
           delay(ANIM_DELAY);
        }
      }
    }
  }
  if(changeDetected==0)
  {
//    Serial.println(maxRuns);
//    Serial.println(runs);
//    Serial.println("--");
    if((maxRuns<1)||(runs<maxRuns))
    {
      int msgLen=decodedMsg.length();
      for ( int i =  -LEDMATRIX_WIDTH; i < width * msgLen + LEDMATRIX_WIDTH  - spacer; i++ ) {
        marqueeserver.handleClient();   // checks for incoming messages
    
        int letter = i / width;
        int y = 0;//(matrix.height() - 8) / 2; // center the text vertically
//     Serial.print((char *)decodedMsg.c_str());
//     Serial.println(i);
        drawString(marqueeFont,(char *)decodedMsg.c_str(), msgLen, -i, y);
    lmd.display();
    
        delay(wait);
      }
      ++runs;
    }

    // Draw the text to the current position
    drawString(clockfont,lcdBuf, 4, (s%2)+16, 0);
    // In case you wonder why we don't have to call lmd.clear() in every loop: The font has a opaque (black) background...
    
    // Toggle display of the new framebuffer
    lmd.display();
    delay(1000);
  }
  else
  {
    --animcounter;
    if(animcounter<0)
    {
      animationmode=random(0,5);
      animcounter=random(30,100);
    }
  }
    marqueeserver.handleClient();   // checks for incoming messages

  double sensorValue = analogRead(A0);
//  Serial.println(sensorValue);
  intensity=(int)(((sensorValue/1024.0)*(sensorValue/1024.0))*10.0);
  lmd.setIntensity(intensity);   // 0 = low, 10 = high
}

int getRandomNumber(int startNum, int endNum) {
  return random(startNum, endNum);
}


/**
 * This function draws a string of the given length to the given position.
 */
void drawString(byte font[][8],char* text, int len, int x, int y )
{
  for( int idx = 0; idx < len; idx ++ )
  {
    int c = text[idx] - 32;

    // stop if char is outside visible area
    if( x + idx * 8  > LEDMATRIX_WIDTH )
      return;

    // only draw if char is visible
    if( 8 + x + idx * 8 > 0 )
      drawSprite( font[c], x + idx * 8, y, 8, 8 );
  }
}

/**
 * This draws a sprite to the given position using the width and height supplied (usually 8x8)
 */
void drawSprite( byte* sprite, int x, int y, int width, int height )
{
  // The mask is used to get the column bit from the sprite row
  byte mask = B10000000;
  
  for( int iy = 0; iy < height; iy++ )
  {
    for( int ix = 0; ix < width; ix++ )
    {
      lmd.setPixel(x + ix, y + iy, (bool)(sprite[iy] & mask ));

      // shift the mask by one pixel to the right
      mask = mask >> 1;
    }

    // reset column mask
    mask = B10000000;
  }
}

void handle_msg() {
                        
//  matrix.fillScreen(LOW);
  marqueeserver.send(200, "text/html", form);    // Send same page so they can send another msg
  refresh=0;
  runs=0;
  
  
  msg = marqueeserver.arg("msg");
  String runsI=marqueeserver.arg("maxRuns");
  maxRuns=runsI.toInt();
  String spdI=marqueeserver.arg("scrSp");
  wait=spdI.toInt();
  Serial.println(wait);
  if(wait<5)
    wait=5;
  else if(wait>80)
    wait=80;
  decodedMsg = msg;
  // Restore special characters that are misformed to %char by the client browser
  decodedMsg.replace("+", " ");      
  decodedMsg.replace("%21", "!");  
  decodedMsg.replace("%22", "");  
  decodedMsg.replace("%23", "#");
  decodedMsg.replace("%24", "$");
  decodedMsg.replace("%25", "%");  
  decodedMsg.replace("%26", "&");
  decodedMsg.replace("%27", "'");  
  decodedMsg.replace("%28", "(");
  decodedMsg.replace("%29", ")");
  decodedMsg.replace("%2A", "*");
  decodedMsg.replace("%2B", "+");  
  decodedMsg.replace("%2C", ",");  
  decodedMsg.replace("%2F", "/");   
  decodedMsg.replace("%3A", ":");    
  decodedMsg.replace("%3B", ";");  
  decodedMsg.replace("%3C", "<");  
  decodedMsg.replace("%3D", "=");  
  decodedMsg.replace("%3E", ">");
  decodedMsg.replace("%3F", "?");  
  decodedMsg.replace("%40", "@"); 

  decodedMsg.toUpperCase();   // Had to convert the string to upper case.  weird shit happened with lower case.  Why?

// Save decoded message to SPIFFS file for playback on power up.
  File f = SPIFFS.open("/msgf.txt", "w");
  if (!f) {
    Serial.println("File open failed!");
  } else {
    Serial.print("Entered Message was: ");
    Serial.print(decodedMsg);
  f.print(decodedMsg);
  }
  f.close();
}

