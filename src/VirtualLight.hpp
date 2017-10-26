#pragma once

#include "LightNode/Light.hpp"
#include "StripWindow.hpp"

class VirtualLight : public Light {
public:
	VirtualLight(const std::string& name, uint16_t ledCount, int width, int height);

	bool windowUpdate();

	virtual void update() override;
private:
	StripWindow window;
};
