#pragma once
#include <iostream>
using namespace std;
#ifndef ARRAY_H
class Array {
	int* data;//T
	int size;
	int grow;//grow step if array is filled
public:
	//cons  & dest
	Array(int size, int grow);
	// methods
	int getSize();
	void setSize(int size, int grow);
	void show();
	// operators
	int& operator[](int);//T?
	Array& operator=(const Array&);//T T
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
void Array::show() {
	for (int i = 0; i < size; i++)
		cout << data[i] << ' ';
	cout << endl;
}
int& Array::operator[](int i) {
	if (i < size)
		return data[i];
	else
		throw "ofr";//out of range exception
}
Array& Array::operator=(const Array &arr) {
	if (this == &arr)
		return *this;
	delete this;

}

#define ARRAY_H
#endif // !ARRAY_H

