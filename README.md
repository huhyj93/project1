# SSE3: Project1

This project's purpose is to implement Library Management. So, when we enter books and process about borrow or return, the program handle their work and make result.

## Running

I make library management system using three header file.
Compositions is *member.h*, *resource.h*, *library.h*, and this project realize undergraduate under member and book under resource. 
There are two function in *library.h* that manage library.

```
void set();
void process();
```
		 
First fuction is *set()* that reads *resource.dat* file and save data into book.
Second fuction is *process()* that reads* input.dat* file, divides returen code using each case and writes data at *output.dat* file.
So,* main.cpp* just have three line.

```
int main(){
	library Library;
	Library.set();
	Library.process();
}
```
More explanations of functions are in code.

## Getting started

I make Makefile.

``` 
# Makefile

hello: main.o library.o
	g++ -o hello main.o library.o 
main.o: main.cpp
	g++ -c main.cpp	
library.o: library.cpp
	g++ -c library.cpp	
clean:	
	rm *.o hello
```

So, just enter **make** and then **hello** file is created. 
Then, you just implement that program. 

## Versioning

Using **c++** language in Ubuntu environment

## Author : Yang Jun Huh

