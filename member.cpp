#include "member.h"
#include <string>

void member :: clear(){
	name = " ";
	books = " ";
	state = 0 ;
	late = 0;
	date = 0;
	booknum = 0;
	int i;
	for(i=0; i<10 ;i++){
		rent[i].clear();
	}
}
