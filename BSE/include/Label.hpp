#ifndef LABEL_HPP
#define LABEL_HPP

#include <SFML/Graphics.hpp>

class Label
{
private:
    sf::Text m_text;
    sf::Font m_font;

public:
    Label(/* args */);
    void setText(const char *);
    ~Label();
};

Label::Label(/* args */)
{
    if (!m_font.loadFromFile("res/font.ttf"))
    {
        printf("couldn't load");
    }

    m_text.setFont(m_font);
    m_text.setCharacterSize(24);
    m_text.setFillColor(sf::Color::Red);
}

void Label::setText(const char* text)
{
    m_text.setString(text);
}

Label::~Label()
{
}

#endif