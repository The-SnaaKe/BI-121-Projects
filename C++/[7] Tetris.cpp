#include <SFML/Graphics.hpp> // среда разработки(простая,быстрая,мультимедийная библиотека)
#include <ctime>
#include <SFML/Audio.hpp>
using namespace sf;

const int width = 20, height = 10; //высота и ширина для полей
int pole[width][height] = { 0 }; //объявили двумерный массив(размерность массива всегда const), фигурки будут выпадать из нолика
const int size = 34;
int figure[7][4] = { // 7 строк, 4 столбца
1,3,5,7,
2,4,5,7,
3,5,4,6,
3,5,4,7,
2,3,5,7,
3,5,7,6,
2,3,4,5,
};

struct koordinati_kubika { //Struct конструкция, которая может хранить несколько типов данных
	int x, y;
} tek[4], pred[4]; //tek-tekyshaya положение фигуры(из 4 квадратиков) pred-predidushaya для того чтобы

/*Проверка на границы*/
bool test() {
	for (int i = 0; i < 4; i++) //двигаюсь по х
		if (tek[i].x < 0 || tek[i].x >= height || tek[i].y >= width) //Проверка на границы, если мы вышли за границы игра не заканчивается 
			return 0; //Всё окей мы врезаемся, но работаем дальше
		else if (pole[tek[i].y][tek[i].x])
			return 0; //Всё окей мы врезаемся, но работаем дальше
}

int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(0));
	RenderWindow window1(VideoMode(height * size, width * size), L"Жесткий тетрис!", Style::Close);
	Image icon;
	icon.loadFromFile("C:/Users/Семён/Рабочий стол/Дистант/Paint/elements.png");
	//Проигрышь
	Texture gameOverTexture;
	gameOverTexture.loadFromFile("C:/Users/Семён/Рабочий стол/Дистант/Paint/loze.png");
	window1.setIcon(428, 608, icon.getPixelsPtr()); //Выводим иконку в левом верхнем углу, с помощью растровой графики, при приближении увижу пиксили
	Texture quad; // текстура для квадратов
	quad.loadFromFile("C:/Users/Семён/Рабочий стол/Дистант/Paint/tiles.png");
	Sprite sfigure(quad); // модель для фигурки в 2 пространстве в расстровом виде
	Clock timeClock; //время за которое фигура падает
	bool rotate = false; //изначально фигуры без поворота
	int stepX = 0, line = 1, topline = 0; //шаг по Х; линия
	float delay = 0.5, secondomer = 0; //задержка падения ; для измерения времени с помощью timeClock

	while (window1.isOpen()) {
		float time = timeClock.getElapsedTime().asSeconds();
		timeClock.restart();
		secondomer += time * 0.5; //когда фигурка падает секундомер вкл и начинает робить

		Music music;//создаем объект музыки
		music.openFromFile("C:/Users/Семён/Рабочий стол/Дистант/Paint/Music.ogg");//загружаем файл
		music.play();//воспроизводим музыку

		/*Обработка действий*/
		Event doing;
		while (window1.pollEvent(doing)) { //Пока собитие работает
			if (doing.type == Event::KeyPressed) //Eсли тип события клавиша зажата
				if (doing.key.code == Keyboard::Up) //Если зажата клавиша в верх крутим фигуру
					rotate = true; //если нажал на клавишу наверх то поворот
				else if (doing.key.code == Keyboard::Right)
					stepX = 1;
				else if (doing.key.code == Keyboard::Left)
					stepX = -1;

			if (doing.type == Event::Closed)
				window1.close();//закрытие окна
		}

		if (Keyboard::isKeyPressed(Keyboard::Down))
			delay = 0.05;//если клавиша вниз то уменьшается задержка

		for (int i = 0; i < 4; i++) {
			pred[i] = tek[i];
			tek[i].x += stepX;
		}

		if (!test()) { //если достиг границы то след положение будет предыдущим
			for (int i = 0; i < 4; i++)
				tek[i] = pred[i];
		} 

		if (rotate) {
			koordinati_kubika buff = tek[1]; //В структу закидываем буфер с кубиком
			for (int i = 0; i < 4; i++) {
				int x = tek[i].y - buff.y; //Что бы вычислить координату по х, надо работать с у
				int y = tek[i].x - buff.x;
				tek[i].x = buff.x - x; //Узнаю тек положение координаты кубика по х
				tek[i].y = buff.y + y;
			}
			if (!test()) { //Проверка на границы при повороте! если достиг границы то след положение будет предыдущим
				for (int i = 0; i < 4; i++)
					tek[i] = pred[i];
			}
		}

		/*Падение с проверкой теста*/
		if (secondomer > delay) {
			for (int i = 0; i < 4; i++) {
				pred[i] = tek[i];
				tek[i].y += 1;
			}

			/*Проверка условия на, то что достигли нижней линии*/
			if (!test()) {
				for (int i = 0; i < 4; i++)
					pole[pred[i].y][pred[i].x] = line;
				line = 1 + rand() % 7; //Приземление фигуры
				int n = rand() % 7; //Генерация новой фигуры
				for (int i = 0; i < 4; i++) {
					tek[i].x = figure[n][i] % 2; //Остаток от деления на 2
					tek[i].y = figure[n][i] / 2; //Деление на 2. Потому-что 2 столбца.
				}
			}
			secondomer = 0; //Когда фигура сгенериловалась она сбросила 
		}


		//Проигрышь
		if (!test())
			for (int i = 0; i < 4; i++)
				if (pole[pred[i].y][pred[i].x] == 1) {
					window1.clear(Color::White);
					Sprite gameOverSprite;
					gameOverSprite.setTexture(gameOverTexture);
					window1.draw(gameOverSprite);
					window1.display();
					system("pause");
			}

		int n = rand() % 7; //Задали первую фигуру
		if (tek[1].x == 0) //Левая гранца 
			for (int i = 0; i < 4; i++) {
				tek[i].x = figure[n][i] % 2;
				tek[i].y = figure[n][i] / 2;
			}

		int delLine = width - 1; //При удалении мы рассматриваем всё поле
		for (int i = width - 1; i > 0; i--) {
			int kolvoLine = 0;
			for (int j = 0; j < height; j++) {
				if (pole[i][j])
					kolvoLine++; //Если я линию нашёл увеличил счётчик на 1
				pole[delLine][j] = pole[i][j]; 
			}
			if (kolvoLine < height) //Если линия заполнена, она будет удалена
				delLine--;
		}

		/*Делаем базовые значения фигуры*/
		stepX = 0; 
		rotate = false;
		delay = 0.7;
		window1.clear(Color::White); //Цвет окошка всего

		for (int i = 0; i < width; i++)
			for (int j = 0; j < height; j++) {
				if (pole[i][j] == 0) //Если мы в 0, то начинаем отрисовку
					continue;
				sfigure.setTextureRect(IntRect(pole[i][j] * size, 0, size, size)); //Вырезаем прямоугольник
				sfigure.setPosition(j * size, i * size); //Задал позицию где я буду отписовывать
				window1.draw(sfigure); //Отрисовал в окошке
			}

		for (int i = 0; i < 4; i++) { //Сделал действия для всех 4 квадратиков (Фигуры)
			sfigure.setTextureRect(IntRect(line * size, 0, size, size));
			sfigure.setPosition(tek[i].x * size, tek[i].y * size);
			window1.draw(sfigure);
		}

		window1.display(); //Вывел всё на дисплей
	}
}
