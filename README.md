# SSE3: Project1

## Library Management

This project makes library management system using three header file.
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

##Compile Method

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

## Author : Yang Jun Huh

