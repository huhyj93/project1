#include <string>
#include "member.h"
#include <fstream>
class library{
	public: 
		book Book[30];
		magazine Magazine[30];
	       	e_book Ebook[30];
		undergraduate Undergraduate[30];
		graduate Graduate[30];
		faculty Faculty[30];
		string idat[50][6];
		int idatnum;
		int idattime[50];
		string sdat[50][8];
		int sdatnum;
		int sdattime[50][2];
		int n[6];
		ofstream out;
		void set();
		void setidat();
		void setsdat();
		void write(int op, int rc, int time);
		void bprocess(int op);
		void process();
		void fprocess();
};

		 
