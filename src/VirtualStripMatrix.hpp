#pragma once


#include "LightNode/LightStripMatrix.hpp"
#include "VirtualStrip.hpp"

class VirtualStripMatrix : public VirtualStrip<LightStripMatrix>
{
public:
	VirtualStripMatrix(uint8_t width, uint8_t height);

private:
	virtual void update() override;
};
