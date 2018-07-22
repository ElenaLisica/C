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
		cout << "Задания" << endl << "1. Поменять местами элементы массива" << endl
			<< "2. Из двух массивов сформировать один массив, упорядоченный по возростанию" << endl 
			<< "3. Из двух массивов сформировать третий с 5 заданиями к нему"<<endl
			<< "4. Выход" << endl;
		do {
			cout << "Выберите один из предложенных вариантов" << endl;
			cin >> answer;
		} while (answer != 1 && answer != 2 && answer != 3 && answer != 4);

		switch (answer)
		{
		case 1:
			do {
				system("CLS");
				cout << "Введите размер массива. Для данной задачи это должно быть четное число.    ";
				cin >> answer2;
				} while ((answer2 - int(answer2))> 0 || answer2 <= 0 || int(answer2)%2!=0);
				
					size1 =int (answer2);

			cout << "Исходный массив" << endl;
			build_mas(A, size1);
			write_mas(A, size1);
			swap(A, size1);
			cout << endl<<"Новый массив" << endl;
			write_mas(A, size1);
			system("pause");
			break;


		case 2:
			
			system("CLS");
			cout << " Укажите размерность массива А.  ";
			query(&size1);
			
			cout << " Укажите размерность массива B.  ";
			query(&size2);
								
			build_mas(A, size1);
			cout << " Массив А:  "<< endl;
			write_mas(A, size1);
			sorting(A,size1);
			cout <<endl<< " Отсортированный массив А по возрастанию:  " << endl;
			write_mas(A, size1);

			cout << endl << endl << endl;

			cout << " Массив В:  " << endl;
			build_mas(B, size2);
			write_mas(B, size2);
			sorting(B, size2);
			cout << endl << " Отсортированный массив В по возрастанию:  " << endl;
			write_mas(B, size2);

			cout << endl << endl << endl;

			cout << " Массив C, состоящий из элементов массивов А и В:  " << endl;
			create_mas(C, 0, A, size1);
			create_mas(C, size1, B, size1+size2);
			write_mas(C, size1 + size2);
			cout <<endl<< "Отсортированный массив C по возрастанию:  " << endl;
			sorting(C, size1 + size2);
			write_mas(C, size1 + size2);

			cout << endl << endl << endl;

			system("pause");

			break;




		case 3:
			system("CLS");
			cout << " Укажите размерность массива А.  ";
			query(&size1);

			cout << " Укажите размерность массива B.  ";
			query(&size2);


			//  1. объединенный массив
			build_mas(A, size1);
			cout << " Массив А:  " << endl;
			sorting(A, size1);
			write_mas(A, size1);

			cout << endl << endl << endl;

			cout << " Массив В:  " << endl;
			build_mas(B, size2);
			sorting(B, size2);
			write_mas(B, size2);

			cout << endl << endl << endl;

			cout << " Массив C, состоящий из элементов массивов А и В:  " << endl;
			create_mas(C, 0, A, size1);
			create_mas(C, size1, B, size1 + size2);
			write_mas(C, size1 + size2);

						
			//  2. общие элементы двух массивов
			compare(C, A, B, size1, size2, &size3, 0, 2);
			if (size3 > 0)
			{
				cout << " Массив C, состоящий из общих элементов :  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " Отсутствуют общие элементы массивов А и В" << endl;
			

			//3. Элементы массива А, которых нет в B
			cout << endl << endl << endl;
			compare(C, A, B, size1, size2, &size3,0, 3);
			
			if (size3 > 0)
			{
				cout << " Массив C, состоящий из элементов массива А, которые не включаются в массив В:  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " Отсутствуют элементы массива А,которые не включены в массив В." << endl;


			//4. Элементы массива B, которых нет в A

			compare(C, B, A, size2, size1, &size3,0,4);

			if (size3 > 0)
			{
				cout << " Массив C, состоящий из элементов массива В, которые не включаются в массив А:  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " Отсутствуют элементы массива В,которые не включены в массив А." << endl;


			//5. Элементы, которые не являются общими для массивов А и B одновременно
			compare(C, A, B, size1, size2, &size3, size3,5);

			if (size3 > 0)
			{
				cout << " Массив C, состоящий из элементов, которые не являются общими для массивов А и B одновременно  " << endl;
				write_mas(C, size3);
			}
			else
				cout << " Отсутствуют элементы, которые не являются общими для массивов А и B одновременно " << endl;
			system("pause");
			break;




		default:
			break;

		}
	} while (answer != 4);
}




//Функции


void query(int  *size)
{
	double answer;
	do {

		cout << "Введите целое число. ";
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





