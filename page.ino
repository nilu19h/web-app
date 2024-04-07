#include <ESP32Servo.h>
#include <WiFi.h>

// network credentials
const char* ssid = "ESP32";
const char* password = "ESP32AF10";

// set webserver port number to 80
WiFiServer server(80);

// HTTP request header
String header;
String state = "in";

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

  Serial.println("");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  server.begin();
}

void loop() {
  int value = digitalRead(sensor_pin);
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

            // display webpage
            client.println("<!DOCTYPE html><html>");
            client.println("<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
            client.println("<link rel=\"icon\" href=\"data:,\">");

            client.println("<style>html { font-family: monospace; display: inline-block; margin: 0px auto; text-align: center;}");
            client.println(".button { background-color: yellowgreen; border: none; color: white; padding: 16px 40px;");
            client.println("text-decoration: none; font-size: 32px; margin: 2px; cursor: pointer;}");
            client.println(".button2 {background-color: gray;}</style></head>");

            client.println("<body><h1>ESP32 Web Server</h1>");
            client.println("<p>ESP32</p>");

            if (state == "out") {
              client.println("<p><a href=\"/13/in\"><button class=\"button\">IN</button></a></p>");
            } 
            else {
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
