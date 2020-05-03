#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "Macierz.hh"
#include "Wektor.hh"

template <typename typ, int rozmiar>
class UkladRownanLiniowych {
  Macierz<typ, rozmiar> UklMac;
  Wektor<typ, rozmiar> UklWek;
  
public:
  UkladRownanLiniowych<typ, rozmiar>(){};
  UkladRownanLiniowych<typ, rozmiar>(const Macierz<typ, rozmiar> & A, const Wektor<typ, rozmiar> & B){UklMac=A; UklWek=B;};
  
  const Wektor<typ, rozmiar> & getwektor() const;
  void setwektor(const Wektor<typ, rozmiar> & W);

  const Macierz<typ, rozmiar> & getmacierz() const;
  void setmacierz(const Macierz<typ, rozmiar> & M);
  
  Wektor<typ, rozmiar> Rozwiaz()const;
};

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych<typ, rozmiar> &UklRown);

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych<typ, rozmiar> &UklRown);


#endif
