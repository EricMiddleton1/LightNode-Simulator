#include "VirtualLight.hpp"


VirtualLight::VirtualLight(boost::asio::io_service& _ioService, const std::string& name,
	uint16_t ledCount)
	:	Light{_ioService, name, ledCount}
	,	window{name, ledCount, 1} {
}

bool VirtualLight::windowUpdate() {
	return window.windowUpdate();
}

void VirtualLight::update() {
	int ledIndex = 0;

	for(const auto& led : leds) {
		int x = ledIndex % window.getWidth(),
			y = ledIndex / window.getWidth();

		if(y & 0x01) {
			x = window.getWidth() - x - 1;
		}
		window.drawLED(x, y, led.getColor());
		ledIndex++;
	}
}
