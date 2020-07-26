#pragma once
#include<SFML/Graphics.hpp>
#include<string>
#include "GUI/Textbox.h"
#include "GUI/Button.h"
#include "Pages/mainPage.h"
#include "Pages/playPage.h"


class Engine
{
private:
    sf::RenderWindow *m_Window = nullptr; // Окно
    sf::Vector2f resolution; // разрешение
    
    mainPage *mainpage = nullptr;
    playPage *playpage = nullptr;

    sf::Font stand;
    
    void input(sf::Event event); // input.cpp
    void update(float dtAsSecond); // update.cpp
    void draw(); // draw.cpp
    
    void initWindow();
    void setResolution();
    
    //mainPage
    void initMainPage();
    void mainPageDraw();
    void mainPageInput(sf::Event event);
    void delMainPage();
    
    /*//playPage
    void initPlayPage();
    void playPageDraw();
    void playPageInput(sf::Event event);
    void delPlayPage();*/
public:

    bool isMainPage = true;
    //bool isPlayPage = false;

    Engine();
    ~Engine();
    void start();

};
