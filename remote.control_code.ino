#include <SoftwareSerial.h> // مكتبة للتواصل عبر البلوتوث
#include <Servo.h> // مكتبة للتحكم في المحركات

const int buttonPin1 = 3; 
const int buttonPin2 = 2; 
const int buttonPin3 = 4;  
const int buttonPin4 = 5;  
const int potPin = A0;    // المتحكم في السيرفو
const int stepbuttclk = 6; // (الزر للتحرك باتجاه عقارب الساعة(الزر الأزرق 
const int stepbuttanticlk = 7; //  (الزر للتحرك عكس اتجاه عقارب الساعة (الزر الأحمر 
const int stepbuttstp = 8; // (الزر لإيقاف المحرك (الزر البنفسجي
const int max_speed = 9;   //الزر الأحمر
const int mid_speed = 10; //الزر الأخضر
const int min_speed = 11;  //الزر الأصفر

Servo myservo;  

void setup() {
  // تهيئة الأزرار كمدخلات
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  pinMode(stepbuttclk, INPUT_PULLUP);
  pinMode(stepbuttanticlk, INPUT_PULLUP);
  pinMode(stepbuttstp, INPUT_PULLUP);
  pinMode(max_speed, INPUT_PULLUP);
  pinMode(mid_speed, INPUT_PULLUP);
  pinMode(min_speed, INPUT_PULLUP);

  // بدء الاتصال التسلسلي
  Serial.begin(9600);
}

void loop() {
  // قراءة حالة الأزرار
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);
  int stepbuttclk_state = digitalRead(stepbuttclk);
  int stepbuttanticlk_state = digitalRead(stepbuttanticlk);
  int stepbuttstp_state = digitalRead(stepbuttstp);
  int max_speed_state = digitalRead(stepbuttstp);
  int mid_speed_state = digitalRead(stepbuttstp);
  int min_speed_state = digitalRead(stepbuttstp);

  // قراءة قيمة المتحكم في السيرفو
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 40, 160);

  // إرسال قيمة الزاوية للسيرفو
  Serial.println(servoAngle);

  // التحكم في الروبوت بناء على حالة الأزرار
  if (buttonState1 == LOW) { // في حال كان الزر مضغوط
    Serial.println('r'); // إرسال أمر للتحرك إلى اليمين
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState2 == LOW) { // في حال كان الزر مضغوط
    Serial.println('l'); // إرسال أمر للتحرك إلى اليسار
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState3 == LOW) { // في حال كان الزر مضغوط
    Serial.println('f'); // إرسال أمر للتحرك إلى الأمام
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState4 == LOW) { // في حال كان الزر مضغوط
    Serial.println('b'); // إرسال أمر للتحرك إلى الخلف    
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (stepbuttclk_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("clk"); // إرسال أمر للتحرك باتجاه عقارب الساعة    
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (stepbuttanticlk_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("anticlk"); // إرسال أمر للتحرك عكس اتجاه عقارب الساعة    
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (stepbuttstp_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("stp"); // إرسال أمر لإيقاف المحرك    
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر


  }  if (max_speed_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("max");   
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر

  }  if (mid_speed_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("mid");  
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر

  }  if (min_speed_state == LOW) { // في حال كان الزر مضغوط
    Serial.println("min"); 
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }
}
