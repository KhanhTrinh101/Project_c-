#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "Carsetting.h"
#include "Common.h"
#include "BST.h"
#include "BST.cpp"
#include "valiuData.h"

using namespace std;

BST<CarSetting*> Listcar; // danh sach luu thong tin cac xe

vector<Common> timezoneList; // danh sach luu thong tin timezone
vector<Common> languageList; // danh sach luu thong tin languge

int countCnt = 0; // bien giam xac chi so cua xe hien tai

void NhapThongTinCaiDat();
void XuatThongTinCaiDat();

void NhapThongTinCaiDat_Sound();
void NhapThongTinCaiDat_General();
void NhapThongTinCaiDat_Display();

void XuatThongTinCaiDat_Sound();
void XuatThongTinCaiDat_General();
void XuatThongTinCaiDat_Display();
void XuatThongTinTatCaTinCaiDat();


void downloadLanguage(string namefile);
void downloadTimeZone(string namefile);


void menu();

int main(int argc, char** argv) {
	//Doc_File("Setting.txt");
	Listcar.ReadFile("Setting.txt");
	countCnt = Listcar.size();
	downloadTimeZone("timezones.txt");
	downloadLanguage("languages.txt");
	system("pause");
	menu();
	Listcar.writeFlile("Setting.txt");

	return 0;
}

/*
	ham Menu dung de show menu.
	goi toi cac ham nhap, xuat.
*/

void menu() {
	int selection = 0;
	// menu lua chon nhap, xuat thong tin
	system("cls");
	cout << "--- SELECT MENU ---" << endl;
	cout << "1. Input setting information" << endl;
	cout << "2. Print setting information" << endl;
	cout << "3. Exit" << endl;
	// nhap lua chon menu
	do {
		selection = inputNumbers("Your selection:	"); // dung ham inputNumbers nhap value cho bien selection.
		if (selection >= 1 && selection <= 3) {
			break;
		}
		else {
			cout << "Please enter only 1,2,3!" << endl;
		}
	} while (true);
	
	switch (selection)
	{
	// neu chon 1 thi thuc hien nhap thong tin cai dat
	case 1:
		system("cls");
		NhapThongTinCaiDat();
		break;
	// neu chon 2 thi thuc hien xuat thong tin cai dat
	case 2:
		system("cls");
		XuatThongTinCaiDat();
		break;
	// neu lua chon 3 thi thoat khoi chuong trinh
	case 3:
		cout << "Good Bye" << endl;
		break;
	}
}

/*
	ham Menu dung de show menu cai dat.
	goi toi cac ham nhap: display, sound, general.
*/
void NhapThongTinCaiDat() {
	
	// menu lua chon nhap: display, sound, general.
	system("cls");
	cout << "      --- SELECT MENU ---" << endl;
	cout << "1. Display Setting Information" << endl;
	cout << "2. Sound Setting Information" << endl;
	cout << "3. General Setting Information" << endl;
	cout << "4. Exit" << endl;
	// nhap lua chon menu
	int selection = 0;
	do {
		selection = inputNumbers("Your selection:	"); // dung ham inputNumbers nhap value cho bien selection.
		if (selection >= 1 && selection <= 4) {
			break;
		}
		else {
			cout << "Please enter only 1,2,3,4!" << endl;
		}
	} while (true);

	switch (selection)
	{
	// neu chon 1 thi thuc hien nhap thong tin cai dat cua display
	case 1:
		system("cls");
		NhapThongTinCaiDat_Display();
		break;
	// neu chon 2 thi thuc hien nhap thong tin cai dat cua sound
	case 2:
		system("cls");
		NhapThongTinCaiDat_Sound();
		break;
	// neu chon 3 thi thuc hien nhap thong tin cai dat cua general
	case 3:
		system("cls");
		NhapThongTinCaiDat_General();
		break;
	// neu chon 4 thi tro ve menu chinh
	case 4:
		menu();
	}
}

