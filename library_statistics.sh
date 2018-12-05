#!/bin/bash
rm -r result
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
		;;		
	space)
		;;		
	output)
		;;
	all)
				;;	
esac		
