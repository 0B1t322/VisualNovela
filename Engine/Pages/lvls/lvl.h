#pragma once
#include "character.h"
#include <SFML/Graphics.hpp>

class lvl
{
protected:
    Character *character = nullptr; // Character of course 

    // Background
    sf::Texture *m_backgroundTexture = nullptr;
    sf::Sprite  *m_backgroundSprite  = nullptr;
    // Background end

    
};