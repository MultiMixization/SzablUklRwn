#include "Macierz.hh"

Macierz::Macierz()
{
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  this->tab[i][j]=0;
	}
    }
}

Macierz::Macierz(typ tablica[])
{
  int pom=0;
  Wektor<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      temp[0]=tablica[pom];
      temp[1]=tablica[pom+1];
      temp[2]=tablica[pom+2];
      this->tab[i]=temp;
      pom=pom+3;
    }
}

Macierz::Macierz(Wektor<typ, rozmiar> tablica[])
{
  for(int i=0;i<rozmiar;i++)
    {
      this->tab[i]=tablica[i];
    }
}

Macierz::Macierz(Wektor<typ, rozmiar> A, Wektor<typ, rozmiar> B, Wektor<typ, rozmiar> C)
{
  this->tab[0]=A;
  this->tab[1]=B;
  this->tab[2]=C;
}

Macierz::Macierz(int jednostkowa)
{
  if(jednostkowa!=1)
    {
      std::cerr << "Macierz jednostkowa z niezerowym argumentem." << std::endl;
      exit(2);
    }
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  this->tab[i][j]=jednostkowa;
	}
    }
}

const Wektor<typ, rozmiar> & Macierz::operator [](int index) const
{
  if(index<0 || index>=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return this->tab[index];
}

Wektor<typ, rozmiar> & Macierz::operator [](int index)
{
  if(index<0 || index >=rozmiar)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return this->tab[index];
}

double Macierz::wyznacznik() const //Gauss
{
  Macierz Mtemp(*this);
  double temp=1;
  for(int i=0;i<rozmiar;i++)
    {
      bool flaga=0;
      int j=i;
      while(!flaga && j<rozmiar)
	{
	  if(Mtemp[i][j]!=0)
	    {
	      if(i!=j)
		{
		  Mtemp=Mtemp.ZamienKolumny(i,j);
		  temp=-temp;
		}
	      flaga=1;
	    }
	  j++;
	}
      if(!flaga)
	{
	  return 0;
	}
      for(int k=i+1;k<rozmiar;k++)
	{
	  Mtemp[k]=Mtemp[k]-Mtemp[i]*(Mtemp[k][i]/Mtemp[i][i]);
	}
    }
  for(int i=0;i<rozmiar;i++)
    {
      temp=temp*Mtemp[i][i];
    }
  return temp;
}

double Macierz::dopelnienie(int x, int y) const
{
  double temp;
  if(x<0 || x>=ROZMIAR || y<0 || y>=ROZMIAR)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  temp=(*this)[(x+1)%rozmiar][(y+1)%rozmiar] * (*this)[(x+2)%rozmiar][(y+2)%rozmiar] - (*this)[(x+2)%rozmiar][(y+1)%rozmiar] * (*this)[(x+1)%rozmiar][(y+2)%rozmiar];
  return temp;
}

Macierz<typ, rozmiar> Macierz::operator +(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]+B[i];
    }
  return wynik;
}

Macierz<typ, rozmiar> Macierz::operator -(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]-B[i];
    }
  return wynik;
}

Macierz<typ, rozmiar> Macierz::operator *(const Macierz<typ, rozmiar> &B) const
{
  Macierz<typ, rozmiar> MATrans((*this).transponuj());
  Macierz<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  temp[j][i]=temp[j][i]+MATrans[j]*B[i];
	}
    }
  return temp;
}

Macierz<typ, rozmiar> Macierz::operator *(const typ B) const
{
  Macierz<typ rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      wynik[i]=(*this)[i]*B;
    }
  return wynik;
}

Wektor<typ, rozmiar> Macierz::operator *(const Wektor<typ, rozmiar> &W) const
{
  Wektor<typ, rozmiar> wynik;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  wynik[i]=wynik[i]+(*this)[j][i]*W[j];
	}
    }
  return wynik;
}

bool Macierz::operator ==(const Macierz<typ, rozmiar> &W2)const
{
  for(int i=0;i<rozmiar;i++)
    {
      if((*this)[i]!=W2[i])
	{
	  return 0;
	}
    }
  return 1;
}

bool Macierz::operator !=(const Macierz<typ, rozmiar> &W2)const
{
  return !(*this==W2);
}

Macierz<typ, rozmiar> Macierz::transponuj() const
{
  Macierz<typ, rozmiar> temp;
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  temp[i][j]=(*this)[j][i];
	}
    }
  return temp;
}

Macierz<typ rozmiar> Macierz::odwroc() const
{
  Macierz<typ rozmiar> temp;
  double Wyzn=(*this).wyznacznik();
  if(Wyzn==0)
    {
      std::cerr << "Wyznacznik 0." << std::endl;
      exit(4);
    }
  else
    {
      for(int i=0;i<rozmiar;i++)
	{
	  for(int j=0;j<rozmiar;j++)
	    {
	      temp[i][j]=(*this).dopelnienie(i,j)/Wyzn;
	    }
	}
    }
  return temp.transponuj();
}

template <typename typ, int rozmiar>
std::istream& operator >> (std::istream &Strm, Macierz<typ, rozmiar> &Mac)
{
  for(int i=0;i<rozmiar;i++)
    {
      Strm >> Mac[i];
    }
  return Strm;
}

template <typename typ, int rozmiar>
std::ostream& operator << (std::ostream &Strm, const Macierz<typ, rozmiar> &Mac)
{
  for(int i=0;i<rozmiar;i++)
    {
      for(int j=0;j<rozmiar;j++)
	{
	  Strm << Mac.transponuj()[i][j];
	}
      Strm << std::endl;
    }
  return Strm;
}

template <typename typ, int rozmiar>
Macierz operator *(typ l, const Macierz<typ,rozmiar> M)
{
  return M*l;
}

Macierz<typ, rozmiar> Macierz::ZamienKolumny(int k1, int k2) const
{
  Macierz<typ rozmiar> M2(*this);
  if(k1<0 || k1>=rozmiar || k2<0 || k2>=rozmiar)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor<typ, rozmiar> temp(M2[k1]);
  M2[k1]=M2[k2];
  M2[k2]=temp;
  return M2;
}

Macierz<typ, rozmiar> Macierz::ZamienWiersze(int w1, int w2) const
{
  Macierz M2((*this).transponuj());
  if(w1<0 || w1>= rozmiar || w2<0 || w2>=rozmiar)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor<typ, rozmiar> temp(M2[w1]);
  M2[w1]=M2[w2];
  M2[w2]=temp;
  M2=M2.transponuj();
  return M2;
}
