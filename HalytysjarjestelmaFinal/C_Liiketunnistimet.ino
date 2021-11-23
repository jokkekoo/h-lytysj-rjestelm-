long matkaPituus(){ //Ultraäänisensorin muuttaminen liiketunnistimeksi
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); //Lähetetään 10µs ääniaalto laukaisupinnillä
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  kesto = pulseIn(echoPin, HIGH); //Luetaan kaikupinniltä ääniaallon ajankesto
  matka = kesto*0.034/2; //Lasketaan matkan pituus kertomalla ajankesto äänen nopeudella ja jaetaan tulos 2:lla
  return matka; //Palautetaan matka-muuttuja 
}

long matkaPituus1(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  kesto1 = pulseIn(echoPin1, HIGH);
  matka1 = kesto1*0.034/2; 
  return matka1;
}

long matkaPituus2(){
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  kesto2 = pulseIn(echoPin2, HIGH);
  matka2 = kesto2*0.034/2;
  return matka2; 
}
