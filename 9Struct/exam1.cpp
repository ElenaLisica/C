#include<iostream>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>

using namespace std;
#define tabl1 cout<<" "<<trucks_arr[i].ovner<<"\t       "<<trucks_arr[i].model<<"\t\t        "<<trucks_arr[i].carrying	<<"\t       "<<trucks_arr[i].color<<" \t     "<<trucks_arr[i].Release_Date<<"\t   "<<trucks_arr[i].adress<<"  \t    " << trucks_arr[i].license_plate << endl;
#define tabl2 cout<<" "<<result_serch[i].ovner<<"\t       "<<result_serch[i].model<<"\t\t        "<<result_serch[i].carrying	<<"\t       "<<result_serch[i].color<<" \t     "<<result_serch[i].Release_Date<<"\t   "<<result_serch[i].adress<<"  \t    " << result_serch[i].license_plate << endl;
#define tabl3 cout<<" "<<cars_arr[i].ovner<<"   \t    "<<cars_arr[i].model<<"  \t   "<<cars_arr[i].color<<" \t    "<<cars_arr[i].Release_Date<<"\t"<<cars_arr[i].adress<<"    \t " << cars_arr[i].license_plate << endl;
#define tabl4 cout<<" "<<result_serch1[i].ovner<<"   \t    "<<result_serch1[i].model<<"  \t   "<<result_serch1[i].color<<" \t    "<<result_serch1[i].Release_Date<<"\t"<<result_serch1[i].adress<<"    \t " << result_serch1[i].license_plate << endl;

/////////////////////////////////////////////////////////////////
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}
/////////////////////////////////////////////////////////////////////////////////////
struct trucks
{
	char ovner[30];
	char model[20];
	double carrying;
	char color[20];
	int Release_Date;
	char adress[30];
	int license_plate;
};
struct cars
{
	char ovner[30];
	char model[20];
	char color[20];
	int Release_Date;
	char adress[30];
	int license_plate;
};
/////////////////////////////////////////////////////////////////////////////////////
int ovner = 9, ovner_1 = 9,ovner_rez=0;
char choice;//��� ������ ������ ������
trucks* trucks_arr = new trucks[ovner];
trucks* result_serch = new trucks[ovner];
cars* cars_arr = new cars[ovner_1];
cars* result_serch1 = new cars[ovner_1];
////////////////////////////////////////////////////////////////////
//////////////    ������� �������� �����������       //////////////
//////////////////////////////////////////////////////////////////
void Menu_t();//���� �������� �����������
char Sort_menu();//���� ������ ����������
void Sort_trucks();//���������� ���������� ������
trucks* Input_mas();//��������� ����������� ������
trucks* FindName();//����� �� �������
trucks* FindModel();//����� �� ������ ����
trucks* FindCarrying();//����� �� ����������������
trucks* FindColor();//����� �� �����
trucks* FindRelease_Date();//����� �� ���� �������
trucks* FindAdress();//����� �� �������
trucks* FindLicense_plate();//����� �� ��� ������
void AddElements();//���������� ��������� � ������
void Set_new_element(trucks* mas_trucks, const int amount);//���� ������ �������� � ������
trucks* Add(trucks* arr, const int amount);//���������� ������������� ������� ���������
void sort(trucks mas_trucks[], int choice);//���������� �������
char Find_menu();//���� ������
void Find_trucks();//���������� ������
void menu_Find_trucks(char choice);
void Rez();
////////////////////////////////////////////////////////////////////
//////////////    ������� �������� �����������       //////////////
//////////////////////////////////////////////////////////////////
void Menu_c();//���� �������� �����������
char Sort_menu();//���� ������ ����������
void Sort_cars();//���������� ���������� ������
cars* Input_mas_1();//��������� ����������� ������
cars* FindName_1();//����� �� �������
cars* FindModel_1();//����� �� ������ ����
cars* FindColor_1();//����� �� �����
cars* FindRelease_Date_1();//����� �� ���� �������
cars* FindAdress_1();//����� �� �������
cars* FindLicense_plate_1();//����� �� ��� ������
void AddElements_1();//���������� ��������� � ������
void Set_new_element_1(cars* mas_cars, const int amount);//���� ������ �������� � ������
cars* Add_1(cars* arr, const int amount);//���������� ������������� ������� ���������
void sort_1(cars mas_cars[], char choice);//���������� �������
char Find_menu_1();//���� ������
void Find_cars();//���������� ������
void menu_Find_cars(char choice);
void Rez_1();
///////////////////////////////////////////////////////////////////////////////////////////////
void watch(int ovner)
{
	cout << "� | ��� ���������  |  ������ ���������� | ����������������(�)|  ����      | ��� ������� |  ������         | ���.�����|\n";
	for (int i = 0; i < ovner; i++)
	{
		cout << i + 1 << ".";tabl1;
	}
}

