#include "TextBox.h"

void TextBox::add(const std::string& new_str)
{
    messages.push_back(new_str);
    if (messages.size() > 6){messages.pop_front();}
}

void TextBox::update_str()
{
    for (auto i: messages)
    {
        content.append(i + '\n');
    }
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(background);
    txt.setString(content);
    window.draw(txt);
}