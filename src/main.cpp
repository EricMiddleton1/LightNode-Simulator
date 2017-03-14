#include "LightNode/LightNode.hpp"

#include "VirtualStripDigital.hpp"
#include "VirtualStripAnalog.hpp"


int main(int argc, char* argv[]) {
	std::vector<std::shared_ptr<VirtualStrip>> virtualStrips;
	
	if(argc < 2) {
		std::cout << "Usage: " << argv[0]
			<< " AnalogCount [DigitalStrip1] [DigitalStrip2] ..." << std::endl;

		return 1;
	}

	for(int i = 0; i < std::stoi(argv[1]); ++i) {
		virtualStrips.push_back(std::make_shared<VirtualStripAnalog>());
	}

	for(int i = 2; i < argc; ++i) {
		virtualStrips.push_back(std::make_shared<VirtualStripDigital>(std::stoi(argv[i])));
	}

	std::vector<std::shared_ptr<LightStrip>> lightStrips;
	for(auto strip : virtualStrips) {
		lightStrips.push_back(strip);
	}

	LightNode lightNode(lightStrips, "LightNode Simulator");

	while(true) {
		bool run = true;

		for(auto strip : virtualStrips) {
			run &= strip->windowUpdate();
		}

		if(!run)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}
