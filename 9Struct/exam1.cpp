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
char choice;//для выбора всяких всячин
trucks* trucks_arr = new trucks[ovner];
trucks* result_serch = new trucks[ovner];
cars* cars_arr = new cars[ovner_1];
cars* result_serch1 = new cars[ovner_1];
////////////////////////////////////////////////////////////////////
//////////////    Функции грузовых автомобилей       //////////////
//////////////////////////////////////////////////////////////////
void Menu_t();//Меню грузовых автомобилей
char Sort_menu();//Меню выбора сортировки
void Sort_trucks();//Сортировка выполнение выбора
trucks* Input_mas();//Заполняем изначальный массив
trucks* FindName();//Поиск по фамилии
trucks* FindModel();//Поиск по модели авто
trucks* FindCarrying();//Поиск по грузоподъемности
trucks* FindColor();//Поиск по цвету
trucks* FindRelease_Date();//Поиск по году выпуска
trucks* FindAdress();//Поиск по адрессу
trucks* FindLicense_plate();//Поиск по ГОС номеру
void AddElements();//добавление элементов в массив
void Set_new_element(trucks* mas_trucks, const int amount);//Ввод нового элемента в массив
trucks* Add(trucks* arr, const int amount);//Заполнение динамического массива структуры
void sort(trucks mas_trucks[], int choice);//Сортировка массива
char Find_menu();//Меню поиска
void Find_trucks();//Реализация поиска
void menu_Find_trucks(char choice);
void Rez();
////////////////////////////////////////////////////////////////////
//////////////    Функции легковых автомобилей       //////////////
//////////////////////////////////////////////////////////////////
void Menu_c();//Меню легковых автомобилей
char Sort_menu();//Меню выбора сортировки
void Sort_cars();//Сортировка выполнение выбора
cars* Input_mas_1();//Заполняем изначальный массив
cars* FindName_1();//Поиск по фамилии
cars* FindModel_1();//Поиск по модели авто
cars* FindColor_1();//Поиск по цвету
cars* FindRelease_Date_1();//Поиск по году выпуска
cars* FindAdress_1();//Поиск по адрессу
cars* FindLicense_plate_1();//Поиск по ГОС номеру
void AddElements_1();//добавление элементов в массив
void Set_new_element_1(cars* mas_cars, const int amount);//Ввод нового элемента в массив
cars* Add_1(cars* arr, const int amount);//Заполнение динамического массива структуры
void sort_1(cars mas_cars[], char choice);//Сортировка массива
char Find_menu_1();//Меню поиска
void Find_cars();//Реализация поиска
void menu_Find_cars(char choice);
void Rez_1();
///////////////////////////////////////////////////////////////////////////////////////////////
void watch(int ovner)
{
	cout << "№ | ФИО владельца  |  Модель автомобиля | Грузоподъемность(т)|  Цвет      | Год выпуска |  Адресс         | ГОС.номер|\n";
	for (int i = 0; i < ovner; i++)
	{
		cout << i + 1 << ".";tabl1;
	}
}

void watch_rezult(int ovner_rez)
{
	cout << "№ | ФИО владельца  |  Модель автомобиля | Грузоподъемность(т)|  Цвет      | Год выпуска |  Адресс         | ГОС.номер|\n";
	for (int i = 0; i < ovner_rez; i++)
	{
		cout << i + 1 << "."; tabl2;
	}
}

void watch_1(int ovner1)
{
	cout << "№ | ФИО владельца  |  Модель автомобиля |  Цвет      | Год выпуска |    Адресс       | ГОС.номер|\n";
	for (int i = 0; i < ovner_1; i++)
	{
		cout << i + 1 << "."; tabl3;
	}
}

