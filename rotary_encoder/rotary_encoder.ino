/*
 * Wiring:
 *   CLK (A) -> D2
 *   DT (B) -> D3
 *   GND -> GND
 */

const int PIN_A = 2;
const int PIN_B = 4;

byte a, b;

void setup() {
  Serial.begin(9600);

  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);
}

void loop() {
  static byte lastA = 0b0;
  static int counts = 0;

  a = digitalRead(PIN_A);
  b = digitalRead(PIN_B);

  // Check if pin A has changed
  if (a != lastA) {
    // Update counts depending on phase
    if (a == b) {
      counts -= 1;
    } else {
      counts += 1;
    }

    Serial.print("Counts: ");
    Serial.println(counts);
    delay(1);
  }

  // Save state of a
  lastA = a;

  delay(1);
}
