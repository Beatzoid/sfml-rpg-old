#pragma once

#include "GameState.h"
#include"../UI/Button.h"

class MainMenuState :
    public State
{
private:
    // Variables
    sf::RectangleShape background;
    sf::Font font;

    Button* gamestateButton;

    // Functions
    void initFonts();
    void initKeybinds();

public:
    MainMenuState(sf::RenderWindow* window, std::map<std::string, int>* supportedKeys);
    virtual ~MainMenuState();

    void endState();

    void updateInput(const float& dt);
    void update(const float& dt);
    void render(sf::RenderTarget* target = nullptr);
};

