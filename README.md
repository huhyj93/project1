# SSE3: Project1

Project2는 기존의 Project1에서 진행했던 library management system에 space관리 기능을 추가하는 과제이다.
Space는 Studyroom과 Seat 두가지 종류가 있으며 종류에 따라 이용규칙이 다르다.
또한, Space관리 기능은 기존에 진행되었던 Book관리 기능과 동시에 작동할 수 있어야 한다. 

## Running

나는 기존에 진행되었던 project1에 space.h와 space.cpp파일을 추가했다. space.h는 각각 Studyroom과 Seat 클래스를 생성했고 구성은 아래와 같다.

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

또한, Project1에서 만들었던 header file의 class에 각각 clear()함수를 추가하기 위해서 member.cpp, resource.cpp를 추가했다. 
Project1에서는 한개의 함수에서 모든 작업을 진행하도록 코딩하였는데 이 방식이 비효율적이라 판단해서 작업을 여러 함수를 통해서 진행 될수 있게 쪼개서 만들었다. 
먼저, *set()* 함수는 **resource.dat** 파일을 읽어서 목록에 있는 책들을 저장하도록 하는 함수이다. *setidat()* , *setsdat()* 역시 각각 **input.dat** , **space.dat** 파일을 읽는 함수이다.
그리고, **output.dat** 에 간편히 쓰기 위해 *write()* 함수를 통해서 rc에 따라서 각각의 결과를 쓰게 만든함수이다.
또한, 책의 빌리고 반납을 처리하는 project1의 기능을 수행하는 *bookprocess()* 함수를 만를었다. 이 함수의 장점은 한개의 operation씩 처리할 수 있게 만든 것이다.
그리고 다음날이 된 경우 모든 space가 초기화 되는 기능을 수행하기 위한 *roomclear()* 함수를 만들었고, *studyroomprocess()* 와 *seatprocess()* 함수에서 각각 studyroom과 seat와 관련된 operation을 처리할 수 있도록 했다. 마찬가지로, 이 두 함수 역시 한개의 operation씩 처리할 수 있다.
마지막으로, 시간의 순서대로 space와 book을 처리할 수 있게 만들어 주는 *process()* 를 통해서 모든 process를 처리하도록 만들었다.
그 결과 **main.cpp**에서는 library class 선언과 process함수만 처리하도록 했다.
각각의 함수에 대한 이해는 코드를 통해 설명되어 진다.

## Getting started

 Project1과 마찬가지로 Makefile을 만들었다.

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

