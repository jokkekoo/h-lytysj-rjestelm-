void salasananSyotto() { //Salasanan syöttö aliohjelma
  int k = 9; //Muuttuja salasanan piirtymistä varten
  String salasanaYritys = ""; //Muuttuja syötetylle salasanalle
  kysytaankoSalasanaa = true;
  printtaus("*** H\xe1lytys! ***",0,0,1);
  printtaus("Salasana:",0,1,0);
  while(kysytaankoSalasanaa) {
    painettuNappain = myKeypad.getKey(); //Luetaan painettu näppäin
    if (painettuNappain != NO_KEY){
      if (painettuNappain == '0' || painettuNappain == '1' || painettuNappain == '2' || painettuNappain == '3' ||
        painettuNappain == '4' || painettuNappain == '5' || painettuNappain == '6' || painettuNappain == '7' ||
        painettuNappain == '8' || painettuNappain == '9' ) {
        salasanaYritys += painettuNappain; //Lisätään syötetty numero salasanaYritys muuttujaan
        printtaus("*",k,1,0);//Tulostetaan * merkkejä numeroiden tilalle
        k++;
      }
    }
    if (k > 13 || painettuNappain == '#') { //Jos salasanaa kirjoitetaan enemmän kuin 4 numeroa TAI painetaan #-merkkiä, "nollataan" kirjoitus
      salasanaYritys = "";
      k = 9;
      printtaus("*** H\xe1lytys! ***",0,0,1);
      printtaus("Salasana:",0,1,0);
    }
    if ( painettuNappain == '*') { //Painettaessa *-merkkiä testataan onko salasana oikein
      if ( salasanaYritys == salasana ) { //Jos salasana on oikein, hälytys ja summeri kytkeytyvät pois päältä
        kysytaankoSalasanaa = false;
        halytPaalla = false;
        digitalWrite(puhelinTieto, LOW);
        noTone(summeri);
      }
      else if (salasanaYritys != salasana) { //Jos syötetty salasana on väärä, kerrotaan siitä ja annetaan käsky yrittää uudelleen
        printtaus("V\xe1\xe1r\xe1 salasana!",0,0,1);
        printtaus("Yrit\xe1 uudelleen",0,1,0),
        delay(2000);
        printtaus("*** H\xe1lytys! ***",0,0,1);
        printtaus("Salasana:",0,1,0);
      }
    }    
  }
}
