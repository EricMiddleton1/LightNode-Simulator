#include "VirtualStripAnalog.hpp"


constexpr size_t VirtualStripAnalog::LEDS_PER_STRIP;
size_t VirtualStripAnalog::stripCount = 0;


VirtualStripAnalog::VirtualStripAnalog()
	:	VirtualStrip(LightStrip::Type::Analog, 1,
		"Analog Strip " + std::to_string(stripCount++), LEDS_PER_STRIP, 1) {
}

void VirtualStripAnalog::update() {
	for(size_t i = 0; i < LEDS_PER_STRIP; ++i) {
		window.drawLED(i, 0, leds[0]);
	}
}
