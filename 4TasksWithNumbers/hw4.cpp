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
		cout <<"�������� �������"<<endl<< "1-������1.����� �� ����� �����." << endl << "2-������2.���������� ����� ����� �������� �����" << endl
			<< "3-������3.���������� ���������� �����" <<"�������������� �������:"<<endl<< "�������� ���� �� ������������ ������� " << endl;
		cin >> a;
		system("CLS");
		switch (a)
		{
		case 1:
			i = 1;
			GotoXY(20, 4);
			cout << "������� ������, ������� ����� �����������" << endl;
			char symbol;
			cin >> symbol;
			 cout << "������� ����� ����������" << endl;
		 quantity:cin >> a;
			if (a <= 0) {
				cout << "������� ������������� ����� �����";
				goto quantity;
			}
			else {
			choice:	cout << "�������� ������������ �����:" << endl << "1- ��������������" << "2-������������ �����" << endl;
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
					cout << "����� ������� �� ����������. �������� ���� �� ���������!"<<endl;
					goto choice;

				}
			}
			system("pause");
				break;
		case 2:
			int start, end, intermediate;
			cout << "������� ������ ���������" << endl;
			cin >> start;
			cout << "������� ����� ���������" << endl;
			cin >> end;
			if (start == end )
			{
				if (start % 2 != 0)
					cout << "����� �������� ����� ����� � ��������� �� " << start << " �� " << end << " ����� " << start << endl;
				else 
					cout << "����� �������� ����� ����� � ��������� �� " << start << " �� " << end << " ����� 0" << endl;
				
			}
			else {
				if (start > end)
				{
					intermediate = start;
					start = end;
					end = intermediate;
				}
				intermediate = 0;
				cout << "����� �������� ����� ����� � ��������� �� " << start << " �� " << end << " ����� ";
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
			Factorial:	cout << "������� ����� ��� ���������� ��� ����������" << endl;
			cin >> n;
			if (n-int(n)== 0) {
				if (n < 0)
				{
					cout << "�� ������ ������� ������ ������������� �����" << endl;
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
				cout << "�� ������ ������ ������ ����� ����� ������������� �����" << endl;
				goto Factorial;
			}
			system("pause");
			break;
		

		}
		goto Menu;
}
