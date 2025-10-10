/*
 * Project: Smart Greenhouse via GSM (SMS Control)
 * Author: Yasin Rezaei
 * Description:
 *   Control fan, lamps, faucets, and window motor using SMS commands.
 *   The system can also send temperature, humidity, and soil moisture data.
 * Hardware:
 *   - Arduino UNO
 *   - SIM800L / GSM Module
 *   - DHT11 Sensor
 *   - Soil Moisture Sensor (Analog)
 *   - 4-Channel Relay Module
 *   - DC Motor for Window
 * Date: 2025-10-11
 */
 
#include "dht.h"
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);  // (Rx,Tx  > Tx,Rx) 
#define soilPin A0 
 float soil = 0; 

char incomingByte; 
String inputString;

int yasin=0;
int ali=0;
  
int a=0;
int b=0;

int y=0;
int x=0;

 
int d=0;
int c=0;

int e=0;
int f=0;

int g=0;
int h=0;

int i=0;
int j=0;

int l=0;
int k=0;

int m=0;
int n=0;

int r=0;
int s=0;

int o=0;
int p=0;

int z=0;
int w=0;

int op=0;
int cl=0;

int en=0;
int os=0;

int com=0;
String number="09022909323";


 
 int dht_pin = 8;
 
 dht DHT;
//===============================================
#define fan 4
#define feucet 5
#define feucet2 6
#define lamp 7

#define in1 10
#define in2 11
//===========================================
void setup() 
{
      delay(20000);
      Serial.begin(9600);
      mySerial.begin(9600); 

     while(!mySerial.available()){
        mySerial.println("AT");
        delay(1000); 
        Serial.println("Connecting...");
        }
      Serial.println("Connected!");  
      mySerial.println("AT+CMGF=1");  //Set SMS to Text Mode 
      delay(1000);  
      mySerial.println("AT+CNMI=1,2,0,0,0");  //Procedure to handle newly arrived messages(command name in text: new message indications to TE) 
      delay(1000);
      mySerial.println("AT+CMGL=\"REC UNREAD\""); // Read Unread Messages
      
 
      //===============================================================
      pinMode(in1,OUTPUT);
      pinMode(in2,OUTPUT);
      pinMode(dht_pin,INPUT_PULLUP);
      pinMode(fan,OUTPUT);
      pinMode(feucet,OUTPUT);
      pinMode(feucet2,OUTPUT);
      pinMode(lamp,OUTPUT);
      digitalWrite(fan,HIGH);
       digitalWrite(feucet,HIGH);
        digitalWrite(feucet2,HIGH);
         digitalWrite(lamp,HIGH);
         
          wellcome();
   // delay(3000);
    //command();
     }

