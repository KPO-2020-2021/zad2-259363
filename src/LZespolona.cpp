#include "LZespolona.hh"
#include <cmath>

#define MIN_DIFF 0.00001

using namespace std;


/*
 * Przeciazenie operatora do wyswietlania liczb zepolonych.
 * Argumenty:
 *    StrmWy - Strumien wyjsciowy
 *    LZesp - Liczba zespolona.
 * Zwraca:
 *    Wyswietlona liczbe zespolona na ze strumienia.
 */

ostream& operator << ( ostream &StrmWy, LZespolona LZesp )
{   
    return StrmWy << "(" << LZesp.re << showpos << LZesp.im << noshowpos << "i)";
}

/*
 * Funkcja wczytuje sprawdza czy zgadza sie z podanym znakiem. Jak nie to daje blad
 * Argumenty:
 *     Znak - okreslony znak do porownania z wczytanym
 */

void Sprawdzenie_znaku(istream &StrWej, char Znak)
{
    char WczytanyZnak=' ';
    Strmwej >> WczytanyZnak;
    if (WczytanyZnak != Znak)
    {
        StrWej.setstate(ios::failbit);
    }
}

/*
 * Przeciazenie operatora do wczytywania liczb zespolonych
 * Argumenty:
 *      StrWej - Strumien wejsciowy
 *      LZesp - Liczba Zespolona
 */

istream& operator >> (istream& StrWej, LZespolona &LZesp )
{
    Sprawdzenie_znaku(Strwej, '(');
    StrWej >> LZesp.re;
    StrWej >> LZesp.im;
    Sprawdzenie_znaku(Strwej, 'i');
    Sprawdzenie_znaku(Strwej, ')');
    return StrWej;
}

/*!
 * Realizuje porównanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwsza porównywana liczba zespolona,
 *    Skl2 - druga porównywana liczba zespolona.
 * Zwraca:
 *    True dla równych liczb zespolonych.
 */

bool  operator == (LZespolona  Skl1,  LZespolona  Skl2){
  if ((Skl1.re == Skl2.re) && (Skl1.im == Skl2.im))
    return true;
  else
    return false;
  //alternatywnie, dla MIN_DIFF i wyników od użytkownika
  /*
  if abs(Skl1.re - Skl2.re) <= MIN_DIFF && abs(Skl1.im - Skl2.im) <= MIN_DIFF
    return true;
  else
    return false;
  */
}


/*!
 * Realizuje dodanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik dodawania,
 *    Skl2 - drugi skladnik dodawania.
 * Zwraca:
 *    Sume dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2){
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}


/*!
 * Realizuje odejmowanie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik odejmowania,
 *    Skl2 - drugi skladnik odejmowania.
 * Zwraca:
 *    Roznica dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator - (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re - Skl2.re;
  Wynik.im = Skl1.im - Skl2.im;
  return Wynik;
}


/*!
 * Realizuje mnozenie dwoch liczb zespolonych.
 * Argumenty:
 *    Skl1 - pierwszy skladnik mnozenia,
 *    Skl2 - drugi skladnik mnozenia.
 * Zwraca:
 *    Iloczyn dwoch skladnikow przekazanych jako parametry.
 */

LZespolona  operator * (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = ((Skl1.re * Skl2.re) - (Skl1.im * Skl2.im));
  Wynik.im = (Skl1.re * Skl2.im) + (Skl1.im * Skl2.re);
  return Wynik;
}


/*
 * Funkcja obliczajaca sprzezenie liczby zespolonej
 * Argumenty:
 *      LZesp - Liczba zespolona
 * Zwraca:
 *      Sprzezana liczbe zespolona
 */

LZespolona  sprzezenie (LZespolona  LZesp)
{
  LZesp.im = -(LZesp.im);
  return LZesp;
}


/*!
 * Realizuje modul liczb zespolonej.
 * Argumenty:
 *    LZesp - liczba zespolona.
 * Zwraca:
 *    Modul zadanej liczby zespolonej.
 */

LZespolona  modul (LZespolona  LZesp)
{
    double Modul;
    Modul=sqrt(pow(LZesp.re, 2) + pow(LZesp.im, 2));
    return Modul;
}

/*!
 * Realizuje dzielenie liczby zespolonej przez liczbe zespolona.
 * Argumenty:
 *    Skl1 - dzielona liczba zespolona,
 *    Skl2 - dzielnik, liczba zespolona
 * Zwraca:
 *    Wynik dzielenia dwoch liczb zespolonych przez siebie.
 */

LZespolona  operator / (LZespolona  Skl1, LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik = operator * (Skl1, sprzezenie(Skl2));
  Wynik.re = (Wynik.re)/(pow(modul(Skl2), 2));
  Wynik.im = (Wynik.im)/(pow(modul(Skl2), 2));
  return Wynik;
}

/*
 * Funkcja wyswitlajaca na standardowe wyjscie liczbe zespolona
 * Argumenty:
 *      LZesp - Liczba zespolona
 */ 

void Wyswietl (LZespolona LZesp)
{
    cout << "(" << LZesp.re << showpos << LZesp.im << noshowpos << "i)";
}
