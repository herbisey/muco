#include <Servo.h> 
int k=700, inc=14;  // servo initial value and amount of incrementation
int  previous_error = 0, integral = 0, error, derivative, dt = 20;
int measured_val, measured_val2;
int Kp=90, Ki=5, Kd=10;  // controller values
Servo myservo;

unsigned long timerA;
unsigned long previoustimerA=0;
unsigned long interval=100;

int potPin= 0;  //Birinci Motor
int sayi, sayi2, eskisayi;

//Setup kısmı ilk olarak çalıştırılır ve bir daha kullanılmaz.
//Pinleri output olarak belirleme, Seri haberleşmeyi başlatma vs burada yapılır.
void setup()
{
  // initialize the serial communication:
  Serial.begin(115200);
  
  myservo.attach(7);
}

//Loop kısmı sürekli olarak döngü halinde çalışır.
void loop()
{
 sayi = analogRead(potPin);   // reads the value of the
          // potentiometer (value between
          // 0 and 1023)

 sayi2 = map(sayi, 0, 1023, 0, 1595);  // scale it to use it with
          // the servo (value between 0 and
          // 180)
  
 /*if (abs(eskisayi-sayi)>99)
 {
   Serial.println(int(sayi));
   eskisayi = sayi;
 }*/
 //if (Serial.available()>0)
 {
 myservo.writeMicroseconds(sayi2+695);
 delay(15);
 }
}
