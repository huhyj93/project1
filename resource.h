#include <string>
using namespace std;
class resource{
	public:
		string name;
		int state;
		string type;
		int date;
		void clear();
};

class book: public resource{
};


