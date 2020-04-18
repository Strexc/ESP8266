#include <ESP8266WiFi.h>

const char* ssid = "Casa-chetos";
const char* pass = "Amalia987_";


void setup() {
  Serial.begin(115200);

  // Initialize the LED_BUILTIN pin as an output
  pinMode(LED_BUILTIN, OUTPUT);

  WiFi.begin(ssid, pass);
  Serial.printf("\n\nConectando a la red: %s\n", WiFi.SSID().c_str());
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.printf(".");
  }
  Serial.println("");
  Serial.println("Conexion exitosa");
}

// the loop function runs over and over again forever
void loop() {


  if (WiFi.status() != WL_CONNECTED) {
    // Hara que se apague una vez que pierda la conexion con la red WiFi.
    pinMode(LED_BUILTIN, LOW);
  }
  else
  { 
    /*esto hara que el led que tiene integrado el ESP encienda y apage
    mientras este conectado al WiFi de tu Casa*/
    pinMode(LED_BUILTIN, HIGH);
    Serial.println("1");
    delay(1000);
    pinMode(LED_BUILTIN, LOW);
    Serial.println("2");
    delay(1000);
  }
}
