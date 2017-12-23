#include "VirtualMatrix.hpp"


VirtualMatrix::VirtualMatrix(boost::asio::io_service& _ioService, const std::string& name,
	uint8_t width, uint8_t height)
	:	Matrix{_ioService, name, width, height}
	,	window{name, width, height} {
}

bool VirtualMatrix::windowUpdate() {
	return window.windowUpdate();
}

void VirtualMatrix::update() {
	int ledIndex = 0;

	for(const auto& led : leds) {
		int x = ledIndex % window.getWidth(),
			y = ledIndex / window.getWidth();

		window.drawLED(x, y, led.getColor());
		ledIndex++;
	}
}
