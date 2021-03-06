#!/bin/bash
if [ ! -f hello ]
then
	make
fi
if [ -d result ]
then
	rm -r result
fi
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
			
			e-book)
				mkdir -p result/resource
				
				touch e-book.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> e-book.dat

					elif [ "$l0" = "E-book" ]
					then

						echo "$l0	$l1" >> e-book.dat
					fi
				done < resource.dat
				mv e-book.dat result/resource/;;
			
			magazine)
				mkdir -p result/resource
				
				touch magazine.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> magazine.dat

					elif [ "$l0" = "Magazine" ]
					then
						echo "$l0	$l1" >> magazine.dat
					fi
				done < resource.dat
				mv magazine.dat result/resource/;;
			
			all)
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
				mv book.dat result/resource/

				touch e-book.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> e-book.dat

					elif [ "$l0" = "E-book" ]
					then
						echo "$l0	$l1" >> e-book.dat
					fi
				done < resource.dat
				mv e-book.dat result/resource/

				touch magazine.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> magazine.dat

					elif [ "$l0" = "Magazine" ]
					then
						echo "$l0	$l1" >> magazine.dat
					fi
				done < resource.dat
				mv magazine.dat result/resource/;;
		esac;;		
	
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

			e-book)
				mkdir -p result/input
				
				touch e-book.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat

					elif [ "$l1" = "E-book" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp e-book.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat e-book.dat
				cp output.dat result/input/e-book.dat;;

			magazine)
				mkdir -p result/input
				
				touch magazine.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat

					elif [ "$l1" = "Magazine" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp magazine.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat magazine.dat
				cp output.dat result/input/magazine.dat;;

			undergraduate)

				mkdir -p result/input
				
				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat

					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp undergraduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat undergraduate.dat
				cp output.dat result/input/undergraduate.dat;;

			graduate)

				mkdir -p result/input
				
				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat

					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat graduate.dat
				cp output.dat result/input/graduate.dat;;

			faculty)
				
				mkdir -p result/input
				
				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat

					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/input/faculty.dat;;


			all)
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
				cp output.dat result/input/book.dat

				touch e-book.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat

					elif [ "$l1" = "E-book" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp e-book.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat e-book.dat
				cp output.dat result/input/e-book.dat
		
				touch magazine.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat

					elif [ "$l1" = "Magazine" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp magazine.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat magazine.dat
				cp output.dat result/input/magazine.dat

				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat

					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp undergraduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat undergraduate.dat
				cp output.dat result/input/undergraduate.dat

				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat

					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat graduate.dat
				cp output.dat result/input/graduate.dat

				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat

					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/input/faculty.dat;;
		esac;;		
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
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp date.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat date.dat
				cp output.dat result/space/date.dat;;
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
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp studyroom.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat studyroom.dat
				cp output.dat result/space/studyroom.dat;;

			seat)
				mkdir -p result/space
				touch seat.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat
					elif [ "$3" = "all" ]
					then
						if [ "$l1" = "Seat" ]
						then
							echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat
						fi
					elif [ "$l1" = "Seat" -a "$3" = "$l2" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp seat.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat seat.dat
				cp output.dat result/space/seat.dat;;	

			undergraduate)
				mkdir -p result/space
				
				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp undergraduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat undergraduate.dat
				cp output.dat result/space/undergraduate.dat;;

			graduate)
				mkdir -p result/space
				
				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat graduate.dat
				cp output.dat result/space/graduate.dat;;

			faculty)
				mkdir -p result/space
				
				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/space/faculty.dat;;
			all)
				mkdir -p result/space

				touch studyroom.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat

					elif [ "$l1" = "StudyRoom" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp studyroom.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat studyroom.dat
				cp output.dat result/space/studyroom.dat

				touch seat.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat

					elif [ "$l1" = "Seat" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp seat.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat seat.dat
				cp output.dat result/space/seat.dat

				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp  undergraduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat  undergraduate.dat
				cp output.dat result/space/undergraduate.dat

				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat  graduate.dat
				cp output.dat result/space/graduate.dat
				
				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/space/faculty.dat;;
		esac;;		
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
	all)
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
				mv book.dat result/resource/

				touch e-book.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> e-book.dat

					elif [ "$l0" = "E-book" ]
					then
						echo "$l0	$l1" >> e-book.dat
					fi
				done < resource.dat
				mv e-book.dat result/resource/

				touch magazine.dat
				while read l0 l1
				do
					if [ "$l0" = "Type" ]
					then
						echo "$l0	$l1" >> magazine.dat

					elif [ "$l0" = "Magazine" ]
					then
						echo "$l0	$l1" >> magazine.dat
					fi
				done < resource.dat
				mv magazine.dat result/resource/

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
				cp output.dat result/input/book.dat

				touch e-book.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat

					elif [ "$l1" = "E-book" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> e-book.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp e-book.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat e-book.dat
				cp output.dat result/input/e-book.dat
		
				touch magazine.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l1" = "Resource_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat

					elif [ "$l1" = "Magazine" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> magazine.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp magazine.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat magazine.dat
				cp output.dat result/input/magazine.dat

				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat

					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> undergraduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp undergraduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat undergraduate.dat
				cp output.dat result/input/undergraduate.dat

				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat

					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> graduate.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat graduate.dat
				cp output.dat result/input/graduate.dat

				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat

					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5" >> faculty.dat
					fi
				done < input.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat input.dat
				./hello
				rm input.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/input/faculty.dat	

				mkdir -p result/space

				touch studyroom.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat

					elif [ "$l1" = "StudyRoom" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> studyroom.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp studyroom.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat studyroom.dat
				cp output.dat result/space/studyroom.dat

				touch seat.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l1" = "Space_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat

					elif [ "$l1" = "Seat" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> seat.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp seat.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat seat.dat
				cp output.dat result/space/seat.dat

				touch undergraduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					elif [ "$l4" = "Undergraduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> undergraduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp  undergraduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat  undergraduate.dat
				cp output.dat result/space/undergraduate.dat

				touch graduate.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					elif [ "$l4" = "Graduate" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> graduate.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp graduate.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat  graduate.dat
				cp output.dat result/space/graduate.dat
				
				touch faculty.dat
				while read l0 l1 l2 l3 l4 l5 l6 l7
				do
					if [ "$l4" = "Member_type" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					elif [ "$l4" = "Faculty" ]
					then
						echo "$l0	$l1	$l2	$l3	$l4	$l5	$l6	$l7" >> faculty.dat
					fi
				done < space.dat
				cp input.dat temp.dat
				cp space.dat temp2.dat
				rm input.dat space.dat
				cp faculty.dat space.dat
				./hello
				rm space.dat
				cp temp.dat input.dat
				cp temp2.dat space.dat
				rm temp.dat temp2.dat faculty.dat
				cp output.dat result/space/faculty.dat

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
				./hello
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
esac		
