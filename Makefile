# Makefile

hello: main.o library.o
	g++ -o hello main.o library.o 
main.o: main.cpp
	g++ -c main.cpp	
library.o: library.cpp
	g++ -c library.cpp	
clean:	
	rm *.o hello
