#pragma once
#ifndef SOUND_H_
#define SOUND_H_

#include <iostream>
#include <string>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class Sound
{
public:
	Sound();
	virtual ~Sound();
	void nhapThongTin();
	void xuatThongTin();
	int get_media_level();
	int get_call_level();
	int get_navi_level();
	int get_notification_level();
	void set_media_level(int);
	void set_call_level(int);
	void set_navi_level(int);
	void set_notification_level(int);

private:
	int media_level;
	int call_level;
	int navi_level;
	int notification_level;
};

#endif
