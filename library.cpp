#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
#include <cstdlib>
using namespace std;

void library ::set(){
	n[0] = 0;
	string dump;
	ifstream fin;
        fin.open("resource.dat");
	fin >> dump;
        fin >> dump;	
	while(fin){	
		fin >> dump;	
		if(dump == "Book"){
			Book[n[0]].type = dump;
			fin >> dump;
			Book[n[0]].name = dump;
			Book[n[0]].state = 0;
			n[0]++;
		}
	}
	fin.close();
}
void library :: setidat(){
	ifstream fin;
	fin.open("input.dat");
	int i=0;
	int j=0;
	string dump;
	for(j=0;j<6;j++){
		fin >> dump;
	}
	
	while(fin){
		for(j=0;j<6;j++){
			fin >> idat[i][j];
		}
		i++;
	}
	idatnum =i-1;
	fin.close();
	int date[3];
	char t[2];
	for(i=0; i<idatnum; i++){
		date[0] = atoi(idat[i][0].c_str());
		t[0] = idat[i][0].at(3);
		t[1] = idat[i][0].at(4);
		date[1] =atoi(t);
		t[0] = idat[i][0].at(6);
		t[1] = idat[i][0].at(7);
		date[2] =atoi(t);
		idattime[i] = 360*date[0] + 30*date[1] + date[2];
	}
}
void library :: write(int top,int op, int rc,  int time){
	out << top << "	";
	int y,m,d;
	
	switch(rc){
		case 0:
			out << "0	Success." << endl;
			break;
		case 1:
			out << "1	Non exist resource." << endl;
			break;	
		case 2:
			out << "2	Exceeds your possible number of borrow. Possible# of borrows: 1" << endl;
			break;
		case 3:
			out << "3	You did not borrow this book." << endl;
			break;	
		case 4:
			out << "4	You already borrowed this book at " ;
			break;	
		case 5:
			out << "5	Other member already borrowed this book. This book will be returned at " ;
			break;
		case 6:
			out << "6	Restricted member until ";
			break;	
		case 7:
			out << "7	Delayed return. You'll be restricted until " ;
			break;
		case 8:
			out << "8	Invalid space id." << endl;
			break;	
		case 9:
			out << "9	This space is not available now. Available from " ;
			break;
		case 10:
			out << "10	You did not borrow this space." << endl;
			break;
		case 11:
			out << "11	You already borrowed this kind of space." << endl;
			break;
		case 12:
			out << "12	Exceed available number." << endl;
			break;
		case 13:
			out << "13	Exceed available time." << endl;
			break;
		case 14:
			out << "14	There is no remain space. This space is available after " ;
			break;	
		case 16:	
			out << "-1	";
			break;	
		default:
			break;
	}
	if((rc == 4)||(rc==5)||(rc==6)||(rc==7)){
		y= time/360;
		m= (time%360)/30;
		d= (time%360)%30;
		out.fill('0');
		out.width(2); 
		out << y; 
		out << "/" ;
		out.fill('0');
		out.width(2); 
		out<< m; 
		out << "/";
		out.fill('0');
		out.width(2); 
		out << d; 
		out <<endl;
	}
	if(rc == 9){
		if(time == 0)
			out << "09 to 18." <<endl;
		else
			out << "09 to 21" <<endl;
	}
	if(rc == 14){
		out.fill('0');
		out.width(2);
		out << time;
		out << "." << endl;
		
	}
	if(rc == 16){
		switch(time){
			case 1:
				out << "Date out of range" <<endl;;
				break;
			case 2:
				out << "Non-exist space type" << endl;
				break;	
			case 3:
				out << "Non-exist operation" << endl;
				break;	
			case 4:
				out << "Non-exist member type" << endl;
				break;	
			case 5:
				out << "Member name with numbers" << endl;
				break;	
			case 6:
				out << "Negative time" << endl;
				break;	
		}
	}
}
void library :: bookprocess(int top,int op){
	int i,j,k;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		/*if(idattime[op-1] < 3631)
			throw 1;
		if((idat[op-1][3] != "R") && (idat[op-1][3] != "B"))
			throw 3;
		if(idat[op-1][4] != "Undergraduate")
			throw 4;
		for(i = 0; i< idat[op-1][5].length();i++){

			if(isdigit(idat[op-1][5].at(i)) != 0)
			       throw 5;
		}	*/
		for(i = 0; i< n[0]; i++){
			if(Book[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[3] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[3];j++){
							//member check
							if(Undergraduate[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								if(Undergraduate[j].state != 1)
									write(top,op,3,0);
								
								//borrow
								else{
									//match book
									if(Undergraduate[j].books == idat[op-1][2]){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Book[i].date) <14){
											write(top,op,0,0);
											Undergraduate[j].state = 0;
										}
										//late return
										else{
											Undergraduate[j].state = 2;
											Undergraduate[j].late = idattime[op-1] - Book[i].date -13;
											Undergraduate[j].date = idattime[op-1] + Undergraduate[j].late;
											write(top,op,7,idattime[op-1] + Undergraduate[j].late);
										}
									}
									//didn't match borrow book	
									else
										write(top,op,3,0);
													
								}

							}	
						}
					 	//if didn't enter member	
						if(flag2 == 0){
							write(top,op,3,0);
						}
						flag2=0;
					}
				}
				//borrow	
				else{
					//first member check
					if(n[3] == 0){
						Undergraduate[n[3]].clear();
						Undergraduate[n[3]].name = idat[op-1][5];
						//if book is not here
						if( Book[i].state == 1)
							write(top,op,5,Book[i].date + 13);
						
						// if book is here
						else{
							Undergraduate[n[3]].books = idat[op-1][2];
							Book[i].state = 1;
							Undergraduate[n[3]].state =1;
							Book[i].date = idattime[op-1];
							Undergraduate[n[3]].rent[Undergraduate->booknum] = Book[i];
							Undergraduate[n[3]].booknum++;
							write(top,op,0,0);
						}
						n[3]++;	
					}
					//have member info
					else{

						for(j=0;j<n[3];j++){
							//check name
							if(Undergraduate[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Undergraduate[j].state == 2) && (idattime[op-1] > Undergraduate[j].date))
									Undergraduate[j].state = 0;
								//one more borrow
								if(Undergraduate[j].state == 1){
									write(top,op,2,0);
									break;
								}
								//check already borrow
								for(k=0;k<(Undergraduate->booknum); k++){
									if( Book[i].name == Undergraduate->rent[k].name){
										flag3=1;
										write(top,op,4, Undergraduate ->rent[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										write(top,op,5,Book[i].date + 13);
										break;
									}

									//check restrict member
									if( Undergraduate[j].state ==2 )
										write(top,op,6,Undergraduate[j].date);
									
									//success borrow
									else{
										Undergraduate[j].books = idat[op-1][2];
										Book[i].state = 1;
										Undergraduate[j].state =1;
										Book[i].date = idattime[op-1];
										Undergraduate[j].rent[Undergraduate->booknum] = Book[i];
										Undergraduate[j].booknum++;
										write(top,op,0,0);
									}
							}

						}
						if(flag2 ==0){
							
							Undergraduate[n[3]].clear();
							Undergraduate[n[3]].name = idat[op-1][5];
							if( Book[i].state == 1)
								write(top,op,5,Book[i].date + 13);
							else{
								Undergraduate[n[3]].books = idat[op][2];
								Book[i].state = 1;
								Undergraduate[n[3]].state =1;
								Book[i].date = idattime[op-1];
								Undergraduate[n[3]].rent[Undergraduate->booknum] = Book[i];
								Undergraduate[n[3]].booknum++;
								write(top,op,0,0);
							}
							n[3]++;	
						}	
						flag2=0;
					}
				}				
			}
		}		
		if(flag == 0){
			write(top,op,1,0);
		}	
		flag = 0;

}
void library :: process(){
	set();
	setidat();
	out.open("output.dat");
	n[3] = 0;
	out << "Op_#	Return_code	Description" << endl;
	int sop=1;
	int iop=1;
	int top=1;
	int i =0;
	while(iop<=idatnum){
		bookprocess(top,iop);
		iop++;
		top++;	
	}

	out.close();
}
