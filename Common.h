#pragma once
#ifndef COMMON_H_
#define COMMON_H_

#include <iostream>
#include <string>

using namespace std;

class Common
{
public:
	string getNumber() {
		return number;
	}

	string getName() {
		return name;
	}

	void setNumber(string data) {
		number = data;
	}

	void setName(string data) {
		name = data;
	}
private:
	string number;
	string name;
};

#endif