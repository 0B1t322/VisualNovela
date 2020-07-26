#include "Engine.h"

void Engine::input(sf::Event event)
{
    // обработка escape
    while (m_Window->pollEvent(event))
        {
            if(isMainPage) mainPageInput(event);
            //if(isPlayPage) playPageInput(event);
// --------------------------------------------------------------

            if (event.type == sf::Event::Closed)
                m_Window->close();
            if(event.type == sf::Event::KeyPressed) // кнопочки
                switch (event.key.code)
                {
                case sf::Keyboard::Escape:
                    m_Window->close();
                    break;
                }

//----------------------------------------------------------------
        }
}

void Engine::mainPageInput(sf::Event event)
{
    if(event.type == sf::Event::MouseButtonPressed && this->isMainPage)
    {
        // EXIT_BUTTON
        if( this->mainpage->getExitButton()->isMouseOver(*m_Window) ) 
            this->mainpage->getExitButton()->onClickDo(*m_Window);
        // PLAY_BUTTON
        if( this->mainpage->getPlayButton()->isMouseOver(*m_Window) ) 
        {
            this->isMainPage = false;
            this->delMainPage();


            /*this->initPlayPage();
            this->isPlayPage = true;*/
        }
    }
    if(event.type == sf::Event::MouseMoved && this->isMainPage)
    {
        // EXIT_BUTTON
        if( this->mainpage->getExitButton()->isMouseOver(*m_Window)) 
            this->mainpage->getExitButton()->setBright();
        else this->mainpage->getExitButton()->unSetBrigt();
        // PLAY_BUTTON
        if( this->mainpage->getPlayButton()->isMouseOver(*m_Window)) 
            this->mainpage->getPlayButton()->setBright();
        else this->mainpage->getPlayButton()->unSetBrigt();
    }  
}

/*void Engine::playPageInput(sf::Event event)
{
    if(event.type == sf::Event::MouseButtonPressed && this->isPlayPage)
    {
        // BACK_BUTTON
        if( this->playpage->getBackButton()->isMouseOver(*m_Window) )
        {
            this->isPlayPage = false;
            this->delPlayPage();
            this->initMainPage();
            this->isMainPage = true;
        }
    }

    if(event.type == sf::Event::MouseMoved && this->isPlayPage)
    {
        // BACK_BUTTON
        if(this->playpage->getBackButton()->isMouseOver(*m_Window))
            this->playpage->getBackButton()->setBright();
        else this->playpage->getBackButton()->unSetBrigt();
    }
}
*/