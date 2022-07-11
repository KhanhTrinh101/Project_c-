#include "Setting.h"

Setting::Setting()
{
	car_name = "";
	personal_key = "";
	email = "";
	odo = 0;
	service_remind = 0;
}

Setting::~Setting() {}

string Setting::getCarName() {
	return car_name;
}

string Setting::getPersonalKey() {
	return personal_key;
}

string Setting::getEmail() {
	return email;
}

int Setting::getODO() {
	return odo;
}

int Setting::getServiceRemind() {
	return service_remind;
}

void Setting::setCarName(string data)
{
	car_name = data;
}

void Setting::setPersonalKey(string data)
{
	personal_key = data;
}

void Setting::setEmail(string data)
{
	email = data;
}

void Setting::setODO(int data)
{
	odo = data;
}

void Setting::setServiceRemind(int data)
{
	service_remind = data;
}

void Setting::nhapThongTin() {
	while (car_name == "") {
		cout << "Input Owner Name:   ";
		getline(cin, car_name);
	}

	do {
		cout << "Input Email:   ";
		getline(cin, email);
	} while (checkEmail(email) == false);

	bool flash = true;
	do {
		cout << "Input key number:   ";
		getline(cin, personal_key);
		flash = true;

		if (personal_key.size() == 8) {
			for (unsigned int i = 0; i < personal_key.size(); i++) {
				if (checkNumber(personal_key[i]) == false) {
					cout << "===> please, only positive numbers are allowed!" << endl;
					flash = false;
					break;
				}
			}
		}
		else {			
			flash = false;
			cout << "Please enter all 8 numbers!" << endl;
		}
	} while (flash == false);
	
	odo = inputNumbers("Input Information ODO Number:   ");
	service_remind = inputNumbers("Input Information Remind Service (km):   ");
}

void Setting::xuatThongTin() {
	cout << setw(20) << car_name
		<< setw(25) << email
		<< setw(10) << personal_key
		<< setw(10) << odo
		<< setw(10) << service_remind;
}