/* 
	ham NhapThongTinCaiDat_Sound dung de cai dat thong tin cho gia tri sound cua xe.
*/
void NhapThongTinCaiDat_Sound()
{
	string continues = "";

	do {
		system("cls");
		// khoi tao xe moi
		CarSetting* newcar = new CarSetting; 
		cout << " INPUT SOUND SETTING " << endl;
		cout << " Car index " << countCnt + 1 << endl;

		// nhap thong tin setting cho xe
		newcar->nhapThongTin();

		// nhap thong tin sound cho xe
		// kiem tra ma so ca nhan co trung khong?
		// neu trung thi ghi de len xe da ton tai trong danh sach
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newcar);

		if (newNode != NULL) {
			cout << "*** xe da ton tai, data se bi ghi de" << endl;
			newcar->getsound()->nhapThongTin();
			newNode->data = newcar;

		}
		else {
			cout << "*** xe moi" << endl;
			newcar->getsound()->nhapThongTin();
			Listcar.Insert(newcar);
			countCnt++;
		}
		// kiem tra xem nguoi dung co muon nhap tiep khong?
		do {
			cout << "Will you input for car " << countCnt + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "n") break;
		} while (true);

		cout << endl;
	} while (continues == "y");

	NhapThongTinCaiDat();
}

/*
	ham NhapThongTinCaiDat_General dung de cai dat thong tin cho gia tri General cua xe.
*/
void NhapThongTinCaiDat_General()
{
	string continues = "";

	do {
		system("cls");
		// khoi tao xe moi
		CarSetting* newcar = new CarSetting;
		cout << " INPUT GENERAL SETTING " << endl;
		cout << " Car index " << countCnt + 1 << endl;

		// nhap thong tin setting cho xe
		newcar->nhapThongTin();

		// nhap thong tin general cho xe
		// kiem tra ma so ca nhan co trung khong?		
		// neu trung thi ghi de len xe da ton tai trong danh sach
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newcar);

		if (newNode != NULL) {
			newcar->getgeneral()->nhapThongTin();
			newNode->data = newcar;
		}
		else {
			newcar->getgeneral()->nhapThongTin();
			Listcar.Insert(newcar);
			countCnt++;
		}

		// kiem tra xem nguoi dung co muon nhap tiep khong?
		do {
			cout << "Will you input for car " << countCnt + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "n") break;
		} while (true);

		cout << endl;
	} while (continues == "y");

	NhapThongTinCaiDat();
}

/*
	ham NhapThongTinCaiDat_Display dung de cai dat thong tin cho gia tri Display cua xe.
*/
void NhapThongTinCaiDat_Display()
{
	string continues = "";

	do {
		system("cls");
		// khoi tao xe moi
		cout << " INPUT DISPLAY SETTING " << endl;
		cout << " Car index " << countCnt + 1 << endl;
		CarSetting* newcar = new CarSetting();

		// nhap thong tin setting cho xe
		newcar->nhapThongTin();

		// nhap thong tin dislay cho xe
		// kiem tra ma so ca nhan co trung khong?		
		// neu trung thi ghi de len xe da ton tai trong danh sach
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newcar);

		if (newNode != NULL) {
			newcar->getdisplay()->nhapThongTin();
			newNode->data = newcar;

		}
		else {
			newcar->getdisplay()->nhapThongTin();
			Listcar.Insert(newcar);
			countCnt++;
		}

		// kiem tra xem nguoi dung co muon nhap tiep khong?
		do {
			cout << "Will you input for car " << countCnt + 1 << " ? (y/n): ";
			getline(cin, continues);
			if (continues == "y" || continues == "n") break;
		} while (true);

		cout << endl;
	} while (continues == "y");

	NhapThongTinCaiDat();
}
/*
	ham XuatThongTinCaiDat dung de show thong tin co trong list car
*/
void XuatThongTinCaiDat() {
	
	// ham lua chon xuat thong tin: display, sound, general;
	system("cls");
	cout << "      --- SELECT MENU ---" << endl;
	cout << "1. Print Display Setting Information" << endl;
	cout << "2. Print Sound Setting Information" << endl;
	cout << "3. Print General Setting Information" << endl;
	cout << "4. Print All Setting Information" << endl;
	cout << "5. Exit" << endl;
	// nhap lua chon menu
	int selection = 0;
	do {
		selection = inputNumbers("Your selection:	"); // nhap value cho selection
		if (selection >= 1 && selection <= 5) {
			break;
		}
		else {
			cout << "Please enter only 1,2,3,4,5!" << endl;
		}
	} while (true);

	switch (selection)
	{
	// neu lua chon 1 thi xuat thong tin display
	case 1:
		system("cls");
		XuatThongTinCaiDat_Display();
		break;
	// neu lua chon 2 thi xuat thong tin sound
	case 2:
		system("cls");
		XuatThongTinCaiDat_Sound();
		break;
	// neu lua chon 3 thi xuat thong tin general
	case 3:
		system("cls");
		XuatThongTinCaiDat_General();
		break;
	// neu lua chon 4 thi xuat tat ca thong tin
	case 4:
		system("cls");
		XuatThongTinTatCaTinCaiDat();
		break;
	// neu lua chon 5 thi tro ve menu chinh
	case 5:
		menu();
	}
}

