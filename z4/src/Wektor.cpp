#include "Wektor.hh"

template <int rozmiar>
Wektor::Wektor()
{
  for(int i=0;i<rozmiar;i++)
    {
      this->tab[i]=0;
    }
}

template <typename typ>
Wektor::Wektor(typ xx, typ yy, typ zz)
{
  this->tab[0]=xx;
  this->tab[1]=yy;
  this->tab[2]=zz;
}

template<typename typ, int rozmiar>
Wektor::Wektor(typ *tablica)
{
  for(int i=0;i<rozmiar;i++)
    {
	this->tab[i]=tablica[i];
    }
}

Wektor::Wektor(const Wektor &W)
{
  for(int i=0;i<rozmiar;i++)
    {
      this->tab[i]=W[i];
    }
}

const typ & Wektor::operator [](int index) const
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

typ & Wektor::operator [](int index)
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza Zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

Wektor<typ, rozmiar> Wektor::operator +(const Wektor<typ, rozmiar> & W2) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]+W2[i];
    }
  return temp;
}

Wektor<typ, rozmiar> Wektor::operator -(const Wektor<typ, rozmiar> & W2) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]-W2[i];
    }
  return temp;
}

typ Wektor::operator *(const Wektor<typ, rozmiar> & W2) const
{
  typ wynik=0;
  for(int i=0;i<rozmiar;i++)
    {
      wynik+=(*this)[i]*W2[i];
    }
  return wynik;
}

Wektor<typ, rozmiar> Wektor::operator *(const typ & ls) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]*ls;
    }
  return temp;
}

Wektor<typ, rozmiar> Wektor::operator /(const typ & ls) const
{
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[i]=(*this)[i]/ls;
    }
  return temp;
}

typ Wektor::dlugosc()
{
  typ sum=0;
  for(int i=0;i<rozmiar;i++)
    {
      sum+=(*this)[i];
    }
  return sqrt(sum);
}

bool Wektor::operator ==(const Wektor<typ, rozmiar> &W2) const
{
  for(int i=0;i<rozmiar;i++)
    {
      if(abs((*this)[i]-W2[i])>0.00001)
	{
	  return 0;
	}
    }
  return 1;
}

bool Wektor::operator !=(const Wektor &<typ, rozmiar>W2) const
{
  return !((*this)==W2);
}

Wektor<typ, rozmiar> Wektor::swap(int w1, int w2) const
{
  Wektor<typ, rozmiar> W(*this);
  if(w1<0 || w1>=rozmiar || w2<0 || w2>=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  typ temp(W[w1]);
  W[w1]=W[w2];
  W[w2]=temp;
  return W;
}


template <typename typ, int rozmiar>
std::istream &operator >> (std::istream &Strm, Wektor<typ, rozmiar> &Wek)
{
  for(int i=0;i<rozmiar;i++)
    {
      Strm >> Wek[i];
    }
  return Strm;
}

template <typename typ, int rozmiar>
std::ostream &operator << (std::ostream &Strm, const Wektor<typ, rozmiar> &Wek)
{
  for(int i=0;i<rozmiar;i++)
    {
      if(Wek[i]>=0)
	{
	  Strm << " ";
	}
      Strm << Wek[i] << " ";
    }
  return Strm;
}

template <typename typ, int rozmiar>
Wektor operator *(typ l1, Wektor<typ, rozmiar> &W2)
{
  return W2*l1;
}
