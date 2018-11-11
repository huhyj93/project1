#include "member.h"
#include <string>

void undergraduate :: clear(){
	name = " ";
	books = " ";
	state = 0 ;
	late = 0;
	date = 0;
	booknum = 0;
	rent[0].clear();
	rent[1].clear();
	sr.clear();
	st.clear();
}
