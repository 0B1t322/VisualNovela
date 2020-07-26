#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

class Textbox
{
private:
    sf::Text textbox;
    std::wostringstream text;
    bool isSelected = false;
    bool hasLimit = false;
    int limit;

    void inputLogic(int charTyped);

    void deleteLastChar();

public:
    Textbox();
    Textbox(int size, sf::Color color, bool sel);
    void setFont(const sf::Font &font) {textbox.setFont(font);}
    void setPosition(sf::Vector2f pos) {textbox.setPosition(pos);}
    void setLimit(bool ToF) {hasLimit = ToF; }
    void setLimit(bool ToF, int lim) {hasLimit = ToF; limit = lim - 1;}
    void setSelected(bool sel);
    std::wstring getText() {return text.str();}
    void drawTo(sf::RenderWindow &window) {window.draw(textbox);}
    void typeOn(sf::Event input);
};