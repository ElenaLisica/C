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
	cout << "Ресторан \"Аристократ\"" << endl
		<< "1-Меню\n"
		<< "2-Выход из программы\n"
		<< "Выберите действие" << endl;
	cin >> a;

	if (a == 1) {
	Menu:	system("CLS");
		GotoXY(20, 4);
		cout << "Меню\n\n\n"
			<< "1-Холодные закуски" << endl << "2-Первое блюдо" << endl << "3-Второе блюдо" << endl << "4-Десерт" << endl << "5-Напитки" << endl
			<< "Ваш выбор под номером  \n";
		cin >> a;
		system("CLS");
		switch (a)
		{
		case 1:
		First_Menu:	system("CLS");
			cout.fill(' ');
			GotoXY(20, 4);
			cout << "Холодные закуски\n\n\n"
				<< "1-Блины с семгой и сыром     " << setw(20) << "190г" << setw(10) << "89грн" << endl
				<< "2-Блины с красной икрой      " << setw(20) << "190г" << setw(10) << "75грн" << endl
				<< "3-Тартар из лосося           " << setw(20) << "150г" << setw(10) << "179грн" << endl
				<< "4-Мясная тарелка             " << setw(20) << "250г" << setw(10) << "115грн" << endl
				<< "5-Ассорти рыбных деликатессов" << setw(20) << "150г" << setw(10) << "199грн" << endl
				<< "6-Выход в главное меню" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "Сколько порций блинов с семгой и сыром ?  ";
					cin >> a;
					cold_appetizer1 += a;
				}
				else {
					cout << "Вы уже заказали " << cold_appetizer1 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> cold_appetizer1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "Сколько порций блинов с красной икрой ?  ";
					cin >> a;
					cold_appetizer2 += a;
				}
				else {
					cout << "Вы уже заказали " << cold_appetizer2 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> cold_appetizer2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "Сколько порций тартаров из лосося ?  ";
					cin >> a;
					cold_appetizer3 += a;
				}
				else {
					cout << "Вы уже заказали " << cold_appetizer3 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> cold_appetizer3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "Сколько порций мясных тарелок ?  ";
					cin >> a;
					cold_appetizer4 += a;
				}
				else {
					cout << "Вы уже заказали " << cold_appetizer4 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> cold_appetizer4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "Сколько порций ассорти рыбных деликатессов ?  ";
					cin >> a;
					cold_appetizer5 += a;
				}
				else {
					cout << "Вы уже заказали " << cold_appetizer5 << " порций этого блюда. Сколько порций Вам необходимо?";
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
			cout << "Первое блюдо\n\n\n"
				<< "1-Царская уха              " << setw(20) << "400г" << setw(10) << "100грн" << endl
				<< "2-Борщ украинский          " << setw(20) << "300г" << setw(10) << "49грн" << endl
				<< "3-Суп с перепелкой         " << setw(20) << "300г" << setw(10) << "55грн" << endl
				<< "4-Суп гречневый            " << setw(20) << "400г" << setw(10) << "69грн" << endl
				<< "5-Крем-суп из белых грибов " << setw(20) << "200г" << setw(10) << "49грн" << endl
				<< "6-Выход в главное меню" << endl;
			cin >> a;
			switch (a) {
			case 1:
				if (v == 1) {
					cout << "Сколько порций цапской ухи ?  ";
					cin >> a;
					first_dish1 += a;
				}
				else {
					cout << "Вы уже заказали " << first_dish1 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> first_dish1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "Сколько порций борща украинского ?  ";
					cin >> a;
					first_dish2 += a;
				}
				else {
					cout << "Вы уже заказали " << first_dish2 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> first_dish2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "Сколько порций супа с перепелкой ?  ";
					cin >> a;
					first_dish3 += a;
				}
				else {
					cout << "Вы уже заказали " << first_dish3 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> first_dish3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "Сколько порций гречневого супа ?  ";
					cin >> a;
					first_dish4 += a;
				}
				else {
					cout << "Вы уже заказали " << first_dish4 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> first_dish4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "Сколько порций крем-супа из белых грибов ? ";
					cin >> a;
					first_dish5 += a;
				}
				else {
					cout << "Вы уже заказали " << first_dish5 << " порций этого блюда. Сколько порций Вам необходимо?";
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
			cout << "Второе блюдо\n\n\n"
				<< "1-Каша манная с ягодами      " << setw(20) << "400г" << setw(10) << "35грн" << endl
				<< "2-Хрустящая гранола с орехами" << setw(20) << "400г" << setw(10) << "40грн" << endl
				<< "3-Омлет с белыми грибами     " << setw(20) << "260г" << setw(10) << "55грн" << endl
				<< "4-Филе судака с овощами      " << setw(20) << "300г" << setw(10) << "109грн" << endl
				<< "5-Японский жаренный рис      " << setw(20) << "300г" << setw(10) << "85грн" << endl
				<< "6-Выход в главное меню" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "Сколько порций каши манной с ягодами?  ";
					cin >> a;
					second_dish1 += a;
				}
				else {
					cout << "Вы уже заказали " << second_dish1 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> second_dish1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "Сколько порций гранолы с орехами ?  ";
					cin >> a;
					second_dish2 += a;
				}
				else {
					cout << "Вы уже заказали " << second_dish2 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> second_dish2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "Сколько порций омлета с белыми грибами ?  ";
					cin >> a;
					second_dish3 += a;
				}
				else {
					cout << "Вы уже заказали " << second_dish3 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> second_dish3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "Сколько порций филе судака с овощами ?  ";
					cin >> a;
					second_dish4 += a;
				}
				else {
					cout << "Вы уже заказали " << second_dish4 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> second_dish4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "Сколько порций японского жаренного риса ?  ";
					cin >> a;
					second_dish5 += a;
				}
				else {
					cout << "Вы уже заказали " << second_dish5 << " порций этого блюда. Сколько порций Вам необходимо?";
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
			cout << "Десерты\n\n\n"
				<< "1-Шоколадный торт      " << setw(20) << "150г" << setw(10) << "55грн" << endl
				<< "2-Штрудель яблочный    " << setw(20) << "180г" << setw(10) << "55грн" << endl
				<< "3-Наполеон             " << setw(20) << "150г" << setw(10) << "45грн" << endl
				<< "4-Шоколадный фондан    " << setw(20) << "100г" << setw(10) << "59грн" << endl
				<< "5-Сырники со сметаной  " << setw(20) << "200г" << setw(10) << "60грн" << endl
				<< "6-Выход в главное меню" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "Сколько порций шоколадного торта ?  ";
					cin >> a;
					dessert1 += a;
				}
				else {
					cout << "Вы уже заказали " << dessert1 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> dessert1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "Сколько порций штруделя ?  ";
					cin >> a;
					dessert2 += a;
				}
				else {
					cout << "Вы уже заказали " << dessert2 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> dessert2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "Сколько порций наполеона ?  ";
					cin >> a;
					dessert3 += a;
				}
				else {
					cout << "Вы уже заказали " << dessert3 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> dessert3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "Сколько порций шоколадного фондана ?  ";
					cin >> a;
					dessert4 += a;
				}
				else {
					cout << "Вы уже заказали " << dessert4 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> dessert4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "Сколько порций сырников со сметаной?  ";
					cin >> a;
					dessert5 += a;
				}
				else {
					cout << "Вы уже заказали " << dessert5 << " порций этого блюда. Сколько порций Вам необходимо?";
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
			cout << "Напитки\n\n\n"
				<< "1-Спрайт             " << setw(20) << "250г" << setw(10) << "40грн" << endl
				<< "2-Фреш ананасовый    " << setw(20) << "250г" << setw(10) << "65грн" << endl
				<< "3-Мохито             " << setw(20) << "250г" << setw(10) << "40грн" << endl
				<< "4-Холодный чай       " << setw(20) << "500г" << setw(10) << "40грн" << endl
				<< "5-Красная роза       " << setw(20) << "350г" << setw(10) << "60грн" << endl
				<< "6-Выход в главное меню" << endl;
			cin >> a;

			switch (a) {
			case 1:
				if (v == 1) {
					cout << "Сколько порций спрайта ?  ";
					cin >> a;
					drink1 += a;
				}
				else {
					cout << "Вы уже заказали " << drink1 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> drink1;
				}
				break;
			case 2:
				if (v == 1) {
					cout << "Сколько порций фреша ананасового ?  ";
					cin >> a;
					drink2 += a;
				}
				else {
					cout << "Вы уже заказали " << drink2 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> drink2;
				}
				break;
			case 3:
				if (v == 1) {
					cout << "Сколько порций мохито ?  ";
					cin >> a;
					drink3 += a;
				}
				else {
					cout << "Вы уже заказали " << drink3 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> drink3;
				}
				break;
			case 4:
				if (v == 1) {
					cout << "Сколько порций холодного чая ?  ";
					cin >> a;
					drink4 += a;
				}
				else {
					cout << "Вы уже заказали " << drink4 << " порций этого блюда. Сколько порций Вам необходимо?";
					cin >> drink4;
				}
				break;
			case 5:
				if (v == 1) {
					cout << "Сколько порций красной розы?  ";
					cin >> a;
					drink5 += a;
				}
				else {
					cout << "Вы уже заказали " << drink5 << " порций этого блюда. Сколько порций Вам необходимо?";
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
		cout << "Вы желаете что-то еще ? " << endl << "1- да, хочу добавить " << endl << "2- нет, хочу уменьшить выбранное" << endl << "3- спасибо, этого достаточно" << endl;
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
			cout << "Ваш заказ:" << endl << endl << "Наименование" << setw(33) << "Количество порций,шт" << setw(9) << "Цена,грн" << setw(15) << "Стоимость,грн"  << endl
				<<"______________________________________________________________________________________________________" << endl;

			if (cold_appetizer1 != 0) { cout << "Блины с семгой и сыром         " << setw(10) << cold_appetizer1 << setw(10) << 89  << setw(10) << cold_appetizer1 * 89  << endl; value += cold_appetizer1 * 89; }
			if (cold_appetizer2 != 0) { cout << "Блины с красной икрой          " << setw(10) << cold_appetizer2 << setw(10) << 75  << setw(10) << cold_appetizer2 * 75  << endl; value += cold_appetizer2 * 75; }
			if (cold_appetizer3 != 0) { cout << "Тартар из лосося               " << setw(10) << cold_appetizer3 << setw(10) << 179 << setw(10) << cold_appetizer3 * 179 << endl;value += cold_appetizer3 * 179; }
			if (cold_appetizer4 != 0) { cout << "Мясная тарелка                 " << setw(10) << cold_appetizer4 << setw(10) << 115 << setw(10) << cold_appetizer4 * 115 << endl; value += cold_appetizer4 * 115; }
			if (cold_appetizer5 != 0) { cout << "Ассорти рыбных деликатессов    " << setw(10) << cold_appetizer5 << setw(10) << 199 << setw(10) << cold_appetizer5 * 199 << endl; value += cold_appetizer5 * 199; }
			if (first_dish1 != 0) { cout << "Царская уха                    "     << setw(10) << first_dish1     << setw(10) << 100 << setw(10) << first_dish1 * 100     << endl;  value += first_dish1 * 100; }
			if (first_dish2 != 0) { cout << "Борщ украинский                "     << setw(10) << first_dish2     << setw(10) << 49  << setw(10) << first_dish2 * 49      << endl; value += first_dish2 * 49; }
			if (first_dish3 != 0) { cout << "Суп с перепелкой               "     << setw(10) << first_dish3     << setw(10) << 55  << setw(10) << first_dish3 * 55      << endl; value += first_dish3 * 55; }
			if (first_dish4 != 0) { cout << "Суп гречневый                  "     << setw(10) << first_dish4     << setw(10) << 69  << setw(10) << first_dish4 * 69      << endl; value += first_dish4 * 69; }
			if (first_dish5 != 0) { cout << "Крем-суп из белых грибов       "     << setw(10) << first_dish5     << setw(10) << 49  << setw(10) << first_dish5 * 49      << endl; value += first_dish5 * 49; }
			if (second_dish1 != 0) { cout << "Каша манная с ягодами          "    << setw(10) << second_dish1    << setw(10) << 35  << setw(10) << second_dish1 * 35     << endl; value += second_dish1 * 35; }
			if (second_dish2 != 0) { cout << "Хрустящая гранола с орехами    "    << setw(10) << second_dish2    << setw(10) << 40  << setw(10) << second_dish2 * 40     << endl; value += second_dish2 * 40; }
			if (second_dish3 != 0) { cout << "Омлет с белыми грибами         "    << setw(10) << second_dish3    << setw(10) << 55  << setw(10) << second_dish3 * 55     << endl; value += second_dish3 * 55; }
			if (second_dish4 != 0) { cout << "Филе судака с овощами          "    << setw(10) << second_dish4    << setw(10) << 109 << setw(10) << second_dish4 * 109    << endl; value += second_dish4 * 109; }
			if (second_dish5 != 0) { cout << "Японский жаренный рис          "    << setw(10) << second_dish5    << setw(10) << 85  << setw(10) << second_dish5 * 85     << endl; value += second_dish5 * 85; }
			if (dessert1 != 0) { cout << "Шоколадный торт                "        << setw(10) << dessert1        << setw(10) << 55  << setw(10) << dessert1 * 55         << endl; value += dessert1 * 55; }
			if (dessert2 != 0) { cout << "Штрудель яблочный              "        << setw(10) << dessert2        << setw(10) << 55  << setw(10) << dessert2 * 55         << endl; value += dessert2 * 55; }
			if (dessert3 != 0) { cout << "Наполеон                       "        << setw(10) << dessert3        << setw(10) << 45  << setw(10) << dessert3 * 45         << endl; value += dessert3 * 45; }
			if (dessert4 != 0) { cout << "Шоколадный фондан              "        << setw(10) << dessert4        << setw(10) << 59  << setw(10) << dessert4 * 59         << endl; value += dessert4 * 59; }
			if (dessert5 != 0) { cout << "Сырники со сметаной            "        << setw(10) << dessert5        << setw(10) << 60  << setw(10) << dessert5 * 60         << endl; value += dessert5 * 60; }
			if (drink1 != 0) { cout << "Спрайт                         "          << setw(10) << drink1          << setw(10) << 40  << setw(10) << drink1 * 40           << endl; value += drink1 * 40; }
			if (drink2 != 0) { cout << "Фреш ананасовый                "          << setw(10) << drink2          << setw(10) << 65  << setw(10) << drink2 * 65           << endl; value += drink2 * 65; }
			if (drink3 != 0) { cout << "Мохито                         "          << setw(10) << drink3          << setw(10) << 40  << setw(10) << drink3 * 40           << endl; value += drink3 * 40; }
			if (drink4 != 0) { cout << "Холодный чай                   "          << setw(10) << drink4          << setw(10) << 40  << setw(10) << drink4 * 40           << endl; value += drink4 * 40; }
			if (drink5 != 0) { cout << "Красная роза                   "          << setw(10) << drink5			 << setw(10) << 60  << setw(10) << drink5 * 60           << endl;value += drink5 * 60; }
			cout << "______________________________________________________________________________________________________" << endl<< "К оплате  " << value << "грн" << endl << endl << "Приятного времяпровождения!";
		}

		else  cout << "Увы..Вы ничего не заказали...";

		PlaySound(TEXT("music.wav"), NULL, SND_FILENAME);
	}
}

