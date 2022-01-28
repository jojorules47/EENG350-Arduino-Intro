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

// Blink parameters. led_rate is updated often, making
// it volatile
volatile int led_rate = 200;

const int led_inc = 25;
const int led_min = 25;
const int led_max = 500;

/*
 * GAS_PIN ISR to increase blinking speed
 */
void blink_fast() {
  led_rate -= led_inc;
  if (led_rate < led_min)
    led_rate = led_min;

  delay(1);
}

/*
 * BRAKE_PIN ISR to decrease blinking speed
 */
void blink_slow() {
  led_rate += led_inc;
  if (led_rate > led_max)
    led_rate = led_max;

  delay(1);
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(LED_PINS[i], OUTPUT);
  }

  // Set buttons to input pullup, making them active low
  pinMode(GAS_PIN, INPUT_PULLUP);
  pinMode(BRAKE_PIN, INPUT_PULLUP);

  // Set each ISR to trigger when buttons are pressed and released
  // A press/release event will create a rising edge
  attachInterrupt(digitalPinToInterrupt(GAS_PIN), blink_fast, RISING);
  attachInterrupt(digitalPinToInterrupt(BRAKE_PIN), blink_slow, RISING);
}

void loop() {
  static int cnt = 0;
  static bool led_on = true;
  static int last_led = led_rate;

  digitalWrite(LED_PINS[cnt], led_on);

  cnt += 1;

  // Change LED states on rollover
  if (cnt == 4) {
    cnt = 0;
    led_on = !led_on;
  }

  // Tell user if rate changes
  if (led_rate != last_led) {
    Serial.print("LED refresh updated to ");
    Serial.println(led_rate);
  }

  last_led = led_rate;

  delay(led_rate);
}
