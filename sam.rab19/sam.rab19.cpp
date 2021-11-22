#include <iostream>
#include <string>
#include <cmath>
#include <ctime>
#include <Windows.h>

using namespace std;

int questionts = 5;
int qtyQuestion;
int  lives = 3;
int qtyLives;
int sup = 3;
int getSup;
int userAns;
int score;

const int QTYQ = 15;

struct Question {

	string question;
	string answer[4];
	string uncorrect;
	string correct;
};

Question question[QTYQ]{
	{"Сколько будет 5+5?", {"1", "2", "5", "10"},"5", "10"},
	{"Что хранит тип данных int?", { "Целое число", "Символ", "Строку", "Булево"},"Строку", "Целое число"},
	{"Самый дешовый бургер в маке?", { "Гамбургер", "Биг Мак", "Чизбургер", "Нагетсы"}, "Биг Мак" ,"Гамбургер" },
	{"Как зовут президента РФ?", {"Володя", "Паша", "Катя", "Никита"},"Катя" , "Володя"},
	{"Последня часть фифы?", {"FIFA22", "FIFA21", "FIFA ONLINE 4", "FIFA 5"},"FIFA 5" , "FIFA22" },
	{"Последняя часть Mortal Kombat?", {"MK11", "MK Mobail","MKXL", "MKX"},"MKXL" , "MK11"},
	{"У какого треугольник все углы равны?",{"Равносторонний", "Прямоугольный", "Равнобедренный", "Равноугольный"},"Прямоугольный" , "Равносторонний" },
	{"Человек который очень любит детей?", {"Влад А4", "Джарахов", "Путин", "Папич"},"Путин" , "Влад А4"},
	{"Сколь будет 2*2+2?", {"6","14", "8", "4"},"8", "6" },
	{"Сколько у человека(Здорового) хромосом?",{"46","45", "47", "48"},"47", "46"},
	{"Сколько стоит авп в кс го", {"4750", "4650", "4550", "4850"},"4850","4750" },
	{"Последня версия Windows?", {"11", "9", "XP", "10"},"10" , "11"},
	{"На какой планете мы живем?", {"Земля", "Марс", "Юпитер", "Луна"},"Марс", "Земля" },
	{"Сколько будет 1 + 1?", {"2", "3", "1", "4"},"1" , "2"},
	{"Сколько будет 3 + 3?", {"6", "3", "1", "10"}, "3" ,"6" }

};



void showGame() {
	for (int i = 0; i < 15; i++) {
		swap(question[i], question[rand() % 15]);
	}
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 4; j++) {
			swap(question[i].answer[j], question[i].answer[rand() % 4]);
		}
	}

	for (int i = 0; i < questionts; i++)
	{
		if (lives > 0)
		{
			cout << question[i].question << endl;
			for (int k = 0; k < 4; k++)
			{
				cout << "[\x1b[95m" << to_string(k + 1) << "\x1b[0m] " << question[i].answer[k] << endl;
			}
			cout << "Для того чтобы воспользоваться подсказкой введите 7\nВыберите вариант ответа или используйте подсказку: ";
			while (true) {
				cout << "\nВведите ваш выбор: ";
				cin >> userAns;
				if ((cin.fail() || userAns < 1 || userAns>4) && userAns != 7) {
					cin.clear();
					cin.ignore();
				}
				else
				{
					break;
				}
			}
			/// ПОДСКАЗКА 
			if (userAns == 7 && sup > 0)
			{
					system("cls");
					cout << question[i].question << endl;

					question[i].answer[0] = question[i].correct;
					short random = rand() % 2;
					if (random == 0) {

						cout << "[\x1b[95m" << to_string(1) << "\x1b[0m] " << question[i].uncorrect << endl;
						cout << "[\x1b[95m" << to_string(2) << "\x1b[0m] " << question[i].answer[0] << endl;
						question[i].answer[1] = question[i].correct;
						question[i].answer[0] = question[i].uncorrect;
					}
					else {

						cout << "[\x1b[95m" << to_string(1) << "\x1b[0m] " << question[i].answer[0] << endl;
						cout << "[\x1b[95m" << to_string(2) << "\x1b[0m] " << question[i].uncorrect << endl;
						question[i].answer[0] = question[i].correct;
						question[i].answer[1] = question[i].uncorrect;
					}

					sup--;
					while (true) {

						cout << "Введите вариант ответа : ";
						cin >> userAns;
						if (cin.fail() || userAns < 1 || userAns>2) {
							cin.clear();
							cin.ignore();
						}
						else
						{
						break;
						}
					}
				//КОНЕЦ ПОДСКАЗКИ
			}
			else if (userAns == 7 && sup == 0)
			{
				cout << "[\x1b[95mУ вас закончились подсказки\x1b[0m]\n";
				cin.clear();
				while (true) {
					cout << "Введите вариант ответа: ";
					cin >> userAns;
					if (cin.fail() || userAns < 1 || userAns>4) {
						cin.clear();
						cin.ignore();
					}
					else
					{
						break;
					}
				}
			}

			if (question[i].answer[userAns - 1] == question[i].correct)
			{
				score++;
				if (score == 1)
				{
					cout << "Ответ верный " << "Вы получаете +1 балл. " << " У вас " << "\x1b[92m" << to_string(score) << "\x1b[0m" << " балл\n";
				}
				else if (score == 2 || score == 3 || score == 4)
				{
					cout << "Ответ верный " << "Вы получаете +1 балл. " << " У вас " << "\x1b[92m" << to_string(score) << "\x1b[0m" << " балла\n";
				}
				else {
					cout << "Ответ верный " << "Вы получаете +1 балл. " << " У вас " << "\x1b[92m" << to_string(score) << "\x1b[0m" << " баллов\n";
				}
				system("pause");
				system("cls");
			}
			else
			{
				lives--;
				cout << "Ответ не верный, вы теряете 1 жизнь. У вас осталось " << "\x1b[91m" << to_string(lives) << "\x1b[0m" << " жизней\n";
				system("pause");

				system("cls");
			}
		}
		else
		{
			system("cls");
			cout << "     Вы ошиблись максимальное колличество раз. Игра закончена\n";
			cout << "\n    Итоговый счет: " << "\x1b[92m" << to_string(score) << "\x1b[0m" << endl;
			system("pause");
			exit(0);
		}
	}
}


