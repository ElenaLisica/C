#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;

enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};

void SetColor(int text, int background);

void build_mas(int ar[], int size, int start, int end);

void write_mas(int ar[], int size);

void sorting(int ar[], int start1, int end1);

void color_write_mas(int ar[], int size, int start, int end);

int search(int ar[], int left, int right, int key);

void search_element(int ar[], int ar2[], int size);





void main()
{
int size_mas,answer,start,end;
setlocale(LC_ALL, "Russian");
const int size1=30;
int mas1[size1] =  {};
const int size = 100;
int mas[size] = {};


do {
	system("CLS");
	cout << "�������" << endl << " 1. ���������� ������� � ��������� ���������" << endl << " 2. ����� ��������� ������� ������� � ������ �������" <<endl<< " 3. �����" << endl;
	do {
		cout << "�������� ���� �� ������������ ���������" << endl;
		cin >> answer;
	} while (answer != 1 && answer != 2 && answer!=3);

	switch (answer)
	{
	case 1:
		do {
			system("CLS");
			cout << "������� ������ �������, �� ����� 30:     ";
			cin >> size_mas;
		} while (size_mas < 1 || size_mas>30);

		cout << "�������� ������" << endl;
		build_mas(mas1, size_mas, -20, 20);
		write_mas(mas1, size_mas);
		cout << "������� ������� ���������� �������." << endl;
		do
		{
			cout << "������ ��������� �� 1 �� "<<size_mas<<"  :";
			cin >> start;
		} while (start<1 || start>size_mas);
		
		do
		{
			cout << "������� ����� ��������� �� "<< start<<" �� " << size_mas << "  :";
			cin >> end;
		} while (end<start || end>size_mas);
		sorting(mas1, start, end);
		system("CLS");
		cout << "��������������� ������ � ��������� [" << start << ";" << end << "]" << endl;
		color_write_mas(mas1, size_mas, start, end);
		system("pause");
		SetColor(White, Black);
		break;


	case 2:
		system("CLS");
		do {
			cout << "������� ������ ������� �������� ��� 10:      ";
			cin >> size_mas;
		} while (size_mas <= 10);
		system("CLS");
		cout << "������ ������" << endl;
		build_mas(mas, size_mas, -3, 13);
		write_mas(mas, size_mas);
		cout << "������ ������" << endl;
		build_mas(mas1, 3, -3, 13);
		write_mas(mas1, 3);
		sorting(mas, 1, size_mas);
		cout << "��������������� ������ ������" << endl;
		write_mas(mas, size_mas);
		cout << "��������� ������ ���������:" << endl;
		search_element(mas, mas1, size_mas);
		SetColor(White, Black);
		system("pause");
		break;

	default:
		break;

	}
} while (answer != 3);
}




//�������

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}


void build_mas(int ar[], int size, int start, int end)
{
	for (int i = 0;i < size;i++)
		ar[i] = rand() % (end - start + 1) + start;

}

void write_mas(int ar[], int size)
{
	for (int i = 0;i < size;i++)
		cout << ar[i] << "   ";
	cout << endl;

}
void sorting(int ar[], int start1, int end1)
{
	int memory;
	for (int i = start1 - 1;i < end1;i++)
	{
		for (int j = i;j < end1;j++)
		{
			if (ar[i] > ar[j])
			{
				memory = ar[i];
				ar[i] = ar[j];
				ar[j] = memory;
			}
		}
	}
}



void color_write_mas(int ar[], int size, int start, int end)
{
	for (int i = 0;i < size;i++)
	{
		if (i >= (start - 1) && i < end)
		{
			SetColor(Green, Black);
			cout << ar[i] << "   ";
		}

		else
		{
			SetColor(White, Black);
			cout << ar[i] << "   ";
		}
	}
	cout << endl;

}



int search(int ar[], int left, int right, int key)
{
	int midd = 0;
	while (1)
	{
		midd = (right + left) / 2;
		if (key > ar[midd])
			left = midd + 1;
		if (key < ar[midd])
			right = midd - 1;
		if (key == ar[midd])
			return midd;

		if (left > right)
			return -1;
	}
}

void search_element(int ar[], int ar2[], int size)
{
	for (int i = 0;i < 3;i++)
	{

		if (search(ar, 0, size - 1, ar2[i]) > -1)
		{
			SetColor(Yellow, Blue);
			cout << i + 1 << "� ������� ������� ������� ������������ � ������ �������" << endl;
		}
		else
		{
			SetColor(Yellow, Blue);
			cout << i + 1 << "� ������� ������� ������� ����������� � ������ �������" << endl;
		}
	}

	cout << endl;
}



