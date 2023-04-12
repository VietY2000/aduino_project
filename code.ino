// Khai báo biến mảng sáng dần
#include "bien_mang_1.h"


//chân ST_CP (Chân 12) của 74HC595
int chot = 2;
int chot1 = 5;
//chân SH_CP (Chân 11) của 74HC595
int xung = 3;
int xung1 = 4;
//Chân DS (chân 14) của 74HC595
int dataPin = 1;
int dataPin1 =6;

int B_MODE = A2;
int B_UP = A3;
int B_DOW = A4;
int B_OK = A5;
int K1 = 12;
int K2 = 13;
int J1 = 10;
int J2 = 11;
int ENA = 9;
int IN1 = 7;
int IN2 = 8;

int Mode = 8 ;
int q; int w; int e; int r; int w1; int e1; int r1; int thoat = 0;
int delayvalue = 0; int delayvalue2 = 10; int toc_do = 0; int analogvalue = 0; int thuc_hien = 0; int count = 0; int b = 0;

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void sang_dan_sang_don(int x)
{
  for (int j = b; j <= 89; j++)
  { int delayvalue1 = analogRead(A0);

    for (int k = 3; k >= 0; k--)
    {
      byte led_status = sangdan_sangdon[j][k];
      //ShiftOut ra IC
      shiftOut(dataPin, xung, MSBFIRST, led_status);
    }
    if (digitalRead(B_MODE) == 0)
    {
      while (digitalRead(B_MODE) == 0)
      {

      }
      digitalWrite(chot, HIGH);
      delay(10);
      digitalWrite(chot, LOW);
      delay(10);
      Mode = 0;
      thuc_hien = 0;
      byte led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      delay(10);
      digitalWrite(chot, HIGH);
      delay(10);
      digitalWrite(chot, LOW);
      break;
    }
    digitalWrite(chot, HIGH); //các đèn LED sẽ sáng với trạng thái vừa được cập nhập
    delay(delayvalue);
    b = j + 1;
    if (b == 90 ) {
      b = 0;
    }
    digitalWrite(chot, LOW);
    if (delayvalue1 / 5 != delayvalue)
    {
      break;
    }
  }
}

void sang_nhieu_kieu()
{
  for (int j = 0; j <= 63; j++)
  {
    for (int k = 3; k >= 0; k--)
    {
      byte led_status = sangnhieukieu[j][k];
      //ShiftOut ra IC
      shiftOut(dataPin, xung, MSBFIRST, led_status);
    }
    digitalWrite(chot, LOW);
    digitalWrite(chot, HIGH); //các đèn LED sẽ sáng với trạng thái vừa được cập nhập
    delay(10);
    digitalWrite(chot, LOW);
    quetMode(4);
    if (digitalRead(B_MODE) == 0)
    {
      while (digitalRead(B_MODE) == 0)
      {

      }
      digitalWrite(chot, HIGH);
      delay(10);
      digitalWrite(chot, LOW);
      delay(10);
      Mode = 0;
      thuc_hien = 0;
      byte led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      led_status = 0b11111111;
      shiftOut(dataPin, xung, MSBFIRST, led_status);
      delay(10);
      digitalWrite(chot, HIGH);
      delay(10);
      digitalWrite(chot, LOW);
      break;
    }
  }
}

void hienthi7doan(int x)
{
  byte led_status = Led_7SEG[x][0];
  shiftOut(dataPin1, xung1, LSBFIRST, led_status);
  digitalWrite(chot1, HIGH);
  digitalWrite(chot1, LOW);
}

void quet(int x1, int x2, int y1, int y2)
{
  for (int k = 0; k <= 10; k++)
  {
    digitalWrite(K2, 0);
    hienthi7doan(x1);
    digitalWrite(J1, 1); // cho led thu nhất sáng
    delay(5);
    digitalWrite(J1, 0);
    hienthi7doan(x2);
    digitalWrite(J2, 1); // cho led thứ 2 sáng
    delay(5);
    digitalWrite(J2, 0);
    hienthi7doan(y1);
    digitalWrite(K1, 1);
    delay(5);
    digitalWrite(K1, 0);
    hienthi7doan(y2);
    digitalWrite(K2, 1);
    delay(5);
  }
}

void quet_1(int x1, int x2, int y1, int y2)
{ delayvalue2 = analogRead(A1);
  delayvalue2 = delayvalue2 / 5;
  for (int k = 0; k <= delayvalue2; k++)
  {
    digitalWrite(K2, 0);
    hienthi7doan(x1);
    digitalWrite(J1, 1); // cho led thu nhất sáng
    delay(5);
    digitalWrite(J1, 0);
    hienthi7doan(x2);
    digitalWrite(J2, 1); // cho led thứ 2 sáng
    delay(5);
    digitalWrite(J2, 0);
    hienthi7doan(y1);
    digitalWrite(K1, 1);
    delay(5);
    digitalWrite(K1, 0);
    hienthi7doan(y2);
    digitalWrite(K2, 1);
    delay(5);
    /*int change = analogRead(A1);
    if (change / 5 != delayvalue2)
    {
      break;
    }*/
    if (digitalRead(B_MODE) == 0)
    {
      Mode = 0;
      thuc_hien = 0;
      thoat = 1;
      break;
    }
  }
}

