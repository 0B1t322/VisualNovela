#include "playPage.h"

playPage::playPage()
{
    Init();
}

playPage::~playPage()
{
    Delete();
}


void playPage::drawTo( sf::RenderWindow &window)
{
    window.draw(*m_backgroundSprite);
}


void playPage::initTexture()
{
    m_backgroundTexture = new sf::Texture;
    m_backgroundTexture->loadFromFile("Textures/background.png");

}

void playPage::initSprite()
{
    m_backgroundSprite = new sf::RectangleShape;
    m_backgroundSprite->setTexture(m_backgroundTexture);
}


void playPage::Init()
{
    initTexture();
    initSprite();
}

void playPage::delTexture()
{
    delete m_backgroundTexture;
}

void playPage::delSprite()
{
    delete m_backgroundSprite;
}

void playPage::Delete()
{
    delSprite();
    delTexture();
}