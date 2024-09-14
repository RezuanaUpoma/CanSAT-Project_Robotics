#include <OneWire.h>
#include <DallasTemperature.h>
#include <Adafruit_BMP280.h>
#include <SPI.h>
#include <RF24.h>

// DS18B20 Temperature Sensor
#define ONE_WIRE_BUS 2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

// BMP280 Pressure Sensor
Adafruit_BMP280 bmp;

// Sonar HYSR505
#define SONAR_TRIG_PIN 3
#define SONAR_ECHO_PIN 4

// Radio Transmitter & Receiver
RF24 radio(9, 10); // CE, CSN

void setup() {
  Serial.begin(9600);

  // Initialize DS18B20 Temperature Sensor
  sensors.begin();

  // Initialize BMP280 Pressure Sensor
  if (!bmp.begin(0x76)) {
    Serial.println(F("Could not find a valid BMP280 sensor, check wiring!"));
    while (1);
  }

  // Initialize Sonar
  pinMode(SONAR_TRIG_PIN, OUTPUT);
  pinMode(SONAR_ECHO_PIN, INPUT);

  // Initialize Radio
  radio.begin();
  radio.openWritingPipe(0xF0F0F0F0E1LL);
  radio.setPALevel(RF24_PA_HIGH);
  radio.startListening();
}

void loop() {
  // Read Temperature from DS18B20
  sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);

  // Read Pressure from BMP280
  float pressure = bmp.readPressure() / 100.0F; // Convert to hPa

  // Read Distance from Sonar
  digitalWrite(SONAR_TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(SONAR_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(SONAR_TRIG_PIN, LOW);
  long duration = pulseIn(SONAR_ECHO_PIN, HIGH);
  float distance = (duration / 2.0) * 0.0344; // Convert to cm

  // Send Data via Radio
  char data[100];
  snprintf(data, sizeof(data), "Temp: %.2f C, Pressure: %.2f hPa, Distance: %.2f cm", temperature, pressure, distance);
  radio.write(&data, sizeof(data));

  // Print Data to Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  Serial.print("Pressure: ");
  Serial.print(pressure);
  Serial.println(" hPa");

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(2000); // Delay for 2 seconds
}
