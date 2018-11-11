# Makefile

hello: main.o library.o resource.o member.o space.o
	g++ -o hello main.o library.o resource.o member.o space.o
main.o: main.cpp
	g++ -c main.cpp	
library.o: library.cpp
	g++ -c library.cpp
resource.o: resource.cpp
	g++ -c resource.cpp	
member.o: member.cpp
	g++ -c member.cpp
space.o: space.cpp
	g++ -c space.cpp	
clean:	
	rm *.o hello
