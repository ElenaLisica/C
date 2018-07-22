#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include <MMSystem.h>
#pragma comment(lib, "winmm")
using namespace std;
enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background);

void GotoXY(int X, int Y);

void music();

void build_cube(int x, int y);

void build_point(int point, int number_cube, int x, int y);

void global_create_point(int x, int y);

int random_point(int number_cube, int x, int y, int z);

int step(int z);

void menu(int position, int x1, int x2);

void go_string(int position);

void create_string(int z);

void win(int amount1, int amount2);



void main()
{
	int answer, point, amount1 = 0, amount2 = 0, throww=0;
	setlocale(LC_ALL, "Russian");
	cout << " Имеете ли Вы желание ходить первым? " << endl << "1. Да " << endl << "2. Нет " << endl << endl;
	do {
		cout<< "Выберите один из указанных возможностей:    ";
		cin >> answer;
	} while (answer != 1 && answer != 2);

	system("CLS");

	build_cube(10, 10);
	build_cube(60, 10);

	menu(1,5,20);
	menu(2,55,70);

	for (int move = 1; move < 6; move++)
	{
		SetColor(LightGray, Black);
		GotoXY(15, 30);
		cout << move;
		GotoXY(68, 30);
		cout << move;
		

		if (answer == 1)
		{
			throww = step(0);
			amount1 += throww;
			GotoXY(27, 38);
			cout << throww;
			GotoXY(24, 42);
			cout << amount1;


			throww = step(50);
			amount2 += throww;
			GotoXY(77, 38);
			cout << throww;
			GotoXY(73, 42);
			cout << amount2;

		}
		
		else
		{
			throww = step(50);
			amount2 += throww;
			GotoXY(77, 38);
			cout << throww;
			GotoXY(73, 42);
			cout << amount2;
			

			throww = step(0);
			amount1 += throww;
			GotoXY(27, 38);
			cout << throww;
			GotoXY(24, 42);
			cout << amount1;
		}
	}

	win(amount1, amount2);	

}





void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
void music()
{

}


void build_cube(int x, int y)
{
	SetColor(Green, Black);
	GotoXY(x + 4, y - 2);
	cout << "* * * * * * * * * * * *";
	GotoXY(x + 2, y - 1);
	cout << "*                     * *";
	GotoXY(x, y);
	cout << "* * * * * * * * * * * *   *" << endl;

	for (int i = 1;i < 13;i++)
	{
		GotoXY(x, y + i);
		if (i<12)
			cout << "*" << "                     *   *" << endl;
		else
			cout << "*" << "                     * *" << endl;
	}
	GotoXY(x, y + 13);
	cout << "* * * * * * * * * * * *" << endl;
}



void build_point(int point, int number_cube, int x, int y)
{
	SetColor(Yellow, Black);
	if (point == 1)
	{
		GotoXY(x + 11, y + 7);
		cout << "o";
	}
	else

		if (point == 2)
		{
			GotoXY(x + 15, y + 4);
			cout << "o";
			GotoXY(x + 6, y + 9);
			cout << "o";
		}
		else

			if (point == 3)
			{
				GotoXY(x + 15, y + 4);
				cout << "o";
				GotoXY(x + 10, y + 7);
				cout << "o";
				GotoXY(x + 6, y + 10);
				cout << "o";
			}
			else

				if (point == 4)
				{
					GotoXY(x + 6, y + 4);
					cout << "o";
					GotoXY(x + 15, y + 4);
					cout << "o";
					GotoXY(x + 15, y + 10);
					cout << "o";
					GotoXY(x + 6, y + 10);
					cout << "o";
				}
				else

					if (point == 5)
					{
						GotoXY(x + 6, y + 4);
						cout << "o";
						GotoXY(x + 15, y + 4);
						cout << "o";
						GotoXY(x + 10, y + 7);
						cout << "o";
						GotoXY(x + 15, y + 10);
						cout << "o";
						GotoXY(x + 6, y + 10);
						cout << "o";
					}
					else
					{
						GotoXY(x + 6, y + 4);
						cout << "o";
						GotoXY(x + 15, y + 4);
						cout << "o";
						GotoXY(x + 6, y + 7);
						cout << "o";
						GotoXY(x + 15, y + 7);
						cout << "o";
						GotoXY(x + 15, y + 10);
						cout << "o";
						GotoXY(x + 6, y + 10);
						cout << "o";
					}
	if (point != 1)
	{
		GotoXY(x + 13, y - 1);
		cout << "o";
	}

	if (point != 2)
	{
		GotoXY(x + 24, y + 2);
		cout << "o";
		GotoXY(x + 24, y + 8);
		cout << "o";
	}
	if (point == 1)
	{
		GotoXY(x + 9, y - 1);
		cout << "o";
		GotoXY(x + 13, y - 1);
		cout << "o";
		GotoXY(x + 17, y - 1);
		cout << "o";
	}
	if (point == 2)
	{

		GotoXY(x + 24, y + 2);
		cout << "o";
		GotoXY(x + 24, y + 5);
		cout << "o";
		GotoXY(x + 24, y + 8);
		cout << "o";
	}
}


