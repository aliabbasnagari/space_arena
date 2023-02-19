#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
using namespace std;
using namespace sf;
class Animation
{
	Texture texture;
	Sprite sprite;
	Vector2f position;
	float size;
	float rotation;
	int frameRate;
	float offset;
public:
	Animation();
	Animation(Sprite, Texture);
	Animation(string path);
	void setTexture(Texture);
	void setTexture(string path);
	void setSprite(Sprite);
	void setRotation(float);
	void setSize(float);
	void setPosition(Vector2f);
	void setPosition(float, float);
	void move(float, float);
	void move(Vector2f);
	void rotate(float r);
	void update();
	void draw(RenderTarget* window);
};

