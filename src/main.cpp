#include <Arduino.h>
#include "DHT.h"

// Ustawienia DHT11
#define DHTPIN 26      // Pin podłączony do czujnika DHT11
#define DHTTYPE DHT11  // Typ czujnika

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  dht.begin();
  Serial.println("Odczyt danych z DHT11...");
}

void loop() {
  // DHT11 potrzebuje trochę czasu pomiędzy pomiarami
  delay(2000);

  // Odczyt temperatury i wilgotności
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  // Sprawdzenie, czy odczyt się powiódł
  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Błąd odczytu z czujnika DHT11!");
    return;
  }

  // Wysyłanie danych na Serial Monitor
  Serial.print("Wilgotność: ");
  Serial.print(humidity);
  Serial.print(" %\t");

  Serial.print("Temperatura: ");
  Serial.print(temperature);
  Serial.println(" *C");
}
