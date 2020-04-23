#ifndef UKLADROWNANLINIOWYCH_HH
#define UKLADROWNANLINIOWYCH_HH

#include <iostream>
#include <fstream>
#include "Macierz.hh"
#include "Wektor.hh"

class UkladRownanLiniowych {
  Macierz UklMac;
  Wektor UklWek;
  
public:
  UkladRownanLiniowych(){}; //Zostawiam puste
  UkladRownanLiniowych(const Macierz & A, const Wektor & B);
  
  const Wektor & getwektor() const;
  void setwektor(const Wektor & W);

  const Macierz & getmacierz() const;
  void setmacierz(const Macierz & M);
  
  Wektor Rozwiaz()const;
};

std::istream& operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown);
std::ostream& operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown);


#endif
