/*
COMPUTER SCIENCE PROJECT

NAME OF PROJECT:
RN JEWELLERS

AUTHORS:
ROHAN GUPTA - XII C
AMAN ARORA - XII C

TEACHER INCHARGE:
MRS. RITU NAGPAL

*/

#include <fstream>
#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <process.h>
#include <string.h>
#include <ctype.h>
using namespace std;

class mainmenu
{
public:
	void menu();
	void menu2();
	void menu3();
};
class employee
{
	char ename[100], eaddress[100];
	long int esalary, eid;
	long int eno;
	void edisplay();
	void eview();
	void eedit();

public:
	void eenter();
	void emenu();
};
class customer
{
	char cname[100], caddress[100];
	long int cno;
	void cview();
	void cedit();

public:
	long int cid;
	void cdisplay();
	void center();
	void cmenu();
};
class item
{
	char icategory[100], itype[100];
	float iweight, ino, inetprice, itax, igrandtotal, imakingcharge, irate, itotal;

public:
	void iview();
	void ienter();
	void idisplay();
	void igenerate();
	void iprice();
};
void create(char *filename)
{
	fstream f;
	if (strcmpi(filename, "customer.dat") == 0)
	{
		customer c;
		f.open("customer.dat", ios::app | ios::binary);
		c.center();
		f.write((char *)&c, sizeof(c));
		f.close();
	}
	else if (strcmpi(filename, "employee.dat") == 0)
	{
		employee e;
		f.open("employee.dat", ios::app | ios::binary);
		e.eenter();
		f.write((char *)&e, sizeof(e));
		f.close();
		e.emenu();
	}
}
int main()
{
	mainmenu m;
	m.menu();
	getch();
	return 0;
}
void mainmenu::menu()
{
	int ch1;
	system("cls");
	//(33,3);
	cout << "R.N. JEWELLERS" << endl;
	//(36,11);
	cout << "1. ADMIN" << endl;
	//(36,13);
	cout << "2. USER" << endl;
	//(36,15);
	cout << "3. EXIT" << endl;
	//(33,22);
	cout << "enter your choice: ";
	cin >> ch1;
	item i;
	switch (ch1)
	{
	case 1:
		system("cls");
		char p1, p2;
		//(33,10);
		cout << "Enter password: ";
		p1 = getch();
		cout << "*";
		p2 = getch();
		cout << "*";
		if (((p1 == 'R') || (p1 == 'r')) && ((p2 == 'N') || (p2 == 'n')))
		{
			menu2();
		}
		else
		{
			//(33,15);
			cout << "wrong password";
			getch();
			mainmenu::menu();
		}
		break;
	case 2:
		menu3();
		break;
	case 3:
		exit(0);
	default:
		cout << "enter from '1' to '3'";
		getch();
		mainmenu::menu();
	}
}
void mainmenu::menu2()
{
	system("cls");
	int ch2;
	customer c;
	employee e;
	item i;
	//(30,8);
	cout << "1. CUSTOMER";
	//(30,10);
	cout << "2. EMPLOYEE";
	//(30,12);
	cout << "3. STOCK DETAILS";
	//(30,14);
	cout << "4. GENERATE BILL";
	//(30,16);
	cout << "5. RETURN TO PREVIOUS MENU";
	//(30,18);
	cout << "6. EXIT";
	//(30,22);
	cout << "ENTER YOUR CHOICE: ";
	cin >> ch2;
	switch (ch2)
	{
	case 1:
		c.cmenu();
		break;
	case 2:
		e.emenu();
		break;
	case 3:
		i.iview();
		break;
	case 4:
		i.igenerate();
		break;
	case 5:
		mainmenu::menu();
		break;
	case 6:
		exit(0);
	cdefault:
		cout << "enter from '1' to '6'";
		getch();
		mainmenu::menu2();
	}
}
void customer::cmenu()
{
	customer c;
	mainmenu m;
	int chc;
	system("cls");
	//(30,12);
	cout << "1.VIEW CUSTOMER DETAILS";
	//(30,14);
	cout << "2.EDIT CUSTOMER DETAILS";
	//(30,16);
	cout << "3.ADD CUSTOMER";
	//(30,18);
	cout << "4.RETURN TO PREVIOUS MENU";
	//(30,20);
	cout << "5.EXIT";
	//(30,23);
	cout << "ENTER YOUR CHOICE: ";
	cin >> chc;
	switch (chc)
	{
	case 1:
		c.cview();
		customer::cmenu();
		break;
	case 2:
		cedit();
		break;
	case 3:
		create("customer.dat");
		customer::cmenu();
		break;
	case 4:
		m.menu2();
		break;
	case 5:
		exit(0);
	default:
		cout << "enter from '1' to '5'";
		getch();
		customer::cmenu();
	}
}
void employee::emenu()
{
	employee e;
	mainmenu m;
	int chc1;
	system("cls");
	//(30,12);
	cout << "1.VIEW EMPLOYEE DETAILS";
	//(30,14);
	cout << "2.EDIT EMPLOYEE DETAILS";
	//(30,16);
	cout << "3.ADD EMPLOYEE";
	//(30,18);
	cout << "4.RETURN TO PREVIOUS MENU";
	//(30,20);
	cout << "5.EXIT";
	//(30,23);
	cout << "ENTER YOUR CHOICE: ";
	cin >> chc1;
	switch (chc1)
	{
	case 1:
		e.eview();
		employee::emenu();
		break;
	case 2:
		eedit();
		break;
	case 3:
		create("employee.dat");
		employee::emenu();
		break;
	case 4:
		m.menu2();
		break;
	case 5:
		exit(0);
	default:
		cout << "enter from '1' to '5'";
		getch();
		employee::emenu();
	}
}
void mainmenu::menu3()
{
	system("cls");
	item i;
	int chc2;
	system("cls");
	//(30,8);
	cout << "1. SHOP DETAILS";
	//(30,10);
	cout << "2. STOCK DETAILS";
	//(30,12);
	cout << "3. RETURN TO PREVIOUS MENU";
	//(30,14);
	cout << "4. EXIT";
	//(30,22);
	cout << "ENTER YOUR CHOICE: ";
	cin >> chc2;
	switch (chc2)
	{
	case 1:
		system("cls");
		//(25,2);
		cout << "RN JEWELLERS";
		//(25,5);
		cout << "PARTNERS:";
		//(25,6);
		cout << "ROHAN GUPTA";
		//(25,7);
		cout << "AMAN ARORA";
		//(25,9);
		cout << "ADDRESS:";
		//(25,10);
		cout << "1, ASHOK PLACE";
		//(25,11);
		cout << "BHAI VIR SINGH MARG";
		//(25,12);
		cout << "NEAR GOLE DAKHANA";
		//(25,13);
		cout << "NEW DELHI-110001";
		//(25,15);
		cout << "CONTACT:";
		//(25,16);
		cout << "+91 98713 43423";
		break;
	case 2:
		i.iview();
		break;
	case 3:
		mainmenu::menu();
	case 4:
		exit(0);
	default:
		cout << "enter from '1' to '4'";
		getch();
		mainmenu::menu3();
	}
}
void customer::cview()
{
	customer c;
	fstream file;
	file.open("customer.dat", ios::in | ios::binary);
	int x, ff;
	ff = 1;
	system("cls");
	cout << "ENTER CUSTOMER ID: ";
	cin >> x;
	file.seekg(0);
	while (!file.eof())
	{
		file.read((char *)&c, sizeof(c));
		if (c.cid == x)
		{
			c.cdisplay();
			ff = -1;
			break;
		}
	}
	if (ff == 1)
		cout << "not found";
	file.close();
	getch();
}
void employee::eview()
{
	employee e;
	fstream file;
	file.open("employee.dat", ios::in | ios::binary);
	int x, ff;
	ff = 1;
	system("cls");
	cout << "ENTER EMPLOYEE ID: ";
	cin >> x;
	file.seekg(0);
	while (!file.eof())
	{
		file.read((char *)&e, sizeof(e));
		if (e.eid == x)
		{
			e.edisplay();
			ff = -1;
			break;
		}
	}
	if (ff == 1)
		cout << "not found";
	file.close();
	getch();
}
void customer::cdisplay()
{
	cout << "\nCUSTOMER NAME: ";
	cout << cname;
	cout << "\nCUSTOMER NO.: ";
	cout << cno;
	cout << "\nCUSTOMER ADDRESS: ";
	cout << caddress;
	cout << "\nCUSTOMER ID: ";
	cout << cid;
}
void employee::edisplay()
{
	cout << "\nEMPLOYEE NAME: ";
	cout << ename;
	cout << "\nEMPLOYEE NO.: ";
	cout << eno;
	cout << "\nEMPLOYEE ADDRESS: ";
	cout << eaddress;
	cout << "\nEMPLOYEE ID: ";
	cout << eid;
	cout << "\nEMPLOYEE SALARY: ";
	cout << esalary;
}
void customer::cedit()
{
	customer c;
	fstream file;
	file.open("customer.dat", ios::in | ios::out | ios::binary);
	int x = 0, fff = 0, i = 0;
	char ccd[4];
	system("cls");
	cout << "ENTER CUSTOMER ID: ";
	cin >> x;
	while (!file.eof())
	{
		file.read((char *)&c, sizeof(c));
		if (file.eof())
			break;
		i++;
		if (c.cid == x)
		{
			file.seekg((i - 1) * sizeof(c), ios::beg);
			c.center();
			file.write((char *)&c, sizeof(c));
			fff = 1;
			x = 0;
			break;
		}
	}
	if (fff == 0)
		cout << "not found\n";
	file.close();
	cout << "do you want to edit more? (yes/no) ";
	gets(ccd);
	if (strcmpi(ccd, "yes") == 0)
		c.cedit();
	getch();
	c.cmenu();
}
void employee::eedit()
{
	employee e;
	fstream file;
	file.open("employee.dat", ios::in | ios::out | ios::binary);
	int x = 0, fff = 0, i = 0;
	char ccd[4];
	system("cls");
	cout << "ENTER EMPLOYEE ID: ";
	cin >> x;
	while (!file.eof())
	{
		file.read((char *)&e, sizeof(e));
		if (file.eof())
			break;
		i++;
		if (e.eid == x)
		{
			file.seekg((i - 1) * sizeof(e), ios::beg);
			e.eenter();
			file.write((char *)&e, sizeof(e));
			fff = 1;
			x = 0;
			break;
		}
	}
	if (fff == 0)
		cout << "not found\n";
	file.close();
	cout << "do you want to edit more? (yes/no) ";
	gets(ccd);
	if (strcmpi(ccd, "yes") == 0)
		e.eedit();
	getch();
	e.emenu();
}
void customer::center()
{
	system("cls");
	//(30,10);
	cout << "ENTER NAME: ";
	gets(cname);
	//(30,12);
	cout << "ENTER NO.: ";
	cin >> cno;
	//(30,14);
	cout << "ENTER ADDRESS: ";
	gets(caddress);
	//(30,16);
	cout << "ENTER ID: ";
	cin >> cid;
}
void employee::eenter()
{
	system("cls");
	//(30,10);
	cout << "ENTER NAME: ";
	gets(ename);
	//(30,12);
	cout << "ENTER NO.: ";
	cin >> eno;
	//(30,14);
	cout << "ENTER ADDRESS: ";
	gets(eaddress);
	//(30,16);
	cout << "ENTER ID: ";
	cin >> eid;
	//(30,18);
	cout << "ENTER SALARY: ";
	cin >> esalary;
}
void item::iview()
{
	item i;
	mainmenu m;
	char chch;
	cout << "do you want to enter any new stock? (y/n) : ";
	cin >> chch;
	if (chch == 'y')
		i.ienter();
	fstream file;
	file.open("items.dat", ios::in | ios::binary);
	file.seekg(0);
	while (!file.eof())
	{
		file.read((char *)&i, sizeof(i));
		if (file.eof())
			break;
		i.idisplay();
	}
	file.close();
	getch();
	m.menu2();
}
void item::idisplay()
{
	cout << "\nITEM CATEGORY: ";
	cout << icategory;
	cout << "\nITEM TYPE: ";
	cout << itype;
	cout << "\nITEM NO: ";
	cout << ino;
	cout << "\nITEM WEIGHT: ";
	cout << iweight;
}
void item::ienter()
{
	item i;
	fstream file;
	file.open("items.dat", ios::binary | ios::app);
	system("cls");
	cout << "ENTER CATEGORY (GOLD,SILVER,PLATINUM): ";
	cin >> icategory;
	cout << endl
		 << "ENTER THE TYPE OF JEWELLERY: ";
	cin >> itype;
	cout << endl
		 << "ENTER THE TOTAL NO. OF JEWELLERY: ";
	cin >> ino;
	cout << endl
		 << "ENTER THE TOTAL WEIGHT OF JEWELLERY: ";
	cin >> iweight;
	file.write((char *)&i, sizeof(i));
	file.close();
}
void item::igenerate()
{
	mainmenu m;
	iprice();
	customer c;
	fstream file;
	file.open("customer.dat", ios::in | ios::binary);
	int chah;
	cout << "enter customer id: ";
	cin >> chah;
	while (!file.eof())
	{
		file.read((char *)&c, sizeof(c));
		if (file.eof())
			break;
		if (c.cid == chah)
			c.cdisplay();
	}
	file.close();
	getch();
	m.menu2();
}
void item::iprice()
{
	create("customer.dat");
	item i;
	fstream file;
	file.open("items.dat", ios::binary | ios::app);
	system("cls");
	cout << "ENTER CATEGORY (GOLD,SILVER,PLATINUM): ";
	cin >> icategory;
	cout << endl
		 << "ENTER THE TYPE OF JEWELLERY: ";
	cin >> itype;
	cout << endl
		 << "ENTER THE TOTAL NO. OF JEWELLERY: ";
	cin >> ino;
	cout << endl
		 << "ENTER THE TOTAL WEIGHT OF JEWELLERY: ";
	cin >> iweight;
	file.write((char *)&i, sizeof(i));
	file.close();
	if (strcmpi(icategory, "gold") == 0)
	{
		irate = 3650;
		inetprice = ino * irate * iweight;
		imakingcharge = .15 * irate;
	}
	else if (strcmpi(icategory, "silver") == 0)
	{
		irate = 48;
		inetprice = ino * irate * iweight;
		imakingcharge = 7 * irate;
	}
	else if (strcmpi(icategory, "platinum") == 0)
	{
		irate = 2700;
		inetprice = ino * irate * iweight;
		imakingcharge = .15 * irate;
	}
	itotal = inetprice + imakingcharge;
	itax = 0.03 * itotal;
	igrandtotal = itax + itotal;
	cout << "NET PRICE: ";
	cout << inetprice << endl;
	cout << "MAKING CHARGE: ";
	cout << imakingcharge << endl;
	cout << "TAX: ";
	cout << itax << endl;
	cout << "GRAND TOTAL: ";
	cout << igrandtotal << endl;
}