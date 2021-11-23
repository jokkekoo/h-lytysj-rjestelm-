void salasananVaihto() { //Salasanan vaihto aliohjelma
  kysytaankoSalasanaa = true;
  String vanhaSalasana = ""; //Muuttuja syötettyä salasanaa varten
  int k = 9; //Muuttuja salasanan piirtymistä varten
  printtaus("Syot\xe1 nykyinen",0,0,1);
  printtaus("salasana:",0,1,0);
  while(kysytaankoSalasanaa) {
    painettuNappain = myKeypad.getKey(); //Luetaan painettu näppäin
    if (painettuNappain != NO_KEY){
      if (painettuNappain == '0' || painettuNappain == '1' || painettuNappain == '2' || painettuNappain == '3' ||
        painettuNappain == '4' || painettuNappain == '5' || painettuNappain == '6' || painettuNappain == '7' ||
        painettuNappain == '8' || painettuNappain == '9' ) {
        vanhaSalasana += painettuNappain; //Lisätään syötetty numero vanhaSalasana muuttujaan
        printtaus("*",k,1,0);
        k++;
      }
    }
    if (k > 13 || painettuNappain == '#') { //Jos salasanaa kirjoitetaan enemmän kuin 4 numeroa TAI painetaan #-merkkiä, "nollataan" kirjoitus
      vanhaSalasana = "";
      k = 9;
      printtaus("Syot\xe1 nykyinen",0,0,1);
      printtaus("salasana:",0,1,0);
    }
    if ( painettuNappain == '*') { //Painettaessa *-merkkiä testataan onko salasana oikein
      if ( vanhaSalasana == salasana ) { //Jos salasana on oikein, 
        String uusiSalasana = ""; //Muuttuja uudelle salasanalle
        k = 9;
        printtaus("Syot\xe1 uusi",0,0,1);
        printtaus("salasana:",0,1,0);
        while(kysytaankoSalasanaa) {
          painettuNappain = myKeypad.getKey(); //Luetaan painettu näppäin
          if (painettuNappain != NO_KEY){
            if (painettuNappain == '0' || painettuNappain == '1' || painettuNappain == '2' || painettuNappain == '3' ||
              painettuNappain == '4' || painettuNappain == '5' || painettuNappain == '6' || painettuNappain == '7' ||
              painettuNappain == '8' || painettuNappain == '9' ) {
              uusiSalasana += painettuNappain; //Lisätään syötetty numero uusiSalasana muuttujaan
              printtaus(String(painettuNappain),k,1,0);
              k++;
            }  
          }
          if (k > 13 || painettuNappain == '#') { //Jos salasanaa kirjoitetaan enemmän kuin 4 numeroa TAI painetaan #-merkkiä, "nollataan" kirjoitus
            uusiSalasana = "";
            k = 9;
            printtaus("Syot\xe1 uusi",0,0,1);
            printtaus("salasana:",0,1,0);
          }
          if ( painettuNappain == '*') { //Painettaessa *-merkkiä vaihdetaan vanha salasana uuteen
            salasana = uusiSalasana;
            printtaus("Salasana",0,0,1);
            printtaus("vaihdettu!",0,1,0);
            delay(2000);
            kysytaankoSalasanaa = false;
          }
        }
      }
      else if (vanhaSalasana != salasana) { //Jos syötetty salasana on väärä, kerrotaan siitä ja annetaan käsky yrittää uudelleen
        vanhaSalasana = "";
        k = 9;
        printtaus("V\xe1\xe1r\xe1 salasana!",0,0,1);
        printtaus("Yrit\xe1 uudelleen",0,1,0);
        delay(2000);
        printtaus("Syot\xe1 nykyinen",0,0,1);
        printtaus("salasana:",0,1,0);
      }
    }  
  }   
}
