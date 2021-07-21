#include <Servo.h>

#define dirPin_step1 2
#define stepPin_step1 3
#define dirPin_step2 6
#define stepPin_step2 5
#define steps1PerRevolution 1200
#define steps2PerRevolution 1000

int inputPin1 = 8;
int inputPin2 = 9;
int val1 = 0;
int val2 = 0;

Servo myservo1, myservo2;

void setup() {
  // Declare pin sebagai output
  pinMode(stepPin_step1, OUTPUT);
  pinMode(dirPin_step1, OUTPUT);
  pinMode(stepPin_step2, OUTPUT);
  pinMode(dirPin_step2, OUTPUT);
  pinMode(inputPin1, INPUT); // sensor 1 sebagai input
  pinMode(inputPin2, INPUT); // sensor 2 sebagai input
  myservo1.attach(12);
  myservo2.attach(10);
}
void loop() {

  val1 = digitalRead(inputPin1);

  if (val1 == HIGH){
    // pass

    myservo1.write(0);
    delay(10);

    myservo2.write(0);
    delay(10);

    

  }

  else {

  /* --INI UNTUK STEPPER 2 BERGERAK KE BAWAH-- */
    
    digitalWrite(dirPin_step2, LOW); // turun
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }
    
    delay(1000); //delay 1 detik
    
    myservo1.write(180); //capit
    delay(10);

    delay(1000);
    
    digitalWrite(dirPin_step2, HIGH); //naik
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }
  
    delay(1000); //delay 1 detik
  
    /* --INI UNTUK STEPPER 1 BERGERAK KE KIRI-- */
  
    digitalWrite(dirPin_step1, HIGH); //kiri
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 5 * steps1PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step1, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step1, LOW);
      delayMicroseconds(250);
    }
  
    delay(1000); // delay 1 detik
  
    /* --STEPPER 2 TURUN DAN NAIK KEMBALI -- */
    
    digitalWrite(dirPin_step2, LOW); //turun
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }

    delay(1000);

    myservo1.write(0); // Lepas
    delay(10);
    
    delay(1000); // delay 1 detik
  
    digitalWrite(dirPin_step2, HIGH); //naik
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }

    delay(1000);

    /* -- Stepper 1 bergerak ke kanan -- */
   
    digitalWrite(dirPin_step1, LOW); // kanan
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 5 * steps1PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step1, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step1, LOW);
      delayMicroseconds(250);
    }

    delay(1000);

    /* -- STEPPER 2 TURUN DAN NAIK KEMBALI -- */
    
    digitalWrite(dirPin_step2, LOW); // turun
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }
    
    delay(1000); //delay 1 detik

    myservo2.write(180); // capit
    delay(10);

    delay(1000);
  
    digitalWrite(dirPin_step2, HIGH); //naik
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }
  
    delay(1000); //delay 1 detik

    /* -- Stepper 1 bergerak ke kanan -- */
   
    digitalWrite(dirPin_step1, HIGH); // kanan
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 5 * steps1PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step1, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step1, LOW);
      delayMicroseconds(250);
    }

    delay(1000);

    /* -- STEPPER 2 TURUN DAN NAIK KEMBALI -- */
    
    digitalWrite(dirPin_step2, LOW); // turun
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }

    delay(1000);

    myservo2.write(0); // Lepas
    delay(10);

    delay(1000);

    digitalWrite(dirPin_step2, HIGH); //naik
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 4 * steps2PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step2, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step2, LOW);
      delayMicroseconds(250);
    }
  }

  val2 = digitalRead(inputPin2);

  if (val2 == HIGH){
    //pass
  }

  else {

    /* -- Stepper 1 bergerak ke kanan -- */
   
    digitalWrite(dirPin_step1, LOW); // kanan
    // motor bergerak 4 step dikali dengan revolusi
    for (int i = 0; i < 5 * steps1PerRevolution; i++) {
      // perintah
      digitalWrite(stepPin_step1, HIGH);
      delayMicroseconds(250);
      digitalWrite(stepPin_step1, LOW);
      delayMicroseconds(250);
    }
  }
}
