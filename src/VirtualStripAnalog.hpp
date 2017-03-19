#pragma once


#include "VirtualStrip.hpp"


class VirtualStripAnalog : public VirtualStrip<>
{
public:
	VirtualStripAnalog();

private:
	static constexpr size_t LEDS_PER_STRIP = 50;
	static size_t stripCount;

	virtual void update() override;
};
