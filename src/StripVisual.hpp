#pragma once

#include <atomic>
#include <SFML/Graphics.hpp>

#include "LightNode/LightStrip.hpp"

class StripVisual : public LightStrip
{
public:
	StripVisual(size_t ledCount, size_t width, size_t height);

	virtual void update();

	//SFML has a problem with the window event loop
	//running in any thread other than the main thread.
	//So, you have to call this often from the main thread
	bool windowUpdate();
private:
	static const int LED_BORDER = 3;
	static const int LED_SIZE = 20;
	static const int LED_OUTLINE_THICKNESS = 1;

	sf::RenderWindow window;
	size_t windowWidth, windowHeight;

	std::atomic_flag updateFlag;
};
