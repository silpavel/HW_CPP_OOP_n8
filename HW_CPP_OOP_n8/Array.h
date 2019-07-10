#pragma once
#include <iostream>
using namespace std;
#ifndef ARRAY_H
class Array {
	int* data;//T
	int size;
	int grow;//grow step if array is filled
public:
	Array(int size, int grow);
	int getSize();
	void setSize(int size, int grow);
};
int Array::getSize() {
	return size;
}
Array::Array(int size, int grow=10) {
	this->size = size;
	this->grow = grow;
	data = new int[size] {};//T 0 0 0 0 0 0
}
void Array::setSize(int newsize, int newgrow) {
	grow = newgrow;
	int* newdata = new int[newsize] {};//T 0 0 0 0 
	if (newsize > size)
		for (int i = 0; i < size; i++)
			newdata[i] = data[i];
	else if (newsize < size)
		for(int i=0;i<newsize;i++)
			newdata[i] = data[i];
}

#define ARRAY_H
#endif // !ARRAY_H

