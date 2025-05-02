#include <dht.h>

#define dht_apin A0    // DHT11 is connected to A0
#define LED 13         // LED is connected to digital pin 13

dht DHT;

void setup() {
    pinMode(LED, OUTPUT);      // Set LED pin as output
    Serial.begin(9600);        // Set baud rate to 9600
    delay(1000);               // Wait for 1 second
}

void loop() {
    DHT.read11(dht_apin);      // Read data from DHT11 sensor

    // Print humidity
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    Serial.print("% ");

    // Print temperature
    Serial.print("Temperature = ");
    Serial.print(DHT.temperature);
    Serial.println("C");

    // LED control based on temperature
    if (DHT.temperature > 30) {
        digitalWrite(LED, HIGH);   // Turn on LED if temperature > 30°C
    } else {
        digitalWrite(LED, LOW);    // Turn off LED otherwise
    }

    delay(1000); // Wait for 1 second before the next reading
}
