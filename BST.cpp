#include "BST.h"
template <class T>
NODE<T>::NODE(T value)
{
	data = value;
	left = NULL;
	right = NULL;
}

template <class T>
void BST<T>::Insert(T value, NODE<T> * node)
{
	if (value < node->data) {
		if (node->left != NULL) {
			Insert(value, node->left);
		}
		else {
			node->left = new NODE<T>(value);
			node->left->left = NULL;
			node->left->right = NULL;
		}
	}
	else if(value >= node->data){
		if (node->right != NULL) {
			Insert(value, node->right);
		}
		else {
			node->right = new NODE<T>(value);
			node->right->left = NULL;
			node->right->right = NULL;
		}
	}
}

template<class T>
NODE<T>* BST<T>::SearchPerSonnalKey(T value, NODE<T>* node)
{
	if (node != NULL) {
		if (value->Setting::getPersonalKey() == node->data->Setting::getPersonalKey()) {
			return node;
		}
		else if (value < node->data) {
			return SearchPerSonnalKey(value, node->left);
		}
		else {
			return SearchPerSonnalKey(value, node->right);
		}
	}
	else {
		return NULL;
	}
}

// dang su dung
template <class T>
void BST<T>::preOrder(NODE<T> * node, int type)
{
	if (node != NULL) {
		switch (type)
		{
			// display_type
		case 1: {
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
			  // sound_type
		case 2: {
			node->data->Setting::xuatThongTin();
			node->data->getsound()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
			  // general_type
		case 3: {
			node->data->Setting::xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
				// all_Info_type
		default:
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			node->data->getsound()->xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
	}
}

template<class T>
void BST<T>::ShowName(string name, NODE<T>* node)
{
	if (node != NULL) {
		if (name == node->data->Setting::getCarName()) {
			
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			node->data->getsound()->xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			
		}
		ShowName(name, node->left);
		ShowName(name, node->right);
	}
}



template<class T>
BST<T>::BST()
{
	root = NULL;
}

template <class T>
void BST<T>::Insert(T value)
{
	if (root != NULL) {
		Insert(value, root);
	}
	else {
		root = new NODE<T>(value);
		root->left = NULL;
		root->right = NULL;
	}
}

template<class T>
NODE<T>* BST<T>::SearchPerSonnalKey(T value)
{
	return SearchPerSonnalKey(value, root);
}

template <class T>
void BST<T>::preOrder(int type)
{
	preOrder(root, type);
}

template<class T>
void BST<T>::ShowName(string name)
{
	ShowName(name, root);
}

template<class T>
int BST<T>::size(NODE<T>* node)
{
	if (node != NULL) {
		return (1 + size(node->left) + size(node->right));
	}
	else {
		return 0;
	}
}

template<class T>
stringstream BST<T>::getAllData(NODE<T>* node)
{
	stringstream sstr;
	if (node != NULL) {
		
		// ghi thong tin common
		sstr << "Common: ";
		sstr << ",";
		sstr << node->data->getCarName();
		sstr << ",";
		sstr << node->data->getEmail();
		sstr << ",";
		sstr << node->data->getPersonalKey();
		sstr << ",";
		sstr << node->data->getODO();
		sstr << ",";
		sstr << node->data->getServiceRemind();
		sstr << "/";

		// ghi thong tin display setting
		sstr << "Display: ";
		sstr << ",";
		sstr << node->data->getdisplay()->get_light_level();
		sstr << ",";
		sstr << node->data->getdisplay()->get_screen_light_level();
		sstr << ",";
		sstr << node->data->getdisplay()->get_taplo_light_level();
		sstr << "/";

		// ghi thong tin sound setting
		sstr << "Sound: ";
		sstr << ",";
		sstr << node->data->getsound()->get_call_level();
		sstr << ",";
		sstr << node->data->getsound()->get_media_level();
		sstr << ",";
		sstr << node->data->getsound()->get_navi_level();
		sstr << ",";
		sstr << node->data->getsound()->get_notification_level();
		sstr << "/";

		// ghi thong tin general setting
		sstr << "General: ";
		sstr << ",";
		sstr << node->data->getgeneral()->get_language();
		sstr << ",";
		sstr << node->data->getgeneral()->get_timeZone();
		sstr << "\n";

		sstr << getAllData(node->left).str();
		sstr << getAllData(node->right).str();
	}
	return sstr;
}

//============================Begin===============================//
template<class T>
void BST<T>::writeFlile(string nameFile)
{
		// goi doi tuong ghi file
		ofstream file;
		// setup exceptione
		//file.exceptions(ifstream::badbit | ifstream::failbit);
		file.exceptions(std::ifstream::failbit | std::ifstream::badbit);
		// try catch()
		try {
			file.open(nameFile.c_str(), ios_base::out);
			// lay tat ca data trong cay luu vao trong string stream
			stringstream sstr = getAllData(root);
			// doc string stream vao file
			file << sstr.str();
		}
		catch (ifstream::failure& ex) {
			cout << ex.what() << endl;
			cout << "somthing went wrong!!" << endl;
		}

		file.close();
	
}
template<class T>

void BST<T>::ReadFile(string nameFile)
{
		ifstream file;
		string line;

		try {
			file.open(nameFile.c_str());
			if (file.fail()) {
				throw 1;
			}
			else {
				while (getline(file, line)) {
					// khoi tao xe moi theo cac gia tri doc duoc trong file 
					CarSetting* newCar = new CarSetting;
					// tao danh sach cac chuoi cach nhau boi dau '/'
					vector<string> data1;
					// tao danh sach cac chuoi cach nhau boi dau ','
					vector<string> data2;

					// tach cac chuoi duoc cach nhau boi dau '/'
					data1 = explode(line, '/');
					// tach cac chuoi duoc cach nhau boi dau ','
					data2 = explode(data1[0], ',');

					// khoi tao cac gia tri cua setting
					newCar->setCarName(data2[1]);
					newCar->setEmail(data2[2]);
					newCar->setPersonalKey(data2[3]);

					int ODO = atoi(data2[4].c_str());
					int ServiceRemind = atoi(data2[5].c_str());
					newCar->setODO(ODO);
					newCar->setServiceRemind(ServiceRemind);

					// khoi tao cac gia tri cua display setting
					data2 = explode(data1[1], ',');
					int light_level = atoi(data2[1].c_str());
					int screen_light_level = atoi(data2[2].c_str());
					int taplo_light_level = atoi(data2[3].c_str());
					newCar->getdisplay()->set_light_level(light_level);
					newCar->getdisplay()->set_screen_light_level(screen_light_level);
					newCar->getdisplay()->set_taplo_light_level(taplo_light_level);

					// khoi tao cac gia tri cua sound setting
					data2 = explode(data1[2], ',');
					int call_level = atoi(data2[1].c_str());
					int media_level = atoi(data2[2].c_str());
					int navi_level = atoi(data2[3].c_str());
					int notification_level = atoi(data2[4].c_str());
					newCar->getsound()->set_call_level(call_level);
					newCar->getsound()->set_media_level(media_level);
					newCar->getsound()->set_navi_level(navi_level);
					newCar->getsound()->set_notification_level(notification_level);

					// khoi tao cac gia tri cua general setting
					data2 = explode(data1[3], ',');
					newCar->getgeneral()->set_language(data2[1]);
					newCar->getgeneral()->set_timeZone(data2[2]);

					// them phan tu moi vao danh sach
					Insert(newCar);
				}
			}
			file.close();
		}
		catch (int e) {
			if (e == 1) {
				cout << "Error opening writeFile " << nameFile << endl;
				system("pause");
			}
		}
	
}

//=========================== end =============================//
template<class T>
int BST<T>::size()
{
	return size(root);
}

