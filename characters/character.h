#pragma once

#include<SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>

class Character
{
protected:
    std::string cName;
    sf::RectangleShape cShape;
    sf::Texture cTexture;
    sf::Vector2f position;
    int sHeight;
    int sWidth;

    std::fstream *dialogueFile = nullptr;

public:
    void SetSize(int sHeight, int sWidth);
    void SetPos(int X, int Y);
    void SetTexture(const sf::Texture &texture);
    void DrawTool(sf::RenderWindow &window);
    void setFile( std::string fileName );
    // Andrey work on fileIO system in GAME 
    // some open to read with control read speed and output in sfml dialogue obj
    
};