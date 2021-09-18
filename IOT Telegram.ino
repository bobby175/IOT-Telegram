

#include "CTBot.h"
#include <EEPROM.h>
CTBot myBot;
CTBotReplyKeyboard Tbl;
#define EEPROM_SIZE 4
#define Lampu1 D1
#define Lampu2 D2
#define Lampu3 D3
#define Lampu4 D4

#define LAMPU_1_ON  "Lampu_1_ON"
#define LAMPU_1_OFF  "Lampu_1_OFF"
#define LAMPU_2_ON  "Lampu_2_ON"
#define LAMPU_2_OFF  "Lampu_2_OFF"
#define LAMPU_3_ON  "Lampu_3_ON"
#define LAMPU_3_OFF  "Lampu_3_OFF"
#define LAMPU_4_ON  "Lampu_4_ON"
#define LAMPU_4_OFF  "Lampu_4_OFF"
#define SEMUA_LAMPU_ON  "Semua_Lampu_ON"
#define SEMUA_LAMPU_OFF  "Semua_Lampu_OFF"
#define TIDAK  "Tidak"

 String Status_Lampu_1;
 String Status_Lampu_2;
 String Status_Lampu_3;
 String Status_Lampu_4;
 int status_T1;
 int status_T2;
 int status_T3;
 int status_T4;
 int Lampu_1 = HIGH;
 int Lampu_2 = HIGH;
 int Lampu_3 = HIGH;
 int Lampu_4 = HIGH;

 bool TampilkanTombol;
              
 String ssid = "REDMI NOTE 8";
 String pass = "SATUDUATIGA";
 String token = "1977118306:AAEPjKFUTngx-dvR5xLlXUyY4_J9iyCOOVI";

void setup() {
  
  Serial.begin(115200);                           
	Serial.println("Memulai Koneksi...");
  EEPROM.begin(EEPROM_SIZE);
	myBot.wifiConnect(ssid, pass);       
	myBot.setTelegramToken(token);      
  
    if (myBot.testConnection())   
	      Serial.println("\nKoneksi Ke Telegram BOT Berhasil!"); 
	  else 
	      Serial.println("\nTidak Terkoneksi Ke Telegram BOT"); 
	      status_T1= EEPROM.read(0);
        status_T1= EEPROM.read(1);
        status_T1= EEPROM.read(2);
        status_T1= EEPROM.read(3);
        if (status_T1 == LOW) {
        digitalWrite(Lampu1,LOW);}
        else if (status_T1 == HIGH) {
        digitalWrite(Lampu1,HIGH);}
        if (status_T2 == LOW) {
        digitalWrite(Lampu2,LOW);}
        else if (status_T2 == HIGH) {
        digitalWrite(Lampu2,HIGH);}
        if (status_T3 == LOW) {
        digitalWrite(Lampu3,LOW);}
        else if (status_T3 == HIGH) {
        digitalWrite(Lampu3,HIGH);}
        if (status_T4 == LOW) {
        digitalWrite(Lampu4,LOW);}
        else if (status_T4 == HIGH) {
        digitalWrite(Lampu4,HIGH);}
        
        
	      pinMode(Lampu1, OUTPUT);     
        pinMode(Lampu2, OUTPUT);      
        pinMode(Lampu3, OUTPUT);     
        pinMode(Lampu4, OUTPUT);  
           
	      digitalWrite(Lampu1, HIGH);  
        digitalWrite(Lampu2, HIGH);   
        digitalWrite(Lampu3, HIGH);  
        digitalWrite(Lampu4, HIGH); 
                 
           
           Tbl.addButton("TES");
           Tbl.addRow();
           Tbl.addButton("T1 ON");
           Tbl.addButton("T2 ON");
           Tbl.addButton("T3 ON");
           Tbl.addButton("T4 ON");
           Tbl.addRow();
           Tbl.addButton("T1 OFF");
           Tbl.addButton("T2 OFF");
           Tbl.addButton("T3 OFF");
           Tbl.addButton("T4 OFF");
           Tbl.addRow();
           Tbl.addButton("Semua ON");
           Tbl.addButton("Semua OFF");
           Tbl.addRow();
           Tbl.addButton("Cek Status");
           Tbl.enableResize();
           TampilkanTombol = false;
           
           
}

