#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

// ---- WiFi & Telegram ----
const char* ssid     = "Hamim";
const char* password = "naim1526";
String BOTtoken = "7088853958:AAHj0BK5aPeBAjPShUygN_6UkBr35v7HBII";
String chat_id  = "8130473653";

// ---- Hardware ----
#define FLAME_PIN A0
#define FLAME_THRESHOLD 300   // Fire if value goes below this
#define HYSTERESIS 50         // Reset margin

WiFiClientSecure client;
bool flameLatched = false;   // prevents spamming

// ---- Helpers ----
String urlencode(const String& str) {
  String enc = "";
  for (uint16_t i = 0; i < str.length(); i++) {
    char c = str[i];
    if (c == ' ') enc += '+';
    else if (isalnum(c)) enc += c;
    else {
      char hex1 = (c >> 4) & 0xF, hex2 = c & 0xF;
      enc += '%';
      enc += char(hex1 < 10 ? '0' + hex1 : 'A' + (hex1 - 10));
      enc += char(hex2 < 10 ? '0' + hex2 : 'A' + (hex2 - 10));
    }
  }
  return enc;
}

void sendTelegram(const String& msg) {
  if (WiFi.status() != WL_CONNECTED) return;
  if (!client.connect("api.telegram.org", 443)) {
    Serial.println("Telegram connect failed");
    return;
  }
  String url = "/bot" + BOTtoken + "/sendMessage?chat_id=" + chat_id +
               "&text=" + urlencode(msg);
  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: api.telegram.org\r\n" +
               "Connection: close\r\n\r\n");
  Serial.println("Telegram sent: " + msg);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  // Wi-Fi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED) { delay(300); Serial.print("."); }
  Serial.println("\nConnected: " + WiFi.localIP().toString());

  client.setInsecure(); // skip certificate check
}

void loop() {
  int v = analogRead(FLAME_PIN);
  Serial.print("Flame value: "); Serial.println(v);

  bool fireDetected = (v < FLAME_THRESHOLD);
  bool flameCleared = (v > (FLAME_THRESHOLD + HYSTERESIS));

  if (fireDetected && !flameLatched) {
    flameLatched = true;
    sendTelegram("🔥 আগুন লাগছে !! চিন্তা করো না, আমি আছি তো 😏😏😏😏 ");
  }

  if (flameLatched && flameCleared) {
    flameLatched = false; // ready for next fire event
  }

  delay(300);
}
