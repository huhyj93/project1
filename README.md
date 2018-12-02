# SSE3: Project3

Project3는 기존의 Project1과 project2에서 진행했던 library management system과 space관리 기능에 새로운 member인 graduate 와 faculty, 새로운 책종류인 magazine과 e-book을 추가하는 과제이다.

project1을 진행했던 master branch에 주어진 프로젝트 ppt를 참고해서 각각의 member별로 book종류에 대한 규칙을 추가했으며, space기능을 추가했던 project2 branch와 merge했다. 

## Running

나는 기존에 진행되었던 project1의 member.h에다가 graduate와 faculty class를 추가했다.

````
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

`````

또한, resource.h에다가 magazine와 e-book의 class를 추가했다. 

`````````
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

``````````````````

그리고 새로운 기능을 추가할 수 있는 함수들을 library.h에 추가했다. 각각의 파트에 대해서 설명하겠다.

```````````
		//bookprocess
		void undergraduate_bookprocess(int top,int op);
		void graduate_bookprocess(int top,int op);
		void faculty_bookprocess(int top,int op);
		void bookprocess(int top,int op);
```````

위 부분은 각각의 멤버별로 book을 빌리는 함수를 만들었고 *bookprocess* 함수에서 멤버별로 구분해서 진행되도록 만들었다.
마찬가지로 magazine과 e-book에 대한 함수도 멤버별로 만들고 합쳤다.

``````````````
		//magazine process
		int magazinetest(string name,int time);
		void undergraduate_magazineprocess(int top,int op);
		void graduate_magazineprocess(int top,int op);
		void faculty_magazineprocess(int top,int op);
		void magazineprocess(int top,int op);
		//ebook process
		void ebookclear(int op,int state);
		void undergraduate_ebookprocess(int top,int op);
		void graduate_ebookprocess(int top,int op);
		void faculty_ebookprocess(int top,int op);
		void ebookprocess(int top,int op);
		//resource process
		void resourceprocess(int top,int op);
``````

여기서 *magazinetest* 함수는 멤버 전체를 체크해서 magazine을 빌렸는지 체크하는 함수이고 *ebookclear* 함수는 기간이 지난 e-book을 지우는 함수이다.

또한, *resourceprocess* 함수는 모든 resource들을 합치는 함수이다.

```````````````
		//studyroomprocess
		void undergraduate_studyroomprocess(int top,int op);
		void graduate_studyroomprocess(int top,int op);
		void faculty_studyroomprocess(int top,int op);	
		void studyroomprocess(int top,int op);
		//seat process
		void undergraduate_seatprocess(int top,int op);
		void graduate_seatprocess(int top,int op);
		void faculty_seatprocess(int top,int op);
		void seatprocess(int top,int op);
		//space process
		void spaceprocess(int top,int op);
`````````

또한, member별로 studyroom과 seat을 관리하는 함수를 만들었고 *spaceprocess* 에서 두가지 기능을 합친다.

``````````
		//total process
		void process();
``````````

마지막으로 *process*함수에서 모든 기능을 합친다.

그 결과 **main.cpp**에서는 library class 선언과 process함수만 처리하도록 했다.

각각의 함수에 대한 이해는 코드를 통해 설명되어 진다.

## Getting started

 Project1,2과 마찬가지로 Makefile을 만들었다.

``` 
# Makefile

hello: main.o library.o resource.o member.o space.o
	g++ -o hello main.o library.o resource.o member.o space.o
main.o: main.cpp
	g++ -c main.cpp	
library.o: library.cpp
	g++ -c library.cpp
resource.o: resource.cpp
	g++ -c resource.cpp	
member.o: member.cpp
	g++ -c member.cpp
space.o: space.cpp
	g++ -c space.cpp	
clean:	
	rm *.o hello
```

단순히 **make** 라는 명령어만 입력하게 되면 **hello** 라는 실행 파일이 생성된다.

그 후 **hello** 파일을 실행시키면 된다.

```
make

```

## Versioning

 Using **c++** language in Ubuntu environment

## Author : Yang Jun Huh

