#include <Servo.h>

#include <OLED_I2C.h>
Servo myservo;  // create servo object to control a servo

OLED  myOLED(SDA, SCL, 8);

const int increaseButton = 9;

int buttonState;       
int lastButtonState = LOW;

unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 10;

extern uint8_t BigNumbers[];

int value = 0;
int potpin = 0;  // analog pin used to connect the potentiometer
int val;    // variable to read the value from the analog pin

void setup()
{
    myservo.attach(10);  // attaches the servo on pin 9 to the servo object

  myOLED.begin();
  myOLED.setFont(BigNumbers);
  pinMode(increaseButton,INPUT_PULLUP);
}

void loop()
{
  myOLED.printNumI(val,CENTER,24);
  myOLED.update();
  myOLED.clrScr();
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 1023)
  val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
  myservo.write(val);                  // sets the servo position according to the scaled value
  delay(15);                           // waits for the servo to get there
}
