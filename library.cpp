#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
using namespace std;

void library ::set(){
	int i=0;
	int j;
	resource database[300];
	member mem[300];
	string dump;
	ifstream fin;
        fin.open("resource.dat");
	fin >> dump;
        fin >> dump;	
	while(fin){	
	fin >> database[i].type;	
	if(database[i].type == "Book")
		Book[i].type = database[i].type;
	fin >> database[i].name;
	cout << database[i].type<< "  " << Book[i].type << "   " << database[i].name << endl;
	i++;
	}
	fin.close();
	cout << i-1 << endl;
	int n = i-1;
	ifstream fin2;
        fin2.open("input.dat");
	fin2 >> dump;
	fin2 >> dump;
	fin2 >> dump;
        fin2 >> dump;	
        fin2 >> dump;	
        fin2 >> dump;	
	string date[30];
	i = 0;
	while(fin2){
	fin2 >> date[i];
	fin2 >> dump;
	fin2 >> dump;
	fin2 >> dump;
	fin2 >> mem[i].type;	
	fin2 >> mem[i].name;
	cout << date[i] << "    " << mem[i].type << "   " << mem[i].name << endl;
	i++;
	}
	cout << "change hihi" << endl;
}
