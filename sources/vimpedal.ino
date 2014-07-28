/*
 Vim pedal by Aleksey Kurepin
 
 For the Arduino Leonardo and Micro.
 
 Sends a `Esc` and `i` when a pedal is pressed
 and `Esc` when a pedal is released.
 
 The circuit:
 * optical sensor attached to pin 9
 
 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald
 modified 29 Jul 2014
 by Aleksey Kurepin

 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/KeyboardMessage
*/

const int buttonPin = 9;          // input pin for pushbutton
int previousButtonState = HIGH;   // for checking the state of a pushButton

void setup() {
  pinMode(buttonPin, INPUT);
  Keyboard.begin();
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if ((buttonState != previousButtonState)  && (buttonState == HIGH)) {
    Keyboard.write(KEY_ESC);
    Keyboard.write("i");
  }
  else if ((buttonState != previousButtonState)  && (buttonState == LOW)) {
    Keyboard.write(KEY_ESC);
  }
  
  previousButtonState = buttonState;
}
