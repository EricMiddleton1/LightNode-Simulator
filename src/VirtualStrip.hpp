#pragma once

#include "LightNode/LightStrip.hpp"
#include "StripWindow.hpp"

class VirtualStrip : public LightStrip
{
public:
	VirtualStrip(LightStrip::Type type, size_t ledCount,
		const std::string& name, size_t width, size_t height);

	bool windowUpdate();

protected:
	StripWindow window;
};
