#include "Display.h"

Display::Display()
{
	this->light_level = 0;
	this->screen_light_level = 0;
	this->taplo_light_level = 0;
}

Display::~Display() {}

int Display::get_light_level() {
	return light_level;
}

int Display::get_screen_light_level() {
	return screen_light_level;
}

int Display::get_taplo_light_level() {
	return taplo_light_level;
}

void Display::set_light_level(int data) {
	light_level = data;
}

void Display::set_screen_light_level(int data) {
	screen_light_level = data;
}

void Display::set_taplo_light_level(int data) {
	taplo_light_level = data;
}

void Display::xuatThongTin() {
	cout << setw(10) << light_level
		<< setw(10) << taplo_light_level
		<< setw(10) << screen_light_level;
}

bool Display::checkNumber(char s) {
	if (s >= '0' && s <= '9') {
		return true;
	}
	return false;
}

void Display::nhapThongTin() {
	light_level = inputNumbers("Input Information Light Level:   ");
	screen_light_level = inputNumbers("Input Information Screen Light Level:   ");
	taplo_light_level = inputNumbers("Input Information Taplo Light Leve:   ");
}