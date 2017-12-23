#pragma once

#include "LightNode/Matrix.hpp"
#include "StripWindow.hpp"

class VirtualMatrix : public Matrix {
public:
	VirtualMatrix(boost::asio::io_service& ioService, const std::string& name,
		uint8_t width, uint8_t height);

	bool windowUpdate();

	virtual void update() override;
private:
	StripWindow window;
};
