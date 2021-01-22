#define FASTLED_INTERNAL

#include <M5Atom.h>
#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "YOUR_WIFI_SSID";
const char* password = "YOUR_WIFI_PASSWORD";

void post() {
  HTTPClient http;
  http.begin("http://httpbin.org/post");
  http.addHeader("Content-Type", "application/json");
  http.POST("{\"title\": \"test\"}");
  Serial.println(http.getString());
  http.end();
}

void setup() {
  M5.begin();
  Serial.begin(115200);

  Serial.print("WiFi connecting.");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(100);
  }

  post();
}

void loop() { /* 起動時にのみPOSTするので、loopでは何もしない。 */}