void loop()
{  
 
  if(mySerial.available()){
      delay(100);

      // Serial Buffer
      while(mySerial.available()){
        incomingByte = mySerial.read();
        inputString += incomingByte; 
        }

        delay(10);      

        Serial.println(inputString);
        inputString.toUpperCase(); // Uppercase the Received Message
//=====================================================================
        //turn RELAY ON or OFF
        if (inputString.indexOf("FAN OFF") > -1){
          digitalWrite(fan, HIGH);
          b=a+1;
          x=0;
          y=0;
          if(b==1){
            sendon();
          }
        b=a+1;
          
          }
          delay(50);
          
   //====================================================================      
         if (inputString.indexOf("FAN ON") > -1){
          digitalWrite(fan, LOW);
          y=x+1;
          b=0;
          a=0;
          if(y==1){
            sendoff();
          }
          y=x+1;
          }          

        delay(50);
   //===================================================================
     if (inputString.indexOf("SHIR 1 OFF") > -1){
          digitalWrite(feucet, HIGH);
          f=e+1;
          g=0;
          h=0;
          if(f==1){
            relay2on();
          }
        f=e+1;
          
          }
          
          delay(50);
   //====================================================================      
         if (inputString.indexOf("SHIR 1 ON") > -1){
          digitalWrite(feucet, LOW);
          g=h+1;
          f=0;
          e=0;
          if(g==1){
            relay2off();
          }
          g=h+1;
          }          

        delay(50);
//====================================================================
        if (inputString.indexOf("SHIR 2 OFF") > -1){
          digitalWrite(feucet2, HIGH);
          i=j+1;
          l=0;
          k=0;
          if(i==1){
            shir2off();
          }
        i=j+1;
          
          }
          
          delay(50);
  //===============================================================================
  if (inputString.indexOf("SHIR 2 ON") > -1){
          digitalWrite(feucet2, LOW);
          k=l+1;
          j=0;
          i=0;
          if(k==1){
            shir2on();
          }
        k=l+1;
          
          }
          
          delay(50);
  //=================================================================================
  if (inputString.indexOf("LAMP OFF") > -1){
          digitalWrite(lamp, HIGH);
          m=n+1;
          r=0;
          s=0;
          if(m==1){
            lampoff();
          }
        m=n+1;
          
          }
          
          delay(50);
   //===================================================================================
   if (inputString.indexOf("LAMP ON") > -1){
          digitalWrite(lamp, LOW);
         
       
         
          r=s+1;
          m=0;
          n=0;
          if(r==1){
            lampon();
          }
        r=s+1;
          
          }
          
          delay(50);
 //========================================================================
   if (inputString.indexOf("THSM") > -1){
          o=p+1;
        if(o==1){
          
          temp();
          
        }
        o=p+1;
        
        
      if(o==2){
  o=0;
  p=0;
}
delay(50);
   }
   //=====================================================================
    if (inputString.indexOf("SHIR 1&2 ON") > -1){
       digitalWrite(feucet, LOW);
        digitalWrite(feucet2, LOW);
          z=w+1;
          yasin=0;
          ali=0;
        if(z==1){
          
          allon();
          
        }
        z=w+1;
       delay(50);
}

 
   //========================================================================
    if (inputString.indexOf("SHIR 1&2 OFF") > -1){
       digitalWrite(feucet, HIGH);
        digitalWrite(feucet2, HIGH);
          yasin=ali+1;
          
          z=0;
          w=0;
        if(yasin==1){

          alloff();
        
          
        }
        yasin=ali+1;
 delay(50);
    }
    //-------------------------------------------------------------------
     if (inputString.indexOf("CLOSE WINDOW") > -1){
       digitalWrite(in1, HIGH);
          digitalWrite(in2,LOW);
       
       delay(650);
        digitalWrite(in1, LOW);
           digitalWrite(in2,LOW);
          op=cl+1;
          
          en=0;
          os=0;
        if(op==1){

          closewin();
        
          
        }
        op=cl+1;
 delay(50);
    }

        if (inputString.indexOf("OPEN WINDOW") > -1){
       digitalWrite(in1, LOW);
          digitalWrite(in2,HIGH);
       
       delay(600);
        digitalWrite(in1, LOW);
           digitalWrite(in2,LOW);
          en=os+1;
          
          op=0;
          cl=0;
        if(en==1){

          openwin();
        
          
        }
        en=os+1;
 delay(50);
    }

     if (inputString.indexOf("COMMANDS") > -1){
          com=com+1;
        if(com==1){
          
          
          command();
        }
        com=com+1;
        if(com==2){
  
  com=0;
}
        delay(1000);}
//=========================================================================
        //Delete Messages & Save Memory
        if (inputString.indexOf("CLEAR") > -1){
          d=c+1;
        if(d==1){
          mySerial.println("AT+CMGDA=\"DEL ALL\"");
          delay(1000);
          Clear();
        }
        d=c+1;
        if(d==2){
  d=0;
  c=0;
}
        delay(1000);}
        
//==========================================================================
        inputString = "";
  }
}
//===============================

 void temp(){
     DHT.read11(dht_pin);
  // int value = DHT.humidity;
  // int temp = DHT.temperature;
   // Serial.print("humidity = ");
    //Serial.print(value);
    //Serial.print("%  ");
    //Serial.print("temperature = ");
    //Serial.print(DHT.temperature); 
    //Serial.println("C  ");
    soil = analogRead(soilPin); 
    delay(1); 
    
    delay(2000);//We have to wait at least 2 seconds before accessing the sensor again.

    mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
delay(1000);
mySerial.print("Temperature = ");
 mySerial.print(DHT.temperature);
 mySerial.println(" C");

  mySerial.print("Humidity = ");
 mySerial.print(DHT.humidity);
 mySerial.println(" %");

mySerial.print("Soil moisture = ");
 mySerial.print(soil);
 //mySerial.println(" %");

 
 
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
}
 
