#include<iostream>
#include<Windows.h>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include <ctime>
#include<stdio.h>
using namespace std;

void question(int &i, int &j);

void build_mas(int **pmas, int line, int column);

void build_mas1(int **pmas, int line, int column);

void write_mas(int **pmas, int line, int column);

void transpose1(int **pmas, int line, int column);

void transpose2(int **pmas, int line, int column);

void add_column(int **pmas, int line, int column);

void appropriation(int **pmas1, int **pmas2, int line, int column);

void sorting1(int **pmas, int line, int column);

void sorting2(int **pmas, int line, int column);

void average(int **pmas, int line, int column);

void delete_array(int **pmas, int line, int column);

enum ConsoleColor
{
	Black, Blue, Green, Cyan, Red, Magenta, Brown, LightGray, DarkGray,
	LightBlue, LightGreen, LightCyan, LightRed, LightMagenta, Yellow, White
};
void SetColor(int text, int background);




void main()
{
srand(time(NULL));
setlocale(LC_ALL, "Russian");
int line,line2, column, column2;
cout << "  Матрица первая :" << endl;

question(line, column);

int **pmas = new int*[line]; 
for (int i = 0; i < line; i++)
	pmas[i] = new int[column];

void(*arrayWork1[])(int **pmas, int line, int column) = { build_mas , write_mas, transpose1, sorting1, add_column, average,delete_array };
for (int i = 0;i <7;i++)
{
	arrayWork1[i](pmas,line, column);
	cout << endl;
}

SetColor(Yellow, Black);

cout << " Матрица вторая" << endl;
question(line2, column2);

int **pmas1 = new int*[line2];
for (int i = 0; i < line2; i++)
	pmas1[i] = new int[column2];

void(*arrayWork2[])(int **pmas1, int line2, int column2) = { build_mas1 , write_mas, transpose2, sorting2,add_column, average,delete_array };
for (int i = 0;i < 7;i++)
{
	arrayWork2[i](pmas1, line2, column2);
	cout << endl;
}
}


void question(int &i, int &j)
{
	double size;
	do
	{
		cout << "Введите  натуральное число -  количество строк матрицы:" << endl;
		cin >> size;

	} while ((size <= 0) || (size - int(size)) > 0);
	i = int(size);
	do
	{
		cout << "Введите  натуральное число -  количество столбцов матрицы:" << endl;
		cin >> size;

	} while ((size <= 0) || (size - int(size)) > 0);
	j = int(size);
}

void build_mas(int **pmas, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			pmas[i][j] = rand() % 21 - 10;
		}
	}
}

void build_mas1(int **pmas, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			pmas[i][j] = rand() % 41 - 20;
		}
	}
}


void write_mas(int **pmas, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			cout << setw(5) << pmas[i][j];
		}
		cout << "\n";
	}
}


void transpose1(int **pmas, int line, int column)
{
	int **pmas_transpose = new int*[column];
	for (int i = 0; i < column; i++)
		pmas_transpose[i] = new int[line];

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			pmas_transpose[j][i] = pmas[i][j];
		}
	}
	cout << " Транспонированный массив:" << endl;
	write_mas(pmas_transpose, column, line);
}


void transpose2(int **pmas, int line, int column)
{
	int **pmas_transpose1 = new int*[column];
	for (int i = 0; i < column; i++)
		pmas_transpose1[i] = new int[line];

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			pmas_transpose1[j][i] = pmas[i][j];
		}
	}
	cout << " Транспонированный массив:" << endl;
	write_mas(pmas_transpose1, column, line);
}


void add_column(int **pmas, int line, int column)
{
	int sum;
	for (int j = 0; j <column; j++)
	{
		sum = 0;
		for (int i = 0; i < line; i++)
		{
			sum += pmas[i][j];
		}
		cout << " По " << j + 1 << " столбцу исходной матрицы сумма элементов равна " << sum << endl;
	}
}


void appropriation(int **pmas1, int **pmas2, int line, int column)
{
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			pmas2[i][j] = pmas1[i][j];
		}
	}


}
void sorting1(int **pmas, int line, int column)
{
	int **pmas_sorting = new int*[line];
	for (int i = 0; i < line; i++)
		pmas_sorting[i] = new int[column];

	appropriation(pmas, pmas_sorting, line, column);

	int memory;
	for (int i = 0;i < line;i++)
	{

		for (int j = 0;j < column;j++)
			for (int k = j + 1;k < column;k++)
			{
				if (pmas_sorting[i][j] > pmas_sorting[i][k])
				{
					memory = pmas_sorting[i][j];
					pmas_sorting[i][j] = pmas_sorting[i][k];
					pmas_sorting[i][k] = memory;
				}
			}
	}
	cout << " Массив с отсортированными строками по возрастанию  исходной матрицы:" << endl;
	write_mas(pmas_sorting, line, column);

}


void sorting2(int **pmas, int line, int column)
{
	int **pmas_sorting1 = new int*[line];
	for (int i = 0; i < line; i++)
		pmas_sorting1[i] = new int[column];

	appropriation(pmas, pmas_sorting1, line, column);
	int memory;
	for (int i = 0;i < line;i++)
	{

		for (int j = 0;j < column;j++)
			for (int k = j + 1;k < column;k++)
			{
				if (pmas_sorting1[i][j] > pmas_sorting1[i][k])
				{
					memory = pmas_sorting1[i][j];
					pmas_sorting1[i][j] = pmas_sorting1[i][k];
					pmas_sorting1[i][k] = memory;
				}
			}
	}
	cout << " Массив с отсортированными строками по возрастанию исходной матрицы:" << endl;
	write_mas(pmas_sorting1, line, column);
}




void average(int **pmas, int line, int column)
{
	double sum = 0;
	int n = 0;
	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j <column; j++)
		{
			sum += pmas[i][j];
			n++;
		}

	}
	cout << endl << " Среднее арифметическое элементов массива равно " << fixed << setprecision(3) << sum / n << endl;
}


void delete_array(int **pmas, int line, int column)
{
	for (int i = 0; i < line; i++)
		delete[]pmas[i];
	delete[]pmas;
	pmas = nullptr;
}

void SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}



