void showResults()
{
	cout << "        Вы успешно закончили викторину. Итоговый счет: " << "\x1b[92m" << to_string(score) << "\x1b[0m" << endl;
	/*exit(0);*/
}
int chooseLives(int qtyLives)
{
	if (qtyLives > 5 || qtyLives < 1)
	{
		cout << "Введено неверное значение - количество ваших жизней = 3\n"; cin.clear(); cin.ignore(); return 3;
	}
	else
	{
		return qtyLives;
	}



}

int chooseQuestions(int qtyQuestion)
{
	switch (qtyQuestion) {
	case 1: return 5;
	case 2: return 10;
	case 3: return 15;
	default: cout << "Введено неверное значение - количество вопросов = 5\n"; cin.clear(); cin.ignore(); return 5;
	}
}
int chooseSupurt(int getSup)
{
	if (getSup > 15 || getSup < 1)
	{
		cout << "Введено неверное значение - количество ваших подсказок = 3\n"; cin.clear(); cin.ignore(); return 3;
	}
	else {
		return getSup;
	}
}


void showMenuOptions()
{
	setlocale(0, "");
	system("cls");
	cout << "[!] Настройки\n\n[1] Количество вопросов\n[2] Количество жизней\n[3] Подсказка 50x50\n[4] Вернуться в главное меню\n\n [#] Выберите пункт из меню: ";

}

void showRules()
{
	system("cls");
	cout << "Игроки по очереди ставят на свободные клетки поля 3х3, 4x4, 5x5 знаки (один всегда крестики, другой всегда нолики). \nПервый, выстроивший в ряд 3 своих фигур по вертикали, горизонтали или диагонали, выигрывает." << endl;;

}

void BackToMenu()
{
	system("pause");
	cin.get();
}


int main()
{
	srand(static_cast<unsigned int>(time(0)));
	setlocale(0, "");
	int pickMenu;
	int pickMenuOpt;
	while (true) {
		system("cls");
		cout << "[!] Меню\n\n[1] Начать игру\n[2] Настройки\n[3] Правила\n[4] Выйти\n\n [$] Выберите пункт из меню: ";
		cin >> pickMenu;
		if (pickMenu == 1)
		{
			system("cls");
			showGame();
			showResults();
			score = 0;
			BackToMenu();


		}
		else if (pickMenu == 2)
		{
			while (true)
			{
				system("cls");
				showMenuOptions();
				cin >> pickMenuOpt;
				if (pickMenuOpt == 1)
				{
					system("cls");
					cout << " [!]Выберите колличество вопросов:\n\n [1] 5 Вопросов\n [2] 10 Вопросов\n [3] 15 Вопросов\n\n [$] Ваш выбор: ";
					cin >> qtyQuestion;
					questionts = chooseQuestions(qtyQuestion);
					cout << "Выбранное количество вопросов: " << questionts << endl;
					BackToMenu();
					break;

				}
				else if (pickMenuOpt == 2)
				{
					system("cls");
					cout << " [!]Выберите количество жизней: \n\n [1] 1 Жизнь\n [2] 2 Жизни\n [3] 3 Жизни\n [4] 4 Жизни\n [5] 5 Жизней\n\n [$] Ваш выбор: ";
					cin >> qtyLives;
					lives = chooseLives(qtyLives);
					cout << "Выбранное количество жизней: " << lives << endl;
					BackToMenu();
					break;
				}
				else if (pickMenuOpt == 3)
				{
					system("cls");
					cout << " [!] Введите количество подсказок равное не больше 15 \n\n [$] Ваш выбор: ";
					cin >> getSup;
					sup = chooseSupurt(getSup);
					BackToMenu();
					break;
				}
				else if (pickMenuOpt == 4)
				{
					BackToMenu();
				}
				else
				{
					system("cls");
					cout << "somthing wrong" << endl;
					cin.clear();
					cin.ignore();
					BackToMenu();

				}
				break;
			}

		}
		else if (pickMenu == 3)
		{
			showRules();
			BackToMenu();

		}

		else if (pickMenu == 4)
		{
			cout << "bb";
			exit(0);

		}
		else
		{
			system("cls");
			cout << "somthing wrong" << endl;
			cin.clear();
			cin.ignore();
			BackToMenu();

		}
	}
}
