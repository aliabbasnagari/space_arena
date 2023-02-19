#pragma once
#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;

class Player
{
private:
	Texture texture;
	
	Vector2f position;
	float size;
public:
	Sprite sprite;
	float rotation;
	Player();
	Player(sf::Sprite, sf::Texture);
	Player(string path);
	void setTexture(sf::Texture);
	void setTexture(string path);
	void setSprite(sf::Sprite);
	void setRotation(float);
	void setSize(float);
	void setPosition(sf::Vector2f);
	void setPosition(float, float);
	void move(float, float);
	void move(float);
	void move(sf::Vector2f);
	void rotate(float r);
	void update();
	void draw(sf::RenderTarget* window);
	void offset(float, float);
	Vector2f getPosition();
};

