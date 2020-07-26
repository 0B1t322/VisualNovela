#include "character.h"

void Character::SetSize(int sHeight, int sWidth)
{
    cShape.setSize(sf::Vector2f(sHeight, sWidth));
}

void Character::SetPos(int X, int Y)
{
    cShape.setPosition(X, Y);
}

void Character::SetTexture(const sf::Texture &texture)
{
    this->cTexture = texture;
    this->cShape.setTexture(&cTexture);
}

void Character::DrawTool(sf::RenderWindow &window)
{
    window.draw(this->cShape);
}

void Character::setFile(std::string fileName)
{
    dialogueFile = new std::fstream(fileName);
    if( !dialogueFile->is_open() ) std::cout << " file not existed" << std::endl;
    dialogueFile->close();
}