#include "Button.h"

void Button::initTexture()
{
    btnTexture = new sf::Texture;
}


Button::Button()
{
    initTexture();
}

Button::~Button()
{
    delete btnTexture;
    //if(btnSprite) delete btnSprite;
}

Button::Button(std::wstring t, sf::Vector2f size, int charSize, const sf::Color &textColor)
{
    button.setSize(size);

    btnWidth = size.x;
    btnHeight = size.y; 

    text.setString(t);
    text.setCharacterSize(charSize);
    text.setFillColor(textColor);

    initTexture();
}

Button::Button(std::wstring t, sf::Vector2f size, int charSize, const sf::Color &bgColor, const sf::Color &textColor)
{
    button.setSize(size);
	button.setFillColor(bgColor);

    // Get these for later use:
    btnWidth = size.x;
    btnHeight = size.y;

    text.setString(t);
    text.setCharacterSize(charSize);    
    text.setFillColor(textColor);

    initTexture();

}

void Button::setPositon(const sf::Vector2f &pos)
{
    button.setPosition(pos);

    float xPos = (pos.x + btnWidth / 2) - (text.getLocalBounds().width / 2);
	float yPos = (pos.y + btnHeight / 3) - (text.getLocalBounds().height / 3);
	text.setPosition(xPos, yPos);
}

bool Button::isMouseOver(sf::RenderWindow &window)
{
    // Текущая позиция мыши
    float mouseX = sf::Mouse::getPosition(window).x;
    float mouseY = sf::Mouse::getPosition(window).y;

    // Позиция Кнопки
    float btnPosX = button.getPosition().x;
    float btnPosY = button.getPosition().y;

    // Ее высота и ширина
    float btnXPosWidth = btnPosX + button.getLocalBounds().width;
    float btnYPosHeight = btnPosY + button.getLocalBounds().height;

    if(mouseX < btnXPosWidth && mouseX > btnPosX && // Если позиция мышки меньше ширины больше координаты
    mouseY < btnYPosHeight && mouseY > btnPosY) // Если позиция мышки меньше высоты и больше координаты
    return true;

    else return false;
}


void Button::setTexture(const sf::Texture *texture)
{
    this->button.setTexture(texture);
}

void Button::setBright()
{
        sf::Uint8 light = 255; // 255 = initial brightness, 0 = black
        button.setFillColor( sf::Color(light, light, light) );
}
void Button::unSetBrigt()
{
        sf::Uint8 light = 200; // 255 = initial brightness, 0 = black
        button.setFillColor( sf::Color(light, light, light) );
}

void exitButton::onClickDo(sf::RenderWindow &window)
{
    window.close();
}

exitButton::exitButton(std::wstring t, sf::Vector2f size, int charSize ,const sf::Color &bgColor,const sf::Color &textColor) 
    : Button(t, size, charSize ,bgColor, textColor)
{

}

exitButton::exitButton()
    : Button()
{ 

}

playButton::playButton()
    : Button()
{

}

playButton::playButton(std::wstring t, sf::Vector2f size, int charSize ,const sf::Color &bgColor,const sf::Color &textColor)
    : Button(t, size, charSize, bgColor,textColor)
{

}

void playButton::onClickDo()
{
    
}

levelButton::levelButton(std::wstring t, sf::Vector2f size, int charSize ,const sf::Color &bgColor,const sf::Color &textColor)
    : Button(t, size, charSize, bgColor,textColor)
{

}

void levelButton::onClickDo()
{

}

void levelButton::setVisable(bool vis)
{
    this->isVisable = vis;
}