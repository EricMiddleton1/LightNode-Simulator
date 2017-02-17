#include "LightNode/LightNode.hpp"
#include "StripDebug.hpp"

#define LED_COUNT		(32)

using namespace std;

int main(int argc, char* argv[]) {
	int ledCount = LED_COUNT;

	if(argc == 2) {
		ledCount = stoi(argv[1]);

		cout << "[Info] LED count " << ledCount << endl;
	}
	else {
		cout << "[Info] Using default LED count " << ledCount << endl;
	}

	LightNode lightNode(Communicator::NodeType::DIGITAL,
		make_shared<StripDebug>(ledCount, StripDebug::DebugLevel::FULL));

	while(1) {
		this_thread::sleep_for(chrono::seconds(1000));
	}

	return 0;
}
