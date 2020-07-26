#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Button
{
private:
    sf::RectangleShape button;
    sf::Text text;
    sf::Texture *btnTexture;
    //sf::Sprite *btnSprite;
    float btnWidth;
	float btnHeight;

    void initTexture();


public:
    Button();
    ~Button();
    Button(std::wstring t, sf::Vector2f size, int charSize, const sf::Color &textColor);
    Button(std::wstring t, sf::Vector2f size, int charSize ,const sf::Color &bgColor,const sf::Color &textColor);
    void setFont(const sf::Font &font) {text.setFont(font); };
    void setBackColor(const sf::Color &col) { button.setFillColor(col); };
    void setTextColor(const sf::Color &col) {text.setFillColor(col); };
    void setPositon(const sf::Vector2f &pos);
    void drawTo(sf::RenderWindow &window) {window.draw(button); window.draw(text); };
    bool isMouseOver(sf::RenderWindow &window);
    void onClickDo();
    sf::Vector2f getPosition() 
    {
        int btnXPosWidth = button.getPosition().x + button.getLocalBounds().width;
        int btnYPosHeight = button.getPosition().y + button.getLocalBounds().height;
        sf::Vector2f pos;
        pos.x = btnXPosWidth;
        pos.y = btnYPosHeight;
        return pos;
    };
    void setTexture(const sf::Texture *texture);
    void setBright();
    void unSetBrigt();
    sf::Vector2f getSize() { return {this->btnWidth, this->btnHeight}; };
};


class exitButton: public Button
{
using Button::Button;
public:
    exitButton();
    exitButton(std::wstring t, sf::Vector2f size, int charSize ,const sf::Color &bgColor,const sf::Color &textColor);

    virtual void onClickDo(sf::RenderWindow &window);
};

class playButton: public Button
{
    using Button::Button;
public:
    playButton();
    playButton(std::wstring t, sf::Vector2f size, int charSize, const sf::Color &bgColor ,const sf::Color &textColor);
    
    virtual void onClickDo();
};

class levelButton: public Button
{
    using Button::Button;
private:
    bool isVisable = true;
public:
    levelButton();
    levelButton(std::wstring t, sf::Vector2f size, int charSize, const sf::Color &bgColor ,const sf::Color &textColor);
    virtual void onClickDo();
    void setVisable(bool vis);
    bool getVisable() { return this->isVisable; };
};
