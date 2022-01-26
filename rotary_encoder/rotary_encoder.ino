/*
 * Wiring:
 *   CLK (A) -> D2
 *   DT (B) -> D4
 *   GND -> GND
 */

#define ROT_NOCHNG 0b00
#define ROT_CLK    0b01
#define ROT_CNTCLK 0b10

const int PIN_A = 2;
const int PIN_B = 4;

int encCounts = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);  
  attachInterrupt(digitalPinToInterrupt(PIN_A), updateState, CHANGE);
}

void updateState(){
  byte a = digitalRead(PIN_A);
  byte b = digitalRead(PIN_B);

  if (a == b){
    encCounts -= 1;
  } else {
    encCounts += 1;
  }

  delay(1);
}
 


void loop() {
  Serial.print("Counts: ");
  Serial.println(encCounts);
}
