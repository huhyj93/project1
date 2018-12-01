#include <string>
#include "resource.h"
#include "space.h"
class member{
	public:
		string name;
		string books;
		int state;
		int late;
		int date;
		int booknum;
		int mznum;
		int ebnum;
		int cap;	
		book rent[10];
		magazine rent1[10];
		e_book rent2[50];
		studyroom sr;
		seat st;
		void clear();
};

class undergraduate : public member{

};
class graduate : public member{

};
class faculty : public member{

};


