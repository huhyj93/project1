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
		cout << date[0] << date[1] << date[2] << endl ;
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
			out << "0	Sucess." << endl;
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
		default:
			break;
	}
	if((rc == 4)||(rc==5)||(rc==6)||(rc==7)){
		cout << time << endl;
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
}

void library :: bprocess(int op){
	int i,j;
	int flag =0;
	int flag2 =0 ;	
	int date[6];
	int k, flag3 = 0;
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
											date[4] = idattime[op-1] + Undergraduate[j].late;
											Undergraduate[j].date = date[4];
											write(op,7,date[4]);
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
						Undergraduate[n[3]].name = idat[op-1][5];
						Undergraduate[n[3]].state = 0;
						Undergraduate[n[3]].booknum = 0;
						//if book is not here
						if( Book[i].state == 1){
							cout << Book[i].date << endl;
							write(op,5,Book[i].date + 13);
						}
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
										//date[4] = Undergraduate ->rent[k].date;
											
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										date[4] = Book[i].date + 13;
										write(op,5,date[4]);
										break;
									}
									//check restrict member
									if( Undergraduate[j].state ==2 ){

										date[4] = Undergraduate[j].date;
										write(op,6,date[4]);
									}
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
							
							Undergraduate[n[3]].name = idat[op-1][5];
							Undergraduate[n[3]].state = 0;
							if( Book[i].state == 1){
								date[4] = Book[i].date + 13;
								cout << date[4] << endl;
								write(op,5,date[4]);
							}
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
void library :: fprocess(){
	out.open("output.dat");
	n[3] = 0;
	out << "Op_#	Return_code	Description" << endl;
	int op ;
	for(op = 1;op<idatnum+1;op++)
		bprocess(op);
}

