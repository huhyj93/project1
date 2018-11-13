#include <string>

class space{
	public:
		int state;
		int start;
		int during;
		int num;
		void clear();
};

class studyroom : public space{
};

class seat : public space{
};
