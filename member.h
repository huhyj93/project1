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
		
};

class undergraduate : public member{
	public:
		book rent[2];
		studyroom sr;
		seat st;
		void clear();
};

class graduate: public member{
};


class faculty: public member{
};

