#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTTYPE DHT11    
#define SENSOR 33
#define LED 26

DHT_Unified dht(SENSOR, DHTTYPE);

void setup() {


  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);

  // Initialize device.
  dht.begin();
  Serial.println(F("DHTxx Unified Sensor Example"));

  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  dht.humidity().getSensor(&sensor);

  // Afficher l'humidité relative avec un peu de formatage
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println(F("Error reading temperature!"));
  }
  else {
    Serial.print(F("Temperature: "));
    Serial.print(event.temperature);
    Serial.println(F("°C"));
  }
  // Afficher la température avec un peu de formatage
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(F("Error reading humidity!"));
  }
  else {
    Serial.print(F("Humidity: "));
    Serial.print(event.relative_humidity);
    Serial.println(F("%"));
  }

  delay(100); 
  esp_sleep_enable_timer_wakeup(5000000); 
  esp_deep_sleep_start;

}

void loop(){}