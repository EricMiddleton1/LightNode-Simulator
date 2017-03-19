#include "VirtualStripMatrix.hpp"

VirtualStripMatrix::VirtualStripMatrix(uint8_t _width, uint8_t _height)
	:	LightStripMatrix(_width, _height)
	,	VirtualStrip("Matrix Strip", _width, _height) {
}

void VirtualStripMatrix::update() {
	for(unsigned int y = 0; y < height; ++y) {
		for(unsigned int x = 0; x < width; ++x) {
			window.drawLED(x, y, leds[width*y + x]);
		}
	}
}
