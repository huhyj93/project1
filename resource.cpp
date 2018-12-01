#include <string>
#include "resource.h"

void resource :: clear(){
	state = 0;
	date = 0;
}

void resource :: allclear(){
	name = " ";
	type = " ";
	state = 0;
	date = 0;
	cap =0;
}