void global_create_point(int x, int y)
{
	GotoXY(x + 9, y - 1);
	cout << " ";
	GotoXY(x + 24, y + 5);
	cout << " ";
	GotoXY(x + 17, y - 1);
	cout << " ";
	GotoXY(x + 13, y - 1);
	cout << " ";
	GotoXY(x + 24, y + 2);
	cout << " ";
	GotoXY(x + 24, y + 8);
	cout << " ";
	GotoXY(x + 11, y + 7);
	cout << " ";
	GotoXY(x + 6, y + 4);
	cout << " ";
	GotoXY(x + 15, y + 4);
	cout << " ";
	GotoXY(x + 10, y + 7);
	cout << " ";
	GotoXY(x + 15, y + 10);
	cout << " ";
	GotoXY(x + 6, y + 10);
	cout << " ";
	GotoXY(x + 6, y + 7);
	cout << " ";
	GotoXY(x + 15, y + 7);
	cout << " ";
	GotoXY(x + 6, y + 9);
	cout << " ";
	GotoXY(27, 38);
	cout << "   ";
	GotoXY(77, 38);
	cout << "   ";
}


int random_point(int number_cube, int x, int y, int z)
{
	int point, amount = 0;
	for (int i = 1;i < 4;i++)
	{
		point = rand() % 6 + 1;

		if (i < 3) {
			build_point(point, number_cube, x, y);
			Sleep(800);
			global_create_point(x, y);
			Sleep(800);

		}
		else {
			build_point(point, number_cube, x, y);
			PlaySound(TEXT("04526.wav"), NULL, SND_FILENAME);
			SetColor(LightGray, Black);
			if (number_cube == 1) {
				GotoXY(13 + z, 34);
				cout << point;
				amount += point;
			}
			else {
				GotoXY(33 + z, 34);
				cout << point;
				amount += point;
			}
		}
	}
	return amount;
}




int step(int z)
{
	int add = 0;
	create_string(z);
	go_string(z);
	add += random_point(1, 10, 10, z);
	create_string(z);
	go_string(z);
	add += random_point(2, 60, 10, z);
	global_create_point(10, 10);
	global_create_point(60, 10);
	return add;
}



void menu(int position, int x1, int x2)
{
	if (position == 1)
		SetColor(LightBlue, Black);
	else
		SetColor(LightMagenta, Black);
	GotoXY(x1, 30);
	cout << "Бросок № ";
	GotoXY(x1, 32);
	cout << "Кубик 1 ";
	GotoXY(x1, 34);
	cout << "Очко ";
	GotoXY(x1, 36);
	cout << "_________________________";
	GotoXY(x1, 38);
	cout << "Сумма очков за бросок";
	GotoXY(x1, 40);
	cout << "_________________________";
	GotoXY(x1, 42);
	cout << "Сумма всех очков ";
	GotoXY(x2 + 5, 32);
	cout << "Кубик 2 ";
	GotoXY(x2 + 5, 34);
	cout << "Очко ";
}


void create_string(int z)
{
	GotoXY(15 + z, 27);
	cout << "                    ";
}


void go_string(int position)
{
	if (position == 0)
		SetColor(LightBlue, Black);
	else
		SetColor(LightMagenta, Black);

	for (int i = 0;i < 5;i++)
	{
		GotoXY(15 + position + i, 27);
		if (position == 0)
		{
			cout << " ";
			cout << "Игрок ";
		}
		else
		{
			cout << " ";
			cout << "Компьютер ";
		}
		Sleep(100);
	}
}


void win(int amount1, int amount2)
{
	SetColor(Yellow, Black);
	if (amount1 > amount2)
	{
		GotoXY(45, 44);
		cout << "Победитель игрок!";
	}
	else
		if (amount1 < amount2)
		{
			GotoXY(45, 44);
			cout << "Победитель компьютер!";
		}
		else
		{
			GotoXY(45, 44);
			cout << "Ничья!";
		}
	cout << endl << endl;
	PlaySound(TEXT("vyigrysh.wav"), NULL, SND_FILENAME);
}
