#include "WyrazenieZesp.hh"
#include <iostream>
#include "LZespolona.hh"

using namespace std;


/*
 * Funkcja odpawiadajaca za wyswietlanie symbolu w wyrazeniu zespolonym
 * Argumenty:
 *      Znak - Typ enum, odpowiada z kierowanie switchem
 */

void WyswietlanieSymbolu(Operator Znak)
{
  switch (Znak)
  {
    case Op_Dodaj:
        cout << "+";
        break;
    case Op_Odejmij:
        cout << "-";
        break;
    case Op_Mnoz:
        cout << "*";
        break;
    case Op_Dziel:
        cout << "/";
        break;
  }
}


/*
 * Funkcja odpowiada za wyswietlanie wyrazenia zespolonego na standardowe wyjscie.
 * Uzywa funkcji WyswietlanieSymbolu do obslugi znaku w wyrazeniu
 * Argumenty:
 *      WyrZ - Wyrazenie zespolone
 */

void WyswietlWyrazenieZ (WyrazenieZesp WyrZ)
{
  Wyswietl (WyrZ.Arg1);
  WyswietlanieSymbolu (WyrZ.Op);
  Wyswietl (WyrZ.Arg2);
  cout << endl;
}


/*
 * Funkcja wyliczajaca wartosc wyrazenia zespolonego
 * Argumenty:
 *      WyrZ - Wyrazenie zespolone
 * Zwraca:
 *      LZesp - Nowa liczba zespolona
 */

LZespolona Oblicz (WyrazenieZesp WyrZ)
{
  LZespolona LZesp;
  switch (WyrZ.Op)
  {
    case Op_Dodaj:
        LZesp=operator + (WyrZ.Arg1, WyrZ.Arg2);
        break;
    case Op_Odejmij:
        LZesp=operator - (WyrZ.Arg1, WyrZ.Arg2);
        break;
    case Op_Mnoz:
        LZesp=operator * (WyrZ.Arg1, WyrZ.Arg2);
        break;
  case Op_Dziel:
        LZesp=operator / (WyrZ.Arg1, WyrZ.Arg2);
        break;
  }
  return LZesp;
}


/*
 * Funkcja odczytuje symbol w wyrazeniu i zwraca go (pozniej do wyswietlenia)
 * Argumenty:
 *      Operacja - Typ enum, przechowuje numeryczna informacje, o ktory symbol chodzi
 * Zwraca:
 *      Zwraca Znak
 */

char PrzekazanieSymbolu (Operator Operacja)
{
  char Znak;
  switch (Operacja)
  {
    case Op_Dodaj:
        Znak='+';
        break;
    case Op_Odejmij:
        Znak='-';
        break;
    case Op_Mnoz:
        Znak='*';
        break;
    case Op_Dziel:
        Znak='/';
        break;
   }
   return Znak;
}


/*
 * Funkcja pobiera symbol z wyrazenia zespolonego i przypisuje mu konkretna wartosc
 * Argumenty:
 *      Znak - Wczytywany symbol
 * Zwraca:
 *      Operacja - numeryczna wartosc przypisana do wczesniej wczytanego symbolu
 */

Operator PobranieSymbolu (char Znak)
{
  Operator Operacja;
  switch (Znak)
  {
    case '+':
        Operacja=Op_Dodaj;
     break;
    case '-':
        Operacja=Op_Odejmij;
     break;
    case '*':
        Operacja=Op_Mnoz;
     break;
    case '/':
        Operacja=Op_Dziel;
     break;
  }
  return Operacja;
}


/*
 * Przeciazenie operatora dla wyswietlania wyrazenia zespolonego
 * Argumenty:
 *      StrWyj - Strumien wyjsciowy
 *      WyrZ - Wyrazenie zespolone
 * Zwraca:
 *      Wyswietlona liczbe w strumieniu wyjsciowym
 */

ostream& operator << (ostream& StrWyj, WyrazenieZesp WyrZ)
{
  StrWyj << WyrZ.Arg1;
  StrWyj << PrzekazanieSymbolu(WyrZ.Op);
  StrWyj << WyrZ.Arg2 << endl;
  return StrWyj;
}


/*
 * Przeciazenie operatora dla wczytywania wyrazenia zespolonego
 * Argumenty:
 *      StrWej - Strumien wejsciowy
 *      WyrZ - Wyrazenie zespolone
 * Zwraca: Wczytana liczbe na strumien wejsciowy
 */

istream& operator >> (istream& StrWej, WyrazenieZesp& WyrZ)
{
	char Znak;
	StrWej >> WyrZ.Arg1 >> Znak;
	WyrZ.Op = PobranieSymbolu(Znak);
	StrWej >> WyrZ.Arg2;
	return StrWej;
}
