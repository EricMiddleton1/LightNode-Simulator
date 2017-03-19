#pragma once


#include "VirtualStrip.hpp"


class VirtualStripDigital : public VirtualStrip<>
{
public:
	VirtualStripDigital(size_t ledCount);

private:
	static constexpr size_t LEDS_PER_LINE = 75;

	virtual void update() override;
};
