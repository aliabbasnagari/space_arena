#include "Player.h"

const float PI = 3.14159265359;

Player::Player()
{
	this->size = 1;
	this->rotation = 0;
}

Player::Player(Sprite sp, Texture tex)
{
	this->size = 1;
	this->rotation = 0;
	this->sprite = sp;
	this->texture = tex;
}

Player::Player(string path)
{
	this->size = 1;
	this->rotation = 0;
	this->setTexture(path);
}

void Player::setTexture(Texture tex)
{
	this->texture = tex;
	this->update();
}

void Player::setTexture(string path)
{
	texture.loadFromFile(path);
	this->update();
}

void Player::setSprite(sf::Sprite sp)
{
	this->sprite = sp;
}

void Player::setRotation(float r)
{
	this->rotation = r;
	this->update();
}

void Player::setSize(float s)
{
	this->size = s;
	this->update();
}

void Player::setPosition(sf::Vector2f pos)
{
	this->position = pos;
	this->update();
}

void Player::setPosition(float x, float y)
{
	this->position.x = x;
	this->position.y = y;
	this->update();
}

void Player::move(float x, float y)
{
	position.x += x;
	position.y += y;
	this->update();
}

void Player::move(float vel)
{
	float theta = (90 - this->rotation);
	theta = theta * (PI / 180); // Degree to Radians
	position.x += (vel * cos(theta));
	position.y -= (vel * sin(theta));
	this->update();
}

void Player::move(sf::Vector2f mov)
{
	position += mov;
	this->update();
}

void Player::rotate(float r)
{
	this->rotation += r;
	this->update();
}

void Player::update()
{
	this->sprite.setTexture(texture);
	this->sprite.setScale(sf::Vector2f(size, size));
	this->sprite.setPosition(position);
	this->sprite.setRotation(rotation);
}

void Player::draw(sf::RenderTarget* window)
{
	window->draw(this->sprite);
}

void Player::offset(float x, float y)
{
	this->sprite.setOrigin(x, y);
}

Vector2f Player::getPosition()
{
	return position;
	return Vector2f();
}
