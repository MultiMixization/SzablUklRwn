#
#  To sa opcje dla kompilacji
#
CPPFLAGS= -c -g -Iinc -Wall -pedantic -std=c++17

__start__: uklad_rownan
	./uklad_rownan

uklad_rownan: obj/main.o obj/LZespolona.o obj/UkladRownanLiniowych.o obj/Macierz.o obj/Wektor.o
	g++ -Wall -pedantic -o uklad_rownan obj/main.o obj/LZespolona.o obj/Wektor.o  obj/Macierz.o obj/UkladRownanLiniowych.o

obj/main.o: src/main.cpp src/CUkladRownanLiniowych.cpp src/CMacierz.cpp src/CWektor.cpp src/LZespolona.cpp
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/UkladRownanLiniowych.o: src/UkladRownanLiniowych.cpp src/CUkladRownanLiniowych.cpp inc/UkladRownanLiniowych.hh
	g++ ${CPPFLAGS} -o obj/UkladRownanLiniowych.o src/CUkladRownanLiniowych.cpp

obj/LZespolona.o: src/LZespolona.cpp inc/LZespolona.hh
	g++ ${CPPFLAGS} -o obj/LZespolona.o src/LZespolona.cpp

obj/Macierz.o: src/Macierz.cpp src/CMacierz.cpp inc/Macierz.hh 
	g++ ${CPPFLAGS} -o obj/Macierz.o src/CMacierz.cpp

obj/Wektor.o: src/Wektor.cpp src/CWektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -o obj/Wektor.o src/CWektor.cpp

clean:
	rm -f obj/*.o uklad_rownan
