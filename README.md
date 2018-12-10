# SSE3: Project4

Project4는 Shell script를 이용해서 project1,2,3에서 이용하는 dat파일을 정리하는 폴더와 파일을 만드는 과제이다. 

이전 프로젝트에서 이용하는 input.dat, resource.dat, space.dat을 주어진 방식으로 정리해서 output 만들어 정리하는 것이다.

## Running

처음에 실행 파일인 hello 여부를 확인해서 make 작업을 다시하게 했고, result 디렉토리를 확인해서 있을 경우 제거한다.

```````````
if [ ! -f hello ]
then
	make
fi
if [ -d result ]
then
	rm -r result
fi
````````
만들어야 되는 종류는 input.dat, resource.dat, space.dat, output.dat으로 크게 4가지 종류로 나뉜다.

먼저, resource.dat를 이용해서 만드는 명렁어 파트이다. 

Resource를 치면 book, e-book, magazine, all 4가지 경우로 추가적을 나누었고, book의 부분은 아래와 같다. 

E-book, magazine, all부분도 위의 book방식과 마찬가지 방식으로 만들었다.

``````````
case "$1" in
	resource)
		case "$2" in
			book)
				mkdir -p result/resource
				
				touch book.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> book.dat

					elif [ "$l0" = "Book" ]
					then
						echo "$l0	$l1" >> book.dat
					fi
				done < resource.dat
				mv book.dat result/resource/;;

```````````

두번째는 input.dat 파일을 이용하는 경우이다. 뒤에 두번째 명령어가 book, e-book, magazine, undergraduate, graduate, faculty일 경우에 따라 input 파일을 바꿔주고 이를 이용해서 ** ./hello ** 명령어를 통해서 output.dat를 새로 만들어서 각각 디렉토리로 옮긴다.

추가적으로 date부분을 만들어야 했다. 이 부분은 아래 코드를 보면 알 수 있듯이 년도는 360, 월은 30을 곱해서 시간 숫자를 만들었고 입력한 숫자와 비교할 수 있게 했다.  

All인 경우에는 date를 제외한 모든 파일을 만들 수 있도록 했다.

