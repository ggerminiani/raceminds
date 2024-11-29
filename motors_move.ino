
void motor_speed(float percent) {

  float power1 = map(50, 0, 100, 0, 1023);
  float power2 = map(99, 0, 100, 0, 1023);
  Serial.println("MOTOR POWER 1: " + String(power1));
  Serial.println("MOTOR POWER 2: " + String(power2));
  
  analogWrite(MOTOR_A, power1);
  analogWrite(MOTOR_B, power1);
}

void motor_stop() {
  //Serial.println("STOP MOTOERS");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void motor_foward() {
  //Serial.println("MOVE FOWARD");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motor_reverse() {
  //Serial.println("MOVE REVERSE");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void motor_right() {
  //Serial.println("MOVE TURN RIGHT");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motor_left() {
  //Serial.println("MOVE TURN LEFT");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void motor_rot_right() {
  //Serial.println("MOVE ROTATION RIGHT");
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void motor_rot_left() {
  //Serial.println("MOVE ROTATION LEFT");
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}