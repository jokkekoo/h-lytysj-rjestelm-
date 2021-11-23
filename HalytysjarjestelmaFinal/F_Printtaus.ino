void printtaus(String a, int b, int c, int d){  //Kaikki LCD-näytölle kirjoittaminen tapahtuu tässä aliohjelmassa
  if(d==1){
    lcd.clear(); // Jos d = 1, poistetaan entiset tekstit näytöltä
  }
 lcd.setCursor(b,c);//Mihin kohtaan ja kummalle riville
 lcd.print(a); // Mitä tulostetaan LCD-näytölle, pitää olla heittomerkkien sisällä
}
