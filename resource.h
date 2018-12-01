#include <string>
using namespace std;
class resource{
	public:
		string name;
		int state;
		string type;
		int date;
		int cap;
		void clear();
		void allclear();

};

class book: public resource{
};
class magazine: public resource{
};
class e_book: public resource{
};


