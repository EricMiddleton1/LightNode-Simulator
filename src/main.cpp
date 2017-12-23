#include <iostream>
#include <vector>
#include <memory>
#include <string>

#include "LightNode/LightNode.hpp"

#include "VirtualLight.hpp"
#include "VirtualMatrix.hpp"

using namespace std;

int main(int argc, char* argv[]) {
	vector<std::shared_ptr<Light>> lights;
	boost::asio::io_service ioService;
	boost::asio::io_service::work ioWork{ioService};
	
	if(argc < 4) {
		cout << "Usage: " << argv[0]
			<< " AnalogCount DigitalCount MatrixCount "
			"[DigitalCount1] [DigitalCount2] ... [MatrixWidth1 MatrixHeight1] ..." << endl;

		return 1;
	}

	uint8_t analogCount, digitalCount, matrixCount;

	analogCount = atoi(argv[1]);
	digitalCount = atoi(argv[2]);
	matrixCount = atoi(argv[3]);

	if(argc != (4 + digitalCount + 2*matrixCount)) {
		cout << "Error: Invalid parameters" << endl;

		return 1;
	}

	for(int i = 0; i < analogCount; ++i) {
		lights.push_back(make_shared<VirtualLight>(ioService, string("Analog ") +
			to_string(i+1), 1));
	}

	for(int i = 0; i < digitalCount; ++i) {
		lights.push_back(make_shared<VirtualLight>(ioService,
			string("Digital ") + to_string(i+1), stoi(argv[i+4])));
	}

	for(int i = 0; i < matrixCount; ++i) {
		int index = 4 + digitalCount + 2*i;

		uint8_t width = stoi(argv[index]), height = stoi(argv[index+1]);

		lights.push_back(std::make_shared<VirtualMatrix>
			(ioService, string("Matrix ") + to_string(i+1), width, height));
	}

	LightNode lightNode(lights, "LightNode-Simulator");

	std::thread lightThread{[&ioService]() {
		ioService.run();
		std::cout << "[Info] ioService thread closing" << std::endl;
	}};

	while(true) {
		bool run = true;

		for(auto light : lights) {
			auto window = dynamic_pointer_cast<VirtualLight>(light);
			if(window) {
				run &= window->windowUpdate();
			}
			else {
				run &= dynamic_pointer_cast<VirtualMatrix>(light)->windowUpdate();
			}
		}

		if(!run)
			break;

		this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return 0;
}
