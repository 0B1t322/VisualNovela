#include "mainPage.h"

mainPage::mainPage(const sf::Font &stand, const sf::Vector2f &resolution)
{
    this->stand = stand;
    this->resolution = resolution;
    initTexturs();
    initSprites();
    initButtons();
}

mainPage::~mainPage()
{
    delSprites();
    delButtons();
    delTexturs();
}

void mainPage::initTexturs()
{
    this->m_BackgroundTexture = new sf::Texture;
    this->m_BackgroundTexture->loadFromFile("Textures/background.jpg");

    this->m_ButtonTexture = new sf::Texture;
    this->m_ButtonTexture->loadFromFile("Textures/button1.png");
    this->m_ButtonTexture->setSmooth(true);
}

void mainPage::initSprites()
{
    this->m_BackgroundSprite = new sf::RectangleShape;
    this->m_BackgroundSprite->setSize(resolution);
    this->m_BackgroundSprite->setTexture(m_BackgroundTexture);
}

void mainPage::initButtons()
{
    //------------------------EXIT_BUTTON------------------------------
    this->m_exitBtn = new exitButton(L"Exit", {resolution.x/10, resolution.y/10}, 20, sf::Color::Black);
    this->m_exitBtn->setFont(stand);
    this->m_exitBtn->setPositon( {resolution.x/2, resolution.y - resolution.y/5} );
    this->m_exitBtn->setTexture(m_ButtonTexture);
    this->m_exitBtn->unSetBrigt();
    //------------------------PLAY_BUTTON---------------------------------
    this->m_playBtn = new playButton(L"Play", {resolution.x/10, resolution.y/10}, 20 ,sf::Color::Black);
    this->m_playBtn->setFont(stand);
    this->m_playBtn->setPositon({resolution.x/2, resolution.y/2});
    this->m_playBtn->setTexture(m_ButtonTexture);
}

void mainPage::delTexturs()
{
    delete this->m_BackgroundTexture;
    delete this->m_ButtonTexture;
}

void mainPage::delSprites()
{
    delete this->m_BackgroundSprite;
}

void mainPage::delButtons()
{
    delete this->m_playBtn;
    delete this->m_exitBtn;
}

void mainPage::drawBackgoround(sf::RenderWindow &window)
{
    window.draw(*this->m_BackgroundSprite);
}

void mainPage::drawExitButton(sf::RenderWindow &window)
{
    this->m_exitBtn->drawTo(window);
}