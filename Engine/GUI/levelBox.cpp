#include "levelBox.h"

levelBox::levelBox()
{

}

levelBox::levelBox(sf::Vector2f &size, sf::Vector2f &pos)
{
    this->boxWidth = size.x;
    this->boxHeight = size.y;
    this->box.setSize(size);
    this->box.setPosition(pos);
    this->setColor( sf::Color(128, 128, 128) );
}

void levelBox::setColor(const sf::Color &color)
{
    box.setFillColor(color);
}

void levelBox::addButton(levelButton *btn)
{
    if( buttonList.empty() )
    {
        sf::Vector2f pos = box.getPosition();
        btn->setPositon( {pos.x + 10, pos.y + 10} );
        pos = btn->getSize();
        box.setSize( { pos.x + 20, pos.y + 20 } );
    }
    else if (buttonList.size() <= 3)
    {
        sf::Vector2f pos = buttonList.back()->getPosition();
        btn->setPositon( {pos.x + 10, pos.y - buttonList.back()->getSize().y} );
        pos = btn->getSize();
        box.setSize( { pos.x + box.getSize().x + 10, pos.y + 20 } );
    }
    else
    {
        sf::Vector2f pos = buttonList.front()->getPosition();
        btn->setPositon( {pos.x, pos.y - 10} );
    }
    
    buttonList.push_back(btn);
    sf::Vector2f pos = buttonList.back()->getPosition();
}

void levelBox::draw(sf::RenderWindow &window)
{
    window.draw(box);
    for(levelButton* btn : buttonList)
    {
        btn->drawTo(window);
    }
}

