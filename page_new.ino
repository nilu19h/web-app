// Wi-Fi library
#include <Wi-Fi>

// network credentials
const char* ssid = "ESP32-NETWORK";
const char* password = "ESP32AFNAN";

// server listening to port 80
WiFiServer server(80)

// HTTP request
string header;

// todo

void setup() {
  Serial.begin(115200);

  // todo 

  WiFi.softAP(ssid,password);
}

