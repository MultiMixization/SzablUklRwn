#ifndef LZESPOLONA_HH
#define LZESPOLONA_HH

#include <iostream>
#include <cstdio>
#include <cmath>

/*!
 *  Plik zawiera definicje struktury LZesplona oraz zapowiedzi
 *  przeciazen operatorow arytmetycznych dzialajacych na tej 
 *  strukturze.
 */

/*!
 * Modeluje pojecie liczby zespolonej
 */
struct  LZespolona
{
  double   re;    /*! Pole repezentuje czesc rzeczywista. */
  double   im;    /*! Pole repezentuje czesc urojona. */

  LZespolona() : re(0), im(0) {};
  LZespolona(double re2, double im2) : re(re2), im(im2){};
  explicit LZespolona (double liczba) : re(liczba), im(0) {};
  
  LZespolona operator = (double liczba) {re=liczba; im=0.0; return(*this);};
};

LZespolona sprzezenie(const LZespolona &Skl1);
double modul(const LZespolona &Skl1);

std::istream & operator >> (std::istream & strm, LZespolona &Skl);
std::ostream & operator << (std::ostream & strm, const LZespolona Skl);

bool operator == (const LZespolona Skl1, const LZespolona Skl2);
bool operator != (const LZespolona Skl1, const LZespolona Skl2);

bool operator == (const LZespolona Skl1, const double a);
bool operator != (const LZespolona Skl1, const double a);

LZespolona operator + (const LZespolona Skl1, const double a); //Operacje dla lZesp z liczba
LZespolona operator - (const LZespolona Skl1, const double a);
LZespolona operator * (const LZespolona Skl1, const double a);
LZespolona operator / (const LZespolona Skl1, const double a);

LZespolona operator + (const LZespolona Skl1, const LZespolona Skl2); //Operacje dla lZesp z lZesp
LZespolona operator - (const LZespolona Skl1, const LZespolona Skl2);
LZespolona operator * (const LZespolona Skl1, const LZespolona Skl2);
LZespolona operator / (const LZespolona Skl1, const LZespolona Skl2);

#endif
