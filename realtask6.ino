#include <SoftwareSerial.h> // مكتبة للتواصل عبر البلوتوث
#include <Servo.h> // مكتبة للتحكم في المحركات

Servo myservo;
int IN4=2;
int IN3=3;
int IN2=4;
int IN1=5;
int enable_A_b=11;
int motorSpeed=125;

void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(IN4,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(enable_A_b,OUTPUT);
  myservo.attach(9);
}

void loop() {
  String input="";
  while(Serial.available()){
    input+=(char)Serial.read();
    delay(5);
  }
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,LOW);

   if(input.toInt() > 20 && input.toInt() < 160) // تلقي الرقم من وحدة البلوتوث
  {
    int servopos = input.toInt(); // حفظ الرقم المستلم في servopos
    Serial.println(servopos); // طباعة servopos الرقم الحالي المستلم من وحدة البلوتوث
    myservo.write(servopos); // تدوير المحرك بالزاوية المستلمة من الريموت
  }

  if(input=="f"){
    fwd();
  }
  else if(input=="b"){
    rev();
  }
  else if(input=="l"){
    lft();
  }
  else if(input=="r"){
    rght();
  }
  
  else if(input!=""){
    motorSpeed=input.toInt();
  }
}

void fwd(){
  analogWrite(enable_A_b,motorSpeed);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
}
void rev(){
  analogWrite(enable_A_b,motorSpeed);
  digitalWrite(IN4,HIGH);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,HIGH);
  digitalWrite(IN1,LOW);
}
void lft(){
  analogWrite(enable_A_b,motorSpeed);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,HIGH);
}
void rght(){
  analogWrite(enable_A_b,motorSpeed);
  digitalWrite(IN4,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN1,LOW);
}