/*
	ham dung de xuat thong tin cua sound trong list car.
*/
void XuatThongTinCaiDat_Sound() {
	// kiem tra nguoi dung co muon tim kiem theo ma so ca nhan khong?
	// neu co thi xuat phan tu car trong list co ma so ca nhan do.
	string continues = "";
	do {
		cout << "Ban Co Muon Tim Kiem Theo Personalkey Khong" << " ? (y/n): ";
		getline(cin, continues);
		if (continues == "y" || continues == "n") break;
	} while (true);

	if (continues == "y") {
		// nhap personalkey muon tim
		string personalkey = inputPersonalkey(); 
		// tao xe moi
		CarSetting *newCar = new CarSetting(); 
		// khoi tao gia tri personalkey cho xe
		newCar->setPersonalKey(personalkey); 

		// tim personalkey trong list
		// neu co thi xuat thong tin sound cua xe do ra. neu khong thi in ra khong tim thay.		
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newCar);
		if (newNode != NULL) {
			system("cls");
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
			newNode->data->xuatThongTin();
			newNode->data->getsound()->xuatThongTin();
			cout << endl;

		}
		else {
			system("cls");
			cout << "==============================" << endl;
			cout << "\tNot Found!" << endl;
			cout << "==============================" << endl;
		}
		system("pause");
	}
	else {
		system("cls");
		cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
			<< setw(10) << "Sevices" << setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify" << endl;
		Listcar.preOrder(TYPE_SOUND);
		system("pause");
	}


	XuatThongTinCaiDat();
}

/*
	ham XuatThongTinCaiDat_General dung de xuat thong tin cua General trong list car.
*/
void XuatThongTinCaiDat_General() {
	// kiem tra nguoi dung co muon tim kiem theo ma so ca nhan khong?
	// neu co thi xuat phan tu car trong list co ma so ca nhan do.
	string continues = "";
	do {
		cout << "Ban Co Muon Tim Kiem Theo Personalkey Khong" << " ? (y/n): ";
		getline(cin, continues);
		if (continues == "y" || continues == "n") break;
	} while (true);

	if (continues == "y") {
		// nhap personalkey muon tim
		string personalkey = inputPersonalkey();
		// tao xe moi
		CarSetting* newCar = new CarSetting();
		// khoi tao gia tri personalkey cho xe
		newCar->setPersonalKey(personalkey);

		// tim personalkey trong list
		// neu co thi xuat thong tin general cua xe do ra. neu khong thi in ra khong tim thay.
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newCar);
		if (newNode != NULL) {
			system("cls");
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(20) << "TimeZone" << setw(20) << "Language" << endl;
			newNode->data->xuatThongTin();
			newNode->data->getgeneral()->xuatThongTin();
			cout << endl;
		}
		else {
			system("cls");
			cout << "==============================" << endl;
			cout << "\tNot Found!" << endl;
			cout << "==============================" << endl;

		}
		system("pause");
	}
	else {
		system("cls");
		cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
			<< setw(10) << "Sevices" << setw(20) << "TimeZone" << setw(20) << "Language" << endl;
		Listcar.preOrder(TYPE_GENERAL);
		system("pause");
	}
	XuatThongTinCaiDat();
}

