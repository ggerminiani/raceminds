void startButton() {

  int val = digitalRead(BTN_START);
  if (val == 0) {
    START = !START;
    delay(15);
  }
}