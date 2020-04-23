#include "Wektor.hh"

Wektor::Wektor()
{
  for(int i=0;i<ROZMIAR;i++)
    {
      this->tab[i]=0;
    }
}

Wektor::Wektor(double xx, double yy, double zz)
{
  this->tab[0]=xx;
  this->tab[1]=yy;
  this->tab[2]=zz;
}

Wektor::Wektor(double *tablica)
{
  for(int i=0;i<ROZMIAR;i++)
    {
	this->tab[i]=tablica[i];
    }
}

Wektor::Wektor(const Wektor &W)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      this->tab[i]=W[i];
    }
}

const double & Wektor::operator [](int index) const
{
  if(index<0 || index >=ROZMIAR)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

double & Wektor::operator [](int index)
{
  if(index<0 || index >=ROZMIAR)
    {
      std::cerr << "Poza Zakresem." << std::endl;
      exit(1);
    }
  return tab[index];
}

Wektor Wektor::operator +(const Wektor & W2) const
{
  Wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      temp[i]=(*this)[i]+W2[i];
    }
  return temp;
}

Wektor Wektor::operator -(const Wektor & W2) const
{
  Wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      temp[i]=(*this)[i]-W2[i];
    }
  return temp;
}

double Wektor::operator *(const Wektor & W2) const
{
  double wynik=0;
  for(int i=0;i<ROZMIAR;i++)
    {
      wynik+=(*this)[i]*W2[i];
    }
  return wynik;
}

Wektor Wektor::operator *(const double & ls) const
{
  Wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      temp[i]=(*this)[i]*ls;
    }
  return temp;
}

Wektor Wektor::operator /(const double & ls) const
{
  Wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      temp[i]=(*this)[i]/ls;
    }
  return temp;
}

double Wektor::dlugosc()
{
  double sum=0;
  for(int i=0;i<ROZMIAR;i++)
    {
      sum+=(*this)[i];
    }
  return sqrt(sum);
}

bool Wektor::operator ==(const Wektor &W2) const
{
  for(int i=0;i<ROZMIAR;i++)
    {
      if(abs((*this)[i]-W2[i])>0.00001)
	{
	  return 0;
	}
    }
  return 1;
}

bool Wektor::operator !=(const Wektor &W2) const
{
  return !((*this)==W2);
}

Wektor Wektor::swap(int w1, int w2) const
{
  Wektor W(*this);
  if(w1<0 || w1>=ROZMIAR || w2<0 || w2>=ROZMIAR)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  double temp(W[w1]);
  W[w1]=W[w2];
  W[w2]=temp;
  return W;
}

std::istream &operator >> (std::istream &Strm, Wektor &Wek)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      Strm >> Wek[i];
    }
  return Strm;
}

std::ostream &operator << (std::ostream &Strm, const Wektor &Wek)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      if(Wek[i]>=0)
	{
	  Strm << " ";
	}
      Strm << Wek[i] << " ";
    }
  return Strm;
}

Wektor operator *(double l1, Wektor &W2)
{
  return W2*l1;
}
