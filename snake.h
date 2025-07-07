#include "SFML/Graphics.hpp"
#include <cstdlib>
class Snake
{
    enum class Direction{None, Up, Donw, Left, Right};
    struct SnakeSegment
    {
        int x = 0;
        int y = 0;
        SnakeSegment* next;
        SnakeSegment(int input_x, int input_y):x(input_x), y(input_y), next(nullptr){}
        Direction direction = Direction::None;
        void SetPosition(int new_x, int new_y)
        {
            x = new_x;
            y = new_y;
        }
    };
    SnakeSegment* head;
    SnakeSegment* tail;
    sf::RectangleShape Body;
    int my_size;
    int speed = 15;
    void destroy();
    public:
    Snake(int start_x, int start_y, int s, int ms):head(new SnakeSegment(start_x, start_y)), speed(s), my_size(ms){}
    ~Snake(){destroy();}
    void grown_up();
    void move();
    void restart(int new_x, int new_y);
    void draw(sf::RenderWindow& window);
    void update(sf::RenderWindow& window);
};