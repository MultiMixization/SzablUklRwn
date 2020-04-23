#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"

class Macierz {
  Wektor tab[ROZMIAR];
public:
  Macierz();
  Macierz(double tablica[]);
  Macierz(Wektor tablica[]);
  Macierz(Wektor A, Wektor B, Wektor C);
  Macierz(int jednostkowa);

  const Wektor & operator [] (int index) const;
  Wektor & operator [](int index);
  
  double wyznacznik()const;
  double dopelnienie(int x, int y)const;

  Macierz operator +(const Macierz &B) const;
  Macierz operator -(const Macierz &B)const;
  Macierz operator *(const Macierz &B)const;
  Macierz operator *(double B)const;
  Wektor operator *(const Wektor &W)const;

  bool operator ==(const Macierz &W2)const;
  bool operator !=(const Macierz &W2)const;

  Macierz ZamienKolumny(int k1, int k2)const;
  Macierz ZamienWiersze(int w1, int w2)const;

  Macierz transponuj() const;
  Macierz odwroc() const;
};

std::istream& operator >> (std::istream &Strm, Macierz &Mac);
std::ostream& operator << (std::ostream &Strm, const Macierz &Mac);

Macierz operator *(double l, const Macierz M);

#endif
