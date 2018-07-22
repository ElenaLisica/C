#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;


void query(int  *size);

void build_mas(int *mas, int size);

void write_mas(int *mas, int size);

void sorting(int *mas, int size);

void create_mas(int *C, int start, int arr[], int end);

void compare(int *C, int A[], int B[], int size1, int size2, int *index, int start, int task);

void swap(int *A, int size1);

void main()

{
	srand(time(NULL));
	int size1 = 4, size2 = 4, size3 = 4, answer;

	double answer2;
	setlocale(LC_ALL, "Russian");

	int *A = new int[size1];
	int *B = new int[size2];
	int *C = new int[size3];
	
	do {
		system("CLS");
		cout << "�������" << endl << "1. �������� ������� �������� �������" << endl
			<< "2. �� ���� �������� ������������ ���� ������, ������������� �� �����������" << endl 
			<< "3. �� ���� �������� ������������ ������ � 5 ��������� � ����"<<endl
			<< "4. �����" << endl;
		do {
			cout << "�������� ���� �� ������������ ���������" << endl;
			cin >> answer;
		} while (answer != 1 && answer != 2 && answer != 3 && answer != 4);

		switch (answer)
		{
		case 1:
			do {
				system("CLS");
				cout << "������� ������ �������. ��� ������ ������ ��� ������ ���� ������ �����.    ";
				cin >> answer2;
				} while ((answer2 - int(answer2))> 0 || answer2 <= 0 || int(answer2)%2!=0);
				
					size1 =int (answer2);

			cout << "�������� ������" << endl;
			build_mas(A, size1);
			write_mas(A, size1);
			swap(A, size1);
			cout << endl<<"����� ������" << endl;
			write_mas(A, size1);
			system("pause");
			break;


		case 2:
			
			system("CLS");
			cout << " ������� ����������� ������� �.  ";
			query(&size1);
			
			cout << " ������� ����������� ������� B.  ";
			query(&size2);
								
			build_mas(A, size1);
			cout << " ������ �:  "<< endl;
			write_mas(A, size1);
			sorting(A,size1);
			cout <<endl<< " ��������������� ������ � �� �����������:  " << endl;
			write_mas(A, size1);

			cout << endl << endl << endl;

			cout << " ������ �:  " << endl;
			build_mas(B, size2);
			write_mas(B, size2);
			sorting(B, size2);
			cout << endl << " ��������������� ������ � �� �����������:  " << endl;
			write_mas(B, size2);

			cout << endl << endl << endl;

			cout << " ������ C, ��������� �� ��������� �������� � � �:  " << endl;
			create_mas(C, 0, A, size1);
			create_mas(C, size1, B, size1+size2);
			write_mas(C, size1 + size2);
			cout <<endl<< "��������������� ������ C �� �����������:  " << endl;
			sorting(C, size1 + size2);
			write_mas(C, size1 + size2);

			cout << endl << endl << endl;

			system("pause");

			break;




		case 3:
			system("CLS");
			cout << " ������� ����������� ������� �.  ";
			query(&size1);

			cout << " ������� ����������� ������� B.  ";
			query(&size2);


			//  1. ������������ ������
			build_mas(A, size1);
			cout << " ������ �:  " << endl;
			sorting(A, size1);
			write_mas(A, size1);

			cout << endl << endl << endl;

			cout << " ������ �:  " << endl;
			build_mas(B, size2);
			sorting(B, size2);
			write_mas(B, size2);

			cout << endl << endl << endl;

			cout << " ������ C, ��������� �� ��������� �������� � � �:  " << endl;
			create_mas(C, 0, A, size1);
			create_mas(C, size1, B, size1 + size2);
			write_mas(C, size1 + size2);

						
			//  2. ����� �������� ���� ��������
			compare(C, A, B, size1, size2, &size3, 0, 2);
			if (size3 > 0)
			{
				cout << " ������ C, ��������� �� ����� ��������� :  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " ����������� ����� �������� �������� � � �" << endl;
			

			//3. �������� ������� �, ������� ��� � B
			cout << endl << endl << endl;
			compare(C, A, B, size1, size2, &size3,0, 3);
			
			if (size3 > 0)
			{
				cout << " ������ C, ��������� �� ��������� ������� �, ������� �� ���������� � ������ �:  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " ����������� �������� ������� �,������� �� �������� � ������ �." << endl;


			//4. �������� ������� B, ������� ��� � A

			compare(C, B, A, size2, size1, &size3,0,4);

			if (size3 > 0)
			{
				cout << " ������ C, ��������� �� ��������� ������� �, ������� �� ���������� � ������ �:  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " ����������� �������� ������� �,������� �� �������� � ������ �." << endl;


			//5. ��������, ������� �� �������� ������ ��� �������� � � B ������������
			compare(C, A, B, size1, size2, &size3, size3,5);

			if (size3 > 0)
			{
				cout << " ������ C, ��������� �� ���������, ������� �� �������� ������ ��� �������� � � B ������������  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " ����������� ��������, ������� �� �������� ������ ��� �������� � � B ������������ " << endl;
			system("pause");
			break;




		default:
			break;

		}
	} while (answer != 4);
}




//�������


void query(int  *size)
{
	double answer;
	do {

		cout << "������� ����� �����. ";
		cin >> answer;
	
		} while ((answer-int(answer) ) > 0 || answer<=0);
	*size = int(answer);
			system("CLS");
}


void build_mas(int *mas, int size)
{
	for (int i = 0;i < size;i++)
		*(mas + i) = rand() % 20;
}


void write_mas(int *mas, int size)
{
	for (int i = 0;i < size;i++)
		cout << *(mas + i) << "      ";
	cout << endl;
}


void sorting(int *mas, int size)
{
	int memory;
	for (int i = 0;i < size;i++)
	{
		for (int j = i;j < size;j++)
		{
			if (*(mas + i) > *(mas + j))
			{
				memory = *(mas + i);
				*(mas + i) = *(mas + j);
				*(mas + j) = memory;
			}
		}
	}
}


void compare(int *C, int A[], int B[], int size1, int size2, int *index, int start, int task)
{
	int number = 0;
	*index = start;
	for (int i = 0;i < size1;i++)
	{
		for (int j = 0;j < size2;j++)
		{
			if (A[i] == B[j])
				number++;
		}
		if (number == 0 && task>2)
		{
			*(C + (*index)) = A[i];
			(*index)++;
		}
		if (number != 0 && task==2)
		{
			*(C + (*index)) = A[i];
			(*index)++;
		}
		number = 0;
	}
}



void create_mas(int *C, int start, int arr[], int end)
{
	int index = 0;
	for (int i = start;i < end;i++)
	{
		*(C + i) = arr[index];
		index++;
	}
}


void swap(int *A, int size1)
{
	int temp;
	for (int i = 0;i < size1 - 1;)
	{
		temp = *(A + i);
		*(A + i) = *(A + i + 1);
		*(A + i+1) = temp;
		i += 2;
	}	
}





