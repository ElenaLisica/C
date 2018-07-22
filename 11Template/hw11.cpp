#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;

void build_mas(int ar[], int size, int start, int end);

void write_mas(int ar[], int size);

template <typename T, typename T1> T1  AVARAGE(T ar[], T size, T1 avarage);

void equation(double a, double b);

void equation(double a, double b, double c);

void rounding(double number, double sign);


void main()
{
	int answer;
	double a, b, c,k;
	const int size = 10;
	int mas[size] = {};
	double avarage = 0;
	setlocale(LC_ALL, "Russian");
	do
	{
	system("CLS");
	cout << "�������" << endl << " 1. ����� �������� ��������������� �������� �������" << endl 
		<< " 2. ������� ���������" << endl << " 3. ���������� �����"<<endl<<" 4. �����" << endl;
	do
	{
		cout << "�������� ���� �� ������������ ���������" << endl;
		cin >> answer;
	}
	while (answer != 1 && answer != 2 && answer != 3 && answer != 4);
	system("CLS");
	switch (answer)
	{
	case 1:
	build_mas(mas, size, -20, 20);
	cout << "������:" << endl;
	write_mas(mas, size);
	cout <<endl<< "������� �������������� ��������� ������� �����  " << AVARAGE(mas, size, avarage)<<endl<<endl;
	system("pause");
	break;
		
	case 2:
		
			system("CLS");
			cout << " 1. ������� ��������� ��������� ���� a*x+b=0" << endl
				<< " 2. �������  ����������� ��������� ���� a*x^2+b*x+c=0" << endl ;
			do
			{
				cout << "�������� ���� �� ������������ ���������" << endl;
				cin >> answer;
			}
			while (answer != 1 && answer != 2 );
			system("CLS");

			switch (answer)
			{
			case 1:
				cout << "������� ����������� a ";
				cin >> a;
				cout << endl<<"������� ����������� b ";
				cin >> b;
				equation(a, b);
			break;

			case 2:
				do
				{
					cout << "������� ����������� a ";
					cin >> a;
					if (a == 0)
						cout << "����������� � ������ ���� �������� �� ����" << endl;
				} while (a == 0);
				cout << "������� ����������� b ";
				cin >> b;
				cout << "������� ����������� c ";
				cin >> c;
				equation(a, b, c);
			}
					
	system("pause");
	break;
	
	case 3:
	cout << "������� �����  ";
	cin >> a;
	do
	{
		
		cout << endl << "C������ ������ ����� ������� ?    ";
		cin >> b;
		if (b < 0)
			cout << endl << " ������� ������������� ����� �����";
	} while (b < 0);
	cout <<endl<<endl<< "����� "<<a<<" ���������� ����� ";
	if (a>=0)
		rounding(a, b);
	else
	{
		cout << "-";
		rounding(abs(a), b);
	}
	system("pause");	
	
	}
} 
	while (answer != 4);
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

template <typename T, typename T1> T1  AVARAGE(T ar[], T size, T1 avarage)
{
	for (int i = 0;i < size;i++)
		avarage += ar[i];
	return avarage / size;
}

void equation(double a, double b)
{
	if (a == 0 && b == 0)
		cout << "�����:   ��������� �������" << endl << endl;
	else
	{
		if (a == 0 && b != 0)
			cout << "�����:   ��� ������� " << endl << endl;
		else
		{	if ((-b / a) == 0)
				cout << "�����: �= 0" << endl;
			else
				cout << "�����: �= " << -b / a << endl;
		}
	}
			
}


void equation(double a, double b, double c)
{
	double discriminant = b*b - 4 * a*c;
	if (discriminant < 0)
		cout << endl << "�����:  ��� ������" << endl << endl;
	if (discriminant >= 0)
	{
		cout << "�����:" << endl;
		cout << "1-� ������ ����������� ��������� " << (-b + sqrt(discriminant)) / (2 * a);
		cout << endl << "2-� ������ ����������� ��������� " << (-b - sqrt(discriminant)) / (2 * a) << endl << endl;
	}
}

void rounding(double number, double sign)
{
	double variable;
	variable = (number - int(number))*pow(10, sign);
	if ((variable - int(variable)) >= 0.5)
		variable++;
	cout << (int(number) + pow(0.1, sign)*int(variable)) << endl;

}

