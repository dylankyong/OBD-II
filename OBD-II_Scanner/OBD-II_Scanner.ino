#include <Wire.h> // Enable this line if using Arduino Uno, Mega, etc.
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
#include <OBD.h>

COBD obd;

Adafruit_7segment matrix = Adafruit_7segment();
int counterSpd = 0;
int counterRpm = 0;
int rpm, r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, i, counterCheck;
int a = 2;
int b = 3;
int c = 4;
int d = 5;
int e = 6;
int f = 7;
int g = 8;

int power1 = 9;
int power2 = 10;
int power3 = 11;
int power4 = 12;

void setup() {
  Serial.begin(9600);
  Serial.println("7 Segment Backpack Test");
  matrix.begin(0x70);
  delay(500);
  
  rpmInit();
  counterCheck = 0;
  
  obd.begin();
  while (!obd.init());

}

void loop() {
  if (obd.readPID(PID_SPEED, counterSpd)) //set speed display
  {
    matrix.println(counterSpd);
    matrix.writeDisplay();
  }
  if (obd.readPID(PID_RPM, counterRpm)) //set rpm display
  {
    rpmCheck();
  }
  /* COUNTERS: Used to test both 4x7 segment LEDs without needing to connect to the OBD-II scanner
    if (cSpdD == true)
    {
    counterSpd++;
    if (counterSpd > 119)
    {
      cSpdD = false;
    }
    }
    else if (cSpdD == false)
    {
    counterSpd--;
    if (counterSpd == 0)
    {
      cSpdD = true;
    }
    }
    if (cRpmD == true)
    {
    counterRpm += 10;
    if (counterRpm == rpm + 1000)
    {
      cRpmD = false;
    }
    }
    else if (cRpmD == false)
    {
    counterRpm -= 10;
    if (counterRpm == 0)
    {
      cRpmD = true;
    }
    }
  */
}
void revF0() //set max rpm digit 0
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, HIGH);
}
void revF1() //set max rpm digit 1 and 2
{
  digitalWrite(a, LOW);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void revF2() //set max rpm digit 3
{
  digitalWrite(a, LOW);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}
void rev0() //set rpm position 1, 2, 3 and 4
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}

void rev1() //set rpm position 5
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void rev2() //set rpm position 6
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void rev3() //set rpm position 7
{
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void rev4() //set rpm position 8, 9 and 10
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void rev5() //set rpm position 11
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
}
void rev6() //set rpm position 12
{
  digitalWrite(a, HIGH);
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, LOW);
}
void dig0() //select digit 0
{
  digitalWrite(power1, LOW);
  digitalWrite(power2, HIGH);
  digitalWrite(power3, HIGH);
  digitalWrite(power4, HIGH);
}
void dig1() //select digit 1
{
  digitalWrite(power1, HIGH);
  digitalWrite(power2, LOW);
  digitalWrite(power3, HIGH);
  digitalWrite(power4, HIGH);
}
void dig2() //select digit 2
{
  digitalWrite(power1, HIGH);
  digitalWrite(power2, HIGH);
  digitalWrite(power3, LOW);
  digitalWrite(power4, HIGH);
}
void dig3() //select digit 3
{
  digitalWrite(power1, HIGH);
  digitalWrite(power2, HIGH);
  digitalWrite(power3, HIGH);
  digitalWrite(power4, LOW);
}
void digAll() //select all digits
{
  digitalWrite(power1, LOW);
  digitalWrite(power2, LOW);
  digitalWrite(power3, LOW);
  digitalWrite(power4, LOW);
}
void digNone() //select no digits
{
  digitalWrite(power1, HIGH);
  digitalWrite(power2, HIGH);
  digitalWrite(power3, HIGH);
  digitalWrite(power4, HIGH);
}

void rpmInit() //initialize rpm display
{
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);

  pinMode(power1, OUTPUT);
  pinMode(power2, OUTPUT);
  pinMode(power3, OUTPUT);
  pinMode(power4, OUTPUT);

  digitalWrite(power1, HIGH);
  digitalWrite(power2, HIGH);
  digitalWrite(power3, HIGH);
  digitalWrite(power4, HIGH);

  digitalWrite(a, LOW); //number reset
  digitalWrite(b, LOW);
  digitalWrite(c, LOW);
  digitalWrite(d, LOW);
  digitalWrite(e, LOW);
  digitalWrite(f, LOW);
  digitalWrite(g, LOW);
  rpm = 3000; //(MAX RPM) controls the sensetivity of the rpm meter
  r0 = rpm / 12;
  r1 = (rpm / 12) * 2;
  r2 = (rpm / 12) * 3;
  r3 = (rpm / 12) * 4;
  r4 = (rpm / 12) * 5;
  r5 = (rpm / 12) * 6;
  r6 = (rpm / 12) * 7;
  r7 = (rpm / 12) * 8;
  r8 = (rpm / 12) * 9;
  r9 = (rpm / 12) * 10;
  r10 = (rpm / 12) * 11;
  r11 = rpm;
}

void rpmCheck() //check rpm value and set display
{
  if (counterRpm < r0)
  {

    dig0();
    rev0();
    delay(20);
  }
  else if (counterRpm < r1)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(15);

  }
  else if (counterRpm < r2)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev0();
    delay(10);

  }
  else if (counterRpm < r3)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev0();
    delay(5);
    dig3();
    rev0();
    delay(5);

  }

  else if (counterRpm < r4)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev0();
    delay(5);
    dig3();
    rev1();
    delay(5);

  }
  else if (counterRpm < r5)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev0();
    delay(5);
    dig3();
    rev2();
    delay(5);

  }
  else if (counterRpm < r6)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev0();
    delay(5);
    dig3();
    rev3();
    delay(5);

  }
  else if (counterRpm < r7)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev0();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);

  }
  else if (counterRpm < r8)
  {

    dig0();
    rev0();
    delay(5);
    dig1();
    rev4();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);

  }
  else if (counterRpm < r9)
  {
    dig0();
    rev4();
    delay(5);
    dig1();
    rev4();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);
  }
  else if (counterRpm < r10)
  {
    dig0();
    rev5();
    delay(5);
    dig1();
    rev4();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);
  }
  else if (counterRpm < r11)
  {

    dig0();
    rev6();
    delay(5);
    dig1();
    rev4();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);

  }
  else if (counterRpm > r11 && counterCheck <= 10)
  {
    dig0();
    revF0();
    delay(5);
    dig1();
    revF1();
    delay(5);
    dig2();
    revF1();
    delay(5);
    dig3();
    revF2();
    delay(5);
    counterCheck++;
  }
  else if (counterRpm > r11 && counterCheck > 10)
  {
    dig0();
    rev6();
    delay(5);
    dig1();
    rev4();
    delay(5);
    dig2();
    rev4();
    delay(5);
    dig3();
    rev3();
    delay(5);
    counterCheck++;
    if (counterCheck > 19)
    {
      counterCheck = 0;
    }
  }
}
