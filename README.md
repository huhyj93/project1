# SSE3:project1

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

Also, I make Makefile. So, when you want to compile, just enter **make** and then **hello** file is created. Then, you just implement that program. 

## Author : Yang Jun Huh

