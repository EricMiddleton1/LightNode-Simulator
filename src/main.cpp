#include "LightNode/LightNode.hpp"
#include "StripVisual.hpp"

#define LED_COUNT		(32)

using namespace std;

#define WINDOW_WIDTH	800
#define WINDOW_HEIGHT	600

int main(int argc, char* argv[]) {
	int ledCount = LED_COUNT;

	if(argc == 2) {
		ledCount = stoi(argv[1]);

		cout << "[Info] LED count " << ledCount << endl;
	}
	else {
		cout << "[Info] Using default LED count " << ledCount << endl;
	}

	auto strip = make_shared<StripVisual>(ledCount, WINDOW_WIDTH, WINDOW_HEIGHT);

	LightNode lightNode(Communicator::NodeType::DIGITAL, strip);

	while(strip->windowUpdate()) {
		this_thread::sleep_for(chrono::milliseconds(1));
	}

	return 0;
}
