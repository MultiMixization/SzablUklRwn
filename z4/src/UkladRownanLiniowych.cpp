#include "UkladRownanLiniowych.hh"

template <typename typ, int rozmiar>
const Wektor<typ, rozmiar> & UkladRownanLiniowych<typ, rozmiar>::getwektor() const
{
  return UklWek;
}

template <typename typ, int rozmiar>
void UkladRownanLiniowych<typ, rozmiar>::setwektor(const Wektor<typ, rozmiar> &W)
{
  this->UklWek=W;
}

template <typename typ, int rozmiar>
const Macierz<typ, rozmiar> & UkladRownanLiniowych<typ, rozmiar>::getmacierz() const
{
  return UklMac;
}

template <typename typ, int rozmiar>
void UkladRownanLiniowych<typ, rozmiar>::setmacierz(const Macierz<typ, rozmiar> &M)
{
  this->UklMac=M;
}

template <typename typ, int rozmiar>
Wektor<typ, rozmiar> UkladRownanLiniowych<typ, rozmiar>::Rozwiaz() const  //Na razie Crammer
{
  Wektor<typ, rozmiar> UklW(UklWek);
  Macierz<typ, rozmiar> UklM(this->UklMac);
  Wektor<typ, rozmiar> Wynik;
  typ W;

  W=UklM.wyznacznik();
  
  for(int i=0;i<rozmiar;i++)
    {
      UklM[i]=UklWek;    //podmienianie odpowiedniej kolumny wektorem
      Wynik[i]=UklM.wyznacznik();       //Obliczanie wyznacznika podmienionej macierzy
      UklM[i]=UklMac[i];              //Przywracanie macierzy do stanu poczatkowego
    }
  if(W==0)
    {
      std::cerr << "Wyznacznik zerowy." << std::endl;
      exit(7);
    }
  else
    {
      for(int i=0;i<rozmiar;i++)
	{
	  Wynik[i]=Wynik[i]/W;
	}
      return Wynik;
    }
  
}

template <typename typ, int rozmiar>
std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych<typ, rozmiar> &UklRown)
{
  Wektor<typ, rozmiar> tempW;
  Macierz<typ, rozmiar> tempM;
  Strm >> tempM >> tempW;
  UklRown.setwektor(tempW);
  UklRown.setmacierz(tempM);
  return Strm;
}

template <typename typ, int rozmiar>
std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych<typ, rozmiar> &UklRown)
{
  Macierz<typ, rozmiar> trans(UklRown.getmacierz().transponuj());

  for(int i=0;i<rozmiar;i++)
    {
      Strm << "| " << trans[i] << " |" << "|x_" << i+1 << "|" << "  " << (i==(rozmiar)/2?'=':' ') << "|" << UklRown.getwektor()[i] << "|" << std::endl;
    }
  return Strm;
}
