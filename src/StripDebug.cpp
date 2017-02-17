#include "StripDebug.hpp"

#include <iostream>

using namespace std;

StripDebug::StripDebug(size_t _ledCount, DebugLevel _debugLevel)
	: LightStrip(_ledCount)
	,	debugLevel(_debugLevel) {
	
	if(debugLevel == DebugLevel::FULL) {
		cout << "[Info] StripDebug::StripDebug" << endl;
	}
}

void StripDebug::update() {
	if(debugLevel != DebugLevel::NONE) {
		cout << "[Info] StripDebug::update() called" << endl;
	}
	
	if(debugLevel == DebugLevel::FULL) {
		cout << "---LED Colors---";
		for(auto& led : leds) {
			cout << "\n" << led.toString();
		}

		cout << endl;
	}
}
