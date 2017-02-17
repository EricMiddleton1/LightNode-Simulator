#pragma once

#include "LightNode/LightStrip.hpp"


class StripDebug : public LightStrip
{
public:
	enum class DebugLevel {
		NONE,
		SOME,
		FULL
	};

	StripDebug(size_t ledCount, DebugLevel debugLevel);

	virtual void update();
private:
	DebugLevel debugLevel;
};
