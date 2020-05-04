#include <iostream>
#include <iomanip>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"
#include "LZespolona.hh"

using namespace std;

bool otworz(ifstream &wej, const string nazwa) //Nie ma sensu robic modulu na krotka fcje
{
  wej.open(nazwa);
  if(wej.is_open())
    {
      return 1;
    }
  cerr << "Blad podczas otwieranie pliku. Program zamknie sie." << endl;
  exit(6);
}

int main(int argc, char *argv[])
{
  if(argc<=1)
    {
      cerr << "Brak wymaganych argumentow" << endl;
      exit(7);
    }
  string temp=argv[1];
  ifstream wej;
  char rodzaj;
  
  otworz(wej, temp);
  if(!cin.good())
    {
      cerr << "Blad wczytywania." << endl;
      exit(5);
    }
  wej >> rodzaj;

  if(rodzaj=='z')
    {
      UkladRownanLiniowych<LZespolona, 5> Uklad;
      Wektor<LZespolona, 5> wynik;
      Wektor<LZespolona, 5> blad;

      wej >> Uklad;
      cout << fixed << setprecision(2) << Uklad << endl;;
      cout << "---Rozwiazanie metoda Cramera---" << endl;
      cout << "Wyznacznik glowny: " << Uklad.getmacierz().wyznacznik() << endl;
      wynik=Uklad.Rozwiaz();
      blad=Uklad.getmacierz()*wynik-Uklad.getwektor();
      cout << "Rozwiazania: " << fixed << setprecision(2) << wynik << endl;
      cout << "Wektor bledu: " << scientific << setprecision(1)<< blad << endl;
      cout << "Dlg wektoru bledu: " << blad.dlugosc() << endl;
      return 0;
    }
  if(rodzaj=='r')
    {
      UkladRownanLiniowych<double, 5> Uklad;
      Wektor<double, 5> wynik;
      Wektor<double, 5> blad;

      wej >> Uklad;
      cout << fixed << setprecision(2) << Uklad << endl;;
      cout << "---Rozwiazanie metoda Cramera---" << endl;
      cout << "Wyznacznik glowny: " << Uklad.getmacierz().wyznacznik() << endl;
      wynik=Uklad.Rozwiaz();
      blad=Uklad.getmacierz()*wynik-Uklad.getwektor();
      cout << "Rozwiazania: " << fixed << setprecision(2) << wynik << endl;
      cout << "Wektor bledu: " << scientific << setprecision(1)<< blad << endl;
      cout << "Dlg wektoru bledu: " << blad.dlugosc() << endl;
      return 0;
    }
  cerr << "Brak okreslonego typu zawartosci." << endl;
  exit(9);
}
