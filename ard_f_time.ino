#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
//#include <Servo.h> 
//Servo dropServo;
String voice;
int led1 = 8;//Connect LED 1 To Pin #2
int led2 = 9;
int led3 = 11;
int m1=12;
int m2=10;
int m3=13;
void setup() 
{
  pinMode(m1,INPUT);
  pinMode(m2,INPUT);
  pinMode(m3,INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
//  dropServo.attach(10);
//  dropServo.write(30);
  lcd.print("  Voice Based");
  lcd.setCursor(0, 1);
  lcd.print(" Pill Reminder");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  digitalWrite(led3, HIGH);
  
  
}
//-----------------------------------------------------------------------// 
void loop() {
   while (Serial.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable
  char c = Serial.read(); //Conduct a serial read
  if (c == '#') {break;} //Exit the loop when the # is detected after the word
  voice += c; //Shorthand for voice = voice + c
  } 
   if (voice.length() > 0) {
    Serial.println(voice);  
 
 
  //----------Turn On One-By-One----------//
  if(voice == "morning medicine") 
  {
    digitalWrite(led1,LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Cidmus,Rosuvas");
    lcd.setCursor(0, 1);
    lcd.print("gold-9:30AM");
    delay(2000);

  }
  
  //----------Turn Off One-By-One----------//
  else if(voice == "afternoon medicine") 
  {
    digitalWrite(led2, LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Dytor, Tozar H");
    lcd.setCursor(0, 1);
    lcd.print("1:30PM");
    delay(2000);
    }

    else if(voice == "night medicine") 
  {
    lcd.clear();
    lcd.print("Cardivas");
    lcd.setCursor(0, 1);
//    dropServo.write(50);
    lcd.print("Paracetamol-8:30PM");
    digitalWrite(led3, LOW);
    delay(2000);
    }
    else if(voice == "okay")
    {
    lcd.clear();
    lcd.print("THANK YOU");
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);  
    }
  
//-----------------------------------------------------------------------// 
voice="";}
  int medicine1=digitalRead(m1);
   int medicine2=digitalRead(m2);
    int medicine3=digitalRead(m3);
  Serial.println(medicine1);
  delay(1000);
  if(medicine1 == 1) 
  {
    digitalWrite(led1,LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Cidmus,Rosuvas");
    lcd.setCursor(0, 1);
    lcd.print("gold-9:30AM");
    delay(5000);
    digitalWrite(led1,LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Cidmus,Rosuvas");
    lcd.setCursor(0, 1);
    lcd.print("gold-9:30AM");
    delay(3000);
    lcd.clear();
    lcd.print("THANK YOU");
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH); 

  }
  
  //----------Turn Off One-By-One----------//
  else if(medicine2 == 1) 
  {
    digitalWrite(led2, LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Dytor, Tozar H");
    lcd.setCursor(0, 1);
    lcd.print("1:30PM");
    delay(5000);
    digitalWrite(led2, LOW);
    lcd.clear();
//    dropServo.write(50);
    lcd.print("Dytor, Tozar H");
    lcd.setCursor(0, 1);
    lcd.print("1:30PM");
    delay(3000);
    lcd.clear();
    lcd.print("THANK YOU");
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH); 

    
    }

    else if(medicine3 == 1) 
  {
    lcd.clear();
    lcd.print("Cardivas");
    lcd.setCursor(0, 1);
//    dropServo.write(50);
    lcd.print("Paracetamol-8:30PM");
    digitalWrite(led3, LOW);
    delay(5000);
    lcd.clear();
    lcd.print("Cardivas");
    lcd.setCursor(0, 1);
//    dropServo.write(50);
    lcd.print("Paracetamol-8:30PM");
    digitalWrite(led3, LOW);
    lcd.clear();
    delay(3000);
    lcd.print("THANK YOU");
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH); 
    }
    else if(voice == "okay")
    {
    lcd.clear();
    lcd.print("THANK YOU");
     digitalWrite(led1, HIGH);
     digitalWrite(led2, HIGH);
     digitalWrite(led3, HIGH);  
    }
  
//-----------------------------------------------------------------------// 
voice="";} //Reset the variable after initiating
