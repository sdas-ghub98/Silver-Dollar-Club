#include<fstream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<process.h>
#include<dos.h>
void border();
void boundary();
void home();
void addnew();
void leaveclub();
void modify_details();
void search_cid();
void search_cname();
void search_name();
void show_all();
//--------------------------------------------------------------------------//
void border()
{
	int x,y;
	for(x=0;x<=39;x++)
	{
		gotoxy(2*x+1,1);cout<<"";
		gotoxy(2*x+1,24);cout<<"";
	}
	for(y=0;y<=11;y++)
	{
		gotoxy(1,2*y+1);cout<<"";
		gotoxy(1,2*y+2);cout<<"";
		gotoxy(79,2*y+1);cout<<"";
		gotoxy(79,2*y+2);cout<<"";
	}
}
void boundary()
{
	int i,j;
	for(i=1;i<=24;++i)
	{
		gotoxy(1,i);cout<<(char)177;
		gotoxy(2,i);cout<<"";
		gotoxy(3,i);cout<<(char)177;
		gotoxy(78,i);cout<<(char)177;
		gotoxy(79,i);cout<<"";
		gotoxy(80,i);cout<<(char)177;
	}
	for(j=1;j<=80;++j)
	{
		gotoxy(j,1);cout<<(char)177;
		gotoxy(j,2);cout<<"*";
		gotoxy(j,3);cout<<(char)177;
		gotoxy(j,22);cout<<(char)177;
		gotoxy(j,23);cout<<"*";
		gotoxy(j,24);cout<<(char)177;
	}
}
void home()
{
	clrscr();
	gotoxy(1,1);cout<<"			                                                          ";
	gotoxy(1,2);cout<<"			           	                                           ";
	gotoxy(1,3);cout<<"			        	             *                              ";
	gotoxy(1,4);cout<<"			      	                      **	           *       ";
	gotoxy(1,5);cout<<"           000                                         ***               **        ";
	gotoxy(1,6);cout<<"*         00000        *                               ****            ***         ";
	gotoxy(1,7);cout<<" **       00000      **                                 *****        ****          ";
	gotoxy(1,8);cout<<"  ****     000    ****                                   ******    *****          ";
	gotoxy(1,9);cout<<"    *****      *****      			          *************           ";
	gotoxy(1,10);cout<<"     *************                            	          ***********            ";
	gotoxy(1,11);cout<<"      **********             # Silver Dollars #           ***********            ";
	gotoxy(1,12);cout<<"       ********       Unleash the Uniqueness in you!!!   ***********            ";
	gotoxy(1,13);cout<<"       ********                               	        **************           ";
	gotoxy(1,14);cout<<"     ************                                      *****************         ";
	gotoxy(1,15);cout<<"    ***************	                             *********************       ";
	gotoxy(1,16);cout<<"   *****        ****  	                            ********   000   *******     ";
	gotoxy(1,17);cout<<"   ****          ***                               *****      00000      *****    ";
	gotoxy(1,18);cout<<"   ***           **	                          ***         00000         ***   ";
	gotoxy(1,19);cout<<"   **            *                               * 	       000            **" ;
	gotoxy(1,20);cout<<"   *			             		        	    	       *";
	gotoxy(1,21);cout<<"			               ";
	gotoxy(30,24);cout<<"Press ENTER to continue ";
	getch();
}
//-----------------------------------Class Definition----------------------------------------------------------------------------------------//
class club
{
	private:
		int cid, cls;
		char name[60], clubname[40];
	public:
		char *retname()
		{ return name; }
		int retid()
		{ return cid;}
		char *retcname()
		{ return clubname; }
		int retcls()
		{ return cls; }
		void getdata()
		{
			gotoxy(5,5);cout<<"Enter club id : ";cin>>cid;
			gotoxy(5,6);cout<<"Enter name : "; gets(name);
			gotoxy(5,7);cout<<"Enter class : "; cin>>cls;
			gotoxy(5,8);cout<<"Enter club name : "; gets(clubname);
		}
		void putdata(int row);
		void change_name(char tname[])
		{	strcpy(name,tname); }
		void change_cls(int tcls)
		{	cls=tcls; }
		void change_cname(char tcname[])
		{	strcpy(clubname,tcname); }
}; club c;
void club::putdata(int row)
{
	border();
	for(int i=3;i<22;i++)
	{
		gotoxy(22,i);cout<<char(177);
		gotoxy(41,i);cout<<char(177);
		gotoxy(55,i);cout<<char(177);
	}
	gotoxy(7,4);cout<<"CLUB ID";
	gotoxy(30,4);cout<<"NAME";
	gotoxy(43,4);cout<<"CLASS";
	gotoxy(58,4);cout<<"CLUB NAME";
	gotoxy(3,5);cout<<"============================================================================";
	gotoxy(5,row);cout<<cid;
	gotoxy(27,row);cout<<name;
	gotoxy(45,row);cout<<cls;
	gotoxy(60,row);cout<<clubname;
}
//-----------------------------------------------------------------------------------------------------------------//
void addnew()
{
	fstream fin,fin1; club c2;
	char ch='y'; int found;
	fin.open("Member.dat",ios::in|ios::binary);
	while(ch=='y'|| ch=='Y')
	{
		clrscr(); border();
		c.getdata();
		while(fin)
		{
			found=0;
			fin.read((char*)&c2,sizeof(c2));
			if(fin.eof())
				break;
			else if(c2.retid() == c.retid())
			{
				gotoxy(8,15);cout<<"Sorry, the club id already exists!! Please try again.";
				found=1;
				getch();
				break;
			}
		}
		fin.close();
		if(found==0)
		{
			fin1.open("Member.dat",ios::app|ios::binary);
			fin1.write((char*)&c,sizeof(c));
			gotoxy(8,14);cout<<"New member added successfully!!";
			fin1.close();
		}
		gotoxy(8,16);cout<<"Do you want to add more ? (y/n) : ";
		cin>>ch;
	}
	getch();
	int l,j,i=0;
	club arr[20];
	fstream f1;
	f1.open("Member.dat",ios::in|ios::binary);
	while(f1)
	{
		f1.read((char*)&arr[i],sizeof(arr[i]));
		if(f1.eof())
			break;
		++i;
	}
	f1.close();
	club c1;
	for(l=0;l<(i-1);++l)
	{
		for(j=0;j<(i-l-1);++j)
		{
			if(arr[j].retid()>arr[j+1].retid())
			{
				c1=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=c1;
			}
		}
	}
	ofstream f;
	f.open("Member.dat",ios::out|ios::binary);
	for(int k=0;k<i;++k)
		f.write((char*)&arr[k],sizeof(c1));
	f.close();
}
void leaveclub()
{
	clrscr(); border();
	ifstream fin("Member.dat", ios::in|ios::binary);
	ofstream fout("Member2.dat", ios::out|ios::binary);
	int tclubid, found=0;
	gotoxy(5,6);cout<<"Enter the club id of the person leaving = ";
	cin>>tclubid;
	while(fin)
	{
		fin.read((char*)&c, sizeof(c));
		if(fin.eof())
			break;
		if(c.retid()==tclubid)
			found=1;
		else
			fout.write((char*)&c, sizeof(c));
	}
	if(found==0)
	{
		gotoxy(5,18);cout<<"Record not found!!";
	}
	else
	{
		gotoxy(5,18);cout<<"Record deleted successfully!!";
	}
	fin.close();
	fout.close();
	remove("Member.dat");
	rename("Member2.dat","Member.dat");
	getch();
}
void modify_details()
{
	clrscr(); boundary();
	fstream f;
	f.open("Member.dat",ios::in|ios::out|ios::binary);
	int tcls,tid, found=0, row=6, ch=0, tt=0;
	char tcname[60],tname[60];
	gotoxy(5,6);cout<<"Please enter the club ID : ";
	cin>>tid;
	clrscr();
	while(f)
	{
		f.read((char*)&c,sizeof(c));
		tt++;
		if(f.eof())

			break;
		if(c.retid()==tid)
		{
			found=1;
			c.putdata(row);
			getch();
			break;
		}
	}
	if(found==0)
		{ gotoxy(7,20);cout<<"Sorry, no record found!!"; return;}
	while(ch!=4)
	{
		clrscr(); border();
		gotoxy(5,7);cout<<"What do you wish to edit in here?";
		gotoxy(6,9);cout<<"1. Name";
		gotoxy(6,10);cout<<"2. Class";
		gotoxy(6,11);cout<<"3. Club Name";
		gotoxy(6,12);cout<<"4. Exit to Main menu";
		gotoxy(5,13);cout<<"Enter your choice here : "; cin>>ch;
		switch(ch)
		{
			case 1 : clrscr(); border();
				 gotoxy(6,6);cout<<"Enter the new name : ";
				 gets(tname);
				 c.change_name(tname);
				 f.seekp(((tt-1)*sizeof(c)),ios::beg);
				 f.write((char*)&c,sizeof(c));
				 gotoxy(5,10);cout<<"Name changed successfully!!";
				 getch();
				break;
			case 2 : clrscr(); border();
				 gotoxy(6,6);cout<<"Enter the new class : ";
				 cin>>tcls;
				 c.change_cls(tcls);
				 f.seekp(((tt-1)*sizeof(c)),ios::beg);
				 f.write((char*)&c,sizeof(c));
				 gotoxy(5,10);cout<<"Class updated successfully!!";
				  getch();
				break;
			case 3 : clrscr(); border();
				 gotoxy(6,6);cout<<"Enter the new club name : ";
				gets(tcname);
				c.change_cname(tcname);
				f.seekp(((tt-1)*sizeof(c)),ios::beg);
				f.write((char*)&c,sizeof(c));
				gotoxy(5,10);cout<<"Club name modified successfully!!";
				getch();
				break;
		}
	}
	f.close();
	getch();
}
void search_name()
{

	clrscr(); border();
	ifstream f;
	char sname[10]; int found=0, row=6;
	gotoxy(5,5);cout<<"Enter name of the member to be searched :";
	gets(sname);
	f.open("Member.dat",ios::in|ios::binary);
	while(f)
	{
		f.read((char*)&c,sizeof(c));
		if(f.eof())
			break;
		else if(strcmpi(sname,c.retname())==0)
		{
			found=1;
			c.putdata(row);
			row=row+2;
			if(row==20)
			{
				gotoxy(6,23);cout<<"Press Enter to continue to next page.";
				clrscr();
				row=6;
				getch();
			}
		}
	}
	if(found==0)
	{
		gotoxy(6,13);cout<<"Sorry no record found!!!";
	}
	f.close();
	getch();
}
void search_cid()
{
	clrscr(); border();
	ifstream f;
	int tcid, found=0,row=6;
	gotoxy(5,5);cout<<"Enter Club ID : ";
	cin>>tcid;
	f.open("Member.dat",ios::in|ios::binary);
	while(f)
	{
		f.read((char*)&c,sizeof(c));
		if(f.eof())
			break;
		else if(c.retid()==tcid)
		{
			found=1;
			c.putdata(row);
			row=row+2;
			if(row==22)
			{
				clrscr();
				row=6;
				getch();
			}
		}
	}
	f.close();
	if(found==0)
	{ gotoxy(6,13);cout<<"Sorry no record found!!!"; }
	getch();
}
void search_cname()
{
	clrscr(); border(); ifstream f;
	char tcname[40]; int found=0, row=6;
	gotoxy(3,4);cout<<"Enter the club name of the person : ";
	gets(tcname);
	clrscr();
	f.open("Member.dat",ios::in|ios::binary);
	while(f)
	{
		f.read((char*)&c,sizeof(c));
		if(f.eof())
			break;
		else if(strcmpi(tcname,c.retcname())==0)
		{
			found=1;
			c.putdata(row);
			row=row+2;
			if(row==23)
			{
				gotoxy(6,23);cout<<"Press Enter to continue to next page.";
				clrscr();
				row=6;
				getch();
			}
		}
	}
	f.close();
	if(found==0)
	{ gotoxy(6,13);cout<<"Sorry no record found in club "<<tcname;	}
	getch();
}
void show_all()
{
	clrscr(); border();
	int x,y,z,row=6; ifstream f;
	f.open("Member.dat",ios::binary);
	while(f)
	{
		f.read((char*)&c,sizeof(c));
		if(f.eof())
			break;
		c.putdata(row);
		row=row+2;
		if(row==22)
		{
			gotoxy(6,23);cout<<"Press Enter to continue to next page.";
			getch();
			clrscr();
			row=6;
		}
	}
	f.close();
	f.open("member.dat",ios::in);
	f.seekg(0,ios::end);
	x=f.tellg();
	y=sizeof(c); z=x/y;
	gotoxy(5,23);cout<<"Total no. of records : "<<z;
	f.close();
	getch();
}
//----------------------------------------Main function-------------------------------------//
void main()
{
	clrscr();home();
	clrscr();boundary();
	int ch=0;
	char pwd[13]={0},temp; int i=0;
	gotoxy(16,12);cout<<"ENTER PASSWORD : ";
	while((temp=getch())!=13)
	{
		pwd[i++]=temp;
		cout<<"*";
	}
	if(strcmp(pwd,"sahnidas98")==0)
	{
		gotoxy(15,15);cout<<"Access granted !!!";
		getch();
	}
	else
	{
		gotoxy(15,15);cout<<"Password wrong!!! Exiting...";
		getch(); exit(0);
	}
	while(ch!=6)
	{
		clrscr(); boundary();
		gotoxy(21,6);cout<<"WELCOME TO SILVER DOLLAR CLUB !!!";
		gotoxy(20,8);cout<<"Please choose from the following options :- ";
		gotoxy(25,11);cout<<"1. Add new member";
		gotoxy(25,12);cout<<"2. Search the clubs";
		gotoxy(25,13);cout<<"3. Modify details";
		gotoxy(25,14);cout<<"4. Delete record";
		gotoxy(25,15);cout<<"5. Show records";
		gotoxy(25,16);cout<<"6. Exit";
		gotoxy(27,19);cout<<"Enter choice = ";cin>>ch;
		switch(ch)
		{
			case 1 : addnew();
				break;
			case 2 : int s=0;
				 while(s!=4)
				 {
					clrscr(); boundary();
					gotoxy(17,6);cout<<"Search on the basis of following :- ";
					gotoxy(22,8);cout<<"1. Search by Name";
					gotoxy(22,10);cout<<"2. Search by Club Name";
					gotoxy(22,12);cout<<"3. Search by Club ID";
					gotoxy(22,14);cout<<"4. Exit Search menu";
					gotoxy(22,16);cout<<"Enter choice : ";cin>>s;
					switch(s)
					{
						 case 1 : search_name();
						 break;
						 case 2 : search_cname();
						 break;
						 case 3 : search_cid();
						 break;
					}
				 }
				 break;
			case 3 : modify_details();
			       break;
			case 4 : leaveclub();
				break;
			case 5 : show_all();
				break;
			case 6 : exit(0);
		}

	}
}
//-------------------------------------------------------T H E -- E N D-----------------------------------------------------------------//

