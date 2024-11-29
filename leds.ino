void showLED() {
  digitalWrite(LED_CENTER, LOW);
  digitalWrite(LED_RIGHT, LOW);
  digitalWrite(LED_LEFT, LOW);

  if (dcenter <= dright && dcenter <= dleft) {
    digitalWrite(LED_CENTER, HIGH);
  } else if (dright <= dcenter && dright <= dleft) {
    digitalWrite(LED_RIGHT, HIGH);
  } else {
    digitalWrite(LED_LEFT, HIGH);
  }
}


void statusLED() {

  if (READING) {
    if (millis() - timmer_led_start > interval_led_start - 500) {
      timmer_led_start = millis();
      led_start_state = !led_start_state;
      digitalWrite(LED_START, led_start_state);
    }
  } else {
    if (START) {
      if (millis() - timmer_led_start > interval_led_start) {
        timmer_led_start = millis();
        led_start_state = !led_start_state;
        digitalWrite(LED_START, led_start_state);
      }
    } else {
      digitalWrite(LED_START, HIGH);
    }
  }
}