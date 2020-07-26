#include "dialogueWindow.h"

dialogueWindow::dialogueWindow()
{
    initDialogueTexture();
    initDialogueSprite();
}

dialogueWindow::dialogueWindow(const sf::Vector2f &pos, const sf::Vector2f &size)
{
    initDialogueTexture();
    initDialogueSprite();

    this->m_dialogueSprite->setPosition(pos);
    this->m_dialogueSprite->setSize(size);
}

dialogueWindow::~dialogueWindow()
{
    deleteDialogueSprite();
    deleteDialogueTexture();
}

void dialogueWindow::initDialogueTexture()
{
    this->m_dialogueTexture = new sf::Texture;
}

void dialogueWindow::initDialogueSprite()
{
    this->m_dialogueSprite = new sf::RectangleShape;
}

void dialogueWindow::deleteDialogueTexture()
{
    delete m_dialogueTexture;
}

void dialogueWindow::deleteDialogueSprite()
{
    delete m_dialogueSprite;
}

void dialogueWindow::setDialogueTexture(sf::Texture * texture)
{
    this->m_dialogueTexture = texture;
    this->m_dialogueSprite->setTexture(texture);
}

void dialogueWindow::setDialogueTexture(std::string textPath)
{
    this->m_dialogueTexture->loadFromFile(textPath);
    this->m_dialogueSprite->setTexture( this->m_dialogueTexture );
}

void dialogueWindow::draw(sf::RenderWindow *window)
{
    window->draw( *this->m_dialogueSprite );
}