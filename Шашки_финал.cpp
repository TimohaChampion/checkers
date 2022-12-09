
#include <iostream>
#include<time.h>
using namespace std;

int len = 9;

void gen_place(char** mass) {

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (i == 0) {
                if (j == 0)mass[i][j] = 120;
                else
                    mass[i][j] = j + 48;
            }
            else if (j == 0) {
                mass[i][j] = i + 48;
            }
            else {
                if (i < 4 && j % 2 == 1 && i % 2 == 1)mass[i][j] = 46;
                if (i < 4 && j % 2 == 0 && i % 2 == 0)mass[i][j] = 46;

                if (i == 4 || i == 5)mass[i][j] = 46;

                if (i > 5 && j % 2 == 1 && i % 2 == 1) mass[i][j] = 46;
                if (i > 5 && j % 2 == 0 && i % 2 == 0) mass[i][j] = 46;

                if (i < 4 && j % 2 == 0 && i % 2 == 1)mass[i][j] = 1;
                if (i < 4 && j % 2 == 1 && i % 2 == 0)mass[i][j] = 1;

                if (i > 5 && j % 2 == 0 && i % 2 == 1) mass[i][j] = 2;
                if (i > 5 && j % 2 == 1 && i % 2 == 0) mass[i][j] = 2;

            }
        }
    }

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            cout << mass[i][j] << " ";
        }
        cout << endl;
    }
}

