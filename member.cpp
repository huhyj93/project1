#include "member.h"
#include <string>

void member :: clear(){
	name = " ";
	books = " ";
	state = 0 ;
	late = 0;
	date = 0;
	booknum = 0;
	mznum = 0;
	ebnum = 0;
	cap = 0 ;
	int i;
	for(i=0; i<10 ;i++){
		rent[i].allclear();
		rent1[i].allclear();
	}
	for(i=0; i<50 ;i++){
		rent2[i].allclear();
	}
}