/*
	ham XuatThongTinCaiDat_Display dung de xuat thong tin cua Display trong list car.
*/
void XuatThongTinCaiDat_Display() {
	// kiem tra nguoi dung co muon tim kiem theo ma so ca nhan khong?
	// neu co thi xuat phan tu car trong list co ma so ca nhan do.
	string continues = "";
	do {
		cout << "Ban Co Muon Tim Kiem Theo Personalkey Khong" << " ? (y/n): ";
		getline(cin, continues);
		if (continues == "y" || continues == "n") break;
	} while (true);

	if (continues == "y") {
		// nhap personalkey muon tim
		string personalkey = inputPersonalkey();
		// tao xe moi
		CarSetting* newCar = new CarSetting();
		// khoi tao gia tri personalkey cho xe
		newCar->setPersonalKey(personalkey);

		// tim personalkey trong list
		// neu co thi xuat thong tin display cua xe do ra. neu khong thi in ra khong tim thay.
		NODE<CarSetting*> *newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newCar);
		if (newNode != NULL) {
			system("cls");
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
				<< setw(10) << "Sevices" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
			newNode->data->xuatThongTin();
			newNode->data->getdisplay()->xuatThongTin();
			cout << endl;
		}
		else {
			system("cls");
			cout << "==============================" << endl;
			cout << "\tNot Found!" << endl;
			cout << "==============================" << endl;
		}
		system("pause");
	}
	else {
		system("cls");
		cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC" << setw(10) << "ODO"
			<< setw(10) << "Sevices" << setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen" << endl;
		Listcar.preOrder(TYPE_DISPLAY);
		system("pause");
	}
	XuatThongTinCaiDat();
}

/*
	ham XuatThongTinTatCaTinCaiDat dung de xuat tat ca thong tin cua Display, sound, general trong list car.
*/
void XuatThongTinTatCaTinCaiDat() {
	// kiem tra nguoi dung co muon tim kiem theo ma so ca nhan hay theo ten chu xe.
	// neu co thi xuat phan tu car trong list.
	int selection = 0;
	cout << "1. Tim Kiem Theo Ma So Ca Nhan." << endl;
	cout << "2. Tim Kiem Theo Ten Chu Xe." << endl;
	do {
		selection = inputNumbers("Your selection:	");
		if (selection >= 1 && selection <= 2) {
			break;
		}
		else {
			cout << "Please enter only 1,2!" << endl;
		}
	} while (true);

	// neu lua chon 1 thi xuat phan tu car trong list theo ma so ca nhan ma nguoi dung nhap.
	if (selection == 1) {
		// nhap personalkey muon tim
		string personalkey = inputPersonalkey();
		// tao xe moi
		CarSetting* newCar = new CarSetting();
		// khoi tao gia tri personalkey cho xe
		newCar->setPersonalKey(personalkey);

		// tim personalkey trong list
		// neu co thi xuat tat ca thong tin cua xe do ra. neu khong thi in ra khong tim thay.
		NODE<CarSetting*>* newNode(0);
		newNode = Listcar.SearchPerSonnalKey(newCar);
		if (newNode != NULL) {
			system("cls");
			cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC"
				<< setw(10) << "ODO" << setw(10) << "Sevices"
				<< setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
				<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi" << setw(10) << "Notify"
				<< setw(15) << "TimeZone" << setw(20) << "Language" << endl;
			newNode->data->xuatThongTin();
			newNode->data->getdisplay()->xuatThongTin();
			newNode->data->getsound()->xuatThongTin();
			newNode->data->getgeneral()->xuatThongTin();
			cout << endl;
		}
		else {
			system("cls");
			cout << "==============================" << endl;
			cout << "\tNot Found!" << endl;
			cout << "==============================" << endl;
		}
		system("pause");
	}
	// neu lua chon 2 thi xuat phan tu car trong list theo ten chu xe ma nguoi dung nhap.
	else if (selection == 2) {
		// nhap ten chu xe muon tim.
		string name;
		do {
			cout << "Input Oner Name:   ";
			getline(cin, name);
			if (name.size() > 0) {
				break;
			}
			else {
				cout << "Please, re-enter name!" << endl;
			}
		} while (true);
		// xuat thong tin theo ten chu xe.
		system("cls");
		cout << setw(20) << "Owner Name" << setw(25) << "Email" << setw(10) << "MSC"
			<< setw(10) << "ODO" << setw(10) << "Sevices"
			<< setw(10) << "Light" << setw(10) << "Taplo" << setw(10) << "Screen"
			<< setw(10) << "Media" << setw(10) << "Call" << setw(10) << "Navi"<< setw(10) << "Notify"
			<< setw(15) << "TimeZone" << setw(20) << "Language" << endl;
		Listcar.ShowName(name);
		system("pause");
	}
	XuatThongTinCaiDat();
}

