#pragma once
#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <string>
#include <sstream>
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
	void ShowName(string name, NODE<T> *node);
	int size(NODE<T> *node);
	stringstream getAllData(NODE<T>* node);
public:
	BST();
	void Insert(T value);
	NODE<T> *SearchPerSonnalKey(T value);
	void preOrder(int type);
	void ShowName(string name);
	int size();
	void writeFlile(string nameFile);
	void ReadFile(string nameFile);
};

#endif
