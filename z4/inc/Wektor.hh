#ifndef WEKTOR_HH
#define WEKTOR_HH

#include "rozmiar.h"
#include <iostream>
#include <cmath>

class Wektor {
  double tab[ROZMIAR];
public:
  Wektor();
  Wektor(double xx, double yy, double zz);
  Wektor(double *tablica);
  Wektor(const Wektor &W);

  const double & operator [](int index) const;
  double & operator [](int index);
  
  Wektor operator +(const Wektor &W2)const;
  Wektor operator -(const Wektor &W2)const;
  double operator *(const Wektor &W2)const;
  Wektor operator *(const double &l2)const;
  Wektor operator /(const double &l2)const;

  double dlugosc();

  bool operator ==(const Wektor &W2)const;
  bool operator !=(const Wektor &W2)const;

  Wektor swap(int w1, int w2) const;
};

std::istream& operator >> (std::istream &Strm, Wektor &Wek);
std::ostream& operator << (std::ostream &Strm, const Wektor &Wek);

Wektor operator *(double l1, Wektor &W2);

#endif
