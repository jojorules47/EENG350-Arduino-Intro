/*
 * Read the position of a rotary encoder using interrupts, and print
 * to Serial monitor. Designed with the Arduino IDE for Arduino Uno.
 *
 * Author: Josiah Smith
 * Email: jsmith2@mines.edu
 *
 * Wiring: See README for details
 */

// Define pins for encoder
const int PIN_A = 2;
const int PIN_B = 4;

int encCounts = 0;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);

  // Set interrupt for pin A if state changes
  attachInterrupt(digitalPinToInterrupt(PIN_A), updateState, CHANGE);
}

/*
 * ISR for pin A. Determines encoder direction, and increments
 * the encoder count.
 */
void updateState() {
  byte a = digitalRead(PIN_A);
  byte b = digitalRead(PIN_B);

  // Determine if a occurs first (cw) or
  // if b has already occurred first (ccw)
  if (a == b) {
    encCounts -= 1;
  } else {
    encCounts += 1;
  }

  // Add delay to smooth counter response
  delay(1);
}

/*
 * Program main loop
 */
void loop() {
  // Print the current position of the encoder
  Serial.print("Counts: ");
  Serial.println(encCounts);
}