void loop() {
TBMessage msg;

	if (myBot.getNewMessage(msg)) {                                                           
    if (msg.text.equalsIgnoreCase("/start")) {                                         
          myBot.sendMessage(msg.sender.id, "Halo " + msg.sender.username + "\nSelamat Datang Di Bot SMART HOME\n\nGunakan tombol dibawah untuk printah 👇", Tbl);
          Serial.println("\nUser memulai Bot \n");
          TampilkanTombol = true;
    }
    if (msg.text.equalsIgnoreCase("/Start")) {}
     
    else if (msg.text.equalsIgnoreCase("T1 ON")) {  
      digitalWrite(Lampu1, LOW); Lampu_1 = LOW;   EEPROM.write(0,LOW); EEPROM.commit();                        
      myBot.sendMessage(msg.sender.id, "T1 Sudah diaktifkan");
    }
    else if (msg.text.equalsIgnoreCase("T1 OFF")) { 
      digitalWrite(Lampu1, HIGH); Lampu_1 = HIGH; EEPROM.write(0,HIGH); EEPROM.commit();                           
      myBot.sendMessage(msg.sender.id, "T1 Sudah dimatikan"); 
    }
    else if (msg.text.equalsIgnoreCase("T2 ON")) {  
      digitalWrite(Lampu2, LOW); Lampu_2 = LOW;   EEPROM.write(1,LOW); EEPROM.commit();                         
      myBot.sendMessage(msg.sender.id, "T2 Sudah diaktifkan");
    }
    else if (msg.text.equalsIgnoreCase("T2 OFF")) { 
      digitalWrite(Lampu2, HIGH); Lampu_2 = HIGH; EEPROM.write(1,HIGH); EEPROM.commit();                          
      myBot.sendMessage(msg.sender.id, "T2 Sudah dimatikan"); 
    }
    else if (msg.text.equalsIgnoreCase("T3 ON")) {  
      digitalWrite(Lampu3, LOW); Lampu_3 = LOW;   EEPROM.write(2,LOW); EEPROM.commit();                          
      myBot.sendMessage(msg.sender.id, "T3 Sudah diaktifkan");
    }
    else if (msg.text.equalsIgnoreCase("T3 OFF")) { 
      digitalWrite(Lampu3, HIGH); Lampu_3 = HIGH; EEPROM.write(2,HIGH); EEPROM.commit();                          
      myBot.sendMessage(msg.sender.id, "T3 Sudah dimatikan"); 
    }
    else if (msg.text.equalsIgnoreCase("T4 ON")) {  
      digitalWrite(Lampu4, LOW); Lampu_4 = LOW;   EEPROM.write(3,LOW); EEPROM.commit();                          
      myBot.sendMessage(msg.sender.id, "T4 Sudah diaktifkan");
    }
    else if (msg.text.equalsIgnoreCase("T4 OFF")) { 
      digitalWrite(Lampu4, HIGH); Lampu_4 = HIGH; EEPROM.write(3,HIGH); EEPROM.commit();                          
      myBot.sendMessage(msg.sender.id, "T4 Sudah dimatikan"); 
    }
    else if (msg.text.equalsIgnoreCase("TES")) { 
      digitalWrite(Lampu1, LOW);
      digitalWrite(Lampu2, HIGH);
      digitalWrite(Lampu3, HIGH);
      digitalWrite(Lampu4, HIGH);
      delay(1000);
      digitalWrite(Lampu1, HIGH);
      digitalWrite(Lampu2, LOW);
      digitalWrite(Lampu3, HIGH);
      digitalWrite(Lampu4, HIGH);
      delay(1000);
      digitalWrite(Lampu1, HIGH);
      digitalWrite(Lampu2, HIGH);
      digitalWrite(Lampu3, LOW);
      digitalWrite(Lampu4, HIGH);
      delay(1000);
      digitalWrite(Lampu1, HIGH);
      digitalWrite(Lampu2, HIGH);
      digitalWrite(Lampu3, HIGH);
      digitalWrite(Lampu4, LOW);
      delay(1000);
      digitalWrite(Lampu1, HIGH);
      digitalWrite(Lampu2, HIGH);
      digitalWrite(Lampu3, HIGH);
      digitalWrite(Lampu4, HIGH);
      Lampu_1 = HIGH; 
      Lampu_2 = HIGH;
      Lampu_3 = HIGH;
      Lampu_4 = HIGH;       
      myBot.sendMessage(msg.sender.id, "TES BERHASIL"); 
    }
     
    else if (msg.text.equalsIgnoreCase("Semua ON")) {  
      digitalWrite(Lampu1, LOW);
      digitalWrite(Lampu2, LOW);
      digitalWrite(Lampu3, LOW);
      digitalWrite(Lampu4, LOW); 
      Lampu_1 = LOW; 
      Lampu_2 = LOW; 
      Lampu_3 = LOW; 
      Lampu_4 = LOW;                             
      myBot.sendMessage(msg.sender.id, "Semua Sudah diaktifkan");
    }
    else if (msg.text.equalsIgnoreCase("Semua OFF")) { 
      digitalWrite(Lampu1, HIGH);
      digitalWrite(Lampu2, HIGH);
      digitalWrite(Lampu3, HIGH);
      digitalWrite(Lampu4, HIGH); 
      Lampu_1 = HIGH; 
      Lampu_2 = HIGH;
      Lampu_3 = HIGH;
      Lampu_4 = HIGH;
                                   
      myBot.sendMessage(msg.sender.id, "Semua Sudah dimatikan"); 
    }
          
            else if (msg.text.equalsIgnoreCase("Cek Status")) {
            if (Lampu_1 == LOW) {
              Status_Lampu_1 = "T1 ON";
            } else {
              Status_Lampu_1 = "T1 OFF";
            }
            if (Lampu_2 == LOW) {
              Status_Lampu_2 = "T2 ON";
            } else {
              Status_Lampu_2 = "T2 OFF";
            }
            if (Lampu_3 == LOW) {
              Status_Lampu_3 = "T3 ON";
            } else {
              Status_Lampu_3 = "T3 OFF";
            }
            if (Lampu_4 == LOW) {
              Status_Lampu_4 = "T4 ON";
            } else {
              Status_Lampu_4 = "T4 OFF";
        }
        Serial.println("\nUser mengirim perintah 'Cek Status'\n");
        myBot.sendMessage(msg.sender.id, "Status saat ini : \n\n👉 " + Status_Lampu_1 + "\n\n👉 " + Status_Lampu_2 + "\n\n👉 " + Status_Lampu_3 + "\n\n👉 " + Status_Lampu_4 + "\n\nGunakan tombol dibawah untuk mengontrol lampu 👇", Tbl);
        Serial.println("\nStatus saat ini : \n\n👉 " + Status_Lampu_1 + "\n👉 " + Status_Lampu_2 + "\n👉 " + Status_Lampu_3 + "\n👉 " + Status_Lampu_4 + "\n");
      }  else {   
			        myBot.sendMessage(msg.sender.id, "⛔️ ERROR : Perintah tidak dikenali!!!\n\nGunakan tombol dibawah untuk printah 👇", Tbl);
              Serial.println("\nUser mengirim perintah yang tidak dikenal\n");
		    }
	   }
	delay(100);
}