/*
	ham downloadTimeZone dung de download cac thong tin tu file timezone.txt
	sang danh sach timezone.
*/
void downloadTimeZone(string namefile)
{
	ifstream readfile;
	string line;
	vector<int> timezone;
	vector<string> NameArea;

	try {
		readfile.open(namefile.c_str());
		if (readfile.fail()) {
			throw 1;
		}
		else {
			while (getline(readfile, line)) {
				vector<string> newvec = explode(line, '/'); // tach cac chuoi cach nhau boi dau '/'
				if (newvec.size() == 2) {
					// lay so gio sau GMT.
					size_t pos = newvec[0].find("T");
					string str = newvec[0].substr(pos + 1, pos + 3);
					int number = atoi(str.c_str());
					// add vao danh sach so gio
					timezone.push_back(number);
					// add vao danh sach ten khu vuc
					NameArea.push_back(newvec[1]);
				}
			}
			// sap xep so gio tang dan
			// su dung thuat toan sap xep bubble sort
			for (unsigned int i = 0; i < timezone.size() - 1; i++) {
				for (unsigned int j = 0; j < timezone.size() - 1 - i; j++) {
					if (timezone[j] > timezone[j + 1]) {
						swap(timezone[j], timezone[j + 1]);
						swap(NameArea[j], NameArea[j + 1]);
					}
				}
			}
			// add vao danh sach timezoneList
			for (unsigned int i = 0; i < timezone.size(); i++) {
				Common info;
				info.setName(NameArea[i]);
				info.setNumber("(GMT " + to_string(timezone[i]) + ":00)");
				timezoneList.push_back(info);
			}
			// show thong tin timezoneList
			for (unsigned int i = 0; i < timezoneList.size(); i++) {
				cout << i + 1 << ". ";
				cout << timezoneList[i].getNumber() << " / " << timezoneList[i].getName() << endl;
			}
		}
	}
	catch (int e) {
		cout << "Error opening file " << namefile << endl;
		if (e == 1) {
			Common info;
			info.setNumber("(GMT+07:00)");
			for (int i = 0; i < 99; i++) {
				timezoneList.push_back(info);
			}
		}
		system("pause");
	}
	readfile.close();
}

/*
	ham downloadLanguage dung de download cac thong tin tu file Language.txt
	sang danh sach Language.
*/
void downloadLanguage(string namefile)
{
	ifstream writefile;
	string line;
	vector<string> languge;
	vector<string> number;

	try {
		writefile.open(namefile.c_str());
		if (writefile.fail()) {
			throw 1;
		}
		else {
			while (getline(writefile, line)) {
				// khoi tao danh sach cac chuoi cach nhau boi dau '/'
				vector<string> newvec = explode(line, '/');
				if (newvec.size() == 2) {
					languge.push_back(newvec[1]);
					number.push_back(newvec[0]);
				}
			}
			// sap xep languge theo anphabet
			sort(languge.begin(), languge.end());
			// add vao danh sach languageList
			for (unsigned int i = 0; i < languge.size(); i++) {
				Common info;
				info.setName(languge[i]);
				info.setNumber(number[i]);
				languageList.push_back(info);
			}
			// show thong tin languageList
			for (unsigned int i = 0; i < languageList.size(); i++) {
				cout << languageList[i].getNumber() << " / " << languageList[i].getName() << endl;
			}
		}
	}
	catch (int e) {
		cout << "Error opening file " << namefile << endl;
		if (e == 1) {
			Common info;
			info.setName("Vietnamese");
			for (int i = 0; i < 99; i++) {
				languageList.push_back(info);
			}
		}
		system("pause");
	}

	writefile.close();
}