void watch_rezult(int ovner_rez)
{
	cout << "� | ��� ���������  |  ������ ���������� | ����������������(�)|  ����      | ��� ������� |  ������         | ���.�����|\n";
	for (int i = 0; i < ovner_rez; i++)
	{
		cout << i + 1 << "."; tabl2;
	}
}

void watch_1(int ovner1)
{
	cout << "� | ��� ���������  |  ������ ���������� |  ����      | ��� ������� |    ������       | ���.�����|\n";
	for (int i = 0; i < ovner_1; i++)
	{
		cout << i + 1 << "."; tabl3;
	}
}

void watch_rezult_1(int ovner_rez)
{
	cout << "� | ��� ���������  |  ������ ���������� |  ����      | ��� ������� |    ������       | ���.�����|\n";
	for (int i = 0; i < ovner_rez; i++)
	{
		cout << i + 1 << "."; tabl4;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////
void main()
{
	/*setlocale(LC_CTYPE, "rus");*/
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	trucks_arr = Input_mas();
	cars_arr = Input_mas_1();
	do
	{
		system("cls");
		cout << "\n\t\t���������� ��� ������" << endl;
		cout << "\n\t1 - ���� �������� ���������� \n\t2 - ���� �������� ���������� \n\t3 - ����� �� ���������" << endl;
		cout << "\n\t�������� ���� ����� - " ;
		cin>>choice;
		switch (choice)
		{
		case '1':
			Menu_t();
			break;
		case '2':
			Menu_c();
			break;
		}
	} while (choice != '3');

	system("cls");
	
}

void Menu_t()
{
	do
	{
		system("CLS");
	cout << "\t\t�������� ����������" << endl;
	cout << "\t1 - �������� ��� ������ ������� " << "'" << "�������� ����������" << "'" << endl;
	cout << "\t2 - ���� ����������" << endl;
	cout << "\t3 - ���� ������" << endl;
	cout << "\t4 - �������� ������" << endl;
	cout << "\t5 - ����� � ���������� ����\n" << endl;
	cout << "\t����� - " ;
	cin >> choice;
	switch (choice)
	{
	case '1':
		system("CLS");
		GotoXY(22, 0);
		cout << "\t��� ������ ������� " << "'" << "�������� ����������" << "'\n" << endl;
		watch(ovner);
		cout << "\n\n\t��� �������� � ���� ������� ����� ������� ";
		_getch();
		break;
	case '2':
		system("CLS");
		cout << "\t ���� ����������\n" << endl;
		Sort_trucks();
		break;
	case '3':
		system("CLS");
		cout << "\t ���� ������\n" << endl;
		Find_trucks();
		break;
	case '4':
		system("CLS");
		cout << "\t���������� ����� ������ ";
		AddElements();
		break;
	}
	} while (choice !='5');
}
///////////////////////////////////////////////
char Sort_menu()
{
	cout << "\n\t���������� ��:" << endl;
	cout << "\t1 - ��� ���������" << endl;
	cout << "\t2 - ������ ����������" << endl;
	cout << "\t3 - ����������������" << endl;
	cout << "\t4 - �����" << endl;
	cout << "\t5 - ���� �������(�� �����������)" << endl;
	cout << "\t6 - �������" << endl;
	cout << "\t7 - ���������(�� �����������)" << endl;
	cout << "\t8 - ����� � ���������� ����" << endl;
	cout << "\t�����: " ;
	cin >> choice;

	return choice;
}
/////////////////////////////////////////////
void Sort_trucks()
{
	system("cls");
	char a;
	do
	{
		watch(ovner);
		a = Sort_menu();
		sort(trucks_arr, a);
		system("cls");
	} while (a != '8');
}
//////////////////////////////////////////////////////////////////////
void Set_new_element(trucks* mas_trucks, const int amount)
{
	cin.ignore();
	cout << "������� ������� � �������� ��������� - ";
	cin.getline(mas_trucks[amount].ovner,30);
	cout << "������� ������ ���������� - ";
	cin >> mas_trucks[amount].model;
	cout << "������� ���������������� - ";
	cin >> mas_trucks[amount].carrying;
	cout << "������� ���� - ";
	cin >> mas_trucks[amount].color;
	cout << "������� ��� ������� - ";
	cin >> mas_trucks[amount].Release_Date;
	cout << "������� ����� ����������� - ";
	cin >> mas_trucks[amount].adress;
	cout << "������� ��� ����� (5 ����) - ";
	cin >> mas_trucks[amount].license_plate;
}
/////////////////////////////////////////////////////////////////////
void sort(trucks mas_trucks[], int choice)
{
	int go = 0, n = ovner;
	while (go < n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (choice == '1')
				{
					if (_strnicmp(mas_trucks[j].ovner, mas_trucks[i].ovner, 2) < 0)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '2')
				{
					if (_strnicmp(mas_trucks[j].model, mas_trucks[i].model, 2) < 0)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '3')
				{
					if (mas_trucks[j].carrying < mas_trucks[i].carrying)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '4')
				{
					if (_strnicmp(mas_trucks[j].color, mas_trucks[i].color, 2) < 0)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '5')
				{
					if (mas_trucks[j].Release_Date < mas_trucks[i].Release_Date)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '6')
				{
					if (_strnicmp(mas_trucks[j].adress, mas_trucks[i].adress, 2) < 0)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				if (choice == '7')
				{
					if (mas_trucks[j].license_plate < mas_trucks[i].license_plate)
						swap(mas_trucks[i], mas_trucks[j]);
				}
				i++;
			}
		}
		go++;
	}
}
////////////////////////////////////////////////////////////////////
trucks* Add(trucks* arr, const int amount)
{
	trucks* temp = new trucks[amount + 1];
	for (int i = 0; i < amount; i++)
	{
		temp[i] = arr[i]; // �������� �� ��������� ������
	}
	delete[] arr;
	arr = temp;
	return arr;
}
///////////////////////////////////////////////////////////////////
trucks* Input_mas() //��������� ������������ ������ ����������
{
	trucks* temp = new trucks[ovner];

	trucks f1 = { "������ �.�.","���-52",5.0,"�����",1978,"���������",12589 };
	trucks f2 = { "������ �.�.","�����",8.0,"�����",1977,"���������",75964 };
	trucks f3 = { "������� �.�.","���",7.0,"�������",1983,"������",15632 };
	trucks f4 = { "������ �.�.","���-51",4.5,"�����",1988,"������",12954 };
	trucks f5 = { "���� �.�.","����",7.2,"�����",1985,"����������",12369 };
	trucks f6 = { "����� �.�.","����",10.0,"�����",1987,"�����",24587 };
	trucks f7 = { "������ �.�.","�����",6.8,"�������",1990,"������",15638 };
	trucks f8 = { "���� �.�.","�����",25.0,"������",1993,"����",32587 };
	trucks f9 = { "����� �.�.","���-51",4.2,"�������",1968,"���������",89654 };
	trucks mas_trucks[9] = { f1,f2,f3,f4,f5,f6,f7,f8,f9 };

	for (int i = 0; i < ovner; i++)
	{
		temp[i] = mas_trucks[i]; // �������� �� ��������� ������
	}

	return temp;
}
//////////////////////////////////////////////////////////////////
void AddElements()
{
	int YesOrNot = 0; //  ���������� ��� ���������� ���� ������
	do
	{
		system("cls");
		cout << "\t���� ������ ��������:" << endl << endl;
		trucks_arr = Add(trucks_arr, ovner);
		Set_new_element(trucks_arr, ovner);
		ovner++;
		cout << "\n\t���������� ���� ������ (1 - ��, 0 - ���): ";
		cin >> YesOrNot;
		cin.get();
	} while (YesOrNot != 0);
	
}
//////////////////////////////////////////////////////////////////
trucks* FindName()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3,j=0;
	cout << "������� ���� ������ - ";
	char key[30];
	cin>>key;
	for (int i = 0; i < ovner; i++)
	{
		if ((_strnicmp(key, trucks_arr[i].ovner, maxlen) == 0))
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}	
	result_serch = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
trucks* FindModel()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ���� ������ - ";
	char key[30];
	cin>>key;
	for (int i = 0; i < ovner; i++)
	{
		if ((_strnicmp(key, trucks_arr[i].model, maxlen) == 0))
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
///////////////////////////////////////////////////////////////
trucks* FindCarrying()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ���������������� - ";
	double key;
	cin>>key;
	for (int i = 0; i < ovner; i++)
	{
		if (key==trucks_arr[i].carrying )
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
////////////////////////////////////////////////////////////////
trucks* FindColor()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ���� - ";
	char key[30];
	cin>>key;
	for (int i = 0; i < ovner; i++)
	{
		if ((_strnicmp(key, trucks_arr[i].color, maxlen) == 0))
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
trucks* FindRelease_Date()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ��� ������� - ";
	double key;
	cin >> key;
	for (int i = 0; i < ovner; i++)
	{
		if (key == trucks_arr[i].Release_Date)
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
trucks* FindAdress()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ����� - ";
	char key[30];
	cin>>key;
	for (int i = 0; i < ovner; i++)
	{
		if ((_strnicmp(key, trucks_arr[i].adress, maxlen) == 0))
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
//////////////////////////////////////////////////////////////
trucks* FindLicense_plate()
{
	delete[] result_serch;
	ovner_rez = 0;
	trucks* temp = new trucks[ovner];
	int maxlen = 3, j = 0;
	cout << "������� ��� ����� - ";
	double key;
	cin >> key;
	for (int i = 0; i < ovner; i++)
	{
		if (key == trucks_arr[i].license_plate)
		{
			temp[j] = trucks_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch = temp;
	return 0;
}
/////////////////////////////////////////////////////////////
char Find_menu()
{
	cout << "\n\n\t����� ��:" << endl;
	cout << "\t1 - ��� ���������" << endl;
	cout << "\t2 - ������ ����������" << endl;
	cout << "\t3 - ����������������" << endl;
	cout << "\t4 - �����" << endl;
	cout << "\t5 - ���� �������" << endl;
	cout << "\t6 - �������" << endl;
	cout << "\t7 - ���������" << endl;
	cout << "\t8 - ����� � ���������� ����" << endl;
	cout << "\t�����: ";
	cin >> choice;
	return choice;
}
//////////////////////////////////////////////////////////////
void Find_trucks()
{
	system("cls");
	char a;
	do
	{
		watch(ovner);
		a = Find_menu();
		menu_Find_trucks(a);
		system("cls");
	} while (a != '8');
}
/////////////////////////////////////////////////////////////
void menu_Find_trucks(char choice)
{
	switch (choice)
	{
	case '1':
		{
			system("CLS");
			cout << "\t����� �� ������� ���������" << endl;
			FindName();
			Rez();
			break;
		}
	case '2':
		{
			system("CLS");
			cout << "\t����� �� ������ ����������" << endl;
			FindModel();
			Rez();
			break;
		}
	case '3':
		{
			system("CLS");
			cout << "\t����� �� ����������������" << endl;
			FindCarrying();
			Rez();
			break;
		}
	case '4':
		{
			system("CLS");
			cout << "\t����� �� �����" << endl;
			FindColor();
			Rez();
			break;
		}
	case '5':
		{
			system("CLS");
			cout << "\t����� �� ���� �������" << endl;
			FindRelease_Date();
			Rez();
			break;
		}
	case '6':
		{
			system("CLS");
			cout << "\t����� �� �������" << endl;
			FindAdress();
			Rez();
			break;
		}
	case '7':
		{
			system("CLS");
			cout << "\t����� �� ��� ������" << endl;
			FindLicense_plate();
			Rez();
			break;
		}
	}
}
////////////////////////////////////////////////////////////////
void Rez()
{
	if (ovner_rez == 0)
	{
		system("cls");
		cout << "\n\n\t���������� � ���� �� �������." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\n\t���������� ������:\n" << endl;
		watch_rezult(ovner_rez);
	}
	_getch();
}
////////////////////////////////////////////////////////////////////////////////
void Menu_c()
{
	do
	{
		system("CLS");
		cout << "\t\t�������� ����������" << endl;
		cout << "\t1 - �������� ��� ������ ������� " << "'" << "�������� ����������" << "'" << endl;
		cout << "\t2 - ���� ����������" << endl;
		cout << "\t3 - ���� ������" << endl;
		cout << "\t4 - �������� ������" << endl;
		cout << "\t5 - ����� � ���������� ����\n" << endl;
		cout << "\t����� - ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("CLS");
			GotoXY(22, 0);
			cout << "\t��� ������ ������� " << "'" << "�������� ����������" << "'\n" << endl;
			watch_1(ovner_1);
			cout << "\n\n\t��� �������� � ���� ������� ����� ������� ";
			_getch();
			break;
		case '2':
			system("CLS");
			cout << "\t ���� ����������\n" << endl;
			Sort_cars();
			break;
		case '3':
			system("CLS");
			cout << "\t ���� ������\n" << endl;
			Find_cars();
			break;
		case '4':
			system("CLS");
			cout << "\t���������� ����� ������ ";
			AddElements_1();
			break;
		}
	} while (choice != '5');
}
///////////////////////////////////////////////
char Sort_menu_1()
{
	cout << "\n\t���������� ��:" << endl;
	cout << "\t1 - ��� ���������" << endl;
	cout << "\t2 - ������ ����������" << endl;
	cout << "\t3 - �����" << endl;
	cout << "\t4 - ���� �������(�� �����������)" << endl;
	cout << "\t5 - �������" << endl;
	cout << "\t6 - ���������(�� �����������)" << endl;
	cout << "\t7 - ����� � ���������� ����" << endl;
	cout << "\t�����: ";
	cin >> choice;

	return choice;
}
/////////////////////////////////////////////
void Sort_cars()
{
	system("cls");
	char a;
	do
	{
		watch_1(ovner_1);
		a = Sort_menu_1();
		sort_1(cars_arr, a);
		system("cls");
	} while (a != '7');
}
//////////////////////////////////////////////////////////////////////
void Set_new_element_1(cars* mas_cars, const int amount)
{
	cin.ignore();
	cout << "������� ������� � �������� ��������� - ";
	cin.getline(mas_cars[amount].ovner, 30);
	cout << "������� ������ ���������� - ";
	cin >> mas_cars[amount].model;
	cout << "������� ���� - ";
	cin >> mas_cars[amount].color;
	cout << "������� ��� ������� - ";
	cin >> mas_cars[amount].Release_Date;
	cout << "������� ����� ����������� - ";
	cin >> mas_cars[amount].adress;
	cout << "������� ��� ����� (5 ����) - ";
	cin >> mas_cars[amount].license_plate;
}
/////////////////////////////////////////////////////////////////////
void sort_1(cars mas_cars[], char choice)
{
	int go = 0, n = ovner_1;
	while (go < n)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = i + 1; j < n; j++)
			{
				if (choice == '1')
				{
					if (_strnicmp(mas_cars[j].ovner, mas_cars[i].ovner, 2) < 0)
						swap(mas_cars[i], mas_cars[j]);
				}
				if (choice == '2')
				{
					if (_strnicmp(mas_cars[j].model, mas_cars[i].model, 2) < 0)
						swap(mas_cars[i], mas_cars[j]);
				}
				if (choice == '3')
				{
					if (_strnicmp(mas_cars[j].color, mas_cars[i].color, 2) < 0)
						swap(mas_cars[i], mas_cars[j]);
				}
				if (choice == '4')
				{
					if (mas_cars[j].Release_Date < mas_cars[i].Release_Date)
						swap(mas_cars[i], mas_cars[j]);
				}
				if (choice == '5')
				{
					if (_strnicmp(mas_cars[j].adress, mas_cars[i].adress, 2) < 0)
						swap(mas_cars[i], mas_cars[j]);
				}
				if (choice == '6')
				{
					if (mas_cars[j].license_plate < mas_cars[i].license_plate)
						swap(mas_cars[i], mas_cars[j]);
				}
				i++;
			}
		}
		go++;
	}
}
////////////////////////////////////////////////////////////////////
cars* Add_1(cars* arr, const int amount)
{
	cars* temp = new cars[amount + 1];
	for (int i = 0; i < amount; i++)
	{
		temp[i] = arr[i]; // �������� �� ��������� ������
	}
	delete[] arr;
	arr = temp;
	return arr;
}
///////////////////////////////////////////////////////////////////
cars* Input_mas_1() //��������� ������������ ������ ����������
{
	cars* temp = new cars[ovner_1];

	cars f1 = { "�������� �.�.","��� 2101","�����",1988,"���������",12889 };
	cars f2 = { "������ �.�.","���� �3","�����",1977,"���������",45964 };
	cars f3 = { "��������� �.�.","��� 521","�������",1983,"���������",15632 };
	cars f4 = { "������� �.�.","��� 2106","�����",1978,"�����",19054 };
	cars f5 = { "�������� �.�.","����","�����",1985,"����������",12369 };
	cars f6 = { "����� �.�.","��������","�����",1987,"�����",24587 };
	cars f7 = { "������ �.�.","�������","�������",1990,"������",15638 };
	cars f8 = { "��������� �.�.","���","������",1993,"����",32587 };
	cars f9 = { "������� �.�.","������","�������",1968,"���������",89654 };
	cars mas_cars[9] = { f1,f2,f3,f4,f5,f6,f7,f8,f9 };

	for (int i = 0; i < ovner_1; i++)
	{
		temp[i] = mas_cars[i]; // �������� �� ��������� ������
	}

	return temp;
}
//////////////////////////////////////////////////////////////////
void AddElements_1()
{
	int YesOrNot = 0; //  ���������� ��� ���������� ���� ������
	do
	{
		system("cls");
		cout << "\t���� ������ ��������:" << endl << endl;
		cars_arr = Add_1(cars_arr, ovner_1);
		Set_new_element_1(cars_arr, ovner_1);
		ovner_1++;
		cout << "\n\t���������� ���� ������ (1 - ��, 0 - ���): ";
		cin >> YesOrNot;
		cin.get();
	} while (YesOrNot != 0);

}
//////////////////////////////////////////////////////////////////
cars* FindName_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ���� ������ - ";
	char key[30];
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if ((_strnicmp(key, cars_arr[i].ovner, maxlen) == 0))
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
cars* FindModel_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ���� ������ - ";
	char key[30];
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if ((_strnicmp(key, cars_arr[i].model, maxlen) == 0))
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
////////////////////////////////////////////////////////////////
cars* FindColor_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ���� - ";
	char key[30];
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if ((_strnicmp(key, cars_arr[i].color, maxlen) == 0))
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
cars* FindRelease_Date_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ��� ������� - ";
	double key;
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if (key == cars_arr[i].Release_Date)
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
/////////////////////////////////////////////////////////////////
cars* FindAdress_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ����� - ";
	char key[30];
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if ((_strnicmp(key, cars_arr[i].adress, maxlen) == 0))
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
//////////////////////////////////////////////////////////////
cars* FindLicense_plate_1()
{
	delete[] result_serch1;
	ovner_rez = 0;
	cars* temp = new cars[ovner_1];
	int maxlen = 3, j = 0;
	cout << "������� ��� ����� - ";
	double key;
	cin >> key;
	for (int i = 0; i < ovner_1; i++)
	{
		if (key == cars_arr[i].license_plate)
		{
			temp[j] = cars_arr[i];
			ovner_rez++;
			j++;
		}
	}
	result_serch1 = temp;
	return 0;
}
/////////////////////////////////////////////////////////////
char Find_menu_1()
{
	cout << "\n\n\t����� ��:" << endl;
	cout << "\t1 - ��� ���������" << endl;
	cout << "\t2 - ������ ����������" << endl;
	cout << "\t3 - �����" << endl;
	cout << "\t4 - ���� �������" << endl;
	cout << "\t5 - �������" << endl;
	cout << "\t6 - ���������" << endl;
	cout << "\t7 - ����� � ���������� ����" << endl;
	cout << "\t�����: ";
	cin >> choice;
	return choice;
}
//////////////////////////////////////////////////////////////
void Find_cars()
{
	system("cls");
	char a;
	do
	{
		watch_1(ovner_1);
		a = Find_menu_1();
		menu_Find_cars(a);
		system("cls");
	} while (a != '7');
}
/////////////////////////////////////////////////////////////
void menu_Find_cars(char choice)
{
	switch (choice)
	{
	case '1':
	{
		system("CLS");
		cout << "\t����� �� ������� ���������" << endl;
		FindName();
		Rez();
		break;
	}
	case '2':
	{
		system("CLS");
		cout << "\t����� �� ������ ����������" << endl;
		FindModel_1();
		Rez();
		break;
	}

	case '3':
	{
		system("CLS");
		cout << "\t����� �� �����" << endl;
		FindColor_1();
		Rez();
		break;
	}
	case '4':
	{
		system("CLS");
		cout << "\t����� �� ���� �������" << endl;
		FindRelease_Date_1();
		Rez();
		break;
	}
	case '5':
	{
		system("CLS");
		cout << "\t����� �� �������" << endl;
		FindAdress_1();
		Rez();
		break;
	}
	case '6':
	{
		system("CLS");
		cout << "\t����� �� ��� ������" << endl;
		FindLicense_plate_1();
		Rez();
		break;
	}
	}
}
////////////////////////////////////////////////////////////////
void Rez_1()
{
	if (ovner_rez == 0)
	{
		system("cls");
		cout << "\n\n\t���������� � ���� �� �������." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\n\t���������� ������:\n" << endl;
		watch_rezult_1(ovner_rez);
	}
	_getch();
}

