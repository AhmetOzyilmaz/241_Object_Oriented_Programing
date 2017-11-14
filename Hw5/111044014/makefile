all: exe

exe: main.o ConnectFour.o Cell.o
	g++ ConnectFour.o main.o -o exe

main.o: main.cpp ConnectFour.cpp Cell.cpp
	g++ -std=c++11 -c main.cpp ConnectFour.cpp Cell.cpp
clean:
	rm *.o exe