void watch_rezult_1(int ovner_rez)
{
	cout << "№ | ФИО владельца  |  Модель автомобиля |  Цвет      | Год выпуска |    Адресс       | ГОС.номер|\n";
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
		cout << "\n\t\tСправочник ГАИ города" << endl;
		cout << "\n\t1 - Меню грузовые автомобили \n\t2 - Меню легковые автомобили \n\t3 - Выход из программы" << endl;
		cout << "\n\tСделайте свой выбор - " ;
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
	cout << "\t\tГрузовые автомобили" << endl;
	cout << "\t1 - Показать все записи раздела " << "'" << "Грузовые автомобили" << "'" << endl;
	cout << "\t2 - Меню сортировки" << endl;
	cout << "\t3 - Меню поиска" << endl;
	cout << "\t4 - Добавить запись" << endl;
	cout << "\t5 - Выход в предыдущее меню\n" << endl;
	cout << "\tВыбор - " ;
	cin >> choice;
	switch (choice)
	{
	case '1':
		system("CLS");
		GotoXY(22, 0);
		cout << "\tВсе записи раздела " << "'" << "Грузовые автомобили" << "'\n" << endl;
		watch(ovner);
		cout << "\n\n\tДля возврата в меню нажмите любую клавишу ";
		_getch();
		break;
	case '2':
		system("CLS");
		cout << "\t Меню сортировки\n" << endl;
		Sort_trucks();
		break;
	case '3':
		system("CLS");
		cout << "\t Меню поиска\n" << endl;
		Find_trucks();
		break;
	case '4':
		system("CLS");
		cout << "\tДобавление новой записи ";
		AddElements();
		break;
	}
	} while (choice !='5');
}
///////////////////////////////////////////////
char Sort_menu()
{
	cout << "\n\tСортировка по:" << endl;
	cout << "\t1 - ФИО владельца" << endl;
	cout << "\t2 - Модели автомобиля" << endl;
	cout << "\t3 - Грузоподъемности" << endl;
	cout << "\t4 - Цвету" << endl;
	cout << "\t5 - Дате выпуска(по возрастанию)" << endl;
	cout << "\t6 - Адрессу" << endl;
	cout << "\t7 - ГОСномеру(по возрастанию)" << endl;
	cout << "\t8 - Выход в предыдущее меню" << endl;
	cout << "\tВыбор: " ;
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
	cout << "Введите фамилию и инициалы владельца - ";
	cin.getline(mas_trucks[amount].ovner,30);
	cout << "Введите модель автомобиля - ";
	cin >> mas_trucks[amount].model;
	cout << "Введите грузоподъемность - ";
	cin >> mas_trucks[amount].carrying;
	cout << "Введите цвет - ";
	cin >> mas_trucks[amount].color;
	cout << "Введите год выпуска - ";
	cin >> mas_trucks[amount].Release_Date;
	cout << "Введите город регистрации - ";
	cin >> mas_trucks[amount].adress;
	cout << "Введите ГОС номер (5 цыфр) - ";
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
		temp[i] = arr[i]; // копируем во временный объект
	}
	delete[] arr;
	arr = temp;
	return arr;
}
///////////////////////////////////////////////////////////////////
trucks* Input_mas() //Заполняем динамический массив элементами
{
	trucks* temp = new trucks[ovner];

	trucks f1 = { "Шалаев Д.Н.","Газ-52",5.0,"белый",1978,"Мариуполь",12589 };
	trucks f2 = { "Иванов А.Р.","Камаз",8.0,"серый",1977,"Запорожье",75964 };
	trucks f3 = { "Пупочки Л.А.","Маз",7.0,"красный",1983,"Одесса",15632 };
	trucks f4 = { "Азазел В.Г.","Газ-51",4.5,"синий",1988,"Херсон",12954 };
	trucks f5 = { "Мозг Д.Ф.","Краз",7.2,"серый",1985,"Мелитополь",12369 };
	trucks f6 = { "Орлов К.А.","Урал",10.0,"белый",1987,"Днепр",24587 };
	trucks f7 = { "Корова М.Х.","Ккраз",6.8,"зеленый",1990,"Токмак",15638 };
	trucks f8 = { "Лужа З.Д.","Белаз",25.0,"желтый",1993,"Киев",32587 };
	trucks f9 = { "Писец В.В.","Газ-51",4.2,"зеленый",1968,"Запорожье",89654 };
	trucks mas_trucks[9] = { f1,f2,f3,f4,f5,f6,f7,f8,f9 };

	for (int i = 0; i < ovner; i++)
	{
		temp[i] = mas_trucks[i]; // копируем во временный объект
	}

	return temp;
}
//////////////////////////////////////////////////////////////////
void AddElements()
{
	int YesOrNot = 0; //  продолжить или остановить ввод данных
	do
	{
		system("cls");
		cout << "\tВвод нового элемента:" << endl << endl;
		trucks_arr = Add(trucks_arr, ovner);
		Set_new_element(trucks_arr, ovner);
		ovner++;
		cout << "\n\tПродолжить ввод данных (1 - да, 0 - нет): ";
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
	cout << "Введите ключ поиска - ";
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
	cout << "Введите ключ поиска - ";
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
	cout << "Введите грузоподъемность - ";
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
	cout << "Введите цвет - ";
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
	cout << "Введите год выпуска - ";
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
	cout << "Введите город - ";
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
	cout << "Введите ГОС номер - ";
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
	cout << "\n\n\tПоиск по:" << endl;
	cout << "\t1 - ФИО владельца" << endl;
	cout << "\t2 - Модели автомобиля" << endl;
	cout << "\t3 - Грузоподъемности" << endl;
	cout << "\t4 - Цвету" << endl;
	cout << "\t5 - Дате выпуска" << endl;
	cout << "\t6 - Адрессу" << endl;
	cout << "\t7 - ГОСномеру" << endl;
	cout << "\t8 - Выход в предыдущее меню" << endl;
	cout << "\tВыбор: ";
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
			cout << "\tПоиск по фамилии владельца" << endl;
			FindName();
			Rez();
			break;
		}
	case '2':
		{
			system("CLS");
			cout << "\tПоиск по модели автомобиля" << endl;
			FindModel();
			Rez();
			break;
		}
	case '3':
		{
			system("CLS");
			cout << "\tПоиск по грузоподъемности" << endl;
			FindCarrying();
			Rez();
			break;
		}
	case '4':
		{
			system("CLS");
			cout << "\tПоиск по цвету" << endl;
			FindColor();
			Rez();
			break;
		}
	case '5':
		{
			system("CLS");
			cout << "\tПоиск по году выпуска" << endl;
			FindRelease_Date();
			Rez();
			break;
		}
	case '6':
		{
			system("CLS");
			cout << "\tПоиск по адрессу" << endl;
			FindAdress();
			Rez();
			break;
		}
	case '7':
		{
			system("CLS");
			cout << "\tПоиск по ГОС номеру" << endl;
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
		cout << "\n\n\tСовпадений в базе не найдено." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\n\tРезультаты поиска:\n" << endl;
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
		cout << "\t\tЛегковые автомобили" << endl;
		cout << "\t1 - Показать все записи раздела " << "'" << "Легковые автомобили" << "'" << endl;
		cout << "\t2 - Меню сортировки" << endl;
		cout << "\t3 - Меню поиска" << endl;
		cout << "\t4 - Добавить запись" << endl;
		cout << "\t5 - Выход в предыдущее меню\n" << endl;
		cout << "\tВыбор - ";
		cin >> choice;
		switch (choice)
		{
		case '1':
			system("CLS");
			GotoXY(22, 0);
			cout << "\tВсе записи раздела " << "'" << "Легковые автомобили" << "'\n" << endl;
			watch_1(ovner_1);
			cout << "\n\n\tДля возврата в меню нажмите любую клавишу ";
			_getch();
			break;
		case '2':
			system("CLS");
			cout << "\t Меню сортировки\n" << endl;
			Sort_cars();
			break;
		case '3':
			system("CLS");
			cout << "\t Меню поиска\n" << endl;
			Find_cars();
			break;
		case '4':
			system("CLS");
			cout << "\tДобавление новой записи ";
			AddElements_1();
			break;
		}
	} while (choice != '5');
}
///////////////////////////////////////////////
char Sort_menu_1()
{
	cout << "\n\tСортировка по:" << endl;
	cout << "\t1 - ФИО владельца" << endl;
	cout << "\t2 - Модели автомобиля" << endl;
	cout << "\t3 - Цвету" << endl;
	cout << "\t4 - Дате выпуска(по возрастанию)" << endl;
	cout << "\t5 - Адрессу" << endl;
	cout << "\t6 - ГОСномеру(по возрастанию)" << endl;
	cout << "\t7 - Выход в предыдущее меню" << endl;
	cout << "\tВыбор: ";
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
	cout << "Введите фамилию и инициалы владельца - ";
	cin.getline(mas_cars[amount].ovner, 30);
	cout << "Введите модель автомобиля - ";
	cin >> mas_cars[amount].model;
	cout << "Введите цвет - ";
	cin >> mas_cars[amount].color;
	cout << "Введите год выпуска - ";
	cin >> mas_cars[amount].Release_Date;
	cout << "Введите город регистрации - ";
	cin >> mas_cars[amount].adress;
	cout << "Введите ГОС номер (5 цыфр) - ";
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
		temp[i] = arr[i]; // копируем во временный объект
	}
	delete[] arr;
	arr = temp;
	return arr;
}
///////////////////////////////////////////////////////////////////
cars* Input_mas_1() //Заполняем динамический массив элементами
{
	cars* temp = new cars[ovner_1];

	cars f1 = { "Пупочкин В.В.","Ваз 2101","белый",1988,"Мариуполь",12889 };
	cars f2 = { "Иванов А.Р.","Ауди А3","серый",1977,"Запорожье",45964 };
	cars f3 = { "Пупочкина Л.А.","БМВ 521","красный",1983,"Мариуполь",15632 };
	cars f4 = { "Куркуль И.М.","Ваз 2106","синий",1978,"Ровно",19054 };
	cars f5 = { "Мозговой Д.Ф.","Рено","серый",1985,"Мелитополь",12369 };
	cars f6 = { "Орлов К.А.","Мерседес","белый",1987,"Днепр",24587 };
	cars f7 = { "Король М.Х.","Москвич","зеленый",1990,"Токмак",15638 };
	cars f8 = { "Луговской О.О.","Киа","желтый",1993,"Киев",32587 };
	cars f9 = { "Пискарь В.В.","Субару","зеленый",1968,"Запорожье",89654 };
	cars mas_cars[9] = { f1,f2,f3,f4,f5,f6,f7,f8,f9 };

	for (int i = 0; i < ovner_1; i++)
	{
		temp[i] = mas_cars[i]; // копируем во временный объект
	}

	return temp;
}
//////////////////////////////////////////////////////////////////
void AddElements_1()
{
	int YesOrNot = 0; //  продолжить или остановить ввод данных
	do
	{
		system("cls");
		cout << "\tВвод нового элемента:" << endl << endl;
		cars_arr = Add_1(cars_arr, ovner_1);
		Set_new_element_1(cars_arr, ovner_1);
		ovner_1++;
		cout << "\n\tПродолжить ввод данных (1 - да, 0 - нет): ";
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
	cout << "Введите ключ поиска - ";
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
	cout << "Введите ключ поиска - ";
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
	cout << "Введите цвет - ";
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
	cout << "Введите год выпуска - ";
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
	cout << "Введите город - ";
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
	cout << "Введите ГОС номер - ";
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
	cout << "\n\n\tПоиск по:" << endl;
	cout << "\t1 - ФИО владельца" << endl;
	cout << "\t2 - Модели автомобиля" << endl;
	cout << "\t3 - Цвету" << endl;
	cout << "\t4 - Дате выпуска" << endl;
	cout << "\t5 - Адрессу" << endl;
	cout << "\t6 - ГОСномеру" << endl;
	cout << "\t7 - Выход в предыдущее меню" << endl;
	cout << "\tВыбор: ";
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
		cout << "\tПоиск по фамилии владельца" << endl;
		FindName();
		Rez();
		break;
	}
	case '2':
	{
		system("CLS");
		cout << "\tПоиск по модели автомобиля" << endl;
		FindModel_1();
		Rez();
		break;
	}

	case '3':
	{
		system("CLS");
		cout << "\tПоиск по цвету" << endl;
		FindColor_1();
		Rez();
		break;
	}
	case '4':
	{
		system("CLS");
		cout << "\tПоиск по году выпуска" << endl;
		FindRelease_Date_1();
		Rez();
		break;
	}
	case '5':
	{
		system("CLS");
		cout << "\tПоиск по адрессу" << endl;
		FindAdress_1();
		Rez();
		break;
	}
	case '6':
	{
		system("CLS");
		cout << "\tПоиск по ГОС номеру" << endl;
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
		cout << "\n\n\tСовпадений в базе не найдено." << endl;
	}
	else
	{
		system("cls");
		cout << "\n\n\tРезультаты поиска:\n" << endl;
		watch_rezult_1(ovner_rez);
	}
	_getch();
}

