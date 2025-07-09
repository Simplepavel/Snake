#include "snake.h"
class World
{
    int height;
    int weight;
    sf::CircleShape apple;
    int my_size;
    public:
    World(int w, int h, int ms): height(h), weight(w), my_size(ms)
    {
        apple.setFillColor(sf::Color(0, 255, 0));
        apple.setRadius(my_size / 2);
        apple.setOrigin(apple.getRadius(), apple.getRadius());
    }
    int get_size(){return my_size;}
    void CheckBoard(Snake& snk);
    void RespawnApple();
    bool TouchApple(Snake& snk);
    void draw(sf::RenderWindow&);

};

