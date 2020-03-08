#ifndef MARQUEE_FORM_H
#define MARQUEE_FORM_H

// ******************* String form to sent to the client-browser ************************************
String form =
  "<html><body>"
  "<center>"
  "<h1>WiFi Marquee</h1>"
  "<p>Please specify...</p>"
  "<form action='msg'>"
  "<table>"
  "<tr>"
  "<td>Message</td><td><input type='text' name='msg' autofocus></td>"
  "</tr>"
  "<tr>"
  "<td>Scrolling Speed</td><td><input type='text' name='scrSp' value='40'></td>"
  "</tr>"
  "<tr>"
  "<td>Number of Runs</td><td><input type='text' name='maxRuns' value='1'></td>"
  "</tr>"
  "<tr>"
  "<td></td><td><input type='submit' value='Submit'></td>"
  "</tr>"
  "</table>"
  "</form>"
  "</center>"
  "</body></html>";

#endif /* MARQUEE_FORM_H */

