void loop() {
  painettuNappain=myKeypad.getKey();
  if(!halytPaalla){ 
    if(millis() >= halytys + valikko1){ //3 sekunnin delay eri tavalla toteutettuna
      halytys += valikko1;
      printtaus("H\xe1lytys p\xe1\xe1lle",0,0,1); //Tulostetaan näytölle aliohjelman avulla
      printtaus("painamalla *",0,1,0);  //Tulostetaan seuraavalle riville
      painettuNappain=myKeypad.getKey();
    }
    
  if(millis() >= vaihto + valikko2){
    vaihto += valikko2;
    printtaus("Vaihda salasana",0,0,1);
    printtaus("painamalla #",0,1,0);
    painettuNappain=myKeypad.getKey();
  }
  }
  switch (painettuNappain){ //Tarkistetaan onko painettu näppäimiä * tai #    
    case '*': 
      tone(summeri, 1000, 200); //Soitetaan summeria
      halyjenTila=true; //Asetetaan hälytys päälle
      break;
              
    case '#':
      tone(summeri, 1000, 200);
      salasananVaihto(); //Käynnistetään salasananvaihto-aliohjelma
      break;
  }
  if (halyjenTila) { //If lauseke toimii hälytyksen tilan mukaan
    printtaus("J\xe1rjestelm\xe1",0,0,1);
    printtaus("aktivoituu:",0,1,0);
    int laskuri = 9; //Luodaan lähtölaskuri hälyjen päällemenolle
    while (laskuri != 0) {
      printtaus(String(laskuri),11,1,0);
      laskuri--;
      tone(summeri, 500, 100);
      delay(1000);
    }
    printtaus("J\xe1rjestelm\xe1",0,0,1);
    printtaus("aktivoitu!",0,1,0);
    alkuMatka = matkaPituus(); //Mitataan ultraäänisensoreilla alkuetäisyydet
    alkuMatka1 = matkaPituus1();
    alkuMatka2 = matkaPituus2();  
    halyjenTila = false;
    halytPaalla = true; //Hälytykset menevät päälle
  }
  if (halytPaalla == true) {
    digitalWrite(puhelinTieto, HIGH); //Annetaan tieto GSM-moduulille ilmoittaa hälytyksestä
  }
  if (halytPaalla == true){
    nykyMatka = matkaPituus() + 10;
    if ( nykyMatka < alkuMatka ) { //Sensori vertailee eroa alkuperäisen ja nykyisen matkan välillä
      tone(summeri, 1000); //Summeri alkaa toistamaan 1000Hz signaalia jos sensori on havainnut eroa matkojen välillä 
      lcd.clear();
      salasananSyotto(); //Suoritetaan salasanan syöttö aliohjelma
    }
  }
  if (halytPaalla == true){
    nykyMatka1 = matkaPituus1() + 10;
    if ( nykyMatka1 < alkuMatka1 ) {
      tone(summeri, 1000);
      lcd.clear();
      salasananSyotto();
    }
  }
  if (halytPaalla == true){
    nykyMatka2 = matkaPituus2() + 10;
    if ( nykyMatka2 < alkuMatka2 ) {
      tone(summeri, 1000);
      lcd.clear();
      salasananSyotto();
    }
  }        
}
