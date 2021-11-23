#include <GSM.h>  //Lisätään GSM-kirjasto
#define PINNUMBER "1234"  //Määritellään PIN-koodi
const int analogPin = A0; //Määritellään mittausnapa
int arvo = 0; //Mittauksen muuttuja
GSM gsmAccess;  //GSM-kirjaston komennot
GSM_SMS sms;
char remoteNumber[20] = ""; //Puhelinnumero, johon tekstiviesti lähetetään
char txtMsg[200] = "***HALYTYS***  Kodissa havaittu liiketta!"; //Tekstiviesti

void setup() {
  Serial.begin(9600);
  boolean notConnected = true;
  while (notConnected) {  //Yhdistetään GSM-verkkoon
    if (gsmAccess.begin(PINNUMBER) == GSM_READY) {
      notConnected = false;
      }
      else {
        Serial.println("Ei yhteyttä");
        delay(1000);
      }
  }
}

void loop() {
  arvo = analogRead(analogPin);
  delay(1);
  if (arvo > 800) { //Jos A0-napa on HIGH tilassa, lähetetään tekstiviesti 
  arvo = analogRead(analogPin); // Luetaan arvo uudestaan loopissa, jotta arvo päivittyy
  sms.beginSMS(remoteNumber);
  sms.print(txtMsg);
  sms.endSMS();
  delay(60000); //Lähetetään viestejä minuutin välein, niin kauan kun hälytys on päällä
  }
}
