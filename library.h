#include <string>
#include "member.h"
#include <fstream>
class library{
	public: 
		book Book[50];
		magazine Magazine[50];
	       	e_book Ebook[50];
		undergraduate Undergraduate[50];
		graduate Graduate[50];
		faculty Faculty[50];
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
		//get data file
		void set();
		void setidat();
		void setsdat();

		//write fuction
		void write(int top,int op, int rc, int time);
		//bookprocess
		void undergraduate_bookprocess(int top,int op);
		void graduate_bookprocess(int top,int op);
		void faculty_bookprocess(int top,int op);
		void bookprocess(int top,int op);
		//magazine process
		int magazinetest(string name,int time);
		void undergraduate_magazineprocess(int top,int op);
		void graduate_magazineprocess(int top,int op);
		void faculty_magazineprocess(int top,int op);
		void magazineprocess(int top,int op);
		//ebook process
		void ebookclear(int op,int state);
		void undergraduate_ebookprocess(int top,int op);
		void graduate_ebookprocess(int top,int op);
		void faculty_ebookprocess(int top,int op);
		void ebookprocess(int top,int op);
		//resource process
		int checkoverdue(int n, int op, string type);
		void resourceprocess(int top,int op);
		//roomclear
		void roomclear(int type,int op);
		//studyroomprocess
		void undergraduate_studyroomprocess(int top,int op);
		void graduate_studyroomprocess(int top,int op);
		void faculty_studyroomprocess(int top,int op);	
		void studyroomprocess(int top,int op);
		//seat process
		void undergraduate_seatprocess(int top,int op);
		void graduate_seatprocess(int top,int op);
		void faculty_seatprocess(int top,int op);
		void seatprocess(int top,int op);
		//space process
		void spaceprocess(int top,int op);
		//total process
		void process();
};

		 
