#include <Servo.h>
#include <EEPROM.h>
#include <virtuabotixRTC.h>

 int saat,dk;
 char a,b,c,d;
 int sa,su,dki,dks;

Servo servo;
virtuabotixRTC Rtc( 6,7,8); //clock,data,reset

 
void setup() {
 Serial.begin(9600);
 servo.attach(9);
 servo.write(0);
 Rtc.setDS1302Time(00,05,12,1,18,05,2022);
}

void loop() {
      Serial.print("UYGULAMA BASLADİ");
      Serial.println();
    
     delay(60000);
     Rtc.updateTime();
     
   int rtcSaat=Rtc.hours;
    int rtcDk=Rtc.minutes;

    
    
    if(Serial.available()>0)
            { 
      
    EEPROM.write(3,rtcSaat);
    EEPROM.write(4,rtcDk);
    int oku = EEPROM.read(3);
    int oku1=EEPROM.read(4);
    
    Serial.println("RTC");
    Serial.print(oku);
    delay(10);
    Serial.print(oku1);
    delay(10);
    Serial.println();
 
        Serial.print("Gelen veri :  ");
        a=Serial.read();
        Serial.print(a);
        delay(100);
        b=Serial.read();
        Serial.print(b);
        delay(100);
        c=Serial.read();
        Serial.print(c);
        delay(100);
        d=Serial.read();
        Serial.print(d);
        delay(100);
        Serial.println();
          switch(a)
          {
            case '0' : sa=0;
               break;
            case '1' : sa=1;
               break;
            case '2' : sa=2;
               break;
            case '3' : sa=3;
               break;
            case '4' : sa=4;
               break;
            case '5' : sa=5;
               break;
            case '6' : sa=6;
               break;
            case '7' : sa=7;
               break;
            case '8' : sa=8;
               break;
            case '9' : sa=9;
               break;
         
          } 
            switch(b)
          {
             case '0' : su=0;
               break;
            case '1' : su=1;
               break;
            case '2' : su=2;
               break;
            case '3' : su=3;
               break;
            case '4' : su=4;
               break;
            case '5' : su=5;
               break;
            case '6' : su=6;
               break;
            case '7' : su=7;
               break;
            case '8' : su=8;
               break;
            case '9' : su=9;
               break;
  
          } 
           switch(c)
          {
            case '0' : dki=0;
               break;
            case '1' : dki=1;
               break;
            case '2' : dki=2;
               break;
            case '3' : dki=3;
               break;
            case '4' : dki=4;
               break;
            case '5' : dki=5;
               break;
            case '6' :dki=6;
               break;
            case '7' : dki=7;
               break;
            case '8' : dki=8;
               break;
            case '9' : dki=9;
               break;
         
          } 
            switch(d)
          {
             case '0' : dks=0;
               break;
            case '1' : dks=1;
               break;
            case '2' : dks=2;
               break;
            case '3' : dks=3;
               break;
            case '4' : dks=4;
               break;
            case '5' : dks=5;
               break;
            case '6' : dks=6;
               break;
            case '7' : dks=7;
               break;
            case '8' : dks=8;
               break;
            case '9' : dks=9;
               break;
  
          } 
          saat= su+sa*10;
          dk = dki*10+dks;
          Serial.println();
          Serial.print(saat);
          Serial.print(":");
          Serial.println(dk);
          
           
          if((saat==oku)&& (dk ==oku1)){  //rtc saati ve dakikası gelen verideki saat ve dakikaya eşitse
            
            Serial.println("saat ve dk verileri ayni");
              servo.write(90);
              delay(500);
              servo.write(0);
              delay(500);   
              servo.write(90);
              delay(500);
              servo.write(0);
              delay(500);  
            }
         
        
    }
  
   
        }
      
