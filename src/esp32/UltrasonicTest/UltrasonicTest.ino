/*
 * This ESP32 code is created by esp32io.com
 *
 * This ESP32 code is released in the public domain
 *
 * For more detail (instruction and wiring diagram), visit https://esp32io.com/tutorials/esp32-ultrasonic-sensor
 */

 //distance to an object = ((speed of sound in the air)*time)/2
 //speed of sound in the air at 20ºC = 343m/s = 34300cm/s = 0.0343cm/us
 //a degree to the surface that is greater 15 degrees will not be read

#define TRIG_PIN 25 // ESP32 pin GIOP23 connected to Ultrasonic Sensor's TRIG pin
#define ECHO_PIN 26 // ESP32 pin GIOP22 connected to Ultrasonic Sensor's ECHO pin

float duration_us, distance_cm;
int distDroneCentre = 0;

void setup() {
  // begin serial port
  Serial.begin (9600);

  // configure the trigger pin to output mode
  pinMode(TRIG_PIN, OUTPUT);
  // configure the echo pin to input mode
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  // generate 10-microsecond pulse to TRIG pin
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // measure duration of pulse from ECHO pin
  duration_us = pulseIn(ECHO_PIN, HIGH);

  //calculate the distance 
  distance_cm = (0.017 * duration_us)+ distDroneCentre;

  // print the value to Serial Monitor
  //Serial.print("distance: ");
  Serial.println((double)distance_cm);
  //Serial.println(min((double)distance_cm,400.0));
  //Serial.println(" cm");

  delay(500);
}
