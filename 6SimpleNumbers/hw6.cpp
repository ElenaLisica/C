#include <iostream>
#include <Windows.h>
#include <iomanip>
#include<MMSystem.h>
using namespace std;
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
void GotoXY(int X, int Y)
{
	HANDLE hConsole;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { X, Y };
	SetConsoleCursorPosition(hStdOut, coord);
}
void main()
{
	setlocale(LC_ALL, "Russian");
	int answer,i,j , row = 0;
	int Y = 0, y = 0, c = 0, m = 0, d = 1, w = 0,day=1;
Menu:
	system("CLS");
	cout << "Задания:" << endl << "1. Вывод простых чисел" << endl << "2. Вывод простых чисел в виде решета Эратосфена"<<endl
		<<"3. Вывод прямоугольника" << endl << "4. Вывод на экран календаря выбранного месяца" << endl 
		<<endl << "Выберите номер задачи" << endl;
	cin >> answer;
	system("CLS");
	switch (answer)
	{
	case 1:
		cout << " Простые числа от 2 до 1000" << endl;
		for (i = 2;i <= 1000;i++)
		{
			int divider = 0;
			for (j = 1;j <= i;j++)
			{
				if (i%j == 0)
					divider++;
			}
			if (divider < 3)
			{
				row++;
				cout << setw(7) << i << "  ";

				if (row % 10 == 0)
				{
					cout << endl;
					row = 0;
				}
			}
		}
		cout << endl;
		break;


	case 2:
		SetColor(Red, White);
		GotoXY(20, 4);
		cout << "Решето Эратосфена" << endl;

		SetColor(Black, Blue);
		cout << setw(7) << 1 << "  ";
		for (i = 2;i <= 1000;i++)
		{
			int divider = 0;
			for (j = 1;j <= i;j++)
			{
				if (i%j == 0)
					divider++;
			}
			if (divider < 3)
			{
				SetColor(White, Blue);
				cout << setw(7) << i << "  ";
			}
			else
			{
				SetColor(Black, Blue);
				cout << setw(7) << i << "  ";
			}
			if (i % 10 == 0)
				cout << endl;
		}
		SetColor(Red, White);
		cout << endl;
		SetColor(White, Black);
		break;



	case 3:
		double height, width;
		cout << "Введите число - количество * для высоты" << endl;
	h:cin >> height;
		if (height <= 0 || (height - int(height))!=0)
		{
			cout << " Количество должно быть положительным целым числом. Введите это число:" << endl;
			goto h;
		}
		cout << "Введите  число - количество * для ширины" << endl;
	w:cin >> width;
		if (width <= 0 || (width - int(width))!=0)
		{
			cout << " Количество должно быть положительным целым числом. Введите это число:" << endl;
			goto w;
		}
		system("CLS");
		cout << endl;
		for (i = 0;i <height ;i++)
		{
			for (j = 0;j <width;j++)
			{
				if (i == 0 || j == width - 1 || j == 0 || i == height - 1)
					cout << "*";
				else 
					cout << " ";

			}
			cout << endl;
		}
		break;




	case 4:
		double month, year;
		cout << "Введите номер месяца" << endl;
	m:cin >> month;
		if (month <= 0 || (month - int(month))!=0||month>12)
		{
			cout << " Месяц должен быть целым числом от 1 до 12. Введите номер месяца:" << endl;
			goto m;
		}
		cout << "Введите год" << endl;
	y:cin >> year;
		if (year <= 0 || (year - int(year)) != 0 )
		{
			cout << " Год должен быть целым числом. Введите год:" << endl;
			goto y;
		}
		if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
			day = 31;

		if (month == 4 || month == 6 || month == 9 || month == 11)
			day = 30;
		if(int(year)%4==0 & month==2)
			day = 29;
		if (int(year) % 4 != 0 & month == 2)
			day = 28;
		 (month == 1 || month == 2)? Y = year - 1:Y=year;

		 y = Y % 100;
		 c = Y / 100;
		(month >= 3 & month <= 12) ? m = month - 2 : m = month + 1;
		w = (d + int(2.6*m - 0.2) + y + (y / 4) + (c / 4) - 2 * c);
		
		while (w < 0 || w>6)
		{
			if (w < 0)
			{
				w += 7;
			}
			else
			{
				w -= 7;
			}
		}
	
		cout << setw(5)<<"Пн" << setw(5) << "ВТ" << setw(5) << "Ср" << setw(5) << "Чт" << setw(5) << "Пт" << setw(5) << "Сб" << setw(5) << "Вс" << endl;
		for (i = 1;i < w;i++)
		{
			cout <<  setw(6)<<"  " ;
			
		}
		if (w==1)
			cout << setw(4) << " ";


		for (i = 1;i <=day;i++)
		{   
			cout << i << setw(5);
			w++;
			if (w % 8 == 0)
			{
				cout << endl;
				w = 1;
			}
		}
		cout << endl;
		break;
		


	default:
		goto Menu;

	}
	system("pause");
	goto Menu;
}