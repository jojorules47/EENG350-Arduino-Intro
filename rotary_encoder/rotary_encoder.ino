/*
 * Wiring:
 *   CLK (A) -> D2
 *   DT (B) -> D3
 *   GND -> GND
 */

const int PIN_A = 2;
const int PIN_B = 3;

int a, b;
 
void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_A, INPUT_PULLUP);
  pinMode(PIN_B, INPUT_PULLUP);  

}

void loop() {
  // put your main code here, to run repeatedly:
  a = digitalRead(PIN_A);
  b = digitalRead(PIN_B);
  Serial.println(a, b);
}
