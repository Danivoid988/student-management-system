#include <iostream>
#include <conio.h>
#include <string.h>
#include <iomanip>
using namespace std;
class Abstract
{
public:
	virtual void login() = 0;
};
class Signin: public Abstract
{
public:
	void login()
	{
		
			int a = 0, i = 0;
			char uname[10], c = ' ';
			char pword[10], code[10];
			char user[10] = "user";
			char pass[10] = "pass";
			do
			{

				cout << "\n -----------------------LOGIN FIRST-----------------    ";
				cout << " \n\n                  ENTER USERNAME:=";
				cin >> uname;
				cout << " \n\n                  ENTER PASSWORD:=";
				while (i<10)

				{
					pword[i] = _getch();
					c = pword[i];
					if (c == 13)
						break;
					else cout << "*";
					i++;
				}
				pword[i] = '\0';

				i = 0;

				if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
				{
					cout << "  \n\n\n       WELCOME TO STUDENT MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL";
					cout << "\n\n\n\t\t\t\tPress any key to continue...";
					_getch();
					break;
				}
				else
				{
					cout << "\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
					a++;

					_getch();

				}
			} while (i < 10);
		}
	
};
class student
{
private:
	int rollno;
	char name[20];
	char gender;
	int age;
	int semester;
	float marks;


public:
	student()
	{
		rollno = 0;
		strcpy_s(name, "NONAME");
		gender = '-';
		age = 0;
		marks = 0;
		semester = 0;
		cout << "Default Consructor invoked" << endl;
	}
	student(int x, char n[20], char g, int y, float s, int z)
	{
		rollno = x;
		strcpy_s(name, n);
		gender = g;
		age = y;
		marks = s;
		semester = z;
		cout << "Parameterized Consructor invoked" << endl;
	}

	int getRollNo()
	{
		return rollno;
	}

	char *getname()
	{
		return name;
	}
	void get_data()
	{
		cout << "Enter Student Details\n";

		cout << "Enter Roll No: " << endl;
		cin >> rollno;
		cout << "Enter Name: " << endl;
		cin.ignore();
		cin.getline(name, 20);
		cout << "Enter Gender(M for Male/ F for female): " << endl;
		cin >> gender;
		cout << "Enter Age: " << endl;
		cin >> age;
		cout << "Enter Semester: " << endl;
		cin >> semester;
	}

	void modify_data()
	{
		cout << "Enter Roll No: " << rollno << endl;
		cout << "Modify Student Details\n";
		cout << "Enter Name: " << endl;
		cin.ignore();
		cin.getline(name, 20);
		cout << "Enter Gender(M for Male/ F for female): " << endl;
		cin >> gender;
		cout << "Enter Age: " << endl;
		cin >> age;
		cout << "Enter Semester: " << endl;
		cin >> semester;
	}
	void show_data()
	{
		cout << "Student Details\n";
		cout << "Roll No: " << rollno << endl;
		cout << "Name: " << name << endl;
		cout << "Gender: " << gender << endl;
		cout << "Age: " << age << endl;
		cout << "Semester: " << semester << endl;


	}


	void listData()
	{
		cout.setf(ios::left);
		cout << setw(10) << rollno;
		cout << setw(10) << name;
		cout << setw(10) << gender;
		cout << setw(10) << age;
		cout << setw(10) << semester;
		cout << endl;
		//system("pause");
	}

};

