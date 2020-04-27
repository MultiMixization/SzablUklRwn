#ifndef MACIERZ_HH
#define MACIERZ_HH

#include "rozmiar.h"
#include <iostream>
#include "Wektor.hh"

template<typename typ, int rozmiar>
class Macierz {
  Wektor<typ, rozmiar> tab[ROZMIAR];
public:
  Macierz();
  Macierz(typ tablica[]);
  Macierz(Wektor<typ, rozmiar> tablica[]);
  Macierz(int jednostkowa);

  const Wektor<typ, rozmiar> & operator [] (int index) const;
  Wektor<typ, rozmiar> & operator [](int index);
  
  double wyznacznik()const;
  double dopelnienie(int x, int y)const;

  Macierz<typ, rozmiar> operator +(const Macierz<typ, rozmiar> &B) const;
  Macierz<typ, rozmiar> operator -(const Macierz<typ, rozmiar> &B)const;
  Macierz<typ rozmiar> operator *(const Macierz<typ, rozmiar> &B)const;
  Macierz<typ, rozmiar> operator *(typ B)const;
  Wektor<typ, rozmiar> operator *(const Wektor<typ, rozmiar> &W)const;

  bool operator ==(const Macierz<typ, rozmiar> &W2)const;
  bool operator !=(const Macierz<typ, rozmiar> &W2)const;

  Macierz<typ, rozmiar> ZamienKolumny(int k1, int k2)const;
  Macierz<typ, rozmiar> ZamienWiersze(int w1, int w2)const;

  Macierz<typ, rozmiar> transponuj() const;
  Macierz<typ, rozmiar> odwroc() const;
};

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Macierz<typ, rozmiar> &Mac);

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<typ rozmiar> &Mac);

template <typename typ, int rozmiar>
Macierz<typ rozmiar> operator *(typ l, const Macierz<typ, rozmiar> M);

#endif
