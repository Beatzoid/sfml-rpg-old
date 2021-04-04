#include "Game.h"

// Initialization Functions
void Game::initWindow()
{

    std::ifstream ifs("Config/window.ini");

    std::string title = "None";
    sf::VideoMode window_bounds(800, 600);
    unsigned framelate_limit = 120;
    bool verticle_sync_enabled = false;

    if (ifs.is_open())
    {
        std::getline(ifs, title);
        ifs >> window_bounds.width >> window_bounds.height;
        ifs >> framelate_limit;
        ifs >> verticle_sync_enabled;
    }
    
    ifs.close();

	this->window = new sf::RenderWindow(window_bounds, title);
    this->window->setFramerateLimit(framelate_limit);
    this->window->setVerticalSyncEnabled(verticle_sync_enabled);
}

// Constructors/Destructors
Game::Game() 
{
    this->initWindow();
}

Game::~Game() 
{
	delete this->window;
}

// Functions

void Game::updateDt()
{
    /* Update the dt variable with the time it takes to update and render one frame */
    this->dt = this->dtClock.restart().asSeconds();
}

void Game::updateSFMLEvents()
{
    while (this->window->pollEvent(this->sfEvent))
    {
        if (this->sfEvent.type == sf::Event::Closed)
            this->window->close();
    }
}

void Game::update()
{
    this->updateSFMLEvents();
}

void Game::render()
{
    this->window->clear();
    this->window->display();
}

void Game::run()
{
    while (this->window->isOpen())
    {
        this->updateDt();
        this->update();
        this->render();
    }
}
