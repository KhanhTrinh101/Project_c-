#include "CarSetting.h"

CarSetting::CarSetting()
{
	display = new Display();
	sound = new Sound();
	general = new General();
}

CarSetting::~CarSetting() {
	if (display != nullptr) {
		delete display;
	}
	if (sound != nullptr) {
		delete sound;
	}
	if (general != nullptr) {
		delete general;
	}
}

Display* CarSetting::getdisplay()
{
	return display;
}

Sound* CarSetting::getsound()
{
	return sound;
}

General* CarSetting::getgeneral()
{
	return general;
}