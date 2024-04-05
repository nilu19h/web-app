#include <WiFi.h>
#include <WebServer.h>
#include <Servo.h>

const char* ssid = "";
const char* passwd = "";

WebServer server(80);
Servo motor;

int sensor_pin = 2;
int motor_pin = 5;

void root() {
  String page = "";
  server.send(200, "text/html", page);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, passwd);

  while(WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi!");
  Serial.println("IP address : ");
  Serial.println(WiFi.localIP());

  server.on("/", root);
  server.on("/out", []() {
    motor.write(90);
    server.send(200, "text/plain", "out");
  });

  server.on("/in", []() {
    motor.write(0);
    server.send(200, "text/plain", "in");
  });

  server.begin();
  
  motor.attach(motor_pin);
  pinMode(sensor_pin, INPUT);
}

void loop() {
  server.handleClient();
  int value = digitalRead(sensor_pin);
}
