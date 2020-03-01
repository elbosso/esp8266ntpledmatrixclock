# esp8266ntpledmatrixclock

<!---
[![start with why](https://img.shields.io/badge/start%20with-why%3F-brightgreen.svg?style=flat)](http://www.ted.com/talks/simon_sinek_how_great_leaders_inspire_action)
--->
[![GitHub release](https://img.shields.io/github/release/elbosso/esp8266ntpledmatrixclock/all.svg?maxAge=1)](https://GitHub.com/elbosso/esp8266ntpledmatrixclock/releases/)
[![GitHub tag](https://img.shields.io/github/tag/elbosso/esp8266ntpledmatrixclock.svg)](https://GitHub.com/elbosso/esp8266ntpledmatrixclock/tags/)
[![GitHub license](https://img.shields.io/github/license/elbosso/esp8266ntpledmatrixclock.svg)](https://github.com/elbosso/esp8266ntpledmatrixclock/blob/master/LICENSE)
[![GitHub issues](https://img.shields.io/github/issues/elbosso/esp8266ntpledmatrixclock.svg)](https://GitHub.com/elbosso/esp8266ntpledmatrixclock/issues/)
[![GitHub issues-closed](https://img.shields.io/github/issues-closed/elbosso/esp8266ntpledmatrixclock.svg)](https://GitHub.com/elbosso/esp8266ntpledmatrixclock/issues?q=is%3Aissue+is%3Aclosed)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/elbosso/esp8266ntpledmatrixclock/issues)
[![GitHub contributors](https://img.shields.io/github/contributors/elbosso/esp8266ntpledmatrixclock.svg)](https://GitHub.com/elbosso/esp8266ntpledmatrixclock/graphs/contributors/)
[![Github All Releases](https://img.shields.io/github/downloads/elbosso/esp8266ntpledmatrixclock/total.svg)](https://github.com/elbosso/esp8266ntpledmatrixclock)
[![Website elbosso.github.io](https://img.shields.io/website-up-down-green-red/https/elbosso.github.io.svg)](https://elbosso.github.io/)

This repository actually combines what i learned from building
https://github.com/elbosso/sonoffSocket
and 
https://github.com/elbosso/esp8266epaperdoorsign
with an MAX7119 8x8 Led Matrix (well - actually four of them) and
a photo resistor.

The data for connecting with your wifi is located in a header file named `wifi_security.h` that i did
not commit for obvious reasons. Its contents look something like the contents of the example named
`wifi_security_h.example`:

```
#ifndef WIFISECURITY_H
#define WIFISECURITY_H

char wifi_ssid[]="<wifi_ssid>";
char wifi_pwd[]="<wifi_pwd>";
char wifi_ssid_cell_ap[]="<wifi_ssid_cell_ap>";
char wifi_pwd_cell_ap[]="<wifi_pwd_cell_ap>";

#endif /* WIFISECURITY_H */
```

The define `AT_HOME` is used to control what NTP-server should be used: The source code presumes a local NTP-server 
exists at IP-address `192.168.10.2` if
`AT_HOME` is set to 1 - if this is not so, it currently asks `2.de.pool.ntp.org` for the time.

The define `AT_HOME` also decides which pair of WIFI credentials are to be used.

Instructions for setting up the arduino IDE to actually be able to transfer the code to a Wemos D1 (clone) can be found [here](https://averagemaker.com/2018/03/wemos-d1-mini-setup.html)

And so we have a nifty little clock...