void make_move(char** mass) {
    int k = 0;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    while (k > -1) {
        if (k % 2 == 0) {
            //cout << mass[6][1] << mass[5][2] << endl;
            cout << "\n\t\t\t\tХОД БЕЛЫХ!" << endl << "Введите координаты шашки, которую хотите переместить(сначала строку,затем столбец):" << endl; cin >> x1 >> y1;
            if (x1 == 30 && y1 == 5)break;
            // проверка на существование
            if (x1 < 1 || x1>8 || y1 < 1 || y1>8 || mass[x1][y1] != 2) {
                bool flag = false;
                while (flag == false) {
                    cout << "Неверно введены координаты или на указаном вами месте нет вашей шашки, введите заново(0<=(x,y)<=7):" << endl; cin >> x1 >> y1;
                    if (x1 == 30 && y1 == 5)break;
                    if (x1 < 1 || x1>8 || y1 < 1 || y1>8) flag = false;
                    else if (mass[x1][y1] != 2)flag = false;
                    else flag = true;
                }
                cout << endl;
            }
            //
            cout << "\nВведите координаты точки, на которую вы хотите переместить шашку(сначала строку,затем столбец):" << endl; cin >> x2 >> y2;
            if (x2 == 30 && y2 == 5)break;
            // проверка на существование
            if ((x2 < 1 || x2>8 || y2 < 1 || y2>8) || x2 > x1 || abs(x2 - x1) != 1 || abs(y1 - y2) != 1 || mass[x2][y2] == 2) {
                bool flag = false;
                while (flag == false) {
                    cout << "Такой ход невозможен, введите заново координаты(0<=(x,y)<=7):" << endl; cin >> x2 >> y2;
                    if (x2 == 30 && y2 == 5)break;
                    if (x2 < 1 || x2>8 || y2 < 1 || y2>8) flag = false;
                    else if (mass[x2][y2] == 2)flag = false;
                    else if (x2 > x1)flag = false;
                    else if (abs(x2 - x1) != 1 || abs(y1 - y2) != 1 || mass[x2][y2] != 46)flag = false;
                    else flag = true;
                }
                cout << endl;
            }
            if (mass[x2][y2] == 1 && mass[x2 - 1][y2 + 1] == 46 || mass[x2][y2] == 1 && mass[x2 - 1][y2 - 1] == 46) {
                if (y2 > y1)
                    if (mass[x2][y2] == 1 && mass[x2 - 1][y2 + 1] == 46) {
                        if (mass[x2 - 1][y2 + 1] == 46) {
                            swap(mass[x1][y1], mass[x2 - 1][y2 + 1]);
                            mass[x2][y2] = 46;
                        }
                    }
                if (y2 < y1)
                    if (mass[x2][y2] == 1 && mass[x2 - 1][y2 - 1] == 46)
                        if (mass[x2 - 1][y2 - 1] == 46) {
                            swap(mass[x1][y1], mass[x2 - 1][y2 - 1]);
                            mass[x2][y2] = 46;
                        }
            }
            else
                swap(mass[x1][y1], mass[x2][y2]);

            system("cls");
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    cout << mass[i][j] << " ";
                }
                cout << endl;
            }

            //
            k++;
        }
        else {
            //cout << mass[6][1] << mass[5][2] << endl;
            cout << "\n\t\t\t\tХОД ЧЁРНЫХ!" << endl << "Введите координаты шашки, которую хотите переместить(сначала строку,затем столбец):" << endl; cin >> x1 >> y1;
            if (x1 == 30 && y1 == 5)break;
            // проверка на существование
            if (x1 < 1 || x1>8 || y1 < 1 || y1>8 || mass[x1][y1] != 1) {
                bool flag = false;
                while (flag == false) {
                    cout << "Неверно введены координаты или на указаном вами месте нет вашей шашки, введите заново(0<=(x,y)<=7):" << endl; cin >> x1 >> y1;
                    if (x1 == 30 && y1 == 5)break;
                    if (x1 < 1 || x1>8 || y1 < 1 || y1>8) flag = false;
                    else if (mass[x1][y1] != 1)flag = false;
                    else flag = true;
                }
                cout << endl;
            }
            //
            cout << "\nВведите координаты точки, на которую вы хотите переместить шашку(сначала строку,затем столбец):" << endl; cin >> x2 >> y2;
            if (x2 == 30 && y2 == 5)break;
            // проверка на существование
            if ((x2 < 1 || x2>8 || y2 < 1 || y2>8) || x2 < x1 || abs(x2 - x1) != 1 || abs(y1 - y2) != 1 || mass[x2][y2] == 1) {
                bool flag = false;
                while (flag == false) {
                    cout << "Такой ход невозможен, введите заново координаты(0<=(x,y)<=7):" << endl; cin >> x2 >> y2;
                    if (x2 == 30 && y2 == 5)break;
                    if (x2 < 1 || x2>8 || y2 < 1 || y2>8) flag = false;
                    else if (mass[x2][y2] == 1)flag = false;
                    else if (x2 < x1)flag = false;
                    else if (abs(x2 - x1) != 1 || abs(y1 - y2) != 1 || mass[x2][y2] != 46)flag = false;
                    else flag = true;
                }
                cout << endl;
            }
            if (mass[x2][y2] == 2 && mass[x2 + 1][y2 + 1] == 46 || mass[x2][y2] == 2 && mass[x2 + 1][y2 - 1] == 46) {
                if (y2 > y1)
                    if (mass[x2][y2] == 2 && mass[x2 + 1][y2 + 1] == 46) {
                        if (mass[x2 + 1][y2 + 1] == 46) {
                            swap(mass[x1][y1], mass[x2 + 1][y2 + 1]);
                            mass[x2][y2] = 46;
                        }
                    }
                if (y2 < y1)
                    if (mass[x2][y2] == 2 && mass[x2 + 1][y2 - 1] == 46)
                        if (mass[x2 + 1][y2 - 1] == 46) {
                            swap(mass[x1][y1], mass[x2 + 1][y2 - 1]);
                            mass[x2][y2] = 46;
                        }
            }
            else
                swap(mass[x1][y1], mass[x2][y2]);

            system("cls");
            for (int i = 0; i < len; i++) {
                for (int j = 0; j < len; j++) {
                    cout << mass[i][j] << " ";
                }
                cout << endl;
            }

            //
            k++;
        }
    }
}

int main()
{
    setlocale(0, "ru");
    srand(time(0));
    cout << "\t\t\t\tЭТО ШАШКИ" << endl;
    cout << "код выхода из игры (30 5)" << endl << endl;
    char** mass = new char* [len];
    for (int i = 0; i < len; i++) {
        mass[i] = new char[len];
    }
    gen_place(mass);
    make_move(mass);


    for (int i = 0; i < len; i++) {
        delete[]mass[i];
    }
    delete[]mass;
    cout << endl;
    system("pause");
}


