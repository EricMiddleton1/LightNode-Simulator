#pragma once

#include "LightNode/LightStrip.hpp"
#include "StripWindow.hpp"

template<class LightStripClass = LightStrip>
class VirtualStrip : virtual public LightStripClass
{
public:
	VirtualStrip(const std::string& name, size_t width, size_t height)
		:	window(name, width, height) {
	}

	bool windowUpdate() {
		return window.windowUpdate();
	}

protected:
	StripWindow window;
};
