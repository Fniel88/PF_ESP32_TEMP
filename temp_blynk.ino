#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL29Xkc1Izo"
#define BLYNK_TEMPLATE_NAME "temperature"
#define BLYNK_AUTH_TOKEN "_y940G8Gvh9XTZ_Jh2wV0Ys3i-paIud5"



#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Definimos los pines
#define DHTPIN 14        // Pin del sensor DHT22
#define LEDPIN 27        // Pin del LED

// Definimos el tipo de sensor DHT
#define DHTTYPE DHT22    // Tipo de sensor (DHT11, DHT21, DHT22)
// Umbral de temperatura
float thresholdTemp = 30.0; // Cambia este valor según tus necesidades

char ssid[] = "Tu RED";
char pass[] = "Contraseña de tu red";
// Inicializamos el sensor DHT
DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // Configuración del LED como salida
  pinMode(LEDPIN, OUTPUT);
  digitalWrite(LEDPIN, LOW);  // Apagamos el LED inicialmente

  // Configuración del monitor serial
  Serial.begin(115200);
  dht.begin();
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
}

void loop() {
  Blynk.run();
  // Esperamos 2 segundos entre cada lectura
  delay(2000);

  // Leemos la temperatura del sensor
  float temperature = dht.readTemperature();
  Blynk.virtualWrite(V0, temperature);
  Blynk.virtualWrite(V2, 0);
  // Comprobamos si la lectura es válida
  if (isnan(temperature)) {
    Serial.println("Error al leer el sensor DHT!");
    return;
  }

  // Mostramos la temperatura en el monitor serial
  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" °C");

  // Comprobamos si la temperatura supera el umbral
  if (temperature > thresholdTemp) {
    digitalWrite(LEDPIN, HIGH);  // Encendemos el LED
    Serial.println("¡Temperatura alta! LED encendido.");
    Blynk.virtualWrite(V2, 1);
  } else {
    digitalWrite(LEDPIN, LOW);   // Apagamos el LED
    Serial.println("Temperatura dentro de rango. LED apagado.");
  }
}
