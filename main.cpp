#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
//using namespace std;

int main(){
	library Library;
	Library.set();
	Library.setidat();
	cout << "----------------------------------------" << endl;
	Library.setsdat();
}
