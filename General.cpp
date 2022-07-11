#include "General.h"

extern vector<Common> timezoneList;
extern vector<Common> languageList;

General::General()
{
	timeZone = "(GMT+07:00)";
	language = "Vietnamese";
}

General::~General() {}

string General::get_language() {
	return language;
}

string General::get_timeZone() {
	return timeZone;
}

void General::set_timeZone(string data) {
	timeZone = data;
}

void General::set_language(string data) {
	language = data;
}



void General::xuatThongTin() {
	cout << setw(20) << timeZone
		<< setw(20) << language;
}

void General::nhapThongTin()
{
	string line;
	int selection = 0;
	

	for (unsigned int i = 0; i < timezoneList.size(); i++) {
		cout << i + 1 << ". ";
		cout << timezoneList[i].getNumber() << " / " << timezoneList[i].getName() << endl;
	}

	do {
		selection = inputNumbers("Your selection:   ");
	} while (selection < 1 || selection > 32);

	timeZone = timezoneList[selection - 1].getNumber();

	selection = 0;

	for (unsigned int i = 0; i < languageList.size(); i++) {
		cout << languageList[i].getNumber() << " / " << languageList[i].getName() << endl;
	}

	do {
		selection = inputNumbers("Your selection:   ");
	} while (selection < 1 || selection > 30);

	language = languageList[selection - 1].getName();
}









