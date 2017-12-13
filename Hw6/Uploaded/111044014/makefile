all: exe
exe: main.o
	g++ main.o -o exe
main.o:
	g++ -c main.cpp -std=c++11
clean:
	rm *.o exe
