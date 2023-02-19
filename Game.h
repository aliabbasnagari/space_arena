#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Game
{
private:
	sf::RenderWindow* window;
public:
	Game();
	Game(sf::RenderWindow);
};

