
#include <Servo.h>
#include "Wire.h"
#include "Ultrasonic.h"
#include "variables.h"
#include "pins.h"

HC_SR04 us_right(US_RT, US_RC);
HC_SR04 us_center(US_CT, US_CR);
HC_SR04 us_left(US_LT, US_LC);
Servo slave;

void setup() {

  Serial.begin(115200);
  Serial.println("Starting code...");

  slave.attach(SLAVE);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);

  pinMode(LED_RIGHT, OUTPUT);
  pinMode(LED_CENTER, OUTPUT);
  pinMode(LED_LEFT, OUTPUT);

  pinMode(BTN_START, INPUT_PULLUP);

  slave.write(0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN4, MOTOR_A);
  digitalWrite(IN4, MOTOR_B);

  digitalWrite(LED_RIGHT, LOW);
  digitalWrite(LED_CENTER, LOW);
  digitalWrite(LED_LEFT, LOW);

  motor_stop();

  timmer_start = millis();
  timmer_slave = millis();
  timmer_read_distance = millis();
  timmer_led = millis();
  moving = false;
}

void loop() {

  statusLED();
  startButton();
  distanceRead();


  if (READING) {
    if (millis() - timmer_start > interval_start) {
      READING = false;
      Serial.println("Reading has completed... START ON BUTTON!");
    }
  } else {
    if (START) {
      decision();
      nextMove();
    }
  }
}