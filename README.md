<pre> web-app by AFNAN <br></pre>
### arduino code
```ino
// arduino code

/*

smart laundry drying system with automated climate sensing
Group members :
  - AFNAN
  - AJAY
  - ARUN
  - FAHAD
- this smart laundry drying system aims to provide a convenient and efficient solution
- integrating climate sensing technology with automation
- ESP32 acts as a webserver controlling servo motor via raindrop sensor and also via webpage 
- ESP32 IP : 192.168.4.1

*/
#include <ESP32Servo.h>
#include <WiFi.h>

// network credentials
const char* ssid = "ESP32";
const char* password = "ESP32AF10";

// set webserver port number to 80
WiFiServer server(80);

// HTTP request header
String header;
String state;

Servo motor;

int motor_pin = 13;
int sensor_pin = 15;

// time
unsigned long cur = millis();
unsigned long prv = 0;
const long timeout = 2000; // 2s

void setup() {
  Serial.begin(115200);

  motor.attach(motor_pin);
  pinMode(sensor_pin, INPUT);

  // Connecting to Wi-Fi
  Serial.print("Connecting to ");
  Serial.print(ssid);
  Serial.println(" Network...");
  WiFi.softAP(ssid,password);

  // get IP address
  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  
  // TODO : automatic control
  // value : 0 - raining
  // value : 1 - not raining
  // if(state == "out") {
  //   if(value == 1) {
  //     motor.write(180);
  //     state = "in";
  //   }
  //   else {
  //     // control via webpage
  //   }
  // }
  // else {
  //   // control motor using web-page
  // }
  
  WiFiClient client = server.available();

  if (client) {
    cur = millis();
    prv = cur;
    Serial.println("New Client.");
    String line = "";

    while (client.connected() && cur - prv <= timeout) {
      int value = digitalRead(sensor_pin);
      // Serial.println(value);
      if(value == 0) {
        motor.write(0);
        state = "in";
      }
      else {
        state = "out";
      }
      cur = millis();
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        header += c;
        if (c == '\n') {
          if (line.length() == 0) {
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            if (header.indexOf("GET /13/in") >= 0) {
              state = "in";
              motor.write(180);
            } 
            else if (header.indexOf("GET /13/out") >= 0) {
              state = "out";
              motor.write(0);
            }

            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");
            // CSS to style the on/off buttons
            client.println("<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: gray;}</style></head>");

            client.println("<body><br><br><h1> smart laundry drying system </h1><br><br>");

            if (state == "out") {
              client.println("<p><a href=\"/13/in\"><button class=\"button\">IN</button></a></p>");
            } else {
              client.println("<p><a href=\"/13/out\"><button class=\"button button2\">OUT</button></a></p>");
            }

            client.println("</body></html>");

            client.println();
            break;
          } 
          else {
            line = "";
          }
        } else if (c != '\r') {
          line += c;
        }
      }
    }
    // clear the header
    header = "";

    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
```
### code explanation
```ino
// arduino code
```
<pre> which is a comment </pre>
<br>

```ino
#include <Servo.h>
```
<pre>includes library to control servo motor
</pre><br>

```ino
Servo motor;
```
<pre> create motor object to control the servo motor </pre><br>

```ino
int sensor_pin = 4;
int motor_pin = 5;
```

<pre>create two variables for raindrop sensor and servo motor<br>and assigning values to which pin they are connected</pre><br>

```ino
void setup() {
    pinMode(sensor_pin, INPUT);
    motor.attach(motor_pin);
}
```
<pre>setup() runs once, when the hardware is first powered on<br>
pinMode() - configures the specified pin to behave either as an input or an output<br>syntax : pinMode(pin, mode)<br>
.attach() - attach variable to a pin<br> syntax : servo.attach(pin)</pre><br>

```ino
void loop() {
    int val = digitalRead(sensor_pin);
    if(val == 0) {
        motor.write(0);
    }
    else {
        motor.write(180);
    }
}
```
<pre>loop runs continuously to react to signals from input devices<br>or changes to the state of program<br>
digitalRead() - reads the value from a specified digit pin, either HIGH or LOW<br>syntax : digitalRead(pin)<br>
.write() - writes a value to the servo, controlling the shaft accordingly, set the angle in degrees<br></pre>

### HTML page

```html
<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <style>
      body {
        text-align: center;
        font-family: arial;
      }
    </style>
  </head>
  <body>
    <h1> weather-app </h1>
  </body>
</html>
```
### arduino

<pre>an open source programmable circuit board and microcontroller<br>that makes it possible for anyone to build digital hardware products

- most popular model : UNO<br>
- microcontroller
  small inexpensive computer that can run on low power<br>  board is surrounded by pins that can be used to
  construct a circuit by connecting various input and output devices<br>
- USB port
  used to upload code to the device<br>
- software : sketch
  writren in purpose-built easy to learn programming language<br>  every program has 2 basic functions<br>
  1) setup()
     setup runs once, when the hardware is first powered on<br>
  2) loop()
     loop runs continuously to react to signals from input devices or
     changes to the state of program

  used to build IoT products, robots, wearable devices, ...
   </pre>

   ### servo motor

   <pre> ... </pre>

   ### rain drop sensor

   <pre> ... </pre>

   ### ESP32 Web-Server

   <pre> ... </pre>
