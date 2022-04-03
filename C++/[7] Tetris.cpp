#include <SFML/Graphics.hpp>
#include <ctime>

using namespace sf;

const int height = 20;
const int weigh = 30;

int pole[height][weigh] = { 0 };

int* a = new int[n]; // динамич выдел паияти

const int SIZE = 34;//razmer kyba

int figure [7][4] = 
{ 
    1,3,5,7,
    2,4,5,7,
    3,5,4,6,
    3,5,4,7,
    2,3,5,7,
    3,5,7,6,
    2,3,4,5,
 };

 int main()
 {
    srand(time(NULL));
    Texture quad;
    quad.LoadFromFile("Текстуры для кубов.png");
    Sprite sfigure(quad);
 }