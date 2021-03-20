#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH
#include <iostream>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */


/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona {
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */
};


/*
 * Zapowiedzi funckji i przeciazen operatorow
 */

ostream& operator << ( ostream &StrmWy, LZespolona LZesp )
void Sprawdzenie_znaku(istream &StrWej, char Znak)
istream& operator >> (istream& StrWej, LZespolona &LZesp )
bool  operator == (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2);
LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
LZespolona  sprzezenie (LZespolona  Skl1)
LZespolona  modul (LZespolona  Skl2)
LZespolona operator / (LZespolona Skl1, LZespolona  Skl2);

#endif
