/*
 * Wiring:
 *   CLK (A) -> D2
 *   DT (B) -> D3
 *   GND -> GND
 */

#define ROT_NOCHNG 0b00
#define ROT_CLK    0b01
#define ROT_CNTCLK 0b10

const int PIN_A = 2;
const int PIN_B = 3;


//int a, b;
byte a,b;

int evaluateState(byte vals){
  int cnt;
  
  switch(vals){
    case ROT_CLK:
      cnt = 1;
      break;
    case ROT_CNTCLK:
      cnt = -1;
      break;
    case ROT_NOCHNG:
      cnt = 0;
      Serial.println("Whaaaa");
      break;
    default:
      Serial.println("Oof, bad");
      
  }

  return cnt;
}
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(PIN_A, INPUT);
  pinMode(PIN_B, INPUT);  

}

void loop() {
  static byte lastA = 0b0;
  static int counts = 0;
//  int tmp;
  
  // put your main code here, to run repeatedly:
  a = digitalRead(PIN_A);
  b = digitalRead(PIN_B);
//  state = (a<<1) | b;
//  state = (digitalRead(PIN_A)<<1) | digitalRead(PIN_B);

  if (a ^ lastA){
    counts += 2*(a ^ b) - 1;
  }
//  if (state != lastState){
//    counts += evaluateState(state);
//  }
//
lastA = a;
//  lastState = state;
//  Serial.print(a);
//  Serial.print(" ");
//  Serial.print(b);
//  Serial.print(" ");
//  Serial.println(state);
//  Serial.print("Counts: ");
//  Serial.println(counts);
Serial.print(a^b);
Serial.print(" ");
Serial.println(counts);
  delay(1);
}
