#include <string>

class space{
	public:
		int state;
		int time;
		void clear();
};

class studyroom : public space{
};

class seat : public space{
};
