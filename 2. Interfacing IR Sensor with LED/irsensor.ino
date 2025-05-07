int IRSensor = 2;     // IR sensor is connected to pin 2
int LED = 13;         // LED is connected to pin 13

void setup() {
  pinMode(IRSensor, INPUT);   // IR pin is set to input
  pinMode(LED, OUTPUT);       // LED pin is set to output
}

void loop() {
  int statusSensor = digitalRead(IRSensor);   // Read IR sensor value

  if (statusSensor == 1)
    digitalWrite(LED, LOW);   // LED off: no obstacle detected
  else
    digitalWrite(LED, HIGH);  // LED on: obstacle detected
}
