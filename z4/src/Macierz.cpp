#include "Macierz.hh"

Macierz::Macierz()
{
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  this->tab[i][j]=0;
	}
    }
}

Macierz::Macierz(double tablica[])
{
  int pom=0;
  Wektor temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      temp[0]=tablica[pom];
      temp[1]=tablica[pom+1];
      temp[2]=tablica[pom+2];
      this->tab[i]=temp;
      pom=pom+3;
    }
}

Macierz::Macierz(Wektor tablica[])
{
  for(int i=0;i<ROZMIAR;i++)
    {
      this->tab[i]=tablica[i];
    }
}

Macierz::Macierz(Wektor A, Wektor B, Wektor C)
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
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  this->tab[i][j]=jednostkowa;
	}
    }
}

const Wektor & Macierz::operator [](int index) const
{
  if(index<0 || index>=ROZMIAR)
    {
      std::cerr << "Poza zakresem." << std::endl;
      exit(1);
    }
  return this->tab[index];
}

Wektor & Macierz::operator [](int index)
{
  if(index<0 || index >=ROZMIAR)
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
  for(int i=0;i<ROZMIAR;i++)
    {
      bool flaga=0;
      int j=i;
      while(!flaga && j<ROZMIAR)
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
      for(int k=i+1;k<ROZMIAR;k++)
	{
	  Mtemp[k]=Mtemp[k]-Mtemp[i]*(Mtemp[k][i]/Mtemp[i][i]);
	}
    }
  for(int i=0;i<ROZMIAR;i++)
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
  temp=(*this)[(x+1)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+2)%ROZMIAR][(y+2)%ROZMIAR] - (*this)[(x+2)%ROZMIAR][(y+1)%ROZMIAR] * (*this)[(x+1)%ROZMIAR][(y+2)%ROZMIAR];
  return temp;
}

Macierz Macierz::operator +(const Macierz &B) const
{
  Macierz wynik;
  for(int i=0;i<ROZMIAR;i++)
    {
      wynik[i]=(*this)[i]+B[i];
    }
  return wynik;
}

Macierz Macierz::operator -(const Macierz &B) const
{
  Macierz wynik;
  for(int i=0;i<ROZMIAR;i++)
    {
      wynik[i]=(*this)[i]-B[i];
    }
  return wynik;
}

Macierz Macierz::operator *(const Macierz &B) const
{
  Macierz MATrans((*this).transponuj());
  Macierz temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  temp[j][i]=temp[j][i]+MATrans[j]*B[i];
	}
    }
  return temp;
}

Macierz Macierz::operator *(const double B) const
{
  Macierz wynik;
  for(int i=0;i<ROZMIAR;i++)
    {
      wynik[i]=(*this)[i]*B;
    }
  return wynik;
}

Wektor Macierz::operator *(const Wektor &W) const
{
  Wektor wynik;
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  wynik[i]=wynik[i]+(*this)[j][i]*W[j];
	}
    }
  return wynik;
}

bool Macierz::operator ==(const Macierz &W2)const
{
  for(int i=0;i<ROZMIAR;i++)
    {
      if((*this)[i]!=W2[i])
	{
	  return 0;
	}
    }
  return 1;
}

bool Macierz::operator !=(const Macierz &W2)const
{
  return !(*this==W2);
}

Macierz Macierz::transponuj() const
{
  Macierz temp;
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  temp[i][j]=(*this)[j][i];
	}
    }
  return temp;
}

Macierz Macierz::odwroc() const
{
  Macierz temp;
  double Wyzn=(*this).wyznacznik();
  if(Wyzn==0)
    {
      std::cerr << "Wyznacznik 0." << std::endl;
      exit(4);
    }
  else
    {
      for(int i=0;i<ROZMIAR;i++)
	{
	  for(int j=0;j<ROZMIAR;j++)
	    {
	      temp[i][j]=(*this).dopelnienie(i,j)/Wyzn;
	    }
	}
    }
  return temp.transponuj();
}

std::istream& operator >> (std::istream &Strm, Macierz &Mac)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      Strm >> Mac[i];
    }
  return Strm;
}

std::ostream& operator << (std::ostream &Strm, const Macierz &Mac)
{
  for(int i=0;i<ROZMIAR;i++)
    {
      for(int j=0;j<ROZMIAR;j++)
	{
	  Strm << Mac.transponuj()[i][j];
	}
      Strm << std::endl;
    }
  return Strm;
}

Macierz operator *(double l, const Macierz M)
{
  return M*l;
}

Macierz Macierz::ZamienKolumny(int k1, int k2) const
{
  Macierz M2(*this);
  if(k1<0 || k1>=ROZMIAR || k2<0 || k2>=ROZMIAR)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor temp(M2[k1]);
  M2[k1]=M2[k2];
  M2[k2]=temp;
  return M2;
}

Macierz Macierz::ZamienWiersze(int w1, int w2) const
{
  Macierz M2((*this).transponuj());
  if(w1<0 || w1>= ROZMIAR || w2<0 || w2>=ROZMIAR)
    {
      std::cerr << "Poza zakresem" << std::endl;
      exit(1);
    }
  Wektor temp(M2[w1]);
  M2[w1]=M2[w2];
  M2[w2]=temp;
  M2=M2.transponuj();
  return M2;
}
