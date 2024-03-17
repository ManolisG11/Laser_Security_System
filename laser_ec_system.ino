#include <LiquidCrystal.h>
#define green 8
#define red 9
#define buzzer 7      // led pin
#define sensor_pin A0  // sensor pin
int sensor;          // sensor reading
const int threshold = 720;  // threshold to turn LED on

LiquidCrystal lcd(12,11,5,4,3,2);

void setup(){  // setup code that only runs once
  lcd.begin(16,2);
  pinMode(buzzer, OUTPUT);  // set LED pin as output;
  pinMode(green, OUTPUT);
  pinMode(red, OUTPUT);
  Serial.begin(9600);    // initialize serial communication
}

void loop(){   // code that loops forever
  sensor = analogRead(sensor_pin);   // read sensor value
  Serial.println(sensor);      // print sensor value
  if(sensor<threshold){  // if sensor reading is less than threshold
   tone(buzzer,330);
   lcd.setCursor(0,0);
   lcd.print("INTRUDER DETECTED");
   digitalWrite(red, HIGH);
   digitalWrite(green, LOW);
  }  
  else{  // else, if sensor reading is greater than threshold
    noTone(buzzer);
    lcd.setCursor(0,0);
    lcd.print("No intruder detected");
    digitalWrite(red, LOW);
   digitalWrite(green, HIGH);
  }
}
