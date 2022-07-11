#pragma once
#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <string>
#include "CarSetting.h"
#include "valiuData.h"
#include <fstream>

using namespace std;

template <class T>
class NODE {
public:
	T data;
	NODE *left;
	NODE *right;
	NODE(T value);
};

template <class T>
class BST
{
private:
	NODE<T> *root;
	void Insert(T value, NODE<T> *node);
	NODE<T> *SearchPerSonnalKey(T value, NODE<T> *node);
	void preOrder(NODE<T> *node, int type);
	void inOrder(NODE<T> *node, int type);
	void postOrder(NODE<T> *node, int type);
	void ShowName(string name, NODE<T> *node);
	int size(NODE<T> *node);
	vector<T> convertToVector(vector<T> listcar, NODE<T>* node);
public:
	BST();
	void Insert(T value);
	NODE<T> *SearchPerSonnalKey(T value);
	void preOrder(int type);
	void inOrder(int type);
	void postOrder(int type);	
	void ShowName(string name);
	int size();
	vector<T> convertToVector();
};

#endif