void library :: process(){
	string dump;
	string temp[6];
	n[4] =0;
	int i,j;
	int flag =0;
	int flag2 =0 ;
	ifstream fin;
	ofstream fin2;
        fin.open("input.dat");
	fin2.open("output.dat");
	fin >> dump;
        fin >> dump;
	fin >> dump;
	fin >> dump;
	fin >> dump;
	fin >> dump;	
	fin2 << "Op_#	Return_code	Description" << endl;
	int date[6];
	int day;
	int num =1;
	char t[2];
	int k, flag3 = 0;
	while(fin){
		for(i =0; i<6; i++){
			fin >> temp[i];
		}
		if(temp[1] == "Book"){
			date[0] = atoi(temp[0].c_str());
			t[0] = temp[0].at(3);
			t[1] = temp[0].at(4);
			date[1] =atoi(t);
			t[0] = temp[0].at(6);
			t[1] = temp[0].at(7);
			date[2] =atoi(t);
			day = 360*date[0] + 30*date[1] + date[2];
		}
		for(i = 0; i< n[0]; i++){
			if(Book[i].name == temp[2]){
				flag = 1;
				//return
				if(temp[3] == "R"){
					//member check
					if(n[4] == 0){
						fin2 << num << "	3	You did not borrow this book." << endl;
					}

					else
					{
						for(j=0;j<n[4];j++){
							//member check
							if(Undergraduate[j].name == temp[5]){
								flag2 =1;
								//not borrow 
								if(Undergraduate[j].state != 1){
									fin2 << num << "	3	You did not borrow this book." << endl;
								}
								//borrow
								else{
									//match book
									if(Undergraduate[j].books == temp[2]){
										//need late or not
										//sucess return
										if( (day - Book[i].date) <14){
											fin2 << num << "	0	Success."<<endl;
											Undergraduate[j].state = 0;
										}
										//late return
										else{
											Undergraduate[j].state = 2;
											Undergraduate[j].late = day - Book[i].date -13;

											 
											date[4] = day + Undergraduate[j].late;
											Undergraduate[j].date = date[4];
											date[0] = date[4]/360;
											date[1] = (date[4]%360)/30;
											date[2] = (date[4]%360)%30 ;
											fin2 << num << "	7	Delayed return. You'll be restricted until " << date[0] << "/";
											if(date[1] > 9)
												fin2 << date[1] << "/";
											else{
												fin2 << "0" << date[1] << "/";
											}
											if(date[2] > 9)
												fin2 << date[2] <<endl;
											else{
												fin2 << "0" << date[2] <<  endl;
										
											}
										}
									}
									//didn't match borrow book	
									else{
										fin2 << num << "	3	You did not borrow this book." << endl;
									}				
								}

							}	
						}
					 	//if didn't enter member	
						if(flag2 == 0){
							fin2 << num << "	3	You did not borrow this book." << endl;
						}
						flag2=0;
					}
				}
				//borrow	
				else{
					//first member check
					if(n[4] == 0){
						Undergraduate[n[4]].name = temp[5];
						Undergraduate[n[4]].state = 0;
						Undergraduate[n[4]].booknum = 0;
						//if book is not here
						if( Book[i].state == 1){
							date[4] = Book[i].date + 13;
							date[0] = date[4]/360;
							date[1] = (date[4]%360)/30;
							date[2] = (date[4]%360)%30 ;
							fin2 << num << "	5	Other member already borrowed this book. This book will be returned at " << date[0] << "/";
							if(date[1] > 9)
								fin2 << date[1] << "/";
							else{
								fin2 << "0" << date[1] << "/";
							}
							if(date[2] > 9)
			 					fin2 << date[2] <<endl;
							else{
								fin2 << "0" << date[2] <<  endl;
								
							}
							
						}
						// if book is here
						else{
							Undergraduate[n[4]].books = temp[2];
							Book[i].state = 1;
							Undergraduate[n[4]].state =1;
							Book[i].date = day;
							Undergraduate[n[4]].rent[Undergraduate->booknum] = Book[i];
							Undergraduate[n[4]].booknum++;
							fin2 << num << "	0	Success."<<endl;
						}
						n[4]++;	
					}
					//have member info
					else{

						for(j=0;j<n[4];j++){
							//check name
							if(Undergraduate[j].name == temp[5]){
								flag2 =1;
								//restrict member release
								if( (Undergraduate[j].state == 2) && (day > Undergraduate[j].date))
									Undergraduate[j].state = 0;
								//one more borrow
								if(Undergraduate[j].state == 1){
									fin2 << num << "	2	Exceeds your possible number of borrow. Possible# of borrows: 1" << endl;	
									break;
								}
								//check already borrow
								for(k=0;k<(Undergraduate->booknum); k++){
									if( Book[i].name == Undergraduate->rent[k].name){
										flag3=1;
										fin2 <<num <<	"	4	You already borrowe this book at ";
										date[4] = Undergraduate ->rent[k].date;
										date[0] = date[4]/360;
										date[1] = (date[4]%360)/30;
										date[2] = (date[4]%360)%30 ;
										fin2 << date[0] << "/";
										if(date[1] > 9)
											fin2 << date[1] << "/";
										else{
											fin2 << "0" << date[1] << "/";
										}
										if(date[2] > 9)
			 								fin2 << date[2] <<endl;
										else{
											fin2 << "0" << date[2] <<  endl;
										}	
											
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										date[4] = Book[i].date + 13;
										date[0] = date[4]/360;
										date[1] = (date[4]%360)/30;
										date[2] = (date[4]%360)%30 ;
										fin2 << num << "	5	Other member already borrowed this book. This book will be returned at ";
										fin2 << date[0] << "/";
										if(date[1] > 9)
											fin2 << date[1] << "/";
										else{
											fin2 << "0" << date[1] << "/";
										}
										if(date[2] > 9)
			 								fin2 << date[2] <<endl;
										else{
											fin2 << "0" << date[2] <<  endl;
								
										}
										break;
									}
									//check restrict member
									if( Undergraduate[j].state ==2 ){

										date[4] = Undergraduate[j].date;
										date[0] = date[4]/360;
										date[1] = (date[4]%360)/30;
										date[2] = (date[4]%360)%30 ;
										fin2 << num << "	6	Restricted member until  ";
										fin2 << date[0] << "/";
										if(date[1] > 9)
											fin2 << date[1] << "/";
										else{
											fin2 << "0" << date[1] << "/";
										}
										if(date[2] > 9)
			 								fin2 << date[2] <<endl;
										else{
											fin2 << "0" << date[2] <<  endl;
								
										}
									}
									//success borrow
									else{
										Undergraduate[j].books = temp[2];
										Book[i].state = 1;
										Undergraduate[j].state =1;
										Book[i].date = day;
										Undergraduate[j].rent[Undergraduate->booknum] = Book[i];
										Undergraduate[j].booknum++;
										fin2 << num << "	0	Success." << endl;
									}
							}

						}
						if(flag2 ==0){
							
							Undergraduate[n[4]].name = temp[5];
							Undergraduate[n[4]].state = 0;
							if( Book[i].state == 1){
								date[4] = Book[i].date + 13;
								date[0] = date[4]/360;
								date[1] = (date[4]%360)/30;
								date[2] = (date[4]%360)%30 ;
								fin2 << num << "	5	Other member already borrowed this book. This book will be returned at ";
								fin2 << date[0] << "/";
								if(date[1] > 9)
									fin2 << date[1] << "/";
								else{
									fin2 << "0" << date[1] << "/";
								}
								if(date[2] > 9)
			 						fin2 << date[2] <<endl;
								else{
									fin2 << "0" << date[2] <<  endl;
					
								}
							}
							else{
								Undergraduate[n[4]].books = temp[2];
								Book[i].state = 1;
								Undergraduate[n[4]].state =1;
								Book[i].date = day;
								Undergraduate[n[4]].rent[Undergraduate->booknum] = Book[i];
								Undergraduate[n[4]].booknum++;
								fin2 << num << "	0	Success." << endl;
							}
							n[4]++;	
						}	
						flag2=0;
					}
				}				
			}
		}		
		if(flag == 0){
			if(temp[1] == "Book"){
				fin2 << num << "	1	Non exist resource." << endl;
			}
		}
		flag = 0;	
		num++;
		for(i =0; i<6; i++){
			 temp[i] = "	";
		}
	}
	fin.close();	
	fin2.close();
}
