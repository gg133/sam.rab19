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
bool sup = false;
int getSup;
double timer = 10.00;
double counterTime;
int userAns;
int score;






string questionsAndAnswer[15][6] = {
    {"Сколько будет 5+5?", "1", "2", "5", "10", "10"},
    {"Что хранит тип данных int?", "Символ", "Строку", "Целое число", "Булево", "Целое число" },
    {"Самый дешовый бургер в маке?", "Биг Мак", "Чизбургер", "Гамбургер", "Нагетсы", "Гамбургер"},
    {"Как зовут президента РФ?", "1.Володя", "Паша", "Катя", "Никита", "Володя"},
    {"Последня часть фифы?", "FIFA21", "FIFA22", "FIFA ONLINE 4", "FIFA 5", "FIFA22"},
    {"Последняя часть Mortal Kombat?", "MKX", "MK Mobail","MKXL", "MK11", "MK11"},
    {"У какого треугольник все углы равны?", "Прямоугольный", "Равнобедренный", "Равноугольный", "Равносторонний", "Равносторонний"},
    {"Человек который очень любит детей?", "Влад А4", "Джарахов", "Путин", "Папич", "Влад А4"},
    {"Сколь будет 2*2+2?", "1","14", "17", "8", "8"},
    {"Сколько у человека(Здорового) хромосом?", "45","46", "47", "48", "46"},
    {"Сколько стоит авп в кс го", "4550", "4650", "4750", "4850", "4750"},
    {"Последня версия Windows?", "10", "9", "XP", "11", "11"},
    {"На какой планете мы живем?", "Марс", "Земля", "Юпитер", "Луна", "Земля"},
    {"Сколько будет 1 + 1?", "1", "2", "3", "4", "2"},
    {"Сколько будет 3 + 3?", "1", "3", "6", "10", "6"}
};


void showAns(int i)
{
    cout<< questionsAndAnswer[i][0] << endl;
        for (int j = 1; j < 5; j++)
        {
            cout<<j<<"." << questionsAndAnswer[i][j] << endl;
        }
 }

void game()
{
    for (int i = 0; i < 15; i++)
    {
            showAns(i);
            cout << "\nВыберите вариант ответа: ";
            cin >> userAns;
            if (lives > 0)
            {
                if (questionsAndAnswer[i][userAns] == questionsAndAnswer[i][5])
                {
                    score++;
                    cout << "Ответ верный " << "Вы получаете +1 балл." << " У вас " << score << " баллов\n";
                    system("pause");
                    system("cls");
                }

                else
                {
                    lives--;
                    cout << "Ответ не верный, вы теряете 1 жизнь. У вас осталось " << lives << " жизней\n";
                    system("pause");
                    system("cls");
                }
            }
            else
            {
                system("cls");
                cout << "Вы ошиблись максимальное колличество раз. Игра закончена\n";
                cout << "Итоговый счет: " << score << endl;
                system("pause");
                exit(0);
            }
    }
   
}



//void choosePoint3()
//{
//
//    int point;
//    while (true)
//    {
//        cout << "Игрок " << startPlayer << " выбери позицию\n";
//        cin >> point;
//        point--;
//        if (point < 0 || point > 8 || board3[point] == "\x1b[" + to_string(colorNull) + "mO\x1b[0m" || board3[point] == "\x1b[" + to_string(colorCross) + "mX\x1b[0m")
//        {
//            system("cls");
//            DrawBoard3();
//            cout << "неправильно\n";
//            continue;
//        }
//        break;
//    }
//    if (startPlayer != PLAYER1)
//    {
//        board3[point] = "\x1b[" + to_string(colorNull) + "mO\x1b[0m";
//    }
//    else
//    {
//        board3[point] = "\x1b[" + to_string(colorCross) + "mX\x1b[0m";
//    }
//
//
//}



int chooseLives(int qtyLives)
{
    switch (qtyLives) {
    case 1: return 1;
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    default: cout << "Введено неверное значение - количество ваших жизней = 3\n"; cin.clear(); cin.ignore(); return 3;
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
bool chooseSupurt(int getSup)
{
    switch (getSup)
    {
    case 1: return true;
    case 2: return false;
    default: cout << "Введено неверное значение - вы играете без подсказки(\n"; return false;
    }
}
double getTimer(double counterTime) {


    while (cin.fail() || counterTime < 15.00)
    {
        return counterTime;
    }

}

void showTimer()
{
    while (true) {
        if (timer > 0)
        {

            
            cout <<"\r"<< timer;
            timer = timer - 0.01;
            Sleep(100);
           
        }
        else if (timer <= 0)
        {
            cout << "Время истекло - вы проиграли((";
            exit(0);
        }
    }
}

void MenuOptions()
{
    setlocale(0, "");
    system("cls");
    cout << "[!] Настройки\n\n[1] Количество вопросов\n[2] Количество жизней\n[3] Подсказка 50x50\n[4] Время на викторину\n[5] Вернуться в главное меню\n\n [#] Выберите пункт из меню: ";

}



void Rules()
{
    system("cls");
    cout << "Игроки по очереди ставят на свободные клетки поля 3х3, 4x4, 5x5 знаки (один всегда крестики, другой всегда нолики). \nПервый, выстроивший в ряд 3 своих фигур по вертикали, горизонтали или диагонали, выигрывает." << endl;;

}


//void game3()
//{
//    string result = LOSE;
//    while (result == LOSE)
//    {
//        system("cls");
//        DrawBoard3();
//        choosePoint3();
//        result = CheckWinner3();
//        if (startPlayer != PLAYER2)
//        {
//            startPlayer = PLAYER2;
//        }
//        else startPlayer = PLAYER1;
//    }
//    DrawBoard3();
//
//    if (result == DRAW)
//    {
//        cout << "\nНичья\n";
//        system("pause");
//        exit(0);
//    }
//    else {
//        if (startPlayer != PLAYER2)
//        {
//            startPlayer = PLAYER2;
//        }
//        else startPlayer = PLAYER1;
//        cout << "Игрок, который играет за: " << startPlayer << " - победил\n";
//        system("pause");
//        exit(0);
//    }
//
//}

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
            while (true)
            { 
                system("cls");
              /*      cout << "---------------"<<endl;
                    showTimer();
                    cout << "---------------"<<endl;*/
                    game();              
            }
        }
        else if (pickMenu == 2)
        {
            while (true)
            {
                system("cls");
                MenuOptions();
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
                    cout << " [!] Хотите ли иметь однк подсказку? \n\n [1] Да\n [2] Нет, я сильный\n\n [$] Ваш выбор: ";
                    cin >> getSup;
                    sup = chooseSupurt(getSup);
                    BackToMenu();
                    break;
                }
                else if (pickMenuOpt == 4)
                {
                    system("cls");
                    cout << " [!] Введте время на игру в минутах\n\n [$] Таймер = ";
                    cin >> counterTime;
                    while (cin.fail() || counterTime > 15.00)
                    {
                        cin.clear();
                        cin.ignore();
                        cout << "error/Введите корректные данные - число минут, меньшее или равное 15\n";
                        cin >> counterTime;
                    }
                    timer = getTimer(counterTime);
                    cout << " Время на игру = " << timer << endl;
                    BackToMenu();
                    break;
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
            Rules();
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