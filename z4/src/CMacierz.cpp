#include <iostream>

#include"Macierz.cpp"
#include"LZespolona.hh"

template typename Macierz<double, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 3> &Mac);
template Macierz<double, 3> operator *(double l, const Macierz<double, 3> M);

template typename Macierz<double, 4>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 4> &Mac);
template Macierz<double, 4> operator *(double l, const Macierz<double, 4> M);

template typename Macierz<double, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<double, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<double, 5> &Mac);
template Macierz<double, 5> operator *(double l, const Macierz<double, 5> M);

template typename Macierz<LZespolona, 3>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona, 3> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona, 3> &Mac);
template Macierz<LZespolona, 3> operator *(double l, const Macierz<LZespolona, 3> M);

template typename Macierz<LZespolona, 4>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona, 4> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona, 4> &Mac);
template Macierz<LZespolona, 4> operator *(double l, const Macierz<LZespolona, 4> M);

template typename Macierz<LZespolona, 5>;
template std::istream& operator >> (std::istream &Strm, Macierz<LZespolona, 5> &Mac);
template std::ostream& operator << (std::ostream &Strm, const Macierz<LZespolona, 5> &Mac);
template Macierz<LZespolona, 5> operator *(double l, const Macierz<LZespolona, 5> M);
