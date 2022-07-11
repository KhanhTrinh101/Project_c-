#pragma once
#ifndef GENERAL_H_
#define GENERAL_H_

#include "Common.h"
#include <iostream>
#include <string>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class General
{
public:
	General();
	virtual ~General();
	void xuatThongTin();
	void nhapThongTin();
	string get_language();
	string get_timeZone();
	void set_timeZone(string);
	void set_language(string);
private:
	string timeZone;
	string language;
};

#endif