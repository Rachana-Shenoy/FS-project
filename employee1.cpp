#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<dos.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>
#include<fstream>
using namespace std;
class employee
{
	private:
		char name[20];
		char code[5];
		int age;
		int sal;
		int exp;
		char des[10];
	public:

		void menu();
		void insert();
		void edit();
		void del();
		void list();
		void enquiry();
};
void employee::menu()
{
	system("COLOR 1F");
	employee e;
	while(1)
	{
	system("cls");

	cout<<"\n		1 	 To add an employee details";
	cout<<"\n		2	 To see list of employee details";
	cout<<"\n		3	 To edit an employee details";
	cout<<"\n		4	 To remove an employee details from list";
	cout<<"\n		5	 To see details of a employee";
	cout<<"\n		0	 To exit	";
	cout<<"\n\n\n\n		Choose your optiion 	:	";
	int ab;
	cin>>ab;

		switch(ab)
		{
			case 1:
				e.insert();
				break;
			case 2:
				e.list();
				break;
			case 3:
				e.edit();
				break;
			case 4:
				e.del();
				break;
			case 5:
				e.enquiry();
				break;
			case 0:
				return ;
			default:
				cout<<"Invalid Option";
				break;
		}
	}
}
void employee::insert()
{
	system("cls");
	FILE *fa;
	char ch;
	employee e;
	system("cls");
	system("COLOR 2F");
	cout<<"\n	Enter name of employee			:	";
	cin>>e.name;
	cout<<"\n	Enter code of employee			:	";
	cin>>e.code;
	cout<<"\n	Enter designation of employee		:	";
	cin>>e.des;
	cout<<"\n	Enter age of employee			:	";
	cin>>e.age;
	cout<<"\n	Enter salary of employee		:	";
	cin>>e.sal;
	cout<<"\n	Enter expierence of employee		:	";
	cin>>e.exp;
	cout<<"\n	Do you wish to save the above details(y/n)	:	";
	cin>>ch;
	if(ch=='y')
	{
		fa=fopen("details.txt","a");
		fprintf(fa,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		fclose(fa);
	}
	else
		insert();
}
void employee::list()
{
	system("cls");
	system("COLOR 3F");
	FILE *fb;
	fb=fopen("details.txt","r");
	employee e;
	cout<<"\nname	code	designation		age		experience		salary\n";
	while(fscanf(fb,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		cout<<"\n"<<e.name<<"\t"<<e.code<<"\t"<<e.des<<"\t\t"<<e.age<<" \t\t"<<e.exp<<"\t\t"<<e.sal;
	}
	fclose(fb);
			getch();
}

void employee::edit()
{
	system("COLOR 4F");
	system("cls");
	FILE *fc,*fd;

	employee e;
	char ccode[5];
	cout<<"Enter code 	:	";
	cin>>ccode;
	char id[5],desg[10];
	cout<<"Enter new id 	:	";
	cin>>id;
	cout<<"Enter new designation 	:	";
	cin>>desg;
	fc=fopen("details.txt","r");
	fd=fopen("temp.txt","w");
	while(fscanf(fc,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)==0)
		{
			fprintf(fd,"%s %s %s %d %d %d \n",e.name,id,desg,e.age,e.exp,e.sal);
		}
		else
		{
			fprintf(fd,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";

	fclose(fc);
	fclose(fd);

	int a = remove(s);
	int b = rename(t,s);
			getch();
}
void employee::enquiry()
{

	system("cls");
	system("COLOR 6F");
	FILE *fe;

	employee e;
	char ccode[5];
	cout<<"Enter code ";
	cin>>ccode;
	fe=fopen("details.txt","r");
	while(fscanf(fe,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)==0)
		{
			cout<<"\nname		code	designation		age		expierenice		salary";
			cout<<"\n"<<e.name<<"\t\t"<<e.code<<"\t"<<e.des<<"\t\t"<<e.age<<"\t\t"<<e.exp<<"\t\t\t"<<e.sal;
		}
	}
	fclose(fe);
			getch();
}
void employee::del()
{
	system("cls");
	FILE *ff,*fg;

	employee e;
	char ccode[5];
	cout<<"Enter code ";
	cin>>ccode;
	ff=fopen("details.txt","r");
	fg=fopen("temp.txt","w");
	while(fscanf(ff,"%s %s %s %d %d %d \n",e.name,e.code,e.des,&e.age,&e.exp,&e.sal)!=EOF)
	{
		if(strcmp(ccode,e.code)!=0)
		{
			fprintf(fg,"%s %s %s %d %d %d \n",e.name,e.code,e.des,e.age,e.exp,e.sal);
		}
	}
	char s[]="details.txt";
	char t[]="temp.txt";

	fclose(ff);
	fclose(fg);

	int a = remove(s);
	int b = rename(t,s);
			getch();
}


int main()
{
	int a;
	employee e;
	e.menu();

	return 0;
}
