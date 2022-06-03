#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespase sf;

View camera;

class Father{
  private:
    float x, y, stepX, stepY, speed, w, h;
  public:
    float x, y, stepX, stepY, speed, w, h;
    bool onGround;
    enum {
      right,
      left,
      up,
      down,
      jump,
      stay
    } move;
    Image image;
    Texture texture;
    Sprite sprite;
    string Filename;
    Father (String n, float W, float H, float X, float Y){
      stepX = 0;
      stepY = 0;
      speed = 0;
      Filename = n;
      w = W;
      h = H;
      x = X;
      y = Y;
      image.LoadFromFile ("Указываем путь до каталога с картинками" + Filename);  
      image.createMaskFromColor(Color(255, 255, 255));
      Texture.LoadFromFile (Image);
      Sprite.LoadFromFile (Texture);
      sprite.setTextureRect(IntRect(0, 0, w, h));
      
      void control(){
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
           // m.sprite.setScale(0.8, 0.5);
            move = right;
            m.speed = 0.2;
            /*frameMario += 0.01 * time
                if (frameMario > 4)
                    frameMario -= 4;
            m.sprite.setTextureRect(IntRect(80 * int(frameMario), 0, 80, 85)); //Приведение типов, для того чтобы не было пол мужика
            MarioPos(m.MarioX(), m.Marioy()); // MarioPos = CamPos; Вызываем функцию позицию камеры и передаём туда значение */
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
                  //  m.sprite.setScale(-0.8, 0.5);
                    move = left;
                    speed = 0.2;
                   /* frameMario += 0.01 * time
                        if (frameMario > 4)
                            frameMario - +4;
                    m.sprite.setTextureRect(IntRect(80 * int(frameMario), 0, 80, 85));
                    MarioPos(m.MarioX(), m.Marioy()); */
                }

        if (Keyboard::isKeyPressed(Keyboard::Up) && (onGround) {
            move = jump;
            stepY = -0.5;
            onGround = false;
           /* m.speed = 0.2;
            m.sprite.setTextureRect(IntRect(418, 0, 85, 85));
            MarioPos(m.MarioX(), m.Marioy()); */
        }
      }
      void movetime(float time){
        control();
        Switch (move){
          case right:
            stepX = speed;
            break;
          case left:
            stepX = -speed;
          break;
          case up:
            
          break;
          case down:
            
          break;
          case jump:
            
          break;
          case stay:
            
          break;
        }
        x += stepX * time;
        y += stepY * time;
        time = 0;
        sprite.SetPosition(x, y + 365);
      }
      float MarioX() {
        return x;
      }
      float MarioY() {
        return y;
      }
      void collision(float stepX, stepY) {
        for (int i = ;)
      }
    };
  
