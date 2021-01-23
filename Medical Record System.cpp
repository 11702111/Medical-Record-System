#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<iomanip>
#include<string.h>
#include<process.h>
#include<windows.h>
using namespace std;
class medicine
{
	int mno;			//Data Members
	char mname[25];
	double mprice;
	int mquantity;
	public:				//Member Functions

	medicine()                       //Default Constructor
	{
	     mno=0;
		strcpy(mname,"XXXXX");
		mprice=0;
		mquantity=0;
			}
	void getdata();
	void putdata();
	void modify();
	int getmno()
	{
		return mno;
	}
	void setmno()
	{
		mno=2000;
	}
	void setmno(int no)	       //Function Overloading
	{
		mno = no + 1;
	}
};
void medicine::getdata()                 //Member Function defined using SRO Operator
{	fflush(stdin);
	cout<<"\nEnter medicine name= ";
	gets(mname);
	cout<<"\nEnter medicine price = ";
	cin>>mprice;
	cout<<"\nEnter quantity of medicine= ";
	cin>>mquantity;


}

void medicine::putdata()
{
	cout.setf(ios::left);
	cout<<"\n"<<setw(20)<<mno<<"\t"<<setw(20)<<mname<<"\t"<<setw(15)<<mprice<<"\t"<<setw(12)<<mquantity;
}

void medicine::modify()
{
	cout<<"\n\nEnter New details.";
	char name[25]="";
	double price;int quantity;
	fflush(stdin);
	cout<<"\nEnter new Name OR . for same= ";
	gets(name);
	cout<<"\nEnter new price OR 0 for same= ";
	cin >>price;
	cout<<"\nEnter new quantity OR 0 for same= ";
	cin>>quantity;
	
	if(strcmp(name,".")!=0)
		strcpy(mname,name);
	if(price!=0)
	mprice=price;
	if(quantity!=0)
		mquantity=quantity;
	
}

void header();

