#include<iostream>
#include<Windows.h>
#include <iomanip>
#include <MMSystem.h>

#pragma comment(lib, "winmm")
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
void music()
{

}
void main()
{
	setlocale(LC_ALL, "Russian");
	int a ,i=1;
Menu:	system("CLS");
	    GotoXY(20,4);
		cout <<"Домашние задания"<<endl<< "1-Задача1.Вывод на экран линии." << endl << "2-Задача2.Нахождение суммы целых нечетных чисел" << endl
			<< "3-Задача3.Нахождение факториала числа" <<"Дополнительные задания:"<<endl<< "Выберите одно из предложенных заданий " << endl;
		cin >> a;
		system("CLS");
		switch (a)
		{
		case 1:
			i = 1;
			GotoXY(20, 4);
			cout << "Введите символ, который будет повторяться" << endl;
			char symbol;
			cin >> symbol;
			 cout << "Введите число повторений" << endl;
		 quantity:cin >> a;
			if (a <= 0) {
				cout << "Введите положительное целое число";
				goto quantity;
			}
			else {
			choice:	cout << "Выберите расположение линии:" << endl << "1- горизонтальная" << "2-вертикальная линия" << endl;
				int position;
				cin >> position;
			
				system("CLS");
				switch (position)
				{
				case 1:
					while (i <= a)
					{
						cout << symbol;
						i++;
					}
					break;
				case 2:
					while (i <= a)
					{
						cout << symbol << endl;
						i++;
					}										break;
				default:
					cout << "Такой вариант не существует. Выберите один из вариантов!"<<endl;
					goto choice;

				}
			}
			system("pause");
				break;
		case 2:
			int start, end, intermediate;
			cout << "Введите начало диапазона" << endl;
			cin >> start;
			cout << "Введите конец диапазона" << endl;
			cin >> end;
			if (start == end )
			{
				if (start % 2 != 0)
					cout << "Сумма нечетных целых чисел в диапазоне от " << start << " до " << end << " равна " << start << endl;
				else 
					cout << "Сумма нечетных целых чисел в диапазоне от " << start << " до " << end << " равна 0" << endl;
				
			}
			else {
				if (start > end)
				{
					intermediate = start;
					start = end;
					end = intermediate;
				}
				intermediate = 0;
				cout << "Сумма нечетных целых чисел в диапазоне от " << start << " до " << end << " равна ";
				while (start <= end)
				{
					if (start % 2 != 0)
						intermediate += start;
					start++;
				}
				cout << intermediate << endl;
			}
			system("pause");
			break;
		case 3:
			i = 1;
			int fact=1;
			float n;
			system("CLS");
			Factorial:	cout << "Введите число для вычисления его факториала" << endl;
			cin >> n;
			if (n-int(n)== 0) {
				if (n < 0)
				{
					cout << "Вы можете вводить только положительное число" << endl;
					goto Factorial;

				}
				if (n > 0) {
					while (i <= n)
					{
						fact *= i;
						i++;
					}

					cout << n << "!= " << fact << endl;
				}

				if (n == 0)
				{
					cout << "0!=1 " << endl;
				}
				
			}
			else
			{
				cout << "Вы можете ввести только целое число положительное число" << endl;
				goto Factorial;
			}
			system("pause");
			break;
		

		}
		goto Menu;
}
