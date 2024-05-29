#include <SoftwareSerial.h>
#include <Servo.h>

const int buttonPin1 = 3; // الزر الأزرق (يمين)
const int buttonPin2 = 2; // الزر الأحمر (يسار)
const int buttonPin3 = 4; // الزر البنفسجي (أمام)
const int buttonPin4 = 5; // الزر الأخضر (خلف)
const int potPin = A0;    // Potentiometer للتحكم في السيرفو
const int servoPin = 9;   // سيرفو موتور

Servo myservo;

void setup() {
  // تهيئة الأزرار كمدخلات
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  // تهيئة السيرفو
  myservo.attach(servoPin);

  // بدء الاتصال التسلسلي
  Serial.begin(9600);
}

void loop() {
  // قراءة حالة الأزرار
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  int buttonState3 = digitalRead(buttonPin3);
  int buttonState4 = digitalRead(buttonPin4);

  // قراءة قيمة Potentiometer
  int potValue = analogRead(potPin);
  int servoAngle = map(potValue, 0, 1023, 40, 160);

  // تحريك السيرفو
  Serial.println(servoAngle);

  // التحكم في الروبوت بناءً على حالة الأزرار
  if (buttonState1 == HIGH) {
    Serial.println('r'); // إرسال أمر للتحرك إلى اليمين
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState2 == HIGH) {
    Serial.println('l'); // إرسال أمر للتحرك إلى اليسار
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState3 == HIGH) {
    Serial.println('f'); // إرسال أمر للتحرك إلى الأمام
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }

  if (buttonState4 == HIGH) {
    Serial.println('b'); // إرسال أمر للتحرك إلى الخلف    
    delay(100); // تأخير بسيط لمنع الإرسال المتكرر
  }