/*void login()
{
	int a = 0, i = 0;
	char uname[10], c = ' ';
	char pword[10], code[10];
	char user[10] = "user";
	char pass[10] = "pass";
	do
	{

		cout << "\n -----------------------LOGIN FIRST-----------------    ";
		cout << " \n\n                  ENTER USERNAME:=";
		cin >> uname;
		cout << " \n\n                  ENTER PASSWORD:=";
		while (i<10)

		{
			pword[i] = _getch();
			c = pword[i];
			if (c == 13)
				break;
			else cout << "*";
			i++;
		}
		pword[i] = '\0';

		i = 0;

		if (strcmp(uname, "user") == 0 && strcmp(pword, "pass") == 0)
		{
			cout << "  \n\n\n       WELCOME TO STUDENT MANAGEMENT SYSTEM !!!! LOGIN IS SUCCESSFUL";
			cout << "\n\n\n\t\t\t\tPress any key to continue...";
			_getch();
			break;
		}
		else
		{
			cout << "\n        SORRY !!!!  LOGIN IS UNSUCESSFUL";
			a++;

			_getch();

		}
	} while (i < 10);
}*/
void menu()
{
	cout << "STUDENT RECORDS\n";
	cout << "=================\n";
	cout << "0. Exit\n";
	cout << "1. Register New Student\n";
	cout << "2. Show All Students\n";
	cout << "3. Search Student By Roll No\n";
	cout << "4. Search Student By Name\n";
	cout << "5. Modify Record\n";
	cout << "6. Delete Record\n";
	cout << "Enter Your Choice: ";
}

void heading()
{
	cout.setf(ios::left);
	cout << setw(10) << "Roll. ";
	cout << setw(10) << "Name";
	cout << setw(10) << "Gender";
	cout << setw(10) << "Age";
	cout << setw(10) << "Semester";
	cout << endl;
}
int main()
{
	Signin s1;
	s1.login();
	int n = 0, ch, rn, i, flag = 0, pos;
	student s[10];
	do
	{
		system("cls");
		menu();
		cin >> ch;
		switch (ch)
		{
		case 1: s[n].get_data(); n++;
			cout << "\n Record Saved successfully.....\n";
			break;
		case 2:
			if (n > 0)
			{
				heading();
				for (i = 0; i < n; i++)
				{
					s[i].listData();
					_getch();

				}
			}
			else
			{
				cout << "\n No Record Found....\n";
				_getch();
			}

			break;
		case 3:

			if (n > 0)
			{
				cout << "Enter Roll Number to print: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getRollNo())
					{
						s[i].show_data();
						flag++;
						_getch();
					}

				}
			}
			else
			{
				cout << "\n No Record Found....\n";
				_getch();
			}
			if (flag == 0)
			{
				cout << "\n No Entity Found by this name.....\n ";
				_getch();
			}
			break;

		case 4:

			if (n > 0)
			{
				char nm[20];
				cout << "Enter Name to print: ";
				cin >> nm;
				for (i = 0; i < n; i++)
				{
					if (strcmp(nm, s[i].getname()) == 0)
					{
						s[i].show_data();
						flag++;
						_getch();
					}
				}
			}
			else
			{
				cout << "\n No Record Found....\n";
				_getch();
			}
			if (flag == 0)
			{
				cout << "\n No Entity Found by this name.....\n ";
				_getch();
			}
			break;

		case 5:

			if (n > 0)
			{
				cout << "Enter Roll Number to print: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getRollNo())
					{
						cout << "Following record will be modified.....\n";
						s[i].show_data();

						cout << "\n Enter New Data\n";

						s[i].modify_data();
						flag++;
						_getch();
					}

				}

			}

			else
			{
				cout << "\n No Record Found....\n";
				_getch();
			}
			if (flag == 0)
			{
				cout << "\n No Entity Found by this name.....\n ";
				_getch();
			}
			break;
		case 6:

			if (n > 0)
			{
				cout << "Enter Roll Number to Delete: ";
				cin >> rn;
				for (i = 0; i < n; i++)
				{
					if (rn == s[i].getRollNo())
					{
						cout << "Following Record is Deleted....\n";
						s[i].show_data();
						flag++;
						pos = i;
						_getch();
						break;

					}
					for (i = pos; i < n; i++)
					{
						s[i] = s[i + 1];
						_getch();
					}
					n--;

				}
			}
			else
			{
				cout << "\n No Record Found....\n";
				_getch();
			}
			if (flag == 0)
			{
				cout << "\n No Entity Found by this name.....\n ";
				_getch();
			}
			break;
		}
	} while (ch);

	system("pause");
	return 0;


}
