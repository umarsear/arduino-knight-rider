/*
  Knight rider running lights by Umar Sear

  lights run back and forth in sequence with the speed controlled by a potentiometer
  
 */

int delay_between = 75;
int firstPin=3;
int lastPin=9;
int speedPin=A3;


void setup() {
  // initialize digital pins as an output for LED's.
  for (int i=firstPin;i<lastPin+1;i++){
    pinMode(i,OUTPUT);
  }
  // initialize analogue input pin for potentiometer
  pinMode(speedPin, INPUT);
}

// turn off all leds 
void all_off() {
  for (int i=firstPin;i<(lastPin+1);i++) {
    digitalWrite(i,LOW);
  }
}

void loop() {
  //read the potentiometer value;
  int pot = analogRead(speedPin);
  
  // map the value to a range from 30 to 300 for the running light speed;
  int mapped=map(pot,0,1023,30,300);
  
  // set the delay to the mapped value;
  delay_between=mapped; 

  // run LED's forward;
  for (int i=firstPin;i<(lastPin+1);i++) {
    all_off();
    digitalWrite(i, HIGH);  
    delay(delay_between);   
  }

  // run LED's backwards;
  for (int i=lastPin;i>(firstPin-1);i--) {
    all_off();
    digitalWrite(i, HIGH);   
    delay(delay_between);  
  }
  
}
