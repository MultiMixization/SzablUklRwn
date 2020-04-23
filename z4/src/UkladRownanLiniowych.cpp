#include "UkladRownanLiniowych.hh"

UkladRownanLiniowych::UkladRownanLiniowych(const Macierz &Am, const Wektor &Bw)
{
  this->UklMac=Am;
  this->UklWek=Bw;
}

const Wektor & UkladRownanLiniowych::getwektor() const
{
  return UklWek;
}

void UkladRownanLiniowych::setwektor(const Wektor &W)
{
  this->UklWek=W;
}

const Macierz & UkladRownanLiniowych::getmacierz() const
{
  return UklMac;
}

void UkladRownanLiniowych::setmacierz(const Macierz &M)
{
  this->UklMac=M;
}

Wektor UkladRownanLiniowych::Rozwiaz() const  //Na razie Crammer
{
  Wektor UklW(UklWek);
  Macierz UklM(this->UklMac);
  Wektor Wynik;
  double W;

  W=UklM.wyznacznik();
  
  for(int i=0;i<ROZMIAR;i++)
    {
      UklM[i]=UklWek;    //podmienianie odpowiedniej kolumny wektorem
      Wynik[i]=UklM.wyznacznik();       //Obliczanie wyznacznika podmienionej macierzy
      UklM[i]=UklMac[i];              //Przywracanie macierzy do stanu poczatkowego
    }

  if(W==0)
    {
      std::cerr << "Wyznacznik zerowy. Brak rozwiazan." << std::endl;
      exit(5);
    }
  else
    {
      for(int i=0;i<ROZMIAR;i++)
	{
	  Wynik[i]=Wynik[i]/W;
	}
      return Wynik;
    }
  
}

std::istream & operator >> (std::istream &Strm, UkladRownanLiniowych &UklRown)
{
  Wektor tempW;
  Macierz tempM;
  Strm >> tempM >> tempW;
  UklRown.setwektor(tempW);
  UklRown.setmacierz(tempM);
  return Strm;
}

std::ostream & operator << (std::ostream &Strm, const UkladRownanLiniowych &UklRown)
{
  Macierz trans(UklRown.getmacierz().transponuj());

  for(int i=0;i<ROZMIAR;i++)
    {
      Strm << "| " << trans[i] << " |" << "|x_" << i+1 << "|" << "  " << (i==1?'=':' ') << "|" << UklRown.getwektor()[i] << "|" << std::endl;
    }
  return Strm;
}
