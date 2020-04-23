#include <iostream>
#include "Wektor.hh"
#include "Macierz.hh"
#include "UkladRownanLiniowych.hh"

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
  UkladRownanLiniowych Uklad;
  Wektor wynik;
  Wektor blad;

  otworz(wej, temp+".txt");
  
  wej >> Uklad;

  cout << Uklad << endl;;

  if(!cin.good())
    {
      cerr << "Blad wczytywania." << endl;
      exit(5);
    }
  
  cout << "---Rozwiazanie metoda Cramera---" << endl;
  //cout << "Wyznacznik glowny: " << Uklad.getmacierz().wyznacznik() << endl;
  wynik=Uklad.Rozwiaz();
  blad=Uklad.getmacierz()*wynik-Uklad.getwektor();
  cout << "Rozwiazanie x_1, x_2, x_3: " << wynik << endl;
  cout << "Wektor bledu: " << blad << endl;
  cout << "Dlg wektoru bledu: " << blad.dlugosc() << endl;
}