//================================
void allon(){
     

     mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
 
  mySerial.print("shir 1 and 2 is now on" );
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
}
//================================
void sendon(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  String sms="Fan is now off";
  mySerial.print(sms);
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //========================================================================
 void sendoff(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
 
  mySerial.print("Fan is now on");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //=====================================================================
 void Clear(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  
  mySerial.print("All messages cleared");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //======================================================================
  void relay2on(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  String sms="Shir 1 now is off";
  mySerial.print(sms);
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //=====================================================================
  void relay2off(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  String sms="Shir 1 is now on";
  mySerial.print(sms);
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //=====================================================
  void shir2off(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  String sms="shir 2 is now off";
  mySerial.print(sms);
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }

  void shir2on(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  String sms="shir 2 is now on";
  mySerial.print(sms);
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //=================================================
  void lampoff(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  
  mySerial.print("the lamp turned off");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }

  void lampon(){
mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  
  mySerial.print("the lamp turned on");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //====================================================
 void alloff(){
  mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
   
  mySerial.print("shir 1 and 2 is now off");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
    
 }
 //------------------------------------------------------
  void openwin(){
  mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
   
  mySerial.print("Window opened");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
  }
     void closewin(){
  mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
   
  mySerial.print("Window closed");
  delay(1000);
    mySerial.println((char)26);
    delay(1500);
     }
 //====================================================
 void wellcome(){
   mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
   
  mySerial.println("**Wellcome to smart greenhouse**");
  
  mySerial.print("*Designer & maker : Yasin Rezaei*");
  delay(1000);
    mySerial.println((char)26);
    delay(2000);
 }
 //===================================================
 void command(){
   mySerial.println("AT+CMGF=1");
  delay(1000);
 mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
   
  mySerial.println("This some command for control greenhouse");
  mySerial.println("command ==> run ");
    mySerial.println("THSM = Temperature - Humidity - Soil Moisture ");
      mySerial.println("Thsm ==> value of temperature,humidity,soil moisture ");
  mySerial.println("fan on ==> the fan turned on");
  mySerial.println("fan off ==> the fan turned off");
  mySerial.println("shir 1 on ==> the shir 1 turned on");
   mySerial.println("shir 1 off ==> the shir 1 turned off");
    mySerial.println("shir 2 on ==> the shir 2 turned on");
     mySerial.println("shir 2 off ==> the shir 2 turned off");
      mySerial.println("lamp on ==> the lamp turned on");
       mySerial.println("lamp off ==> the lamp turned off");
        mySerial.println("shir 1&2 on ==> both of them turned on ");
    mySerial.println("shir 1&2 off ==> both of them turned off ");
    mySerial.println("open window ==> the window opens ");
    mySerial.println("close window ==> the window closes");
      mySerial.println("clear ==> all message from simcard's greenhous clears ");
  
  
  
  delay(1000);
    mySerial.println((char)26);
    delay(2000);
 }
 /*void charge(){
  String ch="*140#";
mySerial.println("AT+CUSD=1");
  delay(1000);
  mySerial.println("AT+CUSD=,\""+ch+"\",15\r");
  mySerial.println("AT+CMGF=1");
  delay(1000);
  mySerial.println("AT+CMGS=\""+ number +"\"\r");
  delay(1000);
  
 mySerial.println(CUSD);
  delay(1000);
    mySerial.println((char)26); 
    
 }
 */
