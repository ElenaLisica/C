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
	int a, v = 1, value = 0;
	int cold_appetizer1 = 0, cold_appetizer2 = 0, cold_appetizer3 = 0, cold_appetizer4 = 0, cold_appetizer5 = 0, first_dish1 = 0, first_dish2 = 0, first_dish3 = 0, first_dish4 = 0, first_dish5 = 0,
		second_dish1 = 0, second_dish2 = 0, second_dish3 = 0, second_dish4 = 0, second_dish5 = 0, dessert1 = 0, dessert2 = 0, dessert3 = 0, dessert4 = 0, dessert5 = 0, drink1 = 0, drink2 = 0, drink3 = 0, drink4 = 0, drink5 = 0;
	SetColor(Green, Black);
	GotoXY(20, 4);
	cout << "�������� \"����������\"" << endl
		<< "1-����\n"
		<< "2-����� �� ���������\n"
		<< "�������� ��������" << endl;
	cin >> a;

	if (a == 1) {
	Menu:	system("CLS");
		GotoXY(20, 4);
		cout << "����\n\n\n"
			<< "1-�������� �������" << endl << "2-������ �����" << endl << "3-������ �����" << endl << "4-������" << endl << "5-�������" << endl
			<< "��� ����� ��� �������  \n";
		cin >> a;
		system("CLS");
		switch (a)
		{
		case 1:
		First_Menu:	system("CLS");
			cout.fill(' ');
			GotoXY(20, 4);
			cout << "�������� �������\n\n\n"
				<< "1-����� � ������ � �����     " << setw(20) << "190�" << setw(10) << "89���" << endl
				<< "2-����� � ������� �����      " << setw(20) << "190�" << setw(10) << "75���" << endl
				<< "3-������ �� ������           " << setw(20) << "150�" << setw(10) << "179���" << endl
				<< "4-������ �������             " << setw(20) << "250�" << setw(10) << "115���" << endl
				<< "5-������� ������ ������������" << setw(20) << "150�" << setw(10) << "199���" << endl
				<< "6-����� � ������� ����" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "������� ������ ������ � ������ � ����� ?  ";
					cin >> a;
					cold_appetizer1 += a;
				}
				else {
					cout << "�� ��� �������� " << cold_appetizer1 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> cold_appetizer1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "������� ������ ������ � ������� ����� ?  ";
					cin >> a;
					cold_appetizer2 += a;
				}
				else {
					cout << "�� ��� �������� " << cold_appetizer2 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> cold_appetizer2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "������� ������ �������� �� ������ ?  ";
					cin >> a;
					cold_appetizer3 += a;
				}
				else {
					cout << "�� ��� �������� " << cold_appetizer3 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> cold_appetizer3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "������� ������ ������ ������� ?  ";
					cin >> a;
					cold_appetizer4 += a;
				}
				else {
					cout << "�� ��� �������� " << cold_appetizer4 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> cold_appetizer4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "������� ������ ������� ������ ������������ ?  ";
					cin >> a;
					cold_appetizer5 += a;
				}
				else {
					cout << "�� ��� �������� " << cold_appetizer5 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> cold_appetizer5;
				}
				break;
			case 6:
				goto Menu;
				break;
			default: goto First_Menu;

			}
			break;

		case 2:
		Second_Menu:system("CLS");
			GotoXY(20, 4);
			cout << "������ �����\n\n\n"
				<< "1-������� ���              " << setw(20) << "400�" << setw(10) << "100���" << endl
				<< "2-���� ����������          " << setw(20) << "300�" << setw(10) << "49���" << endl
				<< "3-��� � ����������         " << setw(20) << "300�" << setw(10) << "55���" << endl
				<< "4-��� ���������            " << setw(20) << "400�" << setw(10) << "69���" << endl
				<< "5-����-��� �� ����� ������ " << setw(20) << "200�" << setw(10) << "49���" << endl
				<< "6-����� � ������� ����" << endl;
			cin >> a;
			switch (a) {
			case 1:
				if (v == 1) {
					cout << "������� ������ ������� ��� ?  ";
					cin >> a;
					first_dish1 += a;
				}
				else {
					cout << "�� ��� �������� " << first_dish1 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> first_dish1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "������� ������ ����� ����������� ?  ";
					cin >> a;
					first_dish2 += a;
				}
				else {
					cout << "�� ��� �������� " << first_dish2 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> first_dish2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "������� ������ ���� � ���������� ?  ";
					cin >> a;
					first_dish3 += a;
				}
				else {
					cout << "�� ��� �������� " << first_dish3 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> first_dish3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "������� ������ ���������� ���� ?  ";
					cin >> a;
					first_dish4 += a;
				}
				else {
					cout << "�� ��� �������� " << first_dish4 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> first_dish4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "������� ������ ����-���� �� ����� ������ ? ";
					cin >> a;
					first_dish5 += a;
				}
				else {
					cout << "�� ��� �������� " << first_dish5 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> first_dish5;
				}
				break;
			case 6:
				goto Menu;
				break;
			default: goto Second_Menu;
			}
			break;

		case 3:
		Third_Menu:	system("CLS");
			cout.fill(' ');
			GotoXY(20, 4);
			cout << "������ �����\n\n\n"
				<< "1-���� ������ � �������      " << setw(20) << "400�" << setw(10) << "35���" << endl
				<< "2-��������� ������� � �������" << setw(20) << "400�" << setw(10) << "40���" << endl
				<< "3-����� � ������ �������     " << setw(20) << "260�" << setw(10) << "55���" << endl
				<< "4-���� ������ � �������      " << setw(20) << "300�" << setw(10) << "109���" << endl
				<< "5-�������� �������� ���      " << setw(20) << "300�" << setw(10) << "85���" << endl
				<< "6-����� � ������� ����" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "������� ������ ���� ������ � �������?  ";
					cin >> a;
					second_dish1 += a;
				}
				else {
					cout << "�� ��� �������� " << second_dish1 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> second_dish1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "������� ������ ������� � ������� ?  ";
					cin >> a;
					second_dish2 += a;
				}
				else {
					cout << "�� ��� �������� " << second_dish2 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> second_dish2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "������� ������ ������ � ������ ������� ?  ";
					cin >> a;
					second_dish3 += a;
				}
				else {
					cout << "�� ��� �������� " << second_dish3 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> second_dish3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "������� ������ ���� ������ � ������� ?  ";
					cin >> a;
					second_dish4 += a;
				}
				else {
					cout << "�� ��� �������� " << second_dish4 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> second_dish4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "������� ������ ��������� ��������� ���� ?  ";
					cin >> a;
					second_dish5 += a;
				}
				else {
					cout << "�� ��� �������� " << second_dish5 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> second_dish5;
				}
				break;
			case 6:
				goto Menu;
				break;
			default: goto Third_Menu;

			}
			break;
		case 4:
		Fourth_Menu:	system("CLS");
			cout.fill(' ');
			GotoXY(20, 4);
			cout << "�������\n\n\n"
				<< "1-���������� ����      " << setw(20) << "150�" << setw(10) << "55���" << endl
				<< "2-�������� ��������    " << setw(20) << "180�" << setw(10) << "55���" << endl
				<< "3-��������             " << setw(20) << "150�" << setw(10) << "45���" << endl
				<< "4-���������� ������    " << setw(20) << "100�" << setw(10) << "59���" << endl
				<< "5-������� �� ��������  " << setw(20) << "200�" << setw(10) << "60���" << endl
				<< "6-����� � ������� ����" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "������� ������ ����������� ����� ?  ";
					cin >> a;
					dessert1 += a;
				}
				else {
					cout << "�� ��� �������� " << dessert1 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> dessert1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "������� ������ �������� ?  ";
					cin >> a;
					dessert2 += a;
				}
				else {
					cout << "�� ��� �������� " << dessert2 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> dessert2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "������� ������ ��������� ?  ";
					cin >> a;
					dessert3 += a;
				}
				else {
					cout << "�� ��� �������� " << dessert3 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> dessert3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "������� ������ ����������� ������� ?  ";
					cin >> a;
					dessert4 += a;
				}
				else {
					cout << "�� ��� �������� " << dessert4 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> dessert4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "������� ������ �������� �� ��������?  ";
					cin >> a;
					dessert5 += a;
				}
				else {
					cout << "�� ��� �������� " << dessert5 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> dessert5;
				}
				break;
			case 6:
				goto Menu;
				break;
			default: goto Fourth_Menu;

			}
			break;
		case 5:
		Fifth_Menu:	system("CLS");
			cout.fill(' ');
			GotoXY(20, 4);
			cout << "�������\n\n\n"
				<< "1-������             " << setw(20) << "250�" << setw(10) << "40���" << endl
				<< "2-���� ����������    " << setw(20) << "250�" << setw(10) << "65���" << endl
				<< "3-������             " << setw(20) << "250�" << setw(10) << "40���" << endl
				<< "4-�������� ���       " << setw(20) << "500�" << setw(10) << "40���" << endl
				<< "5-������� ����       " << setw(20) << "350�" << setw(10) << "60���" << endl
				<< "6-����� � ������� ����" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "������� ������ ������� ?  ";
					cin >> a;
					drink1 += a;
				}
				else {
					cout << "�� ��� �������� " << drink1 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> drink1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "������� ������ ����� ����������� ?  ";
					cin >> a;
					drink2 += a;
				}
				else {
					cout << "�� ��� �������� " << drink2 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> drink2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "������� ������ ������ ?  ";
					cin >> a;
					drink3 += a;
				}
				else {
					cout << "�� ��� �������� " << drink3 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> drink3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "������� ������ ��������� ��� ?  ";
					cin >> a;
					drink4 += a;
				}
				else {
					cout << "�� ��� �������� " << drink4 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> drink4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "������� ������ ������� ����?  ";
					cin >> a;
					drink5 += a;
				}
				else {
					cout << "�� ��� �������� " << drink5 << " ������ ����� �����. ������� ������ ��� ����������?";
					cin >> drink5;
				}
				break;
			case 6:
				goto Menu;
				break;
			default: goto Fifth_Menu;

			}
			break;
		default: goto Menu;
		}
	Kontrol_Question:system("CLS");
		cout << "�� ������� ���-�� ��� ? " << endl << "1- ��, ���� �������� " << endl << "2- ���, ���� ��������� ���������" << endl << "3- �������, ����� ����������" << endl;
		cin >> v;
		switch (v) {
		case 1:
			goto Menu;
			break;
		case 2:
			v = 2;
			goto Menu;
			break;
		case 3:
			goto Check;
			break;
		default:
			goto Kontrol_Question;
		}
	Check: system("CLS");

		if (cold_appetizer1 != 0 || cold_appetizer2 != 0 || cold_appetizer3 != 0 || cold_appetizer4 != 0 || cold_appetizer5 != 0 || first_dish1 != 0 ||
			first_dish2 != 0 || first_dish3 != 0 || first_dish4 != 0 || first_dish5 != 0 || second_dish1 != 0 || second_dish2 != 0 || second_dish3 != 0 || second_dish4 != 0 ||
			second_dish5 != 0 || dessert1 != 0 || dessert2 != 0 || dessert3 != 0 || dessert4 != 0 || dessert5 != 0 || drink1 != 0 || drink2 != 0 || drink3 != 0 || drink4 != 0 || drink5 != 0)
		{
			GotoXY(20, 4);
			cout << "��� �����:" << endl << endl << "������������" << setw(33) << "���������� ������,��" << setw(9) << "����,���" << setw(15) << "���������,���"  << endl
				<<"______________________________________________________________________________________________________" << endl;

			if (cold_appetizer1 != 0) { cout << "����� � ������ � �����         " << setw(10) << cold_appetizer1 << setw(10) << 89  << setw(10) << cold_appetizer1 * 89  << endl; value += cold_appetizer1 * 89; }
			if (cold_appetizer2 != 0) { cout << "����� � ������� �����          " << setw(10) << cold_appetizer2 << setw(10) << 75  << setw(10) << cold_appetizer2 * 75  << endl; value += cold_appetizer2 * 75; }
			if (cold_appetizer3 != 0) { cout << "������ �� ������               " << setw(10) << cold_appetizer3 << setw(10) << 179 << setw(10) << cold_appetizer3 * 179 << endl;value += cold_appetizer3 * 179; }
			if (cold_appetizer4 != 0) { cout << "������ �������                 " << setw(10) << cold_appetizer4 << setw(10) << 115 << setw(10) << cold_appetizer4 * 115 << endl; value += cold_appetizer4 * 115; }
			if (cold_appetizer5 != 0) { cout << "������� ������ ������������    " << setw(10) << cold_appetizer5 << setw(10) << 199 << setw(10) << cold_appetizer5 * 199 << endl; value += cold_appetizer5 * 199; }
			if (first_dish1 != 0) { cout << "������� ���                    "     << setw(10) << first_dish1     << setw(10) << 100 << setw(10) << first_dish1 * 100     << endl;  value += first_dish1 * 100; }
			if (first_dish2 != 0) { cout << "���� ����������                "     << setw(10) << first_dish2     << setw(10) << 49  << setw(10) << first_dish2 * 49      << endl; value += first_dish2 * 49; }
			if (first_dish3 != 0) { cout << "��� � ����������               "     << setw(10) << first_dish3     << setw(10) << 55  << setw(10) << first_dish3 * 55      << endl; value += first_dish3 * 55; }
			if (first_dish4 != 0) { cout << "��� ���������                  "     << setw(10) << first_dish4     << setw(10) << 69  << setw(10) << first_dish4 * 69      << endl; value += first_dish4 * 69; }
			if (first_dish5 != 0) { cout << "����-��� �� ����� ������       "     << setw(10) << first_dish5     << setw(10) << 49  << setw(10) << first_dish5 * 49      << endl; value += first_dish5 * 49; }
			if (second_dish1 != 0) { cout << "���� ������ � �������          "    << setw(10) << second_dish1    << setw(10) << 35  << setw(10) << second_dish1 * 35     << endl; value += second_dish1 * 35; }
			if (second_dish2 != 0) { cout << "��������� ������� � �������    "    << setw(10) << second_dish2    << setw(10) << 40  << setw(10) << second_dish2 * 40     << endl; value += second_dish2 * 40; }
			if (second_dish3 != 0) { cout << "����� � ������ �������         "    << setw(10) << second_dish3    << setw(10) << 55  << setw(10) << second_dish3 * 55     << endl; value += second_dish3 * 55; }
			if (second_dish4 != 0) { cout << "���� ������ � �������          "    << setw(10) << second_dish4    << setw(10) << 109 << setw(10) << second_dish4 * 109    << endl; value += second_dish4 * 109; }
			if (second_dish5 != 0) { cout << "�������� �������� ���          "    << setw(10) << second_dish5    << setw(10) << 85  << setw(10) << second_dish5 * 85     << endl; value += second_dish5 * 85; }
			if (dessert1 != 0) { cout << "���������� ����                "        << setw(10) << dessert1        << setw(10) << 55  << setw(10) << dessert1 * 55         << endl; value += dessert1 * 55; }
			if (dessert2 != 0) { cout << "�������� ��������              "        << setw(10) << dessert2        << setw(10) << 55  << setw(10) << dessert2 * 55         << endl; value += dessert2 * 55; }
			if (dessert3 != 0) { cout << "��������                       "        << setw(10) << dessert3        << setw(10) << 45  << setw(10) << dessert3 * 45         << endl; value += dessert3 * 45; }
			if (dessert4 != 0) { cout << "���������� ������              "        << setw(10) << dessert4        << setw(10) << 59  << setw(10) << dessert4 * 59         << endl; value += dessert4 * 59; }
			if (dessert5 != 0) { cout << "������� �� ��������            "        << setw(10) << dessert5        << setw(10) << 60  << setw(10) << dessert5 * 60         << endl; value += dessert5 * 60; }
			if (drink1 != 0) { cout << "������                         "          << setw(10) << drink1          << setw(10) << 40  << setw(10) << drink1 * 40           << endl; value += drink1 * 40; }
			if (drink2 != 0) { cout << "���� ����������                "          << setw(10) << drink2          << setw(10) << 65  << setw(10) << drink2 * 65           << endl; value += drink2 * 65; }
			if (drink3 != 0) { cout << "������                         "          << setw(10) << drink3          << setw(10) << 40  << setw(10) << drink3 * 40           << endl; value += drink3 * 40; }
			if (drink4 != 0) { cout << "�������� ���                   "          << setw(10) << drink4          << setw(10) << 40  << setw(10) << drink4 * 40           << endl; value += drink4 * 40; }
			if (drink5 != 0) { cout << "������� ����                   "          << setw(10) << drink5			 << setw(10) << 60  << setw(10) << drink5 * 60           << endl;value += drink5 * 60; }
			cout << "______________________________________________________________________________________________________" << endl<< "� ������  " << value << "���" << endl << endl << "��������� ����������������!";
		}

		else  cout << "���..�� ������ �� ��������...";

		PlaySound(TEXT("music.wav"), NULL, SND_FILENAME);
	}
}

