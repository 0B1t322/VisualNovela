#pragma once

#include <SFML/Graphics.hpp>
#include "ABSpageClass.h"
#include "../GUI/Button.h"

class playPage : public ABSpageClass
{
private:
    sf::Texture* m_backgroundTexture = nullptr;
    sf::RectangleShape* m_backgroundSprite = nullptr;

    //Init
    void Init();
    void initTexture();
    void initSprite();

    // Delete
    void Delete();
    void delTexture();
    void delSprite();

public:
    void drawTo( sf::RenderWindow &window );
    playPage();
    ~playPage();


};