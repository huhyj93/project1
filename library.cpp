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

void library :: setsdat(){

	ifstream fin;
	fin.open("space.dat");
	int i=0;
	int j=0;
	string dump;
	for(j=0;j<8;j++){
		fin >> dump;
	}
	
	while(fin){
		for(j=0;j<8;j++){
			fin >> sdat[i][j];
			if(j ==5){
				if( sdat[i][3] == "R"){
					break;	
				}
			}
		}
		i++;
	}
	sdatnum =i-1;
	fin.close();
	int date[3];
	char t[2];
	for(i=0; i<sdatnum; i++){
		t[0] = sdat[i][0].at(2);
		t[1] = sdat[i][0].at(3);
		date[0] =atoi(t);
		t[0] = sdat[i][0].at(5);
		t[1] = sdat[i][0].at(6);
		date[1] =atoi(t);
		t[0] = sdat[i][0].at(8);
		t[1] = sdat[i][0].at(9);
		date[2] =atoi(t);
		sdattime[i][0] = 360*date[0] + 30*date[1] + date[2];
		t[0] = sdat[i][0].at(11);
		t[1] = sdat[i][0].at(12);
		date[0] =atoi(t);
		sdattime[i][1] =date[0];
	}
}

void library :: write(int op, int rc,  int time){
	out << op << "	";
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
			out << "9	This space is not available now. Available from" << endl;
			break;
		case 10:
			out << "10	You did not borrow this place." << endl;
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
	if(rc == 14){
		out << time;
		out << "." << endl;
		
	}
}

