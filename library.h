#include <string>
#include "member.h"
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
		string sdat[50][8];
		int sdatnum;
		int n[6];
		void set();
		void setidat();
		void setsdat();
		void process();
};

		 