`````````
	input)
		case "$2" in
			date)
				
				mkdir -p result/input

				touch date.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l0" = "Date[yy/mm/dd]" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> date.dat
					else
						if [ $((360*(10*(${3:0:1}) +${3:1:1})+ 30*(10*(${3:3:1}) +${3:4:1})+10*(${3:6:1}) +${3:7:1})) -le  $((360*(10*(${l0:0:1}) +${l0:1:1})+ 30*(10*(${l0:3:1}) +${l0:4:1})+10*(${l0:6:1}) +${l0:7:1})) -a $((360*(10*(${4:0:1}) +${4:1:1})+ 30*(10*(${4:3:1}) +${4:4:1})+10*(${4:6:1}) +${4:7:1})) -ge  $((360*(10*(${l0:0:1}) +${l0:1:1})+ 30*(10*(${l0:3:1}) +${l0:4:1})+10*(${l0:6:1}) +${l0:7:1})) ]
						then
							echo "$l0	$l1	$l2	$l3	$l4	$l5" >> date.dat
						fi
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp date.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat date.dat
				cp output.dat result/input/date.dat;;

			book)
				mkdir -p result/input
				
				touch book.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> book.dat

					elif [ "$l1" = "Book" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> book.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp book.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat book.dat
				cp output.dat result/input/book.dat;;

``````````````````

세번째는 space.dat 파일을 이용하는 경우이다. 뒤에 두번째 명령어가 undergraduate, graduate, faculty, all일 경우에는 앞에 방식과 마찬가지로 쓰면 된다.

추가적으로 date, studyroom, seat부분을 만들어야 했다. Date부분은 년도는 360, 월은 30을 곱해서 시간 숫자를 만들었고 여기에 24를 곱하고 시간을 더해서 입력한 숫자와 비교할 수 있게 했다. 

StudyRoom, seat의 경우에는 각각의 번호나 all의 추가적인 parameter에 따라 정리하도록 했다. 

All인 경우에는 date를 제외한 모든 파일을 만들 수 있도록 했고 seat, studyroom 부분은 all 명령어의 경우를 이용했다. 

```````````
	space)
		case "$2" in
			date)

				mkdir -p result/space

				touch date.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do

					if [ "$l0" = "Date[yy/mm/dd/hh]" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> date.dat
					else
						if [ $((24*(360*(10*(${3:0:1}) +${3:1:1})+ 30*(10*(${3:3:1}) +${3:4:1})+10*(${3:6:1}) +${3:7:1}) + 10*(${3:9:1}) + ${3:10:1})) -le  $((24*(360*(10*(${l0:2:1}) +${l0:3:1})+ 30*(10*(${l0:5:1}) +${l0:6:1})+10*(${l0:8:1}) +${l0:9:1}) + 10*(${l0:11:1}) + ${l0:12:1})) -a $((24*(360*(10*(${4:0:1}) +${4:1:1})+ 30*(10*(${4:3:1}) +${4:4:1})+10*(${4:6:1}) +${4:7:1})+ 10*(${4:9:1}) + ${4:10:1})) -ge  $((24*(360*(10*(${l0:2:1}) +${l0:3:1})+ 30*(10*(${l0:5:1}) +${l0:6:1})+10*(${l0:8:1}) +${l0:9:1}) + 10*(${l0:11:1}) + ${l0:12:1}))  ]
						then
							echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> date.dat
						fi
					fi
				done < space.dat
				mv date.dat result/space/;;
			studyroom)
				mkdir -p result/space
				touch studyroom.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat
					elif [ "$3" = "all" ]
					then
						if [ "$l1" = "StudyRoom" ]
						then
							echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat
						fi
				
					elif [ "$l1" = "StudyRoom" -a "$3" = "$l2" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat
					fi
				done < space.dat
				mv studyroom.dat result/space/;;
````````````````

4번째 부분은 output.dat를 정리하는 부분이다.

각각의 Return_code에 따라서 숫자를 만들어서 개수를 센 후에 각각의 개수를 나타내는 파일을 만들었다. 

``````````
	output)
		case "$2" in
			stat_table)
				x0=0	
				x1=0
				x2=0
				x3=0	
				x4=0
				x5=0
				x6=0	
				x7=0
				x8=0
				x9=0	
				x10=0
				x11=0
				x12=0	
				x13=0
				x14=0
				x15=0	
				x16=0
				x17=0
				mkdir -p result/output
				touch stat_table.dat
				echo "Return_code	Number" >> stat_table.dat
				while read l0 l1 l2
				do
					case "$l1" in
						-1)((x0++));;
						0) ((x1++)) ;;
						1) ((x2++));;
						2) ((x3++));;
						3) ((x4++));;
						4) ((x5++));;
						5) ((x6++));;
						6) ((x7++));;
						7) ((x8++));;
						8) ((x9++));;
						9) ((x10++));;
						10) ((x11++));;
						11) ((x12++));;
						12) ((x13++));;
						13) ((x14++));;
						14) ((x15++));;
						15) ((x16++));;
						16) ((x17++));;
					esac
				done < output.dat
				echo "-1	$x0" >> stat_table.dat
				echo "0	$x1" >> stat_table.dat
				echo "1	$x2" >> stat_table.dat
				echo "2	$x3" >> stat_table.dat
				echo "3	$x4" >> stat_table.dat
				echo "4	$x5" >> stat_table.dat
				echo "5	$x6" >> stat_table.dat
				echo "6	$x7" >> stat_table.dat
				echo "7	$x8" >> stat_table.dat
				echo "8	$x9" >> stat_table.dat
				echo "9	$x10" >> stat_table.dat
				echo "10	$x11" >> stat_table.dat
				echo "11	$x12" >> stat_table.dat
				echo "12	$x13" >> stat_table.dat
				echo "13	$x14" >> stat_table.dat
				echo "14	$x15" >> stat_table.dat
				echo "15	$x16" >> stat_table.dat
				echo "16	$x17" >> stat_table.dat
				mv stat_table.dat result/output/;;
		esac;;
``````````````

그리고 마지막으로 all경우에는 date파일을 제외한 모든 파일을 만들게 했다.

## Getting started

 ./library.statistics.sh를 한후 뒤에 정해진 parameter를 입력하면 된다.

## Versioning

 Using **shell script** in Ubuntu environment

## Author : Yang Jun Huh
