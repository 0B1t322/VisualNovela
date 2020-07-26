#pragma once

#include <SFML/Graphics.hpp>

class ABSpageClass
{
protected:
    sf::Vector2f resolution;
    sf::Font stand;
    
    virtual void Init() = 0;
    virtual void Delete() = 0;
};