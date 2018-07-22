#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int answer,i,j,number, odd = 0, even = 0, multiply = 1;
	const int sizze = 3;
	int mass[sizze][sizze] = { {},{} };
Menu:
	const int size = 10;
	int mas[size] = {};
	system("CLS");
	cout << "Задания:" << endl << "1. Вывод содержимого массива наоборот" << endl << "2. Вывод суммы четных и нечетных элементов массива" << endl
		<< "3. Вывод повторяющихся элементов массива" << endl << "4. Вывод наименьшего нечетного числа массива" << endl
		<< endl<<"Дополнительные задания:"<<endl<< "5.Вывод отсортированного массива по убыванию" << endl << "6.Квадратная матрица и некоторые дествия с ней" << endl<<endl << "Выберите один из предложенных вариантов" << endl;
	cin >> answer;
	system("CLS");
	switch (answer)
	{
	case 1:

				
				cout << "Массив :"<<endl;
				for ( i = 0;i < size;i++)
				{
					mas[i] = rand() % 28 - 8;
					cout << mas[i] << "  ";
				}
				cout << endl<<endl << " Содержимое массива наоборот:"<<endl;
				for ( i = size-1;i >=0;i--)
				{
					cout << mas[i] << "  ";
				}
				cout << endl<< endl;

		break;


	case 2:

				cout << "Массив :" << endl;
				for ( i = 0;i < size;i++)
				{
					mas[i] = rand() % 28 - 8;
					cout << mas[i] << "  ";
					(mas[i] % 2 == 0) ? even+=mas[i] : odd += mas[i];
				}
				cout << endl << endl << " Сумма четных чисел равна  " << even<<endl<<" Сумма нечетных чисел равна  "<<odd<<endl<<endl;
	
	break;




	case 3:
				 number = 1;
				cout << "Массив :" << endl;
				for ( i = 0;i < size;i++)
				{
					mas[i] = rand() % 28 - 8;
					cout << mas[i] << "  ";
				}
	
				cout <<endl<< " Повторяющиеся элементы в массиве:      ";
				for (i = 0;i < size;i++)
				{
					for ( j = i + 1;j < size;j++)
					{
						if (mas[i] == mas[j])
							number++;
					}
					if (number > 1)
						cout << mas[i] << ";  ";
					number = 1;
					}
		
				cout << endl;
		break;




	case 4:
				 number=100;
				cout << "Массив :" << endl;
				for ( i = 0;i < size;i++)
				{
					mas[i] = rand() % 28 - 8;
					cout << mas[i] << "  ";
					if (mas[i] % 2 != 0)
						number = mas[i];
		
				}
				if (number == 100)
				{
					cout << endl << " В данном массиве нет нечетного числа" << endl;
					goto exit;
				}
				else {
					for ( i = 0;i < size;i++)
					{
						if (mas[i] % 2 != 0)
						{
							if (number > mas[i])
								number = mas[i];
						}
					}

					cout << endl << " Наименьшее нечетное число в массиве равно   " << number;
				}
				exit:cout << endl; ;
		break;



	case 5:
				cout << "Массив :" << endl;
				for (i = 0;i < size;i++)
				{
					mas[i] = rand() % 28 - 8;
					cout << mas[i] << "  ";
				}
				cout << endl << endl << " Отсортированный массив по убыванию:" << endl;
	
				for ( i = 0;i <size; i++)
				{
					for ( j = 0;j < size; j++)
					{
						if (mas[j] < mas[i])
						{
							int temporarily = mas[j];
							mas[j] = mas[i];
							mas[i] = temporarily;
						}
					}		
				}
				for ( i = 0;i < size;i++)
				{
					cout << mas[i] << "  ";
				}
				cout << endl << endl;
		break;






	case 6:

				
				
				
				cout << "Квадратная матрица третьего порядка :" << endl;
				for (i = 0;i < sizze;i++)
				{
					for ( j = 0;j < sizze;j++)
					{
						mass[i][j] = rand() % 28 - 8;
						cout << setw(5)<<mass[i][j] << "  ";
						if (i == j)
							multiply *= mass[i][j];
		
					}
					cout << endl << endl;
				}
				cout << endl << endl << " Произведение элементов по главной диагонали равно  " << multiply<<endl<<endl;


				cout << "Транспонированная матрица :" << endl;
				for (j = 0;j < sizze;j++)
				{
					for (i = 0;i < sizze;i++)
					{
						cout << setw(5) << mass[i][j] << "  ";
					}
					cout << endl << endl;
				}
		break;


	default:
		goto Menu;

}

				system("pause");
				goto Menu;
}





