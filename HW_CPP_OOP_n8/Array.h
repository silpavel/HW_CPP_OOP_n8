#pragma once
#include <iostream>
using namespace std;
#ifndef ARRAY_H
class Array {
	int* data;//new T[]
	int size;//size array
	int grow;//grow step if array is filled
	int upperBound;// 1 7 4 6 0 0 0 index=3 size=7
public:
	//cons  & dest
	Array(int size, int grow);
	~Array();
	// methods
	int getSize();
	int getUpperBound();
	bool isEmpty();
	void setSize(int size, int grow);
	void show();
	int getAt(int index);//return T
	void setAt(int value, int index);//T value
	int add(int value);//return upper bound
	//void freeExtra();
	// operators
	int& operator[](int);//return T&
	Array& operator=(const Array&);//T T
};
int Array::getSize() {
	return size;
}
Array::Array(int size, int grow=10) {
	this->size = size;
	this->grow = grow;
	this->upperBound = -1;//empty array
	data = new int[size] {};//new T[] 0 0 0 0 0 0
}
Array::~Array() {
	delete[] data;
}
void Array::setSize(int newsize, int newgrow=1) {
	grow = newgrow;
	int* newdata = new int[newsize] {};//new T 0 0 0 0 
	for (int i = 0; i < size && i<newsize; i++)
		newdata[i] = data[i];
	delete[] data;
	data = newdata;
	size = newsize;
	if (upperBound >= size)
		upperBound = size - 1;
}
void Array::show() {
	for (int i = 0; i < size; i++)//<--upperBound
		cout << data[i] << ' ';
	cout << endl;
}
int& Array::operator[](int i) {
	if (i < size)//<------upperBound
		return data[i];
	else
		throw "out of range";//exception
}
Array& Array::operator=(const Array &arr) {
	if (this->size != arr.size) {
		delete[] data;
		data = new int[arr.size];//T
		this->size = arr.size;
	}
	for (int i = 0; i < this->size; i++)//<-upperBound
		this->data[i] = arr.data[i];
	this->grow = arr.grow;
	this->upperBound = arr.upperBound;// up /|\ 
	return *this;
}
int Array::getUpperBound() {
	return upperBound;
}
bool Array::isEmpty() {
	return upperBound == -1;
}
int Array::getAt(int index) {// T array
	if (index<0 || index > upperBound)
		throw "out of range";//exception
	return data[index];
}
void Array::setAt(int value, int index) {// T value
	if (index<0 || index > upperBound)
		throw "out of range";//exception
	data[index] = value;
}
int Array::add(int value) {//T value
	if (upperBound == size - 1)//array is filled
		setSize(size + grow, grow);
	data[++upperBound]=value;
	return upperBound;
}
#define ARRAY_H
#endif // !ARRAY_H

