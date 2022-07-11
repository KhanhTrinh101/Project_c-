#pragma once
#ifndef SETTING_H_
#define SETTING_H_

#include <iostream>
#include <string>
#include <regex>
#include <iomanip>
#include "valiuData.h"

using namespace std;

class Setting
{
public:
	Setting();
	virtual ~Setting();
	void nhapThongTin();
	void xuatThongTin();
	string getCarName();
	string getPersonalKey();
	string getEmail();
	int getODO();
	int getServiceRemind();
	void setCarName(string);
	void setPersonalKey(string);
	void setEmail(string);
	void setODO(int);
	void setServiceRemind(int);
private:
	string car_name;
	string personal_key; 
	string email;			
	int odo;
	int service_remind;
};

#endif