void library :: bookprocess(int op){
	int i,j,k;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i = 0; i< n[0]; i++){
			if(Book[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[3] == 0)
						write(op,3,0);
					
					else
					{
						for(j=0;j<n[3];j++){
							//member check
							if(Undergraduate[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								if(Undergraduate[j].state != 1)
									write(op,3,0);
								
								//borrow
								else{
									//match book
									if(Undergraduate[j].books == idat[op-1][2]){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Book[i].date) <14){
											write(op,0,0);
											Undergraduate[j].state = 0;
										}
										//late return
										else{
											Undergraduate[j].state = 2;
											Undergraduate[j].late = idattime[op-1] - Book[i].date -13;
											Undergraduate[j].date = idattime[op-1] + Undergraduate[j].late;
											write(op,7,idattime[op-1] + Undergraduate[j].late);
										}
									}
									//didn't match borrow book	
									else
										write(op,3,0);
													
								}

							}	
						}
					 	//if didn't enter member	
						if(flag2 == 0){
							write(op,3,0);
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
							write(op,5,Book[i].date + 13);
						
						// if book is here
						else{
							Undergraduate[n[3]].books = idat[op-1][2];
							Book[i].state = 1;
							Undergraduate[n[3]].state =1;
							Book[i].date = idattime[op-1];
							Undergraduate[n[3]].rent[Undergraduate->booknum] = Book[i];
							Undergraduate[n[3]].booknum++;
							write(op,0,0);
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
									write(op,2,0);
									break;
								}
								//check already borrow
								for(k=0;k<(Undergraduate->booknum); k++){
									if( Book[i].name == Undergraduate->rent[k].name){
										flag3=1;
										write(op,4, Undergraduate ->rent[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										write(op,5,Book[i].date + 13);
										break;
									}

									//check restrict member
									if( Undergraduate[j].state ==2 )
										write(op,6,Undergraduate[j].date);
									
									//success borrow
									else{
										Undergraduate[j].books = idat[op-1][2];
										Book[i].state = 1;
										Undergraduate[j].state =1;
										Book[i].date = idattime[op-1];
										Undergraduate[j].rent[Undergraduate->booknum] = Book[i];
										Undergraduate[j].booknum++;
										write(op,0,0);
									}
							}

						}
						if(flag2 ==0){
							
							Undergraduate[n[3]].clear();
							Undergraduate[n[3]].name = idat[op-1][5];
							if( Book[i].state == 1)
								write(op,5,Book[i].date + 13);
							else{
								Undergraduate[n[3]].books = idat[op][2];
								Book[i].state = 1;
								Undergraduate[n[3]].state =1;
								Book[i].date = idattime[op-1];
								Undergraduate[n[3]].rent[Undergraduate->booknum] = Book[i];
								Undergraduate[n[3]].booknum++;
								write(op,0,0);
							}
							n[3]++;	
						}	
						flag2=0;
					}
				}				
			}
		}		
		if(flag == 0){
			write(op,1,0);
		}	
		flag = 0;
}
void library :: roomclear(int type,int op){
	int i;
	if(type ==1 ){
		for(i=0;i<10;i++){
				if(sdattime[op-1][0] == sdattime[op-2][0]){
					if(sroom[i].state == 1){
						if( sroom[i].start + sroom[i].during < sdattime[op-1][1])
							sroom[i].clear();
					}
				}
				else
					sroom[i].clear();
		}
	
	}
	else{
	
	}
}
void library :: studyroomprocess(int op){
	int i,j,k;
	int flag = 0;
	int snum,mnum,time;
	snum = atoi(sdat[op-1][2].c_str());
	mnum = atoi(sdat[op-1][6].c_str());
	time = atoi(sdat[op-1][7].c_str());
	cout << snum << "	" << mnum << "	"<< time <<endl;
	roomclear(1,op);
	if((snum> 10)||(snum <1))
		write(op,8,0);
	else{
		if((sdattime[op-1][1] >18)||(sdattime[op-1][1]<9))
			write(op,9,0);
		else{
			//check first member
			for(i=0;i<n[3];i++){
				if(Undergraduate[i].name == sdat[op-1][5]){
					flag ==1;
					break;
				}
			}
			if(sdat[op-1][3] == "B"){
				if(flag ==1){
					if(Undergraduate[i].sr.state == 0)
						write(op,11,0);
					else{
						
						if((mnum > 6)|| (mnum <1)){
							write(op,12,0);
						}
						else if((time > 3) ||(time <1)){
							write(op,13,0);
						}
						else if(sroom[snum].state == 0){
							write(op,0,0);
							sroom[snum].start = sdattime[op-1][1];
							sroom[snum].during = time;
							sroom[snum].state = 1;
							Undergraduate[i].sr.state = 1;
						}
						else
							write(op,14,sroom[snum].during+sroom[snum].start);
					}	
				}	
				else{
					Undergraduate[n[3]].clear();
					Undergraduate[n[3]].name = sdat[op-1][5];
					if((mnum > 6)|| (mnum <1)){
						write(op,12,0);
					}
					else if((time > 3) ||(time <1)){
						write(op,13,0);
					}
					else if(sroom[snum].state == 0){
						write(op,0,0);
						sroom[snum].start = sdattime[op-1][1];
						sroom[snum].during = time;
						sroom[snum].state =1;
						Undergraduate[n[3]].sr.state = 1;
					}
					else
						write(op,14,sroom[snum].during+sroom[snum].start);
				}
			}
			
			else if(sdat[op-1][3] == "R"){
				if(flag == 0)
					write(op,10,0);
				else{
					if(sroom[snum].state == 1){
						write(op,0,0);
						sroom[snum].clear();
						Undergraduate[i].sr.clear();
					}
					else
						write(op,10,0);
				}
			}
			
			else if(sdat[op-1][3] == "E"){
				if(flag == 0)
					write(op,10,0);
				else{
					if(sroom[snum].state == 1){
						write(op,0,0);
						sroom[snum].state = 2;
						Undergraduate[i].sr.state = 2;
					}
					else
						write(op,10,0);
			
				}
			}
			else if(sdat[op-1][3] == "C"){
				if(flag == 0)
					write(op,10,0);
				else{
					if(sroom[snum].state == 2){
						write(op,0,0);
						sroom[snum].state = 1;
						Undergraduate[i].sr.state = 1;
					}
					else
						write(op,10,0);
			
				}
			}
			flag =0;
		}
	}
}

void library :: seatprocess(int op){
	write(op,2,0);
}

void library :: process(){
	set();
	setidat();
	setsdat();
	out.open("output.dat");
	n[3] = 0;
	out << "Op_#	Return_code	Description" << endl;
	int op;
	for(op = 1;op<sdatnum+1;op++){
		if(sdat[op-1][1] == "StudyRoom")
			studyroomprocess(op);
		else
			seatprocess(op);
	}
	/*for(op = 1;op<idatnum+1;op++)
		bookprocess(op);
	*/
	out.close();
}
