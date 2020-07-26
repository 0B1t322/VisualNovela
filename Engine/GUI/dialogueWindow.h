#pragma once

#include <SFML/Graphics.hpp>

class dialogueWindow
{
private:
    // Texture
    sf::RectangleShape* m_dialogueSprite = nullptr;
    sf::Texture* m_dialogueTexture = nullptr;

    // Positions and size
    sf::Vector2f m_dialoguePos;

    // Init
    void initDialogueSprite();
    void initDialogueTexture();


    // Delete
    void deleteDialogueSprite();
    void deleteDialogueTexture();

public:
    dialogueWindow();
    dialogueWindow(const sf::Vector2f &pos, const sf::Vector2f &size);
    ~dialogueWindow();
    void setDialogueTexture(sf::Texture * texture);
    void setDialogueTexture(std::string textPath);
    void draw( sf::RenderWindow *window);
};