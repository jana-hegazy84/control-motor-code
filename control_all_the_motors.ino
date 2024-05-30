#include <SoftwareSerial.h> // مكتبة للتواصل عبر البلوتوث
#include <Servo.h> // مكتبة للتحكم في المحركات

Servo myservo; 
int IN4 = 2; 
int IN3 = 3; 
int IN2 = 4; 
int IN1 = 5; 
int enable_A_b = 11; 
int motorSpeed = 125; // سرعة المحرك الافتراضية
const int stepperControl = 12; 
const int directionControl = 13;
const int enableControl = 10;

void setup() {
  Serial.begin(9600); // بدء الاتصال التسلسلي بسرعة 9600 بت في الثانية
  Serial.flush(); // تفريغ المخزن المؤقت للتسلسل

  // إعداد المحركات كمخارج
  pinMode(IN4, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(enable_A_b, OUTPUT);
  myservo.attach(9); // توصيل المحرك السيرفو

  pinMode(directionControl, OUTPUT); 
  pinMode(stepperControl, OUTPUT); 
  pinMode(enableControl, OUTPUT); 
}

void loop() {
  String input = ""; // متغير لتخزين المدخلات
  while (Serial.available()) {
    input += (char)Serial.read(); // قراءة المدخلات من البلوتوث
    delay(5); // تأخير بسيط للسماح بقراءة جميع البيانات
  }

  // إيقاف جميع المحركات بشكل افتراضي
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);

  // التحكم في محرك stepper
  if (input == "clk") { // للتحرك باتجاه عقارب الساعة
    digitalWrite(enableControl, LOW);
    digitalWrite(directionControl, LOW);
    rotateStepper();
  } else if (input == "anticlk") { // للتحرك عكس اتجاه عقارب الساعة
    digitalWrite(enableControl, LOW);
    digitalWrite(directionControl, HIGH);
    rotateStepper();
  } else if (input == "stp") { // لإيقاف المحرك
    digitalWrite(enableControl, HIGH);
  }

  // التحكم في محرك السيرفو بناء على المدخلات
  if (input.toInt() > 20 && input.toInt() < 160) {
    int servopos = input.toInt(); // حفظ الرقم المستلم في servopos
    Serial.println(servopos); // طباعة الرقم المستلم
    myservo.write(servopos); // تدوير المحرك بالزاوية المستلمة
  }

  // التحكم في حركة الروبوت بناء على المدخلات
  if (input == "f") { fwd(); } // التحرك للأمام
  else if (input == "b") { rev(); } // التحرك للخلف
  else if (input == "l") { lft(); } // التحرك لليسار
  else if (input == "r") { rght(); } // التحرك لليمين
  else if (input == "max") { motorSpeed = 255; } // تعيين سرعة المحرك إلى 255
  else if (input == "mid") { motorSpeed = 125; } // تعيين سرعة المحرك إلى 125
  else if (input == "min") { motorSpeed = 65; } // تعيين سرعة المحرك إلى 65
}

void fwd() {
  // تحريك المحرك للأمام
  analogWrite(enable_A_b, motorSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
}

void rev() {
  // تحريك المحرك للخلف
  analogWrite(enable_A_b, motorSpeed);
  digitalWrite(IN4, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN1, LOW);
}

void lft() {
  // تحريك المحرك لليسار
  analogWrite(enable_A_b, motorSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, HIGH);
}

void rght() {
  // تحريك المحرك لليمين
  analogWrite(enable_A_b, motorSpeed);
  digitalWrite(IN4, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN1, LOW);
}

void rotateStepper() {
  // تحريك محرك stepper
  digitalWrite(stepperControl, HIGH);
  delayMicroseconds(100);
  digitalWrite(stepperControl, LOW);
  delayMicroseconds(100);
}
