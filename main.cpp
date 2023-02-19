#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include "Player.h"

using namespace std;
using namespace sf;
int main()
{
	float acc = 0.1;
	float speed = 1;
	RenderWindow window(VideoMode(800, 600), "Space Arena", Style::Close | Style::Titlebar);
	Event events;

	bool ammoLoaded = true;
	bool decelerate = false;

	Clock clock;

	Player ship("Assets/Images/spaceship.png");
	ship.setSize(0.2);
	ship.setPosition(300, 300);
	ship.offset(250, 250);

	Player enemy("Assets/Images/enemy_1.png");
	ship.setSize(0.2);
	ship.setPosition(300, 300);
	ship.offset(250, 250);

	Player bullet("Assets/Images/bullet.png");
	bullet.setSize(0.1);
	bullet.offset(75, 138);


	window.setFramerateLimit(60);
	while (window.isOpen()) {
		Time delta_time = clock.restart();
		while (window.pollEvent(events)) {
			switch (events.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				if (events.key.code == Keyboard::Escape) {
					window.close();
				}
				break;
			case Event::KeyReleased:
				if (events.key.code == Keyboard::W || events.key.code == Keyboard::S) {
					decelerate = true;
				}
				break;
			default:
				break;
			}
		}

		if (Keyboard::isKeyPressed(Keyboard::W)) {
			ship.move(speed);
			decelerate = false;
		} else if (Keyboard::isKeyPressed(Keyboard::S)) {
			ship.move(-speed);
			decelerate = false;
		}
		if (Keyboard::isKeyPressed(Keyboard::A)) {
			ship.rotate(-1);
		} else if (Keyboard::isKeyPressed(Keyboard::D)) {
			ship.rotate(1);
		}

		if (Keyboard::isKeyPressed(Keyboard::Space)) {
			if (ammoLoaded) {
				bullet.setPosition(ship.getPosition());
				bullet.setRotation(ship.rotation);
				ammoLoaded = false;
			}
		}

		if (decelerate) {
			if (speed > 1) {
				speed -= acc;
				ship.move(speed);
			}
		} else {
			if (speed < 4) {
				speed += acc;
			}
		}


		window.clear(Color(60, 61, 65, 255));
		if (!ammoLoaded) {
			if (bullet.getPosition().x < 0 || bullet.getPosition().y < 0 ||
				bullet.getPosition().x > 800 || bullet.getPosition().y > 600) {
				ammoLoaded = true;
			} else {
				bullet.draw(&window);
				bullet.move(6);
			}
		}
		enemy.draw(&window);
		ship.draw(&window);
		window.display();
		ship.move(0.2);
	}
	return 0;
}