#include "VirtualLight.hpp"


VirtualLight::VirtualLight(const std::string& name, uint16_t ledCount, int width, int height)
	:	Light{name, ledCount}
	,	window{name, width, height} {
}

bool VirtualLight::windowUpdate() {
	return window.windowUpdate();
}

void VirtualLight::update() {
	int ledIndex = 0;

	for(const auto& led : leds) {
		window.drawLED(ledIndex % window.getWidth(), ledIndex / window.getWidth(), led.getColor());
		ledIndex++;
	}
}
