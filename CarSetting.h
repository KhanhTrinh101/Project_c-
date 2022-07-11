#pragma once
#ifndef CARSETTING_H_
#define CARSETTING_H_

#include <iostream>
#include "Display.h"
#include "General.h"
#include "Sound.h"
#include "Setting.h"

class CarSetting : public Setting
{
public:
	CarSetting();
	virtual ~CarSetting();
	Display* getdisplay();
	Sound* getsound();
	General* getgeneral();
private:
	Display* display;
	Sound* sound;
	General* general;
};

#endif
