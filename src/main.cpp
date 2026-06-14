#include <Arduino.h>
#include<string.h>

uint8_t pins[5] = {7, 6, 5, 4, 3};
uint8_t actnum = 0;
unsigned long Lastactivation = 0;
char press;
const int interval = 1000;
bool all_on = false;

void setup() {
  Serial.begin(115200);
  while(!Serial){
    ;
  }
  pinMode(pins[0], OUTPUT);
  pinMode(pins[1], OUTPUT);
  pinMode(pins[2], OUTPUT);
  pinMode(pins[3], OUTPUT);
  pinMode(pins[4], OUTPUT);

}

void loop() {
 unsigned long now = millis();
  if(actnum == 5){
  if(now - Lastactivation >= interval){
    all_on = true;
  actnum =0;
  }
 }
if(all_on == false){
 if(now - Lastactivation >= interval){
  digitalWrite(pins[actnum], HIGH);
  actnum++;
  Lastactivation = now;
}
}
if(all_on == true){
  while(Serial.available() > 0){
  press = Serial.read();
  }
  if (press == 'K')
  {
    digitalWrite(pins[0], LOW);
  digitalWrite(pins[1], LOW);
  digitalWrite(pins[2], LOW);
  digitalWrite(pins[3], LOW);
  digitalWrite(pins[4], LOW);
  all_on = false;
  Lastactivation = millis();
  }
  
}
}
