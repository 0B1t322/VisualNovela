#pragma once
#include <SFML/Graphics.hpp>
#include "../GUI/Button.h"
#include "../GUI/dialogueWindow.h"
#include "../../characters/Ulayna/Ulyana.h"
class mainPage
{
private:
    sf::Vector2f resolution;

    //sf::Sprite* m_BackgroundSprite = nullptr;
    sf::RectangleShape* m_BackgroundSprite = nullptr;

    sf::Texture* m_BackgroundTexture = nullptr;
    sf::Texture* m_ButtonTexture = nullptr;
    

    sf::Font stand;

    exitButton* m_exitBtn = nullptr;
    playButton* m_playBtn = nullptr;
    //Init
    void initTexturs();
    void initSprites();
    void initButtons();

    //Delete
    void delTexturs();
    void delSprites();
    void delButtons();
public:
    mainPage();
    mainPage(const sf::Font &stand, const sf::Vector2f &resolution);
    ~mainPage();
    void drawBackgoround(sf::RenderWindow &window);
    void drawExitButton(sf::RenderWindow &window);
    exitButton* getExitButton() { return this->m_exitBtn; };
    playButton* getPlayButton() { return this->m_playBtn; };
    Ulyana test;
};