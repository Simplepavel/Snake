#include "SFML/Graphics.hpp"
#include <cstdlib>
#include <iostream>

enum Direction
{
    None,
    Up,
    Donw,
    Left,
    Right
};
class Snake
{
    struct SnakeSegment
    {
        int x = 0;
        int y = 0;
        SnakeSegment *next;
        SnakeSegment(int input_x, int input_y) : x(input_x), y(input_y), next(nullptr) {}
        Direction direction = Direction::None;
        void SetPosition(int new_x, int new_y)
        {
            x = new_x;
            y = new_y;
        }
    };
    SnakeSegment *head;
    SnakeSegment *tail;
    sf::RectangleShape Body;
    int my_size;
    int speed = 15;
    int HEIGHT = 640;
    int WEIGHT = 480;
    int BLOCK_SIZE = 16;
    void destroy();

public:
    Snake(int start_x, int start_y, int s, int ms) : head(new SnakeSegment(start_x, start_y)), speed(s), my_size(ms)
    {
        tail = head;
    }
    ~Snake() { destroy(); }
    int get_x() { return head->x; }
    int get_y() { return head->y; }
    int get_speed() { return speed; }
    void SetDirection(Direction new_dir) { head->direction = new_dir; }
    Direction GetDirection() { return head->direction; }
    void grown_up();
    void move();
    void restart(int new_x, int new_y);
    void draw(sf::RenderWindow &window);
    void update();
    bool TouchApple(sf::Vector2i &coords) { return coords.x == head->x && coords.y == head->y; }
    void CheckBoard();
};