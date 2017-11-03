all: exe

exe: main.o ConnectFour.o
	g++ ConnectFour.o main.o -o exe

main.o: main.cpp ConnectFour.cpp
	g++ -std=c++11 -c main.cpp ConnectFour.cpp
clean:
	rm *.o exe
