#include "StripVisual.hpp"

#include <iostream>

using namespace std;
using namespace sf;

StripVisual::StripVisual(size_t _ledCount, size_t _width, size_t _height)
	: LightStrip(_ledCount)
	,	window(VideoMode(_width, _height), "LightNode - Visualizer") 
	,	windowWidth{_width}
	,	windowHeight{_height} {
	
	updateFlag.clear();
}

void StripVisual::update() {
	updateFlag.clear();
}

bool StripVisual::windowUpdate() {
	bool update = !updateFlag.test_and_set();

	sf::Event event;
	while(window.pollEvent(event)) {
		if(event.type == sf::Event::Closed) {
			window.close();
			return false;
		}
	}

	if(update) {
		window.clear(sf::Color::Black);
		
		{
			unique_lock<mutex> ledLock(ledMutex);

			int ledCount = leds.size();

			for(int i = 0, x = LED_BORDER, y = LED_BORDER, dir = 1; i < ledCount; ++i) {
				RectangleShape led(Vector2f(LED_SIZE, LED_SIZE));

				led.setPosition(x, y);
				led.setOutlineColor(sf::Color(64, 64, 64));
				led.setOutlineThickness(LED_OUTLINE_THICKNESS);
				led.setFillColor({leds[i].getRed(), leds[i].getGreen(),
					leds[i].getBlue()});
				
				window.draw(led);
				
				//Have LEDs "snake" across the screen
				int newX = x + dir*(LED_SIZE + LED_BORDER);
				if( (newX >= LED_BORDER) &&
					(newX <= ((int)windowWidth - LED_BORDER - LED_SIZE)) ) {
					x = newX;
				}
				else {
					y += LED_SIZE + LED_BORDER;
					dir *= -1;
				}
			}
		}

		window.display();
	}

	return true;
}
