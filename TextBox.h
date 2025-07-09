#include <list>
#include <string>
#include "SFML/Graphics.hpp"
class TextBox
{
    std::list<std::string> messages;
    sf::Text txt;
    sf::Font font;
    sf::RectangleShape background;
    int size = 12;
    int x = 2;
    int y = 2;
    std::string content;
    public:
    TextBox()
    {
        if (!font.loadFromFile("Font/arial.ttf"))
        {
            throw "Error of loading font";
        };
        txt.setFont(font);
        txt.setFillColor(sf::Color::White);
        txt.setCharacterSize(size);
        txt.setPosition(x * 1.2, y * 1.2);


        background.setFillColor(sf::Color(90, 90, 90, 90));
        background.setSize(sf::Vector2f(122, 90));
        background.setPosition(x, y);
    }
    void draw(sf::RenderWindow&);
    void add(const std::string&);
    void update_str();
    void clear(){content.clear();}
};