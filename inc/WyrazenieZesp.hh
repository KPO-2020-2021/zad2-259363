#ifndef WYRAZENIEZESP_HH
#define WYRAZENIEZESP_HH


#include <iostream>
#include "LZespolona.hh"


/*!
 * Modeluje zbior operatorow arytmetycznych.
 */
enum Operator { Op_Dodaj, Op_Odejmij, Op_Mnoz, Op_Dziel };



/*
 * Modeluje pojecie dwuargumentowego wyrazenia zespolonego
 */
struct WyrazenieZesp {
  LZespolona   Arg1;   // Pierwszy argument wyrazenia arytmetycznego
  Operator     Op;     // Opertor wyrazenia arytmetycznego
  LZespolona   Arg2;   // Drugi argument wyrazenia arytmetycznego
};


/*
 * Naglowki funkcji
 */


void WyswietlanieSymbolu(Operator Znak);
void WyswietlWyrazenieZ(WyrazenieZesp  WyrZ);
LZespolona Oblicz(WyrazenieZesp  WyrZ);
char PrzekazanieSymbolu (Operator Operacja);
Operator PobranieSymbolu (char Znak);
ostream& operator << (ostream& StrWyj, WyrazenieZesp WyrZ);
istream& operator >> (istream& StrWej, WyrazenieZesp& WyrZ);

#endif