void quetMode(int x)
{
  digitalWrite(K2, 0);
  byte led_status = 0b11101000;
  shiftOut(dataPin1, xung1, LSBFIRST, led_status);
  digitalWrite(chot1, HIGH);
  digitalWrite(chot1, LOW);
  digitalWrite(J1, 1);
  delay(5);
  digitalWrite(J1, 0);
  led_status = 0b11110000;
  shiftOut(dataPin1, xung1, LSBFIRST, led_status);
  digitalWrite(chot1, HIGH);
  digitalWrite(chot1, LOW);
  digitalWrite(J2, 1);
  delay(5);
  digitalWrite(J2, 0);
  hienthi7doan(0);
  digitalWrite(K1, 1); // cho led thu nhất sáng
  delay(5);
  digitalWrite(K1, 0);
  hienthi7doan(x);
  digitalWrite(K2, 1); // cho led thứ 2 tắt
  delay(5);
  digitalWrite(K2, 0);
}
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void setup() {
  // put your setup code here, to run once:
  pinMode(chot, OUTPUT);
  pinMode(xung, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(chot1, OUTPUT);
  pinMode(xung1, OUTPUT);
  pinMode(dataPin1, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(J1, OUTPUT);
  pinMode(J2, OUTPUT);
  pinMode(K1, OUTPUT);
  pinMode(K2, OUTPUT);
  digitalWrite(J1, 0);
  digitalWrite(J2, 0);
  digitalWrite(K1, 0);
  digitalWrite(K2, 0);

}

// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

void loop() {
  // put your main code here, to run repeatedly:
  if (Mode == 8)
  {
    delayvalue = analogRead(A0);
    delayvalue = delayvalue / 5 ;
    sang_dan_sang_don(delayvalue);
  }

  if (digitalRead(B_MODE) == 0)
  {
    while (digitalRead(B_MODE) == 0)
    {

    }
    Mode = 0 ;
    thuc_hien = 0;
  }

  if (Mode >= 0 and Mode <= 6 and thuc_hien == 0) // ngăn không cho bấm khác nút mà vẫn hiện mode 0
  {
    if (digitalRead(B_UP) == 0)
    {
      while (digitalRead(B_UP) == 0)
      {

      }
      Mode = Mode + 1;
      if (Mode >= 5 )
      {
        Mode = 0;
      }
    }
    if (digitalRead(B_DOW) == 0)
    {
      while (digitalRead(B_DOW) == 0)
      {

      }
      Mode = Mode - 1;
      if (Mode < 0)
      {
        Mode = 0;
      }
    }
    if (digitalRead(B_OK) == 0)
    {
      while (digitalRead(B_OK) == 0)
      {
        thuc_hien = 1;
        if (Mode == 0)
        {
          thuc_hien = 0;
        }
      }
    }
  }

  if (Mode <= 6 and thuc_hien == 0  )
  {
    quetMode(Mode);
  }
  if (Mode == 1 and thuc_hien == 1)
  {
    while (digitalRead(B_UP) == 1 and digitalRead(B_DOW) == 1 and digitalRead(B_OK) == 1)
    {
      if (count == 0)
      {
        quet(0, 0, 0, 0);
      }
      if (count != 0)
      {
        quet(q, w, e, r);
      }
    }

    if (digitalRead(B_UP) == 0)
    {
      while (digitalRead(B_UP) == 0)
      {
        count = count + 1;
        if (count > 9998)
        {
          count = 0;
        }
        q =  (count / 1000);
        w =  ((count % 1000) / 100);
        e =  (((count % 1000) % 100) / 10);
        r = ((((count % 1000) % 100) % 10));
        quet(q, w, e, r);
      }
    }
    if (digitalRead(B_DOW) == 0)
    {
      while (digitalRead(B_DOW) == 0)
      {
        count = count - 1;
        if (count <= 0)
        {
          count = 9998;
        }
        q =  (count / 1000);
        w =  ((count % 1000) / 100);
        e =  (((count % 1000) % 100) / 10);
        r = ((((count % 1000) % 100) % 10));
        quet(q, w, e, r);
      }

    }

    if (digitalRead(B_OK) == 0 and count != 0)
    {
      for (int i = 0; i <= q; i++ )
      {
        if (i == q)
        {
          w1 = w;
        }
        else
        {
          w1 = 9;
        }

        for (int j = 0; j <= w1; j++)
        {
          if (j == w and i == q)
          {
            e1 = e;
          }
          else
          {
            e1 = 9;
          }

          for (int k = 0; k <= e1; k++)
          {
            if (k == e and j == w and i == q)
            {
              r1 = r;
            }
            else
            {
              r1 = 9;
            }

            for (int p = 0; p <= r1; p++)
            {
              quet_1(i, j, k, p);
              if (thoat == 1)
              {
                break;
              }
            }
            if (thoat == 1)
            {
              break;
            }
          }
          if (thoat == 1)
          {
            break;
          }
        }
        if (thoat == 1)
        {
          break;
        }
      }
      count = 0;
      thoat = 0;
    }
  }
  if (Mode == 2 and thuc_hien == 1)
  {
    toc_do = analogRead(A1);
    int bam_xung = map(toc_do,0,1023,0,255);
    /*if (toc_do > 1020)
    {
      toc_do = 1020;
    }
    toc_do = toc_do / 4;*/
    quetMode(2);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, bam_xung);

    if (digitalRead(B_MODE) == 0)
    {
      Mode = 0;
      thuc_hien = 0;
      digitalWrite(ENA, 0);
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
    }
  }
  if (Mode == 3 and thuc_hien == 1)
  {
    analogvalue = analogRead(A1);
    if (analogvalue == 1023)
    {
      analogvalue = 1111;
    }
    analogvalue = analogvalue * 9;
    q =  (analogvalue / 1000);
    w =  ((analogvalue % 1000) / 100);
    e =  (((analogvalue % 1000) % 100) / 10);
    r = ((((analogvalue % 1000) % 100) % 10));
    quet(q, w, e, r);
    if (digitalRead(B_MODE) == 0)
    {
      Mode = 0;
      thuc_hien = 0;
    }
  }
  if (Mode == 4 and thuc_hien == 1)
  {
    sang_nhieu_kieu();
  }
}
