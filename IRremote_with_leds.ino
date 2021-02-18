#include <IRremote.h>  
int RECV_PIN = 2;     
IRrecv irrecv(RECV_PIN);     
decode_results results;  
int green = 5;
int red = 6;
int yellow = 7;
int white = 4;
#define ONE 16582903
#define TWO 16615543
#define THREE 16599223
#define FOUR 16591063
int led[] = {0,0,0,0};

void setup()     
{     
Serial.begin(9600);     
irrecv.enableIRIn(); 
  pinMode(green , OUTPUT);
  pinMode(yellow , OUTPUT);
  pinMode(red, OUTPUT);
  pinMode(white, OUTPUT);
}    
void loop()     
{     
if (irrecv.decode(&results))// Returns 0 if no data ready, 1 if data ready.     
{     
 int deCode = results.value;
Serial.println(deCode);
 switch(deCode) {
  case ONE:
  if(led[0] == 1) {
    digitalWrite(green, LOW);
delay(4000);
led[0] = 0;
} else {
digitalWrite(green, HIGH);
led[0] = 1;
}
break;
 
case TWO:

if(led[1] == 1) {
digitalWrite(red, LOW);
led[1] = 0;
} else {
digitalWrite(red, HIGH);
led[1] = 1;
}
break;

case THREE:

if(led[2] == 1) {
digitalWrite(yellow, LOW);
led[2] = 0;
} else {
digitalWrite(yellow, HIGH);
led[2] = 1;
}
break;
case FOUR:

if(led[3] == 1) {
digitalWrite(white, LOW);
led[3] = 0;
} else {
digitalWrite(white, HIGH);
led[3] = 1;
}
break;
}
Serial.println(deCode);
irrecv.resume();
}
}
