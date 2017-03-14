#include "VirtualStripDigital.hpp"

#include <string>
#include <algorithm>
#include <iostream>

constexpr size_t VirtualStripDigital::LEDS_PER_LINE;

VirtualStripDigital::VirtualStripDigital(size_t _ledCount)
	:	VirtualStrip(LightStrip::Type::Digital, _ledCount,
		"Digital Strip - " + std::to_string(_ledCount) + " LEDs",
		std::min(_ledCount, LEDS_PER_LINE), 1 + (_ledCount-1) / LEDS_PER_LINE) {
}

void VirtualStripDigital::update() {
	for(size_t i = 0; i < leds.size(); ++i) {
		size_t y = i / LEDS_PER_LINE;
		size_t x = (y%2) ? (LEDS_PER_LINE - (i%LEDS_PER_LINE) - 1) : (i%LEDS_PER_LINE);
		
		window.drawLED(x, y, leds[i]);
	}
}
