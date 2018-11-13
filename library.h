#include <string>
#include "member.h"
#include <fstream>
class library{
	public: 
		book Book[30];
		magazine Magazine[30];
	       	e_book Ebook[30];
		undergraduate Undergraduate[200];
		graduate Graduate[30];
		faculty Faculty[30];
		studyroom sroom[10];
		seat seat1[50];
		seat seat2[50];
		seat seat3[50];
		string idat[200][6];
		int idatnum;
		int idattime[200];
		string sdat[200][8];
		int sdatnum;
		int sdattime[200][2];
		int n[6];
		ofstream out;
		void set();
		void setidat();
		void setsdat();
		void write(int top,int op, int rc, int time);
		void bookprocess(int top,int op);
		void roomclear(int type,int op);
		void studyroomprocess(int top,int op);
		void seatprocess(int top,int op);
		void process();
};

		 
