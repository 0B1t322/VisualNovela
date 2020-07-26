#include "Engine.h"


void Engine::draw()
{
    // стираем прошлый кадр
    this->m_Window->clear(sf::Color::Blue);

    // отрисовываем фон
    if(isMainPage) this->mainPageDraw();
    //if(isPlayPage) this->playPageDraw();
    //if(isPlayPage) drawPlayPage();
    // Отображаем все что нарисовали
    this->m_Window->display();
}

void Engine::mainPageDraw()
{
    //m_Window->draw(*m_BackgroundSprite);
    //textbox1.drawTo(*m_Window); // texbox test
    this->mainpage->drawBackgoround(*m_Window);
    this->mainpage->getExitButton()->drawTo(*m_Window);
    this->mainpage->getPlayButton()->drawTo(*m_Window);
    this->mainpage->test.DrawTool(*m_Window);
}

/*void Engine::playPageDraw()
{
    this->playpage->drawBackground(*m_Window);
    this->playpage->getBackButton()->drawTo(*m_Window);
    this->playpage->getLevelBox()->draw(*m_Window);
    this->playpage->getLevelBox()->draw(*m_Window);
}*/