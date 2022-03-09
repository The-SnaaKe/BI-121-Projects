#include <iostream>
#include <conio.h> //Билиотека для управления змейки (Консольный ввод - вывод)

using namespace std;

bool game_over;
const int w = 20;
const int h = 20;
int x,y,
eatx,eaty,
record;
int main(){
enum going { //Enum - перечисление, going - название перечисления
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
    x = w/2;
    y = h/2;
    eatx = rand () % w;
    eaty = rand () % h;
    record = 0;
}

void draw(){

}

void press(){

}

void mechanica(){

}
    setup();
    while (game_over == false){
        draw();
        press();
        mechanica();
    }
}