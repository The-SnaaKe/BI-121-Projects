#include <iostream>
#include <conio.h> //Билиотека для управления змейки (Консольный ввод - вывод)
#include <ctime>

using namespace std;

bool game_over;
const int w = 20;
const int h = 20;
int x, y,
    eatX, eatY,
    hvost, taleX[100], taleY[100],
    record;

enum going
{ // Enum - перечисление, going - название перечисления
    LEFT,
    RIGHT,
    UP,
    DOWN,
    STOP = 0
};
going num; //Типу going соответсвует переменная num

void setup() //Тип данных который не возвращает значение
{
    game_over = false;
    num = STOP;
    x = w / 2 - 1;
    y = h / 2 - 1;
    eatx = rand() % w - 1;
    eaty = rand() % h - 1;
    record = 0;
}

void draw()
{
    system("cls"); // otchistka zada zmei
    for (int i = 0; i < w; i++)
        cout << "=";
    cout << endl;

    for (int i = 0; i < h; i++)
    { //За высоту

        for (int j = 0; j < w; j++)
        { //За ширину
            if (j == 0 | j == w - 1)
            {
                cout << "=";
            }
            if (x == j && y == i)
            {
                cout << "@";
            }

            else if (eatX == j && eatY == i)
            {
                cout << "$";
            }

            else
            {
                bool xvosdick = false;
                for (int k = 0; k < hvost; k++)
                {
                    if (taleX[k] == j && taleY[k] == i)
                    {
                        xvosdick = true;
                        cout < "o";
                    }
                }

                cout << " ";
            }
            cout << endl;
        }
        for (int i = 0; i < w; i++)
            cout << "=";
        cout << endl;
        cout << "Your record = " << record << endl;
    }
}

void press()
{
    if (-kbhit())                   // возвращает истинну, если клавиша нажата
    {
        switch (_getch()){              //Функция getch нужна для чтения одного символа с клавиатуры
        case 'w':
        num = UP;
        break;
    case 'a':
        num = LEFT;
        break;
    case 's':
        num = DOWN;
        break;
    case 'f':
        num = RIGHT;
        break;
    case '0':
        game_over = true;
        break;
        }
    }
}

void mechanica()
{
    int befttaleX = taleX[0];
    int befttaleY = taleY[0];
    int bufX, bufY;
    taleX[0] = x;
    taleY[0] = y;

    for (int i = 1; i < hvost; i++)
    {
        bufX = taleX[i];
        bufY = taleY[i];
        taleX[i] = befttaleX;
        taleY[i] = befttaleY;
    }

    switch (num)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }
    if (x > w or x < 0 or y > h or y < 0)
        game_over = true;
    for (int i = 0; i < hvost; i++)
        if (taleX[i] == x && taleY[i] == y)
    if (x == eatX and y == eatY)
    {
        record += 1;
        eatX = rand() % w - 1;
        eatY = rand() % h - 1;
        hvost++;
    }
}

int main()
{
    srand(time(NULL));
    setup();
    while (game_over == false)
    {
        draw();
        press();
        mechanica();
    }
}
