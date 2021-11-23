void setup() { 
  lcd.begin(16,2); //16 paikkainen sarake ja 2 rivinen LCD-näyttö
  pinMode(puhelinTieto, OUTPUT);  //Määritetään pinni 13 outputiksi
  pinMode(summeri, OUTPUT); //Määritetään inputit ja outputit summerille ja sensorille
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  analogWrite(3,kontrasti); //Muutetaan 3 pinni LCD-näytön kontrastille sopivaksi
}