int main()
{		system("color 0b");
		system("cls");
		cout<<"!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n\n\t\t  \t\t   !*!*!*!*!COMPUTER PROJECT WORK!*!*!*!*! " ;
		Sleep(1000);
		cout<<"\n\n\n\t\t \t\t !*!*!*!*!*!MEDICINE RECORD SYSTEM!*!*!*!*!*!";
		Sleep(1000);
		cout<<"\n\n\n\n\t\t \t\t   !*!*!*!*!MADE BY ABHISHEK PANDEY!*!*!*!*!";
		Sleep(4000);
		system("cls");
system("color 0a");
	medicine t,t1,t2;
	ofstream fout;
	ifstream fin;
	char n;
	int n1;
	char my='n';
	int n2;
	long pos;
	fstream foi;	//Update
	char f;
	char flag='f',confirm;
	do
	{
		cout<<"\t\n----------MAIN MENU----------";
		cout<<"\t\n1.CREATION"<<"\t\n2.APPENDING"<<"\t\n3.SEARCHING"<<"\t\n4.DISPLAYING"<<"\t\n5.DELETION"<<"\t\n6.MODIFICATION"<<"\t\n7.EXIT";
		f = 'n';
		cout<<"\nEnter your choice:";
		n = getche();
		switch(n)
		{
			case '1':
				Beep(400,500);
				system("color 0c");
					system("cls");
				fout.open("medicine.dat",ios::out|ios::binary);
				t.setmno();
				//clrscr();
				t.getdata();
				//clrscr();
				fout.write((char *)&t,sizeof(t));
				fout.close();
				break;

			case '2':
				Beep(400,500);
				system("color 0d");
				system("cls");
				fin.open("medicine.dat",ios::in|ios::binary);
				while(fin)
				{
					fin.read((char*)&t1,sizeof(t1));
				}
				fin.close();

				fout.open("medicine.dat",ios::app|ios::binary);
				t.setmno(t1.getmno());
				//clrscr();
				t.getdata();
				//clrscr();
				fout.write((char *)&t,sizeof(t));
				fout.close();
				break;
			case'3':
				Beep(400,500);
				system("cls");
				system("color 5");
				cout<<"Enter the medicine No: ";
				cin>>n1;
				fin.open("medicine.dat",ios::in|ios::binary);
				while(!fin.eof())
				{
					fin.read((char*)&t1,sizeof(t1));
					if(fin.eof())
					{
						break;
					}
					if(t1.getmno()==n1)
					{
						header();
						t1.putdata();
						cout<<"\n\t\t*****SEARCH IS SUCCESSFUL*****";
						f='y';
						break;
					}
				}
				fin.close();
				if(f=='n')
					cout<<"\n!!!!!SEARCH IS NOT SUCCESSFUL!!!!!";

				break;

			case'4':
				Beep(400,500);
				system("color 0b");
			system("cls");
				fin.open("medicine.dat",ios::in|ios::binary);
				header();
				while(!fin.eof())
				{
					fin.read((char*)&t1,sizeof(t1));
					if(fin.eof())
					{
						break;
					}
					t1.putdata();

				}
				fin.close();
				getch();
				break;
			case'5':
				Beep(400,500);
				system("color 0f");
				system("cls");
				cout<<"Enter the medicine no: ";
				cin>>n2;
				fin.open("medicine.dat",ios::in|ios::binary);
				fout.open("temp.dat",ios::out|ios::binary);
				while(!fin.eof())
				{
					fin.read((char*)& t1,sizeof(t1));
					if(fin.eof())
					{
						break;
					}
					if(t1.getmno()==n2)
					{
						header();
						t1.putdata();
						flag='t';
						cout<<"\n\nConfirm that(y/n):";
						cin>>confirm;
						if(confirm=='n')
						       {	fout.write((char *)&t1,sizeof(t1));
								cout<<"\nRecord not deleted";
								break;
							}
							   cout<<"\nRecord deleted";
							   getch();
					}
					else
						fout.write((char *)&t1,sizeof(t1));



				}
				if(flag=='f')
					cout<<"Record not found";
				fin.close();
				fout.close();
				remove("medicine.dat");
				rename("temp.dat","medicine.dat");
				break;

			case '6':
				Beep(400,500);
				system("color 2");
					system("cls");
				char uname[25],pwd[25];
				int t ,x;
				t=0;x=0;
				char chr;
	for(int i=0;i<3;i++)
	{
		cout<<"\nEnter UserName: ";
		cin>>uname;
		cout<<"\nEnter Password: ";
		while(x<25)
		{
			
			chr = getch();
			if((int)chr != 13)
			{
				pwd[x] = chr;
				putchar('*');
				x++;
			}
			else
				break;
		}
		t++;
		if(strcmp(uname,"abhishek")==0 && strcmp(pwd,"pain")==0)
		{
			cout<<"\nlogin Successful.";
			break;
		}
		else
		{
			if(t == 3)
				exit(0);
			cout<<"\nTry Again";
			getch();
				system("cls");
		}
	}
			system("cls");
				cout<<"Enter the medicine number : ";
				cin>>n2;
				foi.open("medicine.dat",ios::in|ios::out|ios::binary);
				//call();
				while(foi)
				{
					pos = foi.tellg();
					foi.read((char *)&t1,sizeof(t1));
					if(foi.eof())
						break;
					if(t1.getmno()==n2)
					{
						my='y';
						header();
						t1.putdata();
						t1.modify();
						foi.seekg(pos);
						foi.write((char *)&t1,sizeof(t1));
						cout<<"\n\t\t\tRecord modified";
						Sleep(1000)  ;
						break;

					}

				}
				if(my=='n')
					cout<<"Record not found";
				Sleep(1000)           ;
				foi.close();
				system("cls");
				break;
			case'7': 
			system("color 0c");
				Beep(400,500);
				  system("cls");
				   cout<<"      \n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t*!*!*!*!THANK YOU!*!*!*!*!";
				  Sleep(2000);
				   exit(0);
			default:
				Beep(400,500);
				system("cls");
				cout<<"WRONG CHOICE";
				break;
			     }
	}while(1);	//Infinite loop
	return 0;
}


void header()
{
	cout.setf(ios::left);
	cout<<"\n"<<setw(20)<<"MEDICINE NUMBER"<<"\t"<<setw(20)<<"NAME OF MEDICINE"<<"\t"<<setw(15)<<"MEDICINE PRICE"<<"\t"<<setw(15)<<"QUANTITY";

}
