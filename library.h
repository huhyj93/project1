#include <string>
#include "member.h"
#include <fstream>
class library{
	public: 
		book Book[30];
		magazine Magazine[30];
	       	e_book Ebook[30];
		undergraduate Undergraduate[100];
		graduate Graduate[30];
		faculty Faculty[30];
		studyroom sroom[10];
		seat seat1[50];
		seat seat2[50];
		seat seat3[50];
		string idat[100][6];
		int idatnum;
		int idattime[100];
		string sdat[100][8];
		int sdatnum;
		int sdattime[100][2];
		int n[6];
		ofstream out;
		void set();
		void setidat();
		void setsdat();
		void write(int op, int rc, int time);
		void bookprocess(int op);
		void roomclear(int type,int op);
		void studyroomprocess(int op);
		void seatprocess(int op);
		void process();
};

		 
