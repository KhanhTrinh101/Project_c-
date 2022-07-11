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

template <class T>
void BST<T>::preOrder(NODE<T> * node, int type)
{
	if (node != NULL) {
		switch (type)
		{
		case 1: {
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
		case 2: {
			node->data->Setting::xuatThongTin();
			node->data->getsound()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
		case 3: {
			node->data->Setting::xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			preOrder(node->left, type);
			preOrder(node->right, type);
			break;
		}
				
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

template <class T>
void BST<T>::inOrder(NODE<T> * node, int type)
{
	if (node != NULL) {
		switch (type)
		{
		case 1: {
			inOrder(node->left, type);
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			cout << endl;
			preOrder(node->right, type);
			break;
		}
		case 2: {
			inOrder(node->left, type);
			node->data->Setting::xuatThongTin();
			node->data->getsound()->xuatThongTin();
			cout << endl;
			preOrder(node->right, type);
			break;
		}
		case 3: {
			inOrder(node->left, type);
			node->data->Setting::xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			preOrder(node->right, type);
			break;
		}
		default:
			inOrder(node->left, type);
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			node->data->getsound()->xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;
			preOrder(node->right, type);
			break;
		}
	}
}

template <class T>
void BST<T>::postOrder(NODE<T> * node, int type)
{
	if (node != NULL) {
		switch (type)
		{
		case 1: {
			postOrder(node->left, type);
			postOrder(node->right, type);
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			cout << endl;
			break;
		}
		case 2: {
			postOrder(node->left, type);
			postOrder(node->right, type);
			node->data->Setting::xuatThongTin();
			node->data->getsound()->xuatThongTin();
			cout << endl;

			break;
		}
		case 3: {
			postOrder(node->left, type);
			postOrder(node->right, type);
			node->data->Setting::xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;

			break;
		}

		default:
			postOrder(node->left, type);
			postOrder(node->right, type);
			node->data->Setting::xuatThongTin();
			node->data->getdisplay()->xuatThongTin();
			node->data->getsound()->xuatThongTin();
			node->data->getgeneral()->xuatThongTin();
			cout << endl;

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

template <class T>
void BST<T>::inOrder(int type)
{
	inOrder(root, type);
}

template <class T>
void BST<T>::postOrder(int type)
{
	postOrder(root, type);
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
int BST<T>::size()
{
	return size(root);
}

template<class T>
vector<T> BST<T>::convertToVector(vector<T> listcar, NODE<T>* node)
{
	if (node != NULL) {
		listcar.push_back(node->data);
		listcar = convertToVector(listcar, node->left);
		listcar = convertToVector(listcar, node->right);
	}
	return listcar;
}

template<class T>
vector<T> BST<T>::convertToVector()
{
	vector<T> vec;
	vec = convertToVector(vec, root);
	return vec;
}
