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
	int answer, i, j, k, max, z,zz,number, change;
	float answer1;
	const int size = 100;
	int mas[size][size] = { {},{} };
	const int m = 100;
	int mas1[m] = {};
	do
	{
		cout << "�������:" << endl << "1. ����� ������� ��������� � �� ��������� ����������� ������� 3�4" << endl << "2. ����� ����������� �������� �������������� � ������ ������� ���������� �������" << endl
			<< endl << "�������������� �������:" << endl << "3.������������ ����������� ������� �� ��������� ��� ������� ���������� ���������� �������" << endl 
			<<"4. ������������ ������ ������� �� �������������� ����� ������� ������� "<< endl << endl << "�������� ���� �� ������������ ��������� " << endl;
		cin >> answer;
		while (answer != 1 && answer != 2 && answer != 3 && answer != 4 )
		{

			cout << "������� ���� �� ������������ �������  ";
			cin >> answer;

		}
		system("CLS");
		switch (answer)
		{
		case 1:
			number = 0;
			cout << "������ :" << endl;
			for (i = 0;i < 3;i++)
			{
				for (j = 0;j < 4;j++)
				{
					mas[i][j] = rand() % 16 - 10;
					cout << setw(5) << mas[i][j] << "  ";
				}
				cout << endl;
			}
			cout << endl << endl;
			cout << "������� �������� ������� :" << endl;
			for (i = 0;i < 3;i++)
			{
				for (j = 0;j < 4;j++)
				{
					if (mas[i][j] == 0) {
						number++;
						cout << " ������� m" << i + 1 << j + 1 << endl;
					}
				}
			}
			cout << endl << endl;
			cout << "���������� ������� ��������� ����� " << number << endl << endl << endl << endl;
			break;



		case 2:


			cout << "�������:" << endl << "1.  -  �" << endl << "2.  -  �" << endl << "�������� ���� �� ������������ ���������" << endl;
			cin >> answer;
			while (answer != 1 && answer != 2)
			{
				cout << "������� ���� �� ������������ �������";
				cin >> answer;
			}
			switch (answer)
			{
			case 1:
						
				
				do			
				{
					cout << "�������  ����������� ����� -  �������  ���������� �������:"<<endl;
					cin >> answer1;
					
			 } while ((answer1 <= 0) || (answer1 - int(answer1)) > 0);

			 if (answer1 == 1)
				 cout << " ������������ ������� ����� " << rand() % 26 - 10<<endl;
			 else {

				 number = answer1;
				 system("CLS");
				 for (i = 0;i < number;i++)
				 {
					 for (j = 0;j < number;j++)
					 {
						 mas[i][j] = rand() % 26 - 10;
						 cout << setw(5) << mas[i][j] << "  ";
					 }
					 cout << endl << endl;
				 }
				 cout << endl << endl;
				 z = 0;
				 k = int(number / 2);
				 if (number % 2 != 0)
				 {
					 max = mas[k][k];
					 change = k;
				 }
				 else
				 {
					 max = mas[k + 1][k];
					 change = k - 1;
				 }
				 for (i = k;i < number;i++)
				 {
					 for (j = 0;j <= i;j++)
					 {
						 if (j >= change - z)
						 {
							 cout << setw(5) << mas[i][j] << "  ";
							 if (max < mas[i][j])
								 max = mas[i][j];
						 }
						 else
							 cout << setw(5) << "  " << "  ";
					 }
					 z++;
					 cout << endl << endl;

				 }
				 cout << "������������ ������� �����  " << max << endl;
			 }
					
					break;

				case 2:

					do

					{
						cout << "�������  ����������� ����� -  �������  ���������� �������:" << endl;
						cin >> answer1;
					
					} while ((answer1 <= 0) || (answer1 - int(answer1)) > 0);

					if (answer1 == 1)
						cout << " ������������ ������� ����� " << rand() % 26 - 10<<endl;
					else {
						number = answer1;
						system("CLS");
						for (i = 0;i < number;i++)
						{
							for (j = 0;j < number;j++)
							{
								mas[i][j] = rand() % 26 - 10;
								cout << setw(5) << mas[i][j] << "  ";
							}
							cout << endl << endl;
						}
						cout << endl << endl;

						z = 1;	k = int(number / 2);
						if (number % 2 != 0)
						{
							max = mas[0][0];
							change = k;
						}
						else
						{
							max = mas[0][0];
							change = k - 1;
						}
						for (i = 0;i < number;i++)
						{
							for (j = 0;j < number;j++)
							{

								if (i <= k) {
									if (j <= i || j >= number - z || i >= k + 1)
									{
										cout << setw(5) << mas[i][j] << "  ";
										if (max < mas[i][j])
											max = mas[i][j];

									}
									else
										cout << setw(5) << "  " << "  ";
								}
								if (i == k)
									zz = 0;

								if (i > k)
								{
									if (j <= change - zz || j >= k + zz || i < k + 1)
									{
										cout << setw(5) << mas[i][j] << "  ";
										if (max < mas[i][j])
											max = mas[i][j];
									}
									else
										cout << setw(5) << "  " << "  ";
								}
							}
							cout << endl << endl;
							z++;
							zz++;
						}
						cout << endl << endl;
						cout << "������������ ������� ����� " << max << endl << endl << endl;
					}
					break;
									
			
				}

				break;


				case 3:

					do

					{
						cout << "�������  ����������� ����� -  �������  ���������� �������:" << endl;
						cin >> answer1;

					} while ((answer1 <= 0) || (answer1 - int(answer1)) > 0);

					number = answer1;
					system("CLS");
					cout << "������ :" << endl;
					k = 0;
					for (i = 0;i < number;i++)
					{
						for (j = 0;j < number;j++)
						{
							mas[i][j] = rand() % 26 - 10;
							cout << setw(5) << mas[i][j] << "  ";
							if (j > i)
							{
								mas1[k] = mas[i][j];
								k++;
							}
						}
						cout << endl << endl;
					}
					cout << endl << endl;


					cout << "������, ��������� �� ��������� ��� ������� ���������� " << endl << endl << endl << endl;
					for (i = 0; i< k;i++)
					{
						cout << setw(5) << mas1[i] << "  ";

					}
					cout << endl << endl;
					break;




				case 4:

					number = 0;
					cout << "������ :" << endl;
					for (i = 0;i < 12;i++)
					{
						for (j = 0;j < 3;j++)
						{
							mas[i][j] = rand() % 16 - 10;
							cout << setw(5) << mas[i][j] << "  ";
						}
						cout << endl;
					}
					cout << endl << endl;
					
					
					
					cout << "���������� ������ :" << endl;
					for (i = 0;i < 6;i++)
					{
						for (j = 0;j < 3;j++)
						{
							cout << setw(5) << mas[i][j] << "  ";
						}
						cout << endl;
						cout << setw(5) << mas[11-number][0] << "  " << setw(5) << mas[11 - number][1] << "  " << setw(5) << mas[11 - number][2] << "  "<<endl;
						number++;
					}
					
					break;



			}			
			system("pause");
			system("CLS");
		}
		while (answer == 1 || answer == 2 || answer == 3 || answer == 4);
	
}




if (number == 1) {
	int **pmas_transpose1 = new int*[column];
	for (int i = 0; i < column; i++)
		pmas_transpose1[i] = new int[line];
}
else {
	int **pmas_transpose2 = new int*[column];
	for (int i = 0; i < column; i++)
		pmas_transpose2[i] = new int[line];
}


for (int i = 0; i < line; i++)
{
	for (int j = 0; j <column; j++)
	{
		if (number == 1) {
			pmas_transpose1[j][i] = pmas[i][j];
		}
		else {
			pmas_transpose2[j][i] = pmas[i][j];
		}
	}
}
if (number == 1) {
	write_mas(pmas_transpose1, column, line);
}
else {
	write_mas(pmas_transpose2, column, line);
}
