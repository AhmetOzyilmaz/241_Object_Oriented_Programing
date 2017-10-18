all: 111044014_AHMET_OZYILMAZ_HW1

111044014_AHMET_OZYILMAZ_HW1: main.o ConnectFour.o
	g++ ConnectFour.o main.o -o 111044014_AHMET_OZYILMAZ_HW1

main.o: main.cpp ConnectFour.cpp
	g++ -std=c++11 -c main.cpp ConnectFour.cpp
clean:
	rm *.o 111044014_AHMET_OZYILMAZ_HW1
