#include <string>
#include "resource.h"
class member{
	public:
		string name;
		string books;
		int state;
		int late;
		int date;
		int booknum;	
		book rent[300];
};

class undergraduate : public member{
};

class graduate: public member{
};


class faculty: public member{
};

