#include "LightNode/LightNode.hpp"

#include "VirtualStripMatrix.hpp"
#include "VirtualStripDigital.hpp"
#include "VirtualStripAnalog.hpp"


int main(int argc, char* argv[]) {
	std::vector<std::shared_ptr<VirtualStrip<>>> virtualStrips;
	std::vector<std::shared_ptr<VirtualStripMatrix>> virtualMatrices;
	
	if(argc < 4) {
		std::cout << "Usage: " << argv[0]
			<< " AnalogCount DigitalCount MatrixCount "
			"[DigitalCount1] [DigitalCount2] ... [MatrixWidth1 MatrixHeight1] ..." << std::endl;

		return 1;
	}

	uint8_t analogCount, digitalCount, matrixCount;

	analogCount = std::atoi(argv[1]);
	digitalCount = std::atoi(argv[2]);
	matrixCount = std::atoi(argv[3]);

	if(argc != (4 + digitalCount + 2*matrixCount)) {
		std::cout << "Error: Invalid parameters" << std::endl;

		return 1;
	}

	for(int i = 0; i < analogCount; ++i) {
		virtualStrips.push_back(std::make_shared<VirtualStripAnalog>());
	}

	for(int i = 0; i < digitalCount; ++i) {
		virtualStrips.push_back(std::make_shared<VirtualStripDigital>
			(std::stoi(argv[i+4])));
	}

	for(int i = 0; i < matrixCount; ++i) {
		int index = 4 + digitalCount + 2*i;

		virtualMatrices.push_back(std::make_shared<VirtualStripMatrix>
			(std::stoi(argv[index]), std::stoi(argv[index+1])));
	}

	std::vector<std::shared_ptr<LightStrip>> lightStrips;
	for(auto strip : virtualStrips) {
		lightStrips.push_back(strip);
	}
	for(auto strip : virtualMatrices) {
		lightStrips.push_back(strip);
	}

	LightNode lightNode(lightStrips, "LightNode-Simulator");

	while(true) {
		bool run = true;

		for(auto strip : virtualStrips) {
			run &= strip->windowUpdate();
		}
		for(auto strip : virtualMatrices) {
			run &= strip->windowUpdate();
		}

		if(!run)
			break;

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}