  void MarioPos(float x, float y){
    float timeX = x;
    float timeY = y;
    if (X <= 0)
        cameraX = 100;
    if (x < 372)
        cameraY = 372
     camera.setCenter(cameraX, cameraY-180);
  }

int main{
  Father m("hero.png",64, 85, 0, 0);
  m.sprite.setScale(0.8, 0.5);
  int height = 17, width = 240;
  String map[height] = {
"ssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                         u                       bbbbbbbbb   bbbq                        u             bbb                                                                                                                                    s";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                                                                                                                                                                                                                                              s";,
"s                 u     bqbqb                 bqb                  b     bb           u   u   u     b          bb        "
"g(g до 78 символа             g до 167)"
"g(g до 78 символа)"
"g(g до 78 символа)"              // s - небо, g - земля, u - неломаемые прикол, b - ломаемый квадрат 
  }
  
    RenderWindow window1(VideoMode(width * 5, height * 32), "Mario Go Go", Style::Close); //рисуем окно, блокируем разворот
    camera.reset(FloatRect(0, 0, width * 5, height * 32));
    Image icon;
    icon.LoadFromFile("ссылка на иконку");
    window1.setICon(840, 859, icon.GetPixelsPtr()); //icon.GetPixelsPtr - иконка в пиксельной графике
    int size = 32;
    int score = 0;
    Font font;
    font.LoadFromFile("/././.ttf");
    Text scoreText(" lalala ", font, 43);
    
    /*Image hero_image;
    hero_image.LoadFromFile("");
    hero_image.createMaskFrom Color(Color(255,255,255)); // максимальное излучение каждого луча RGB
    Texture hero_texture;
    hero_texture.LoadFromFile("текстуры марио - героя")
    // taly спрайт на спрайте
    Sprite hero_sprite(hero_texture); //вырезаем марио. модель обекта
    hero_sprite.setTextureRect(IntRect(0, 0, 64, 85));
    hero_sprite.SetPosition(0, 360); // стартовый марио */
    Texture map_texture;
    map_texture.LoadFromFile("текстуры земли неба и прочей хуйни")
        Sprite map_sprite(map_texture);
    Music music;
    music.LoadFromFile("музыка ogg");
    music.play();//музыка уже играет - на протяжении всей игры
   float frameMario = 0;
   float frameCoin = 5;

    while (window1.isOpen()) {
        float time = closk.getElapsedTime(), asMicroseconds();
        clock.rastart();// при каждом перезапуске амимации, часы сбрасываются
        time = time / 1000;// чем больше fps,тем плавнее движение
        Event event;//(класс) для того,чтобы зактрывать 
        while (window1.pollEvent(event)) {
            if (event.type == Event::Closed)
                window1.close();// функция
        }
        /* if (Keyboard::isKeyPressed(Keyboard:: Right)){// проще направо,тк текстурки туда и направлены
            //нужно прописать ситуации ухода слева в правую сторону(типа поворот захерачить)
            hero_sprite.setScale(1,1)// функция для отзеркаливания вправую сторону
            nowFrame
+= 0.01 * time; //  время за которое изменяется фрейм 
            if(nowFrame > 4)
            nowFrame -= 4; //откат фрейма к начальному 
            hero_sprite.setTextureRect(IntRect(80* int(nowFrame), 0, 80,85));// вырещали 4 мужика(0вой уже есть)
            hero_sprite.move(time*0.1, 0);// движение
        }
        if (Keyboard::isKeyPressed(Keyboard:: Left))
            hero_sprite.setScale(-1,1)
            nowFrame += 0.1 * time; 
            if(nowFrame > 4)
            nowFrame -= 4; 
            hero_sprite.setTextureRect(IntRect(80* int(nowFrame), 0, 80,85));
            hero_sprite.move(-0.01*time, 0);
    }
    if (Keyboard::isKeyPressed(Keyboard:: Up)){
            hero_sprite.move(0, -0.1*time);
              hero_sprite.setTextureRect(IntRect(418,0,85,85));
    } */
    
    /*    if (Keyboard::isKeyPressed(Keyboard::Right)) {
            m.sprite.setScale(0.8, 0.5);
            m.move = 0;
            m.speed = 0.2;
            frameMario += 0.01 * time
                if (frameMario > 4)
                    frameMario -= 4;
            m.sprite.setTextureRect(IntRect(80 * int(frameMario), 0, 80, 85)); //Приведение типов, для того чтобы не было пол мужика
            MarioPos(m.MarioX(), m.Marioy()); // MarioPos = CamPos; Вызываем функцию позицию камеры и передаём туда значение 
        }

        if (Keyboard::isKeyPressed(Keyboard::Left)) {
                    m.sprite.setScale(-0.8, 0.5);
                    m.move = 1;
                    m.speed = 0.2;
                    frameMario += 0.01 * time
                        if (frameMario > 4)
                            frameMario - +4;
                    m.sprite.setTextureRect(IntRect(80 * int(frameMario), 0, 80, 85));
                    MarioPos(m.MarioX(), m.Marioy());
                }

        if (Keyboard::isKeyPressed(Keyboard::Up)) {
            m.move = 0;
            m.speed = 0.2;
            m.sprite.setTextureRect(IntRect(418, 0, 85, 85));
            MarioPos(m.MarioX(), m.Marioy());
        }
*/
        m.movetime(time); //Что бы мужик стал двигаться и упал с небес на землю
        window1.setView(camera);
        window1.clear(); // Что бы след мужика не оставался
      
        for (int i = 0; i < width; i++)  //выводим текстуры рассматриваем клетки по высоте в таком порядке потому что тип данных стринг и проще объявлять по строчкам
            for (int j = 0; j < height; j++) { // по ширине
                if (map[i][j] == 'g' || map[i][j] == ' ')
                    map_sprite.setTextureRect(IntRect(0, 0, size, size));
                if (map[i][j] == 'u' || map[i][j] == ' ')
                    map_sprite.setTextureRect(IntRect(size, 0, size, size));
                if (map[i][j] == 'b' || map[i][j] == ' ')
                    map_sprite.setTextureRect(IntRect(size * 2, 0, size, size));
                if (map[i][j] == 'q' || map[i][j] == ' ')
                        map_sprite.setTextureRect(IntRect(size * 3, 0, 0, size, size));
                if (map[i][j] == ' ' || map[i][j] == 's')
                    map_sprite.setTextureRect(IntRec(sixe * 4, 0, size, size));// координаты для спрайта небо
                if (map [i][j] == 'c'){
                    frameCoin += 0.00005*time;
                    if(frameCoin > 7)
                        frameCoin -= -2;
                    map_sprite.setTextureRect(IntRect(size * int(frameCoin), 0, size, soze));
            }
            }
                map_sprite.SetPosition(i * size, j * size);
                window1.draw(map_sprite);

            }
        std::ostringstream scoreStream; // output поток символов | scoreStream=cout - то что мы выводим | score - просто счёт
        scoreStream << score;
        scoreText.setString("S C O R E/n/n0000" + scoreStream.str());
        scoreText.setPosition(camera.getCenter().x-550, camera.getCenter().y-272);
        window1.draw(scoreText);
        window1.draw(m.sprite);//рисуем спрайт персонажа
        window1.display(); //вывели на дисплей
    }

}
