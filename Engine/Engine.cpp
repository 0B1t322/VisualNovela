#include "Engine.h"

void Engine::initMainPage()
{
    mainpage = new mainPage(stand,resolution);
    std::cout << "Main Page inited!" << std::endl;
}

void Engine::delMainPage()
{
    delete mainpage;
    std::cout << "Main Page deleted!" << std::endl;
}

/*void Engine::initPlayPage()
{
    playpage = new playPage(stand, resolution);
    std::cout << "Play Page inited!" << std::endl;
}*/


/*void Engine::delPlayPage()
{
    delete playpage;
    std::cout << "Play Page deleted!" << std::endl;
}*/
void Engine::setResolution()
{
    this->resolution.x = sf::VideoMode::getDesktopMode().width;
    this->resolution.y = sf::VideoMode::getDesktopMode().height;
}

void Engine::initWindow()
{
    this->m_Window = new sf::RenderWindow;
    this->m_Window->create(sf::VideoMode(resolution.x,resolution.y), //Разрешение
        "Eroge", // Название
        sf::Style::Fullscreen); //Стиль
}

Engine::Engine()
{

    // получаем разрешение экрана и создаем окно SFML и View
    setResolution();
    initWindow();
    stand.loadFromFile("Textures/Times_New_Roman.ttf");
    initMainPage();

}

Engine::~Engine()
{
    delete m_Window;
    if(this->isMainPage) delMainPage();
    //if(this->isPlayPage) delPlayPage();
}


void Engine::start()
{
    sf::Clock clock;
    sf::Event event;
    while(m_Window->isOpen())
    {
        sf::Time dt = clock.restart();

        float dtAsSeconds = dt.asSeconds();

        input(event);
        update(dtAsSeconds);
        draw();
    }
}

