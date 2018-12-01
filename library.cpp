#include <iostream>
#include <fstream>
#include <string>
#include "library.h"
#include <cstdlib>
using namespace std;

void library ::set(){
	int i,j,k;
	for(i=0;i<6;i++)
		n[i] = 0;
	string dump;
	string temp;
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
		else if(dump == "Magazine"){
			Magazine[n[1]].type = dump;
			fin >> dump;
			Magazine[n[1]].name = dump;
			Magazine[n[1]].state = 0;
			n[1]++;
		}
		else if(dump == "E-book"){
			Ebook[n[2]].type = dump;
			fin >> dump;
			Ebook[n[2]].name = dump;
			Ebook[n[2]].state = 0;
			for(i=0;i<dump.length();i++){
				if(dump.at(i) == '[')
					j= i;
				else if(dump.at(i) == ']')
					k = i;		
			}
			temp = dump.substr(j+1,k-j-1);
			Ebook[n[2]].cap = atoi(temp.c_str());			
			Ebook[n[2]].name = dump.substr(0,j);
			n[2]++;
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
				if( (sdat[i][3] == "R")||(sdat[i][3] == "C")||(sdat[i][3] == "E")){
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
			out << "2	Exceeds your possible number of borrow. Possible# of borrows: " << time << endl;
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
		case 15:
			out << "15	Exceeds your storage capacity" <<endl; ;
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



void library :: undergraduate_bookprocess(int top,int op){

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
						if( Book[i].state == 1){
							if(Book[i].type == "Undergraduate")
								write(top,op,5,Book[i].date + 13);
							else if(Book[i].type == "Graduate")
								write(top,op,5,Book[i].date + 29);
							else if(Book[i].type == "Faculty")
								write(top,op,5,Book[i].date + 29);
						}
						// if book is here
						else{
							Undergraduate[n[3]].books = idat[op-1][2];
							Book[i].state = 1;
							Book[i].type = "Undergraduate";
							Undergraduate[n[3]].state =1;
							Book[i].date = idattime[op-1];
							Undergraduate[n[3]].rent[Undergraduate[n[3]].booknum] = Book[i];
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
								if((Undergraduate[j].state == 1)&&(Undergraduate[j].booknum + Undergraduate[j].mznum >0)){
									write(top,op,2,1);
									break;
								}
								//check already borrow
								for(k=0;k<(Undergraduate[j].booknum); k++){
									if( Book[i].name == Undergraduate[j].rent[k].name){
										flag3=1;
										write(top,op,4, Undergraduate[j].rent[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										if(Book[i].type == "Undergraduate")
											write(top,op,5,Book[i].date + 13);
										else if(Book[i].type == "Graduate")
											write(top,op,5,Book[i].date + 29);
										else if(Book[i].type == "Faculty")
											write(top,op,5,Book[i].date + 29);
										break;
									}

									//check restrict member
									if( Undergraduate[j].state == 2 )
										write(top,op,6,Undergraduate[j].date);
									
									//success borrow
									else{
										Undergraduate[j].books = idat[op-1][2];
										Book[i].state = 1;
										Book[i].type = "Undergraduate";
										Undergraduate[j].state =1;
										Book[i].date = idattime[op-1];
										Undergraduate[j].rent[Undergraduate[j].booknum] = Book[i];
										Undergraduate[j].booknum++;
										write(top,op,0,0);
									}
							}

						}
						if(flag2 ==0){
							
							Undergraduate[n[3]].clear();
							Undergraduate[n[3]].name = idat[op-1][5];
							if( Book[i].state == 1){
								if(Book[i].type == "Undergraduate")
									write(top,op,5,Book[i].date + 13);
								else if(Book[i].type == "Graduate")
									write(top,op,5,Book[i].date + 29);
								else if(Book[i].type == "Faculty")
									write(top,op,5,Book[i].date + 29);
							}
							else{
								Undergraduate[n[3]].books = idat[op][2];
								Book[i].state = 1;
								Book[i].type = "Undergraduate";	
								Undergraduate[n[3]].state =1;
								Book[i].date = idattime[op-1];
								Undergraduate[n[3]].rent[Undergraduate[n[3]].booknum] = Book[i];
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

void library :: graduate_bookprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i = 0; i< n[0]; i++){
			if(Book[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[4] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[4];j++){
							//member check
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								
								if((Graduate[j].state != 1) && (Graduate[j].booknum == 0))
									write(top,op,3,0);
								//borrow
								else{
									for(k=0;k<Graduate[j].booknum;k++){
										if(Graduate[j].rent[k].name == idat[op-1][2]){
											flag3 =1;
											break;
										}
									}
									//match book
									if(flag3 == 1){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Book[i].date) <30){
											write(top,op,0,0);
											for(l=k;l<Graduate[j].booknum-1;l++)
												Graduate[j].rent[l] = Graduate[j].rent[l+1];
											Graduate[j].booknum--;
											Book[i].clear();
											if((Graduate[j].mznum == 0)&&(Graduate[j].booknum == 0))		
												Graduate[j].state = 0;
											
										}
										//late return
										else{
											Graduate[j].state = 2;
											Graduate[j].late = idattime[op-1] - Book[i].date -29;
											Graduate[j].date = idattime[op-1] + Graduate[j].late;
											write(top,op,7,idattime[op-1] + Graduate[j].late);
											for(l=k;l<Graduate[j].booknum-1;l++)
												Graduate[j].rent[l] = Graduate[j].rent[l+1];
											Graduate[j].booknum--;
											Book[i].clear();
										}
									}
									//didn't match borrow book	
									else
										write(top,op,3,0);
									flag3 = 0;				
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
					if(n[4] == 0){
						Graduate[n[4]].clear();
						Graduate[n[4]].name = idat[op-1][5];
						//if book is not here
						if( Book[i].state == 1){
							if(Book[i].type == "Undergraduate")
								write(top,op,5,Book[i].date + 13);
							else if(Book[i].type == "Graduate")
								write(top,op,5,Book[i].date + 29);
							else if(Book[i].type == "Faculty")
								write(top,op,5,Book[i].date + 29);
						}
						// if book is here
						else{
							Graduate[n[4]].books = idat[op-1][2];
							Book[i].state = 1;
							Book[i].type = "Graduate";
							Graduate[n[4]].state =1;
							Book[i].date = idattime[op-1];
							Graduate[n[4]].rent[Graduate[n[4]].booknum] = Book[i];
							Graduate[n[4]].booknum++;
							write(top,op,0,0);
						}
						n[3]++;	
					}
					//have member info
					else{

						for(j=0;j<n[3];j++){
							//check name
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Graduate[j].state == 2) && (idattime[op-1] > Graduate[j].date)){
									if((Graduate[j].mznum == 0)&&(Graduate[j].booknum == 0))	
										Graduate[j].state = 0;
									else
										Graduate[j].state = 1; 										
								}
								//one more borrow
								if((Graduate[j].state == 1) &&(Graduate[j].booknum+Graduate[j].mznum == 5)){
									write(top,op,2,5);
									break;
								}
								//check already borrow
								for(k=0;k<(Graduate[j].booknum); k++){
									if( Book[i].name == Graduate[j].rent[k].name){
										flag3=1;
										write(top,op,4, Graduate[j].rent[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										if(Book[i].type == "Undergraduate")
											write(top,op,5,Book[i].date + 13);
										else if(Book[i].type == "Graduate")
											write(top,op,5,Book[i].date + 29);
										else if(Book[i].type == "Faculty")
											write(top,op,5,Book[i].date + 29);
										break;
									}

									//check restrict member
									if( Graduate[j].state ==2 )
										write(top,op,6,Graduate[j].date);
									
									//success borrow
									else{
										Graduate[j].books = idat[op-1][2];
										Book[i].state = 1;
										Book[i].type = "Graduate";
										Graduate[j].state =1;
										Book[i].date = idattime[op-1];
										Graduate[j].rent[Graduate[j].booknum] = Book[i];
										Graduate[j].booknum++;
										write(top,op,0,0);
									}
							}

						}
						if(flag2 ==0){
							
							Graduate[n[4]].clear();
							Graduate[n[4]].name = idat[op-1][5];
							if( Book[i].state == 1){
								if(Book[i].type == "Undergraduate")
									write(top,op,5,Book[i].date + 13);
								else if(Book[i].type == "Graduate")
									write(top,op,5,Book[i].date + 29);
								else if(Book[i].type == "Faculty")
									write(top,op,5,Book[i].date + 29);
							}
							else{
								Graduate[n[4]].books = idat[op][2];
								Book[i].state = 1;
								Graduate[n[4]].state =1;
								Book[i].type = "Graduate";
								Book[i].date = idattime[op-1];
								Graduate[n[4]].rent[Graduate[n[4]].booknum] = Book[i];
								Graduate[n[4]].booknum++;
								write(top,op,0,0);
							}
							n[4]++;	
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

void library :: faculty_bookprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i = 0; i< n[0]; i++){
			if(Book[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[5] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[5];j++){
							//member check
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								
								if((Faculty[j].state != 1) && (Faculty[j].booknum == 0))
									write(top,op,3,0);
								//borrow
								else{
									for(k=0;k<Faculty[j].booknum;k++){
										if(Faculty[j].rent[k].name == idat[op-1][2]){
											flag3 =1;
											break;
										}
									}
									//match book
									if(flag3 == 1){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Book[i].date) <30){
											write(top,op,0,0);
											for(l=k;l<Faculty[j].booknum-1;l++)
												Faculty[j].rent[l] = Faculty[j].rent[l+1];
											Faculty[j].booknum--;
											Book[i].clear();
											if((Faculty[j].booknum == 0)&&(Faculty[j].mznum == 0))		
												Faculty[j].state = 0;
											
										}
										//late return
										else{
											Faculty[j].state = 2;
											Faculty[j].late = idattime[op-1] - Book[i].date -29;
											Faculty[j].date = idattime[op-1] + Faculty[j].late;
											write(top,op,7,idattime[op-1] + Faculty[j].late);
											for(l=k;l<Faculty[j].booknum-1;l++)
												Faculty[j].rent[l] = Faculty[j].rent[l+1];
											Faculty[j].booknum--;
											Book[i].clear();
										}
									}
									//didn't match borrow book	
									else
										write(top,op,3,0);
									flag3 = 0;				
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
					if(n[5] == 0){
						Faculty[n[5]].clear();
						Faculty[n[5]].name = idat[op-1][5];
						//if book is not here
						if( Book[i].state == 1){
							if(Book[i].type == "Undergraduate")
								write(top,op,5,Book[i].date + 13);
							else if(Book[i].type == "Graduate")
								write(top,op,5,Book[i].date + 29);
							else if(Book[i].type == "Faculty")
								write(top,op,5,Book[i].date + 29);
						}
						// if book is here
						else{
							Faculty[n[5]].books = idat[op-1][2];
							Book[i].state = 1;
							Book[i].type = "Faculty";
							Faculty[n[5]].state =1;
							Book[i].date = idattime[op-1];
							Faculty[n[5]].rent[Faculty[n[5]].booknum] = Book[i];
							Faculty[n[5]].booknum++;
							write(top,op,0,0);
						}
						n[5]++;	
					}
					//have member info
					else{

						for(j=0;j<n[5];j++){
							//check name
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Faculty[j].state == 2) && (idattime[op-1] > Faculty[j].date)){
									if((Faculty[j].booknum == 0)&&(Faculty[j].mznum == 0))	
										Faculty[j].state = 0;
									else
										Faculty[j].state = 1; 										
								}
								//one more borrow
								if((Faculty[j].state == 1) &&(Faculty[j].booknum +Faculty[j].mznum  == 10)){
									write(top,op,2,10);
									break;
								}
								//check already borrow
								for(k=0;k<(Faculty[j].booknum); k++){
									if( Book[i].name == Faculty[j].rent[k].name){
										flag3=1;
										write(top,op,4, Faculty[j].rent[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check book have
									if( Book[i].state == 1){
										if(Book[i].type == "Undergraduate")
											write(top,op,5,Book[i].date + 13);
										else if(Book[i].type == "Graduate")
											write(top,op,5,Book[i].date + 29);
										else if(Book[i].type == "Faculty")
											write(top,op,5,Book[i].date + 29);
										break;
									}

									//check restrict member
									if( Faculty[j].state ==2 )
										write(top,op,6,Faculty[j].date);
									
									//success borrow
									else{
										Faculty[j].books = idat[op-1][2];
										Book[i].state = 1;
										Book[i].type = "Faculty";
										Faculty[j].state =1;
										Book[i].date = idattime[op-1];
										Faculty[j].rent[Faculty[j].booknum] = Book[i];
										Faculty[j].booknum++;
										write(top,op,0,0);
									}
							}

						}
						if(flag2 ==0){
							
							Faculty[n[5]].clear();
							Faculty[n[5]].name = idat[op-1][5];
							if( Book[i].state == 1){
								if(Book[i].type == "Undergraduate")
									write(top,op,5,Book[i].date + 13);
								else if(Book[i].type == "Graduate")
									write(top,op,5,Book[i].date + 29);
								else if(Book[i].type == "Faculty")
									write(top,op,5,Book[i].date + 29);
							}
							else{
								Faculty[n[5]].books = idat[op-1][2];
								Book[i].state = 1;
								Faculty[n[5]].state =1;
								Book[i].type = "Faculty";
								Book[i].date = idattime[op-1];
								Faculty[n[5]].rent[Faculty[n[5]].booknum] = Book[i];
								Faculty[n[5]].booknum++;
								write(top,op,0,0);
							}
							n[5]++;	
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

void library :: roomclear(int type,int op){
	int i;
	if(type ==1 ){
		for(i=0;i<10;i++){
			if(sdattime[op-1][0] == sroom[i].day){
				if(sroom[i].state == 1){
					if( sroom[i].start + sroom[i].during < sdattime[op-1][1])
						sroom[i].clear();
				}
			}
			else
				sroom[i].clear();
		}
		for(i=0;i<n[3];i++){
			if(sdattime[op-1][0] == sroom[i].day){
				if(Undergraduate[i].sr.state == 1){
					if( Undergraduate[i].sr.start +Undergraduate[i].sr.during < sdattime[op-1][1])
						Undergraduate[i].sr.clear();
				}
			}
			else
				Undergraduate[i].sr.clear();
		}
	
	}
	else{
		for(i=0;i<50;i++){
			if(sdattime[op-1][0] == seat1[i].day){
				if((seat1[i].state ==2) && (sdattime[op-1][1] - seat1[i].etime >0))
					seat1[i].clear();
				else if(seat1[i].state == 1){
						if( seat1[i].start + seat1[i].during < sdattime[op-1][1]){
							seat1[i].clear();						
						}
					}

			}
			else
				seat1[i].clear();

			if(sdattime[op-1][0] == seat2[i].day){
				if((seat2[i].state ==2) && (sdattime[op-1][1] - seat2[i].etime >0))
					seat2[i].clear();
				else if(seat2[i].state == 1){
					if( seat2[i].start + seat2[i].during < sdattime[op-1][1]){
						seat2[i].clear();				
					}
				}
			}
			else
				seat2[i].clear();

			if(sdattime[op-1][0] == seat3[i].day){
				if((seat3[i].state ==2) && (sdattime[op-1][1] - seat3[i].etime >0))
					seat3[i].clear();
				else if(seat3[i].state == 1){
					if( seat3[i].start + seat3[i].during < sdattime[op-1][1])
						seat3[i].clear();
				}
			
			}
			else
				seat3[i].clear();

		}

		for(i=0;i<n[3];i++){
			if(sdattime[op-1][0] == Undergraduate[i].st.day){
				if((Undergraduate[i].st.state ==2) && (sdattime[op-1][1] -  Undergraduate[i].st.etime >0))
					Undergraduate[i].st.clear();
				else if(Undergraduate[i].st.state == 1){
					if( Undergraduate[i].st.start + Undergraduate[i].st.during < sdattime[op-1][1])
						Undergraduate[i].st.clear();
				}
			}
			else
				Undergraduate[i].st.clear();	
				
		}	
	}
}
void library :: studyroomprocess(int top,int op){
	int i,j,k;
	int flag = 0;
	int snum,mnum,time;
	snum = atoi(sdat[op-1][2].c_str());
	mnum = atoi(sdat[op-1][6].c_str());
	time = atoi(sdat[op-1][7].c_str());
	roomclear(1,op);
	if((snum> 10)||(snum <1))
		write(top,op,8,0);
	else{
		if((sdattime[op-1][1] >18)||(sdattime[op-1][1]<9))
			write(top,op,9,0);
		else{
			//check first member
			for(i=0;i<n[3];i++){
				if(Undergraduate[i].name == sdat[op-1][5]){
					flag =1;
					break;
				}
			}
			if(sdat[op-1][3] == "B"){
				if(flag ==1){
					if(Undergraduate[i].sr.state == 1)
						write(top,op,11,0);
					else{
						
						if((mnum > 6)|| (mnum <1)){
							write(top,op,12,0);
						}
						else if((time > 3) ||(time <1)){
							write(top,op,13,0);
						}
						else if(sroom[snum].state == 0){
							write(top,op,0,0);
							sroom[snum].day = sdattime[op-1][0];
							sroom[snum].start = sdattime[op-1][1];
							if(sdattime[op-1][1]+ time >18)
								sroom[snum].during = 18 -sdattime[op-1][1];
							else
								sroom[snum].during = time;
							sroom[snum].state = 1;
							Undergraduate[i].sr= sroom[snum];
						}
						else				
							write(top,op,14,sroom[snum].during+sroom[snum].start);
					}	
				}	
				else{
					Undergraduate[n[3]].clear();
					Undergraduate[n[3]].name = sdat[op-1][5];
					if((mnum > 6)|| (mnum <1)){
						write(top,op,12,0);
					}
					else if((time > 3) ||(time <1)){
						write(top,op,13,0);
					}
					else if(sroom[snum].state == 0){
						write(top,op,0,0);
						sroom[snum].day = sdattime[op-1][0];
						sroom[snum].start = sdattime[op-1][1];
						if(sdattime[op-1][1]+ time >18)
							sroom[snum].during = 18 -sdattime[op-1][1];
						else
							sroom[snum].during = time;
						sroom[snum].state =1;
						Undergraduate[n[3]].sr= sroom[snum];
					}
					else
						write(top,op,14,sroom[snum].during+sroom[snum].start);
					n[3]++;
				}
			}
			
			else if(sdat[op-1][3] == "R"){
				if(flag == 0)
					write(top,op,10,0);
				else{
					if(sroom[snum].state == 1){
						write(top,op,0,0);
						sroom[snum].clear();
						Undergraduate[i].sr.clear();
					}
					else
						write(top,op,10,0);
				}
			}
			
			else if(sdat[op-1][3] == "E"){
				if(flag == 0)
					write(top,op,10,0);
				else{
					if(sroom[snum].state == 1){
						write(top,op,0,0);
						sroom[snum].state = 2;
						Undergraduate[i].sr = sroom[snum];
					}
					else
						write(top,op,10,0);
			
				}
			}
			else if(sdat[op-1][3] == "C"){
				if(flag == 0)
					write(top,op,10,0);
				else{
					if(sroom[snum].state == 2){
						write(top,op,0,0);
						sroom[snum].state = 1;
						Undergraduate[i].sr= sroom[snum];
					}
					else
						write(top,op,10,0);
			
				}
			}
			flag =0;
		}
	}

}

void library :: seatprocess(int top,int op){
	int i,j,k;
	int flag = 0;
	int snum,mnum,time;
	int temp;
	snum = atoi(sdat[op-1][2].c_str());
	mnum = atoi(sdat[op-1][6].c_str());
	time = atoi(sdat[op-1][7].c_str());
	roomclear(2,op);
	if((snum> 3)||(snum <1))
		write(top,op,8,0);
	else{
		if(((sdattime[op-1][1] >18)||(sdattime[op-1][1]<9))&& (snum == 3))
			write(top,op,9,0);
		else if(((sdattime[op-1][1] >21)||(sdattime[op-1][1]<9))&&(snum == 2))
			write(top,op,9,1);
		else{
			//check first member
			for(i=0;i<n[3];i++){
				if(!(Undergraduate[i].name.compare(sdat[op-1][5]))){
					flag =1;

					break;
				}
			}
			if(sdat[op-1][3] == "B"){
				if(flag ==1){
					if(Undergraduate[i].st.state != 0)
						write(top,op,11,0);
					else{
						
						if(mnum > 1){
							write(top,op,12,0);
						}
						else if((time > 3) ||(time <1)){
							write(top,op,13,0);
						}
						else{
							for(j=0;j<50;j++){
								if(snum == 1){
									if(seat1[j].state == 0){
										write(top,op,0,0);
										seat1[j].day = sdattime[op-1][0];
										seat1[j].start = sdattime[op-1][1];
										if(seat1[j].start + time > 23)
											seat1[j].during = 24 - seat1[j].start;
										else
											seat1[j].during = time;
										seat1[j].state =1;
										seat1[j].name = Undergraduate[i].name;
										Undergraduate[i].st = seat1[j];
										break;
									}
									else if(j==49){
										for(k=0;k<50;k++){
											if(k==0)
												temp = seat1[k].start+seat1[k].during;
											else{
												if(temp > seat1[k].start +seat1[k].during)
													temp = seat1[k].start+seat1[k].during;
											}
										}
										write(top,op,14,temp);
									}
								}
								else if(snum == 2){
									if(seat2[j].state == 0){
										write(top,op,0,0);
										seat2[j].day = sdattime[op-1][0];
										seat2[j].start = sdattime[op-1][1];
										if(seat2[j].start + time > 20)
											seat2[j].during = 21 - seat2[j].start;
										else
											seat2[j].during = time;
										seat2[j].state =1;
										seat2[j].name = Undergraduate[i].name;
										Undergraduate[i].st = seat2[j];
										break;
									}
									else if(j==49){
										for(k=0;k<50;k++){
											if(k==0)
												temp = seat2[k].start+seat2[k].during;
											else{
												if(temp > seat2[k].start +seat2[k].during)
													temp = seat2[k].start+seat2[k].during;
											}
										}
										write(top,op,14,temp);
									}
								}

								else if(snum == 3){
									if(seat3[j].state == 0){
										write(top,op,0,0);
										seat3[j].day = sdattime[op-1][0];
										seat3[j].start = sdattime[op-1][1];
										if(seat3[j].start + time > 17)
											seat3[j].during = 18 - seat3[j].start;
										else
											seat3[j].during = time;
										seat3[j].state =1;
										seat3[j].name = Undergraduate[i].name;
										Undergraduate[i].st = seat3[j];
										break;
									}
									else if(j==49){
										for(k=0;k<50;k++){
											if(k==0)
												temp = seat3[k].start+seat3[k].during;
											else{
												if(temp > seat3[k].start +seat3[k].during)
													temp = seat3[k].start+seat3[k].during;
											}
										}
										write(top,op,14,temp);
									}



void library :: ebookclear(int op,int state){
	int i,j,k;
	int temp;
	if(state == 1){
	for(i=0;i< n[3]; i++){
		temp = Undergraduate[i].ebnum;
		if(temp != 0){
			j=0;		
			while(temp >0){
				if((idattime[op-1] - Undergraduate[i].rent2[j].date) > 13){
					for(k=j;k<Undergraduate[i].ebnum-1;k++){
						Undergraduate[i].rent2[k] = Undergraduate[i].rent2[k+1];
					}
				}
				else{
					j++;
				}
				temp--;
			}
			Undergraduate[i].ebnum = Undergraduate[i].ebnum-j+1; 
			//for(k=Undergraduate[i].ebnum; k<50;k++)
						
		}
		
	}
	}
	else if(state ==2){
	for(i=0;i< n[4]; i++){
		temp = Graduate[i].ebnum;
		if(temp != 0){
			j=0;		
			while(temp >0){
				if((idattime[op-1] - Graduate[i].rent2[j].date) > 29){
					for(k=j;k<Graduate[i].ebnum-1;k++){
						Graduate[i].rent2[k] = Graduate[i].rent2[k+1];
					}
				}
				else{
					j++;
				}
				temp--;
			}
			Graduate[i].ebnum = Graduate[i].ebnum-j+1; 
		}
		
	}
	}
	else if(state ==3){
	for(i=0;i< n[5]; i++){
		temp = Faculty[i].ebnum;
		if(temp != 0){
			j=0;		
			while(temp >0){
				if((idattime[op-1] - Faculty[i].rent2[j].date) > 29){
					for(k=j;k<Faculty[i].ebnum-1;k++){
						Faculty[i].rent2[k] = Faculty[i].rent2[k+1];
					}
				}
				else{
					j++;
				}
				temp--;
			}
			Faculty[i].ebnum =Faculty[i].ebnum-j+1; 
		}
		
	}
	}
}
void library :: undergraduate_ebookprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		ebookclear(op,1);
		for(i = 0; i< n[2]; i++){
			if(Ebook[i].name == idat[op-1][2]){
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
								if(Undergraduate[j].ebnum == 0)
									write(top,op,3,0);
								
								//borrow
								else{
									for(k=0;k<Undergraduate[j].ebnum;k++){
										if(Undergraduate[j].rent2[k].name == idat[op-1][2]){
											flag3 =1;
											break;
										}
									}					
									//match book
									if(flag3==1){
										//sucess return
										write(top,op,0,0);
										for(l=k;l<Undergraduate[j].ebnum-1;l++)
											Undergraduate[j].rent2[l] = Undergraduate[j].rent2[l+1];
										
										Undergraduate[j].cap = Undergraduate[j].cap -Ebook[i].cap;
										Undergraduate[j].ebnum--;
										for(l=Undergraduate[j].ebnum; l <50; l++)
											Undergraduate[j].rent2[l].allclear();			
		
									}
									//didn't match borrow book	
									else{
										write(top,op,3,0);
									}
									flag3= 0;				
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
						if( (Undergraduate[n[3]].cap +  Ebook[i].cap) > 100)
							write(top,op,15,0);
						else{
							Undergraduate[n[3]].state =1;
							Ebook[i].date = idattime[op-1];
							Undergraduate[n[3]].rent2[Undergraduate[n[3]].ebnum] = Ebook[i];
							Undergraduate[n[3]].ebnum++;
							Undergraduate[n[3]].cap = Undergraduate[n[3]].cap + Ebook[i].cap;
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
								//check already borrow
								for(k=0;k<(Undergraduate[j].ebnum); k++){
									if( Ebook[i].name == Undergraduate[j].rent2[k].name){
										flag3=1;
										write(top,op,4, Undergraduate[j].rent2[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
								//check restrict member
								if( Undergraduate[j].state == 2 )
									write(top,op,6,Undergraduate[j].date);
								//check capacity
								else if(( Undergraduate[j].cap +  Ebook[i].cap) > 100)
									write(top,op,15,0);	
								//success borrow
								else{
									Undergraduate[j].state =1;
									Ebook[i].date = idattime[op-1];
									Undergraduate[j].rent2[Undergraduate[n[3]].ebnum] = Ebook[i];
									Undergraduate[j].ebnum++;
									Undergraduate[j].cap = Undergraduate[j].cap + Ebook[i].cap;
									write(top,op,0,0);
								}
							}

						}
						if(flag2 ==0){
							Undergraduate[n[3]].clear();
							Undergraduate[n[3]].name = idat[op-1][5];
							if( (Undergraduate[n[3]].cap +  Ebook[i].cap) > 100)
								write(top,op,15,0);
							else{
								Undergraduate[n[3]].state =1;
								Ebook[i].date = idattime[op-1];
								Undergraduate[n[3]].rent2[Undergraduate[n[3]].ebnum] = Ebook[i];
								Undergraduate[n[3]].ebnum++;
								Undergraduate[n[3]].cap = Undergraduate[n[3]].cap + Ebook[i].cap;
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
void library :: graduate_ebookprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		ebookclear(op,2);
		for(i = 0; i< n[2]; i++){
			if(Ebook[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[4] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[4];j++){
							//member check
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								if(Graduate[j].ebnum == 0)
									write(top,op,3,0);
								
								//borrow
								else{
									for(k=0;k<Graduate[j].ebnum;k++){
										if(Graduate[j].rent2[k].name == idat[op-1][2]){
											flag3 =1;
											break;
										}
									}					
									//match book
									if(flag3==1){
										//sucess return
										write(top,op,0,0);
										for(l=k;l<Graduate[j].ebnum-1;l++)
											Graduate[j].rent2[l] = Graduate[j].rent2[l+1];
										Graduate[j].cap = Graduate[j].cap -Ebook[i].cap;
										Graduate[j].ebnum--;	
										for(l=Graduate[j].ebnum; l <50; l++)
											Graduate[j].rent2[l].allclear();		
									}
									//didn't match borrow book	
									else
										write(top,op,3,0);
									flag3= 0;				
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
					if(n[4] == 0){
						Graduate[n[4]].clear();
						Graduate[n[4]].name = idat[op-1][5];
						if( (Graduate[n[4]].cap +  Ebook[i].cap) > 500)
							write(top,op,15,0);
						else{
							Graduate[n[4]].state =1;
							Ebook[i].date = idattime[op-1];
							Graduate[n[4]].rent2[Graduate[n[4]].ebnum] = Ebook[i];
							Graduate[n[4]].ebnum++;
							Graduate[n[4]].cap = Graduate[n[4]].cap +  Ebook[i].cap;
							write(top,op,0,0);
						}
						n[4]++;	
					}
					//have member info
					else{
						for(j=0;j<n[4];j++){
							//check name
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Graduate[j].state == 2) && (idattime[op-1] > Graduate[j].date))
									Graduate[j].state = 0;
								//check already borrow
								for(k=0;k<(Graduate[j].ebnum); k++){
									if( Ebook[i].name == Graduate[j].rent2[k].name){
										flag3=1;
										write(top,op,4, Graduate[j].rent2[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
								//check restrict member
								if( Graduate[j].state == 2 )
									write(top,op,6,Graduate[j].date);
								else if( (Graduate[j].cap +  Ebook[i].cap) > 500)
									write(top,op,15,0);	
								//success borrow
								else{
									Graduate[j].state =1;
									Ebook[i].date = idattime[op-1];
									Graduate[j].rent2[Graduate[n[4]].ebnum] = Ebook[i];
									Graduate[j].ebnum++;
									write(top,op,0,0);
								}
							}

						}
						if(flag2 ==0){
							Graduate[n[4]].clear();
							Graduate[n[4]].name = idat[op-1][5];
							if( (Graduate[n[4]].cap +  Ebook[i].cap) > 500)
								write(top,op,15,0);
							else{
								Graduate[n[4]].state =1;
								Ebook[i].date = idattime[op-1];
								Graduate[n[4]].rent2[Graduate[n[4]].ebnum] = Ebook[i];
								Graduate[n[4]].ebnum++;
								Graduate[n[4]].cap = Graduate[n[4]].cap +  Ebook[i].cap;
								write(top,op,0,0);
							}
							n[4]++;		
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
void library :: faculty_ebookprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		ebookclear(op,3);
		for(i = 0; i< n[2]; i++){
			if(Ebook[i].name == idat[op-1][2]){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[5] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[5];j++){
							//member check
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								if(Faculty[j].ebnum == 0)
									write(top,op,3,0);
								
								//borrow
								else{
									for(k=0;k<Faculty[j].ebnum;k++){
										if(Faculty[j].rent2[k].name == idat[op-1][2]){
											flag3 =1;
											break;
										}
									}					
									//match book
									if(flag3==1){
										//sucess return
										write(top,op,0,0);
										for(l=k;l<Faculty[j].ebnum-1;l++)
											Faculty[j].rent2[l] = Faculty[j].rent2[l+1];
										Faculty[j].cap = Faculty[j].cap -Ebook[i].cap;
										Faculty[j].ebnum--;	
										for(l=Faculty[j].ebnum; l <50; l++)
											Faculty[j].rent2[l].allclear();		
									}
									//didn't match borrow book	
									else
										write(top,op,3,0);
									flag3= 0;				
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
					if(n[5] == 0){
						Faculty[n[5]].clear();
						Faculty[n[5]].name = idat[op-1][5];
						if( (Faculty[n[4]].cap +  Ebook[i].cap) > 1000)
							write(top,op,15,0);
						else{
							Faculty[n[5]].state =1;
							Ebook[i].date = idattime[op-1];
							Faculty[n[5]].rent2[Faculty[n[5]].ebnum] = Ebook[i];
							Faculty[n[5]].ebnum++;
							write(top,op,0,0);
							Faculty[n[4]].cap +=  Ebook[i].cap;
							}
						n[5]++;	
					}
					//have member info
					else{
						for(j=0;j<n[5];j++){
							//check name
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Faculty[j].state == 2) && (idattime[op-1] > Faculty[j].date))
									Faculty[j].state = 0;
								//check already borrow
								for(k=0;k<(Graduate[j].ebnum); k++){
									if( Ebook[i].name == Faculty[j].rent2[k].name){
										flag3=1;
										write(top,op,4, Faculty[j].rent2[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
								//check restrict member
								if( Faculty[j].state == 2 )
									write(top,op,6,Faculty[j].date);
								else if( (Faculty[j].cap +  Ebook[i].cap) > 1000)
									write(top,op,15,0);	
								//success borrow
								else{
									Faculty[j].state =1;
									Ebook[i].date = idattime[op-1];
									Faculty[j].rent2[Faculty[n[5]].ebnum] = Ebook[i];
									Faculty[j].ebnum++;
									Faculty[j].cap +=  Ebook[i].cap;		
									write(top,op,0,0);
								}
							}

						}
						if(flag2 ==0){
							Faculty[n[5]].clear();
							Faculty[n[5]].name = idat[op-1][5];
							if( (Faculty[n[5]].cap +  Ebook[i].cap) > 1000)
								write(top,op,15,0);
							else{
								Faculty[n[5]].state =1;
								Ebook[i].date = idattime[op-1];
								Faculty[n[5]].rent2[Faculty[n[5]].ebnum] = Ebook[i];
								Faculty[n[5]].ebnum++;
								Faculty[n[5]].cap +=  Ebook[i].cap;
								write(top,op,0,0);
							}
							n[5]++;		
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
int library :: magazinetest(string name,int time){
	int i,j;	
	for(i=0;i<n[3];i++){
		for(j=0;j< Undergraduate[i].mznum;i++){
			if((Undergraduate[i].rent1[j].name == name)&&(Undergraduate[i].rent1[j].cap == time))
				return 1;		
		}	
	}

	for(i=0;i<n[4];i++){
		for(j=0;j< Graduate[i].mznum;i++){
			if((Graduate[i].rent1[j].name == name)&&(Graduate[i].rent1[j].cap == time))
				return 2;		
		}	
	}

	for(i=0;i<n[5];i++){
		for(j=0;j< Faculty[i].mznum;i++){
			if((Faculty[i].rent1[j].name == name)&&(Faculty[i].rent1[j].cap == time))
				return 3;		
		}	
	}
	return 0;
}
void library :: undergraduate_magazineprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i=0;i<idat[op-1][2].length();i++){
			if(idat[op-1][2].at(i) == '[')
				j= i;
			else if(idat[op-1][2].at(i) == ']')
				k = i;		
			else if(idat[op-1][2].at(i) == '/')
				l = i;	
			}
		int date = 360*atoi(idat[op-1][2].substr(j+1,l-j-1).c_str()) + 30*atoi(idat[op-1][2].substr(l+1,k-l-1).c_str());
		idat[op-1][2] = idat[op-1][2].substr(0,j);
		for(i = 0; i< n[1]; i++){
			if((Magazine[i].name == idat[op-1][2]) &&(idattime[op-1] - date < 360)){
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
									
									//match Magazine
									if((Undergraduate[j].books == idat[op-1][2]) &&(Undergraduate[j].mznum == 1)&&(Undergraduate[j].rent1[0].cap == date)){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Undergraduate[j].rent1[0].date) <14){
											write(top,op,0,0);
											Undergraduate[j].state = 0;
										}
										//late return
										else{
											Undergraduate[j].state = 2;
											Undergraduate[j].late = idattime[op-1] - Undergraduate[j].rent1[0].date -13;
											Undergraduate[j].date = idattime[op-1] + Undergraduate[j].late;
											write(top,op,7,idattime[op-1] + Undergraduate[j].late);
										}
										Undergraduate[j].mznum--;
										Undergraduate[j].rent1[0].allclear();
									}
									//didn't match borrow Magazine	
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
						//if Magazine is not here
						if(magazinetest(idat[op-1][2],date) == 1){
							write(top,op,5,Magazine[i].date + 13);
						}
						else if(magazinetest(idat[op-1][2],date) == 2){
							write(top,op,5,Magazine[i].date + 29);
						}
						else if(magazinetest(idat[op-1][2],date) == 3){
							write(top,op,5,Magazine[i].date + 29);	
						}
						// if Magazine is here
						else{
							Undergraduate[n[3]].books = idat[op-1][2];
							Magazine[i].state = 1;
							Undergraduate[n[3]].state =1;
							Magazine[i].date = idattime[op-1];
							Undergraduate[n[3]].rent1[Undergraduate[n[3]].mznum] = Magazine[i];
							Undergraduate[n[3]].rent1[Undergraduate[n[3]].mznum].cap = date;
							Undergraduate[n[3]].mznum++;
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
								if((Undergraduate[j].state == 1)&&(Undergraduate[j].booknum + Undergraduate[j].mznum >0)){
									write(top,op,2,1);
									break;
								}
								//check already borrow
								for(k=0;k<(Undergraduate[j].mznum); k++){
									if((Magazine[i].name == Undergraduate[j].rent1[k].name)&&(Undergraduate[j].rent[k].cap == date)){
										flag3=1;
										write(top,op,4, Undergraduate[j].rent1[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check Magazine have
									if(magazinetest(idat[op-1][2],date) == 1){
										write(top,op,5,Magazine[i].date + 13);
									}
									else if(magazinetest(idat[op-1][2],date) == 2){
										write(top,op,5,Magazine[i].date + 29);
									}
									else if(magazinetest(idat[op-1][2],date) == 3){
										write(top,op,5,Magazine[i].date + 29);	
									}
									else{
										//check restrict member
										if( Undergraduate[j].state == 2 )
											write(top,op,6,Undergraduate[j].date);
									
										//success borrow
										else{
											Undergraduate[j].books = idat[op-1][2];
											Magazine[i].state = 1;
											Magazine[i].type = "Undergraduate";
											Undergraduate[j].state =1;
											Magazine[i].date = idattime[op-1];
											Undergraduate[j].rent1[Undergraduate[j].mznum] = Magazine[i];
											Undergraduate[j].rent1[Undergraduate[j].mznum].cap = date;			
											Undergraduate[j].mznum++;
											write(top,op,0,0);
										}
									}
							}

						}
						if(flag2 ==0){
							
							Undergraduate[n[3]].clear();
							Undergraduate[n[3]].name = idat[op-1][5];
							if(magazinetest(idat[op-1][2],date) == 1){
								write(top,op,5,Magazine[i].date + 13);
							}
							else if(magazinetest(idat[op-1][2],date) == 2){
								write(top,op,5,Magazine[i].date + 29);
							}
							else if(magazinetest(idat[op-1][2],date) == 3){
								write(top,op,5,Magazine[i].date + 29);	
							}
							else{
								Undergraduate[n[3]].books = idat[op][2];
								Magazine[i].state = 1;
								Magazine[i].type = "Undergraduate";	
								Undergraduate[n[3]].state =1;
								Magazine[i].date = idattime[op-1];
								Undergraduate[n[3]].rent1[Undergraduate[n[3]].mznum] = Magazine[i];
								Undergraduate[n[3]].rent1[Undergraduate[n[3]].mznum].cap = date;
								Undergraduate[n[3]].mznum++;
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

void library :: graduate_magazineprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i=0;i<idat[op-1][2].length();i++){
			if(idat[op-1][2].at(i) == '[')
				j= i;
			else if(idat[op-1][2].at(i) == ']')
				k = i;		
			else if(idat[op-1][2].at(i) == '/')
				l = i;	
			}
		int date = 360*atoi(idat[op-1][2].substr(j+1,l-j-1).c_str()) + 30*atoi(idat[op-1][2].substr(l+1,k-l-1).c_str());
		idat[op-1][2] = idat[op-1][2].substr(0,j);
		for(i = 0; i< n[1]; i++){
			if((Magazine[i].name == idat[op-1][2]) &&(idattime[op-1] - date < 360)){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[4] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[4];j++){
							//member check
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								
								if((Graduate[j].state != 1) && (Graduate[j].mznum == 0))
									write(top,op,3,0);
								//borrow
								else{
									for(k=0;k<Graduate[j].mznum;k++){
										if((Graduate[j].rent1[k].name == idat[op-1][2]) &&(Graduate[j].mznum > 0)&&(Graduate[j].rent1[k].cap == date)){
											flag3 =1;
											break;
										}
									}
									//match Magazine
									if(flag3 == 1){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Graduate[j].rent1[k].date) <30){
											write(top,op,0,0);
											for(l=k;l<Graduate[j].mznum-1;l++)
												Graduate[j].rent1[l] = Graduate[j].rent1[l+1];
											Graduate[j].mznum--;
											Magazine[i].clear();
											if((Graduate[j].mznum == 0)&&(Graduate[j].booknum == 0))		
												Graduate[j].state = 0;
											
										}
										//late return
										else{
											Graduate[j].state = 2;
											Graduate[j].late = idattime[op-1] - Graduate[j].rent1[k].date -29;
											Graduate[j].date = idattime[op-1] + Graduate[j].late;
											write(top,op,7,idattime[op-1] + Graduate[j].late);
											for(l=k;l<Graduate[j].mznum-1;l++)
												Graduate[j].rent1[l] = Graduate[j].rent1[l+1];
											Graduate[j].mznum--;
											Magazine[i].clear();
										}
									}
									//didn't match borrow Magazine	
									else
										write(top,op,3,0);
									flag3 = 0;				
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
					if(n[4] == 0){
						Graduate[n[4]].clear();
						Graduate[n[4]].name = idat[op-1][5];
						//if Magazine is not here
						if(magazinetest(idat[op-1][2],date) == 1){
							write(top,op,5,Magazine[i].date + 13);
						}
						else if(magazinetest(idat[op-1][2],date) == 2){
							write(top,op,5,Magazine[i].date + 29);
						}
						else if(magazinetest(idat[op-1][2],date) == 3){
							write(top,op,5,Magazine[i].date + 29);	
						}
						// if Magazine is here
						else{
							Graduate[n[4]].books = idat[op-1][2];
							Magazine[i].state = 1;
							Magazine[i].type = "Graduate";
							Graduate[n[4]].state =1;
							Magazine[i].date = idattime[op-1];
							Graduate[n[4]].rent1[Graduate[n[4]].mznum] = Magazine[i];
							Graduate[n[4]].rent1[Graduate[n[4]].mznum].cap = date;
							Graduate[n[4]].mznum++;
							write(top,op,0,0);
						}
						n[4]++;	
					}
					//have member info
					else{

						for(j=0;j<n[4];j++){
							//check name
							if(Graduate[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Graduate[j].state == 2) && (idattime[op-1] > Graduate[j].date)){
									if((Graduate[j].mznum == 0)&&(Graduate[j].booknum == 0))	
										Graduate[j].state = 0;
									else
										Graduate[j].state = 1; 										
								}
								//one more borrow
								if((Graduate[j].state == 1) &&(Graduate[j].booknum+Graduate[j].mznum > 5)){
									write(top,op,2,5);
									break;
								}
								//check already borrow
								for(k=0;k<(Graduate[j].mznum); k++){
									if( Magazine[i].name == Graduate[j].rent1[k].name){
										flag3=1;
										write(top,op,4, Graduate[j].rent1[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check Magazine have
									if(magazinetest(idat[op-1][2],date) == 1){
										write(top,op,5,Magazine[i].date + 13);
									}
									else if(magazinetest(idat[op-1][2],date) == 2){
										write(top,op,5,Magazine[i].date + 29);
									}
									else if(magazinetest(idat[op-1][2],date) == 3){
										write(top,op,5,Magazine[i].date + 29);	
									}
									else{
									//check restrict member
										if( Graduate[j].state ==2 )
										write(top,op,6,Graduate[j].date);
									
									//success borrow
										else{
										Graduate[j].books = idat[op-1][2];
										Magazine[i].state = 1;
										Magazine[i].type = "Graduate";
										Graduate[j].state =1;
										Magazine[i].date = idattime[op-1];
										Graduate[j].rent1[Graduate[j].mznum] = Magazine[i];
										Graduate[j].rent1[Graduate[j].mznum].cap = date;		
										Graduate[j].mznum++;
										write(top,op,0,0);
										}
									}
							}

						}
						if(flag2 ==0){
							
							Graduate[n[4]].clear();
							Graduate[n[4]].name = idat[op-1][5];
							if(magazinetest(idat[op-1][2],date) == 1){
								write(top,op,5,Magazine[i].date + 13);
							}
							else if(magazinetest(idat[op-1][2],date) == 2){
								write(top,op,5,Magazine[i].date + 29);
							}
							else if(magazinetest(idat[op-1][2],date) == 3){
								write(top,op,5,Magazine[i].date + 29);	
							}
							else{
								Graduate[n[4]].books = idat[op][2];
								Magazine[i].state = 1;
								Graduate[n[4]].state =1;
								Magazine[i].type = "Graduate";
								Magazine[i].date = idattime[op-1];
								Graduate[n[4]].rent1[Graduate[n[4]].mznum] = Magazine[i];
								Graduate[n[4]].rent1[Graduate[n[4]].mznum].cap = date;
								Graduate[n[4]].mznum++;
								write(top,op,0,0);
							}
							n[4]++;	
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
void library :: faculty_magazineprocess(int top,int op){
	int i,j,k,l;
	int flag =0;
	int flag2 =0 ;	
	int flag3 = 0;
		for(i=0;i<idat[op-1][2].length();i++){
			if(idat[op-1][2].at(i) == '[')
				j= i;
			else if(idat[op-1][2].at(i) == ']')
				k = i;		
			else if(idat[op-1][2].at(i) == '/')
				l = i;	
			}
		int date = 360*atoi(idat[op-1][2].substr(j+1,l-j-1).c_str()) + 30*atoi(idat[op-1][2].substr(l+1,k-l-1).c_str());
		idat[op-1][2] = idat[op-1][2].substr(0,j);
		for(i = 0; i< n[1]; i++){
			if((Magazine[i].name == idat[op-1][2]) &&(idattime[op-1] - date < 360)){
				flag = 1;
				//return
				if(idat[op-1][3] == "R"){
					//member check
					if(n[5] == 0)
						write(top,op,3,0);
					
					else
					{
						for(j=0;j<n[5];j++){
							//member check
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//not borrow 
								
								if((Faculty[j].state != 1) && (Faculty[j].mznum == 0))
									write(top,op,3,0);
								//borrow
								else{
									for(k=0;k<Faculty[j].mznum;k++){
										if((Faculty[j].rent1[k].name == idat[op-1][2]) &&(Faculty[j].mznum > 0)&&(Faculty[j].rent1[k].cap == date)){
											flag3 =1;
											break;
										}
									}
									//match Magazine
									if(flag3 == 1){
										//need late or not
										//sucess return
										if( (idattime[op-1] - Faculty[j].rent1[k].date) <30){
											write(top,op,0,0);
											for(l=k;l<Faculty[j].mznum-1;l++)
												Faculty[j].rent1[l] = Faculty[j].rent1[l+1];
											Faculty[j].mznum--;
											Magazine[i].clear();
											if((Faculty[j].mznum == 0)&&(Faculty[j].booknum == 0))		
												Faculty[j].state = 0;
											
										}
										//late return
										else{
											Faculty[j].state = 2;
											Faculty[j].late = idattime[op-1] - Faculty[j].rent1[k].date -29;
											Faculty[j].date = idattime[op-1] + Faculty[j].late;
											write(top,op,7,idattime[op-1] + Faculty[j].late);
											for(l=k;l<Faculty[j].mznum-1;l++)
												Faculty[j].rent1[l] = Faculty[j].rent1[l+1];
											Faculty[j].mznum--;
											Magazine[i].clear();
										}
									}
									//didn't match borrow Magazine	
									else
										write(top,op,3,0);
									flag3 = 0;				
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
					if(n[5] == 0){
						Faculty[n[5]].clear();
						Faculty[n[5]].name = idat[op-1][5];
						//if Magazine is not here
						if(magazinetest(idat[op-1][2],date) == 1){
							write(top,op,5,Magazine[i].date + 13);
						}
						else if(magazinetest(idat[op-1][2],date) == 2){
							write(top,op,5,Magazine[i].date + 29);
						}
						else if(magazinetest(idat[op-1][2],date) == 3){
							write(top,op,5,Magazine[i].date + 29);	
						}
						// if Magazine is here
						else{
							Faculty[n[5]].books = idat[op-1][2];
							Magazine[i].state = 1;
							Magazine[i].type = "Faculty";
							Faculty[n[5]].state =1;
							Magazine[i].date = idattime[op-1];
							Faculty[n[5]].rent1[Faculty[n[5]].mznum] = Magazine[i];
							Faculty[n[5]].rent1[Faculty[n[5]].mznum].cap = date;
							Faculty[n[5]].mznum++;
							write(top,op,0,0);
						}
						n[5]++;	
					}
					//have member info
					else{

						for(j=0;j<n[5];j++){
							//check name
							if(Faculty[j].name == idat[op-1][5]){
								flag2 =1;
								//restrict member release
								if( (Faculty[j].state == 2) && (idattime[op-1] > Faculty[j].date)){
									if((Faculty[j].mznum == 0)&&(Faculty[j].booknum == 0))	
										Faculty[j].state = 0;
									else
										Faculty[j].state = 1; 										
								}
								//one more borrow
								if((Faculty[j].state == 1) &&(Faculty[j].booknum+Faculty[j].mznum > 10)){
									write(top,op,2,10);
									break;
								}
								//check already borrow
								for(k=0;k<(Faculty[j].mznum); k++){
									if( Magazine[i].name == Faculty[j].rent1[k].name){
										flag3=1;
										write(top,op,4, Faculty[j].rent1[k].date);		
									}
								}
								if(flag3 ==1){
									flag3 =0;
									break;
								}
									//check Magazine have
									if(magazinetest(idat[op-1][2],date) == 1){
										write(top,op,5,Magazine[i].date + 13);
									}
									else if(magazinetest(idat[op-1][2],date) == 2){
										write(top,op,5,Magazine[i].date + 29);
									}
									else if(magazinetest(idat[op-1][2],date) == 3){
										write(top,op,5,Magazine[i].date + 29);	
									}
									else{
									//check restrict member
										if(Faculty[j].state ==2 )
										write(top,op,6,Faculty[j].date);
									
									//success borrow
										else{
										Faculty[j].books = idat[op-1][2];
										Magazine[i].state = 1;
										Magazine[i].type = "Faculty";
										Faculty[j].state =1;
										Magazine[i].date = idattime[op-1];
										Faculty[j].rent1[Faculty[j].mznum] = Magazine[i];
										Faculty[j].rent1[Faculty[j].mznum].cap = date;		
										Faculty[j].mznum++;
										write(top,op,0,0);
										}
									}
							}

						}
						if(flag2 ==0){
							
							Faculty[n[5]].clear();
							Faculty[n[5]].name = idat[op-1][5];
							if(magazinetest(idat[op-1][2],date) == 1){
								write(top,op,5,Magazine[i].date + 13);
							}
							else if(magazinetest(idat[op-1][2],date) == 2){
								write(top,op,5,Magazine[i].date + 29);
							}
							else if(magazinetest(idat[op-1][2],date) == 3){
								write(top,op,5,Magazine[i].date + 29);	
							}
							else{
								Faculty[n[5]].books = idat[op][2];
								Magazine[i].state = 1;
								Faculty[n[5]].state =1;
								Magazine[i].type = "Faculty";
								Magazine[i].date = idattime[op-1];
								Faculty[n[5]].rent1[Faculty[n[5]].mznum] = Magazine[i];
								Faculty[n[5]].rent1[Faculty[n[5]].mznum].cap = date;
								Faculty[n[5]].mznum++;
								write(top,op,0,0);
							}
							n[5]++;	
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
void library :: bookprocess(int top,int op){
	if(idat[op-1][4] == "Undergraduate")
		undergraduate_bookprocess(top,op);
	else if(idat[op-1][4] == "Graduate")
		graduate_bookprocess(top,op);
	else if(idat[op-1][4] == "Faculty")
		faculty_bookprocess(top,op);
}
void library :: magazineprocess(int top,int op){
	if(idat[op-1][4] == "Undergraduate")
		undergraduate_magazineprocess(top,op);
	else if(idat[op-1][4] == "Graduate")
		graduate_magazineprocess(top,op);
	else if(idat[op-1][4] == "Faculty")
		faculty_magazineprocess(top,op);
}
void library :: ebookprocess(int top,int op){
	if(idat[op-1][4] == "Undergraduate")
		undergraduate_ebookprocess(top,op);
	else if(idat[op-1][4] == "Graduate")
		graduate_ebookprocess(top,op);
	else if(idat[op-1][4] == "Faculty")
		faculty_ebookprocess(top,op);
}
void library :: resourceprocess(int top,int op){
	if(idat[op-1][1] == "Book")
		bookprocess(top,op);
	else if(idat[op-1][1] == "E-book")
		ebookprocess(top,op);
	else if(idat[op-1][1] == "Magazine")
		magazineprocess(top,op);
}
void library :: process(){
	set();
	setidat();

	setsdat();
	out.open("output.dat");
	out << "Op_#	Return_code	Description" << endl;
	int sop=1;
	int iop=1;
	int top=1;
	int i =0;
	while((iop<=idatnum)||(sop<=sdatnum)){
		if(sdattime[sop-1][0] >= idattime[iop-1]){
			if(iop <= idatnum){
				resourceprocess(top,iop);
				iop++;
			}
			else{
				spaceprocess(top,sop);
				sop++;
			}
		}
		else{
			if(sop <= sdatnum){
				spaceprocess(top,sop);
				sop++;
			}
			else{
				resourceprocess(top,iop);
				iop++;
			}
		}
		top++;	
	}


	out.close();
}
