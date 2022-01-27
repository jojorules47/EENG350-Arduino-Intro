/*
 * Program to pulse LEDs, with user control over LED
 * speed. 
 * 
 * Author: Josiah Smith
 * Email: jsmith2@mines.edu
 * 
 * Wiring: See README for details
 */

 const int LED_PINS[4] = {10, 11, 12, 13};
 const int GAS_PIN = 2;
 const int BRAKE_PIN = 3;

 void setup(){
  Serial.begin(9600);

  for (int i=0;i<4;i++){
    pinMode(LED_PINS[i], OUTPUT);
  }

  pinMode(GAS_PIN, INPUT_PULLUP);
  pinMode(BRAKE_PIN, INPUT_PULLUP);
  
}

void loop(){
  static int cnt = 0;

  
  
  if(!digitalRead(GAS_PIN)){
    while(!digitalRead(GAS_PIN));

    digitalWrite(LED_PINS[cnt], LOW);
    Serial.println("Gas gas gas");
    cnt = (cnt+1)%4;
    
    delay(10);
  }
  if(!digitalRead(BRAKE_PIN)){
    while(!digitalRead(BRAKE_PIN));
    
    digitalWrite(LED_PINS[cnt], LOW);
    Serial.println("Braku-da");
    cnt -= 1;
    if(cnt < 0) cnt = 3;
    
    delay(10);
  }

  digitalWrite(LED_PINS[cnt], HIGH);

  Serial.print(digitalRead(GAS_PIN));
  Serial.println("hello world");

  
}
