#include "Sound.h"

Sound::Sound() {
	media_level = 0;
	call_level = 0;
	navi_level = 0;
	notification_level = 0;
}

Sound::~Sound() {}

int Sound::get_media_level() {
	return media_level;
}

int Sound::get_call_level() {
	return call_level;
}

int Sound::get_navi_level() {
	return navi_level;
}

int Sound::get_notification_level() {
	return notification_level;
}

void Sound::set_media_level(int data) {
	media_level = data;
}

void Sound::set_call_level(int data) {
	call_level = data;
}

void Sound::set_navi_level(int data) {
	navi_level = data;
}

void Sound::set_notification_level(int data) {
	notification_level = data;
}


void Sound::nhapThongTin() {	
	media_level = inputNumbers("Input Information Media Level:   ");	
	call_level = inputNumbers("Input Information Call Level:   ");	
	navi_level = inputNumbers("Input Information Navi Level:   ");	
	notification_level = inputNumbers("Input Information Notification Level:   ");
}

void Sound::xuatThongTin() {
	cout << setw(10) << media_level;
	cout << setw(10) << call_level;
	cout << setw(10) << navi_level;
	cout << setw(10) << notification_level;
}
