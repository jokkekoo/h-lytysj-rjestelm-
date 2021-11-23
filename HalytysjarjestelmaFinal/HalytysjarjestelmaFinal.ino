/*  Hälytysjärjestelmä
 *  Ryhmä 42
 *  Aleksi Kalliokoski
 *  Jokke Kivijärvi
 *  Matias Koivumaa
 */

#include <LiquidCrystal.h> // Tuodaan kirjastot näytölle ja näppäimistölle
#include <Keypad.h>

#define valikko1 3000 //Vakiot, jotka määrittävät kuinka kauan valikon tekstit näkyvät
#define valikko2 6001
#define summeri 8 //Määritellään pinnit summerille ja sensorille
#define trigPin 9
#define echoPin 10
#define trigPin1 22 
#define echoPin1 23
#define trigPin2 24
#define echoPin2 25

int kontrasti = 20; //Muuttuja LCD-näytön kontrastille
const int puhelinTieto = 13;  //Pinni GSM-moodulille ilmoitusta varten
long kesto, kesto1, kesto2; //Laajempi muuttuja kestolle
int matka, matka1, matka2, alkuMatka, alkuMatka1, alkuMatka2, nykyMatka, nykyMatka1, nykyMatka2; //Muuttujat sensoreille
unsigned long halytys = 0; //Näihin päivitetään aikaa, jotta valikko vaihtaa aina 3 sekunnin välein tekstiä
unsigned long vaihto = 0; 
String salasana = "1234"; //Salasana hälytyksen pois kytkemiseen
boolean kysytaankoSalasanaa = false;  //Tieto kysytäänkö salasanaa
boolean halyjenTila = false;  //Hälytyksen tilasta kertovat muuttujat
boolean halytPaalla = false;

const byte rivit = 4; //Neljä riviä
const byte sarakkeet = 3; //Kolme saraketta
char painettuNappain; //Numeronäppäimistöllä painettu näppäin
char nappaimet[rivit][sarakkeet] = { //Määritellään näppäimistön painikkeet
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
byte rowPins[rivit] = {15, 20, 19, 17}; //Rivien pinnit 
byte colPins[sarakkeet] = {16, 14, 18}; //Sarakkeiden pinnit
Keypad myKeypad = Keypad( makeKeymap(nappaimet), rowPins, colPins, rivit, sarakkeet); 

LiquidCrystal lcd(1, 2, 4, 5, 6, 7); //Luodaan LC objekti ja parametrit 
