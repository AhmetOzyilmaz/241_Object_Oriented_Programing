all: exe

exe: main.o GTUMap.o GTUSet.o GTUSetBase.o 
	g++  GTUMap.o GTUSet.o GTUSetBase.o main.o -o exe

main.o: main.cpp  
	g++ -std=c++11 -c main.cpp

GTUMap.o: GTUMap.h
	g++ -std=c++11 -c GTUMap.h

GTUSet.o: GTUSet.h
	g++ -std=c++11 -c GTUSet.h

GTUSetBase.o: GTUSetBase.h
	g++ -std=c++11 -c GTUSetBase.h

clean:
	rm *.o exe
