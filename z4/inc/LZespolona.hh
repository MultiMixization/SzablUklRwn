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
};

std::istream & operator >> (std::istream & strm, LZespolona &Skl);
std::ostream & operator << (std::ostream & strm, LZespolona Skl);

bool operator == (LZespolona Skl1, LZespolona Skl2);
bool operator != (LZespolona Skl1, LZespolona Skl2);

LZespolona operator + (LZespolona Skl1, double a); //Operacje dla lZesp z liczba
LZespolona operator - (LZespolona Skl1, double a);
LZespolona operator * (LZespolona Skl1, double a);
LZespolona operator / (LZespolona Skl1, double a);

LZespolona operator + (LZespolona Skl1, LZespolona Skl2); //Operacje dla lZesp z lZesp
LZespolona operator - (LZespolona Skl1, LZespolona Skl2);
LZespolona operator * (LZespolona Skl1, LZespolona Skl2);
LZespolona operator / (LZespolona Skl1, LZespolona Skl2);

#endif
