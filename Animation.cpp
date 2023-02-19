#include "Animation.h"

Animation::Animation()
{
	this->size = 1;
	this->rotation = 0;
}

Animation::Animation(sf::Sprite sp, sf::Texture tex)
{
	this->size = 1;
	this->rotation = 0;
	this->sprite = sp;
	this->texture = tex;
}

Animation::Animation(string path)
{
	this->size = 1;
	this->rotation = 0;
	this->setTexture(path);
}

void Animation::setTexture(sf::Texture tex)
{
	this->texture = tex;
	this->update();
}

void Animation::setTexture(string path)
{
	texture.loadFromFile(path);
	this->update();
}

void Animation::setSprite(sf::Sprite sp)
{
	this->sprite = sp;
}

void Animation::setRotation(float r)
{
	this->rotation = r;
	this->update();
}

void Animation::setSize(float s)
{
	this->size = s;
	this->update();
}

void Animation::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	this->update();
}

void Animation::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->update();
}

void Animation::move(float x, float y)
{
	position.x += x;
	position.y += y;
	this->update();
}

void Animation::move(sf::Vector2f mov)
{
	position += mov;
	this->update();
}

void Animation::rotate(float r)
{
	this->rotation += r;
	this->update();
}

void Animation::update()
{
	this->sprite.setTexture(texture);
	this->sprite.setScale(sf::Vector2f(size, size));
	this->sprite.setPosition(position);
	this->sprite.setRotation(rotation);
}

void Animation::draw(sf::RenderTarget* window)
{
	window->draw(this->sprite);
}
