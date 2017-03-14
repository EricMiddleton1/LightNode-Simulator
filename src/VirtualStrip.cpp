#include "VirtualStrip.hpp"


VirtualStrip::VirtualStrip(LightStrip::Type _type, size_t _ledCount,
	const std::string& _name, size_t _width, size_t _height)
	:	LightStrip(_type, _ledCount)
	,	window(_name, _width, _height) {
}

bool VirtualStrip::windowUpdate() {
	return window.windowUpdate();
}
