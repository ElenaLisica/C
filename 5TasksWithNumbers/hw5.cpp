#include <iostream>
#include <Windows.h>
#include <iomanip>
#include<MMSystem.h>
using namespace std;
void main()
{
	setlocale(LC_ALL, "Russian");
	int j, i, rez, division1, division2, result,answer,k;
	float number;
Menu:
	system("CLS");
	cout << "Задания:" << endl << "1. Определение количества цифр в числе" << endl << "2. Вывод на экран перевернутого числа" << endl << "3. Сумма цифр введенного числа" << endl<<
		endl <<"Выберите номер задачи"<<endl;
	cin >>answer;
	switch (answer)
	{
		case 1:
		Message1:
			system("CLS");
			cout << "Введите целое число"<< endl;
			cin >> number;
			if ((number - int(number)) != 0)
					{
					cout << "Вы ввели дробное число"<<endl;
					system("pause");
					goto Message1;
					}
			else {
			        j = 10;
				for (i = 1;;i++)
					{
					 rez = abs(number) / j;
					if (rez < 1)
						break;
					j *= 10;
					}
				system("CLS");
				cout << abs(number) << " содержит " << i << "цифр" << endl << endl;
				}

		break;




	case 2:
		Message2:
			system("CLS");
			cout << "Введите целое число" << endl;
			cin >> number;
			k = 0;
			result = 0;
			division1 = 0;
			division2 = 0;
			j = 10;
			if ((number - int(number)) != 0||(number>180000))
			{
				cout << "Не допускаются дробные числа и те, которые более 180000" << endl;
				system("pause");
				goto Message2;
			}
			else {
				system("CLS");
				cout << "Для числа  " << abs(number) << " перевернутым является число ";
				if (((int(number) % j) / (j*0.1)) == 0)
				{
					for (;;)
					{
						if (((int(number) % j) / (j*0.1)) != 0)
							break;
						j *= 10;
						k++;
					}			
				}
				for (;;)
				{
					if ((abs(number) / (j*0.1)) < 1)
						break;
					division1 = int(number) % j;
					division2 = division1 / (j*0.1);
					result = result * 10 + division2;
					j *= 10;
				}
			}
			if (k>=1)
				{
				for (rez= 1;rez<= k;rez++)
				{
					cout << 0;
		
				}
				}
			
				cout <<abs(result)<<endl << endl;

		break;



	case 3:
		system("CLS");
		cout << "Введите целое число" << endl;
	Message3:	cin >> number;
		result = 0;
		division1 = 0;
		division2 = 0;
		j = 10;
		if ((number - int(number)) != 0 )
		{
			cout << "Вы ввели дробное число. Введите целое" << endl;
			goto Message3;
		}
		else {

			for (;;)
			{
				if ((abs(number) / (j*0.1)) < 1)
					break;
				division1 = int(number) % j;
				division2 = division1 / (j*0.1);
				result = result + division2;
				j *= 10;
			}
		}
		system("CLS");
		cout << "Сумма цифр числа " << abs(number) << "   равна   " << abs(result) << endl << endl;
		break;

		

	default:
			goto Menu;
	}
	system("pause");
	goto Menu;
}