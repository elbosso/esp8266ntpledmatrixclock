#ifndef MARQUEE_FORM_H
#define MARQUEE_FORM_H

//https://www.w3schools.com/howto/howto_css_responsive_form.asp

// ******************* String form to sent to the client-browser ************************************
String form =
"<html>"
"<head>"
"<style>"
"html {  font-size: 3em;}"
"input[type=text], select, textarea{"
"  width: 100%;"
"  padding: 12px;"
"  border: 1px solid #ccc;"
"  border-radius: 4px;"
"  box-sizing: border-box;"
"  resize: vertical;"
"  font-size: 1em;"
"}"
"/*https://www.w3schools.com/howto/howto_css_switch.asp*/"
".switch {"
"  position: relative;"
"  display: inline-block;"
"  width:120px;"
"  height: 68px;"
"}"
".switch input { "
"  opacity: 0;"
"  width: 0;"
"  height: 0;"
"}"
"span.slider{"
"  width: 120px;"
"  height: 68px;"
"}"
".slider {"
"  position: absolute;"
"  cursor: pointer;"
"  top: 0;"
"  left: 0;"
"  right: 0;"
"  bottom: 0;"
"  background-color: #ccc;"
"  -webkit-transition: .4s;"
"  transition: .4s;"
"}"
".slider:before {"
"  position: absolute;"
"  content: '';"
"  height: 52px;"
"  width: 52px;"
"  left: 8px;"
"  bottom: 8px;"
"  background-color: white;"
"  -webkit-transition: .4s;"
"  transition: .4s;"
"}"
"input:checked + .slider {"
"  background-color: #2196F3;"
"}"
"input:focus + .slider {"
"  box-shadow: 0 0 1px #2196F3;"
"}"
"input:checked + .slider:before {"
"  -webkit-transform: translateX(52px);"
"  -ms-transform: translateX(52px);"
"  transform: translateX(52px);"
"}"
"/* Rounded sliders */"
".slider.round {"
"  border-radius: 68px;"
"}"
".slider.round:before {"
"  border-radius: 50%;"
"}"
"label {"
"  padding: 12px 12px 12px 0;"
"  display: inline-block;"
"}"
"input[type=submit] {"
"  background-color: #4CAF50;"
"  color: white;"
"  padding: 12px 20px;"
"  border: none;"
"  border-radius: 4px;"
"  cursor: pointer;"
"  float: right;"
"  font-size: 1em;"
"}"
".container {"
"  border-radius: 5px;"
"  background-color: #f2f2f2;"
"  padding: 20px;"
"}"
".col-25 {"
"  float: left;"
"  width: 25%;"
"  margin-top: 6px;"
"}"
".col-75 {"
"  float: left;"
"  width: 75%;"
"  margin-top: 6px;"
"}"
".row:after {"
"  content: \"\";"
"  display: table;"
"  clear: both;"
"}"
"@media screen and (max-width: 600px) {"
"  .col-25, .col-75, input[type=submit] {"
"    width: 100%;"
"    margin-top: 0;"
"  }"
"} "
"</style>"
"</head>"
"<body>"
"<div class='container'>"
"<div class='row'>"
"<h1>WiFi Marquee</h1>"
"</div>"
"<form action='msg'>"
"<div class='row'>"
"<div class='col-25'>"
"<label for='msg'>Message</label>"
"</div>"
"<div class='col-75'>"
"<input type='text' id='msg' name='msg' placeholder='Your message..'>"
"</div>"
"</div>"
"<div class='row'>"
"<div class='col-25'>"
"<label for='scrSp'>Scrolling Speed</label>"
"</div>"
"<div class='col-75'>"
"<input type='text' id='scrSp' name='scrSp' placeholder='40' value='40'>"
"</div>"
"</div>"
"<div class='row'>"
"<div class='col-25'>"
"<label for='maxRuns'>Number of Runs</label>"
"</div>"
"<div class='col-75'>"
"<input type='text' id='maxRuns' name='maxRuns' placeholder='1' value='1'>"
"</div>"
"</div>"
"<div class='row'>"
"<div class='col-25'>"
"<label for='boldFont'>Use Bold Font</label>"
"</div>"
"<div class='col-75'>"
"<label class='switch'><input type='checkbox' id='boldFont' name='boldFont'><span class='slider round'></span></label>"
"</div>"
"</div>"
"<div class='row'>"
"<input type='submit' value='Submit'>"
"</div>"
"</form>"
"</div> "
"<div class='container'>"
"<form action='cdisptoggle'>"
"<div class='row'>"
"<div class='col-25'>"
"<label>Clock Display</label>"
"</div>"
"<div class='col-75'>"
"<input type='submit' value='Toggle'>"
"</div>"
"</div>"
"</form>"
"</div> "
"<div class='container'>"
"<form action='cdispoff'>"
"<div class='row'>"
"<div class='col-25'>"
"<label>Clock Display</label>"
"</div>"
"<div class='col-75'>"
"<input type='submit' value='Off'>"
"</div>"
"</div>"
"</form>"
"</div> "
"<div class='container'>"
"<form action='cdispon'>"
"<div class='row'>"
"<div class='col-25'>"
"<label>Clock Display</label>"
"</div>"
"<div class='col-75'>"
"<input type='submit' value='On'>"
"</div>"
"</div>"
"</form>"
"</div> "

"</body></html>";

#endif /* MARQUEE_FORM_H */

