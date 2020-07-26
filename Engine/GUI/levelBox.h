#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "Button.h"
class levelBox
{
private:
    sf::RectangleShape box;
    std::vector <levelButton *> buttonList;
    
    int boxWidth;
    int boxHeight;
public:
    levelBox();
    levelBox(sf::Vector2f &size, sf::Vector2f &pos);
    ~levelBox();
    void addButton(levelButton *btn);
    void setColor(const sf::Color &color);
    void draw(sf::RenderWindow &window);
};