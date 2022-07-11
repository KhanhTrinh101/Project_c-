#pragma once
#ifndef VALIUDATE_H_
#define VALIUDATE_H_

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

enum TYPE_SETTING
{
	TYPE_DISPLAY = 1,
	TYPE_SOUND,
	TYPE_GENERAL,
	TYPE_ALL,
};

// kiem tra ky tu nhap vao co phai la so khong
inline bool checkNumber(char s) {
	if (s >= '0' && s <= '9') {
		return true;
	}
	return false;
}

// valiudata nhap vao mot so
inline int inputNumbers(string str) { 
	bool flash = true;
	int numbers = 0;
	string line = "";

	do {
		cout << str;
		// nhap vao mot chuoi
		getline(cin, line);
		flash = true;
		// kiem tra chuoi nhap vao co rong khong
		if (line.size() > 0) {
			// kiem tra chuoi nhap vao chi co so duong
			for (unsigned int i = 0; i < line.size(); i++) {
				if (checkNumber(line[i]) == false) {
					cout << "===> please, only positive numbers are allowed!" << endl;
					flash = false;
					break;
				}
			}
		}
		else {
			flash = false;
		}
	} while (!flash);

	numbers = atoi(line.c_str());
	
	return numbers;
}

// tach chuoi
inline const vector<string> explode(const string & s, const char & c)
{
	string buff{ "" };
	vector<string> v;

	// duyet mang string
	for (auto n : s)
	{
		// neu khong bang c thi input vao buff
		if (n != c)
			buff += n;
		// neu bang c va buff khong rong thi push_back buff vao v
		else if (n == c && buff != "")
		{
			v.push_back(buff);
			buff = "";
		}
	}

	// sau c neu van con sot lai thi push_back vao v tiep
	if (buff != "")
		v.push_back(buff);

	return v;
}

// check email nhap vao theo mau abc@gmail.com
inline bool checkEmail(string str) {
	bool check = false;
	// tao mot regex theo mau abc@gmail.com
	regex re_mail("^[a-zA-Z][a-zA-Z0-9]{2,}@[a-zA-Z]{3,}\\.[a-zA-Z]{3,}$");
	// match regex voi chuoi da nhap
	// kiem tra xem co hop le khong
	if (regex_match(str, re_mail)) {
		check = true;
	}
	else {
		cout << "does not match, please re-enter!" << endl;
	}
	return check;
}

// valiudata nhap vao mot chuoi cac so la ma so ca nhan
inline string inputPersonalkey() {
	string str = "";
	bool flash = true;
	do {
		cout << "Input key number:   ";
		// nhap vao chuoi
		getline(cin, str);
		flash = true;

		// kiem tra xem chuoi nhap vao co du 8 so theo quy dinh khong
		if (str.size() == 8) {
			// kiem tra chuoi nhap vao chi co so duong
			for (unsigned int i = 0; i < str.size(); i++) {
				if (checkNumber(str[i]) == false) {
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

	return str;
}



#endif // VALIUDATE
