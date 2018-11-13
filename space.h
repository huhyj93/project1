#include <string>
using namespace std;
class space{
	public:
		string name;
		int state;
		int start;
		int during;
		int etime;
		int num;
		int day;
		void clear();
};

class studyroom : public space{
};

class seat : public space{
};
