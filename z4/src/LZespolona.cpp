#include "LZespolona.hh"

std::istream & operator >> (std::istream &strm, LZespolona &Skl)
{
  char znak;
  strm >> znak;
  if(znak != '(') strm.setstate(std::ios::failbit);
  strm >> Skl.re >> Skl.im >> znak;
  if(znak != 'i') strm.setstate(std::ios::failbit);
  strm >> znak;
  if(znak != ')') strm.setstate(std::ios::failbit);
  return strm;
}

std::ostream & operator << (std::ostream &strm, LZespolona Skl)
{
  strm << "(" << Skl.re;
  if(Skl.im>=0)
    {
      strm << "+";
    }
  strm << Skl.im << "i)";
  return strm;
}

bool operator == (LZespolona Skl1, LZespolona Skl2)
{
  if(Skl1.re==Skl2.re && Skl1.im==Skl2.im)
    {
      return true;
    }
  return false;
}

bool operator != (LZespolona Skl1, LZespolona Skl2)
{
  if(!(Skl1.re==Skl2.re))
    {
      return true;
    }
  return false;
}

LZespolona operator + (LZespolona Skl1, double a)
{
  LZespolona Wynik;

  Wynik.re=Skl1.re+a;
  Wynik.im=Skl1.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, double a)
{
  LZespolona Wynik;
  
  Wynik.re=Skl1.re-a;
  Wynik.im=Skl1.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, double a)
{
  LZespolona Wynik;

  Wynik.re=Skl1.re*a;
  Wynik.im=Skl1.im*a;
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, double a)
{
  LZespolona Wynik;
  if(a==0)
    {
      std::cerr << "Nie dziel przez 0!" << std::endl;
      std::exit(1);
    }

  Wynik.re=Skl1.re/a;
  Wynik.im=Skl1.im/a;
  return Wynik;
}

LZespolona  operator + (LZespolona  Skl1,  LZespolona  Skl2)
{
  LZespolona  Wynik;

  Wynik.re = Skl1.re + Skl2.re;
  Wynik.im = Skl1.im + Skl2.im;
  return Wynik;
}

LZespolona operator - (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re=Skl1.re-Skl2.re;
  Wynik.im=Skl1.im-Skl2.im;
  return Wynik;
}

LZespolona operator * (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;

  Wynik.re=Skl1.re*Skl2.re-Skl1.im*Skl2.im;
  Wynik.im=Skl1.re*Skl2.im+Skl1.im*Skl2.re;
  return Wynik;
}

LZespolona operator / (LZespolona Skl1, LZespolona Skl2)
{
  LZespolona Wynik;
  
  if(Skl2.re==0 && Skl2.im==0)
    {
      std::cerr << "Blad! Dzielenie przez 0." << std::endl;
      std::exit(1);
    }
  Wynik.re=(Skl1.re*Skl2.re+Skl1.im*Skl2.im)/(pow(Skl1.im,2)+pow(Skl2.im,2));
  Wynik.im=(Skl1.im*Skl2.re-Skl1.re*Skl2.im)/(pow(Skl1.im,2)+pow(Skl2.im,2));
  return Wynik;
}
