#pragma once
#include <iostream>
using namespace std;
#ifndef ARRAY_H
template<class T>
class Array {
	
	int size;
	int grow;
	int last;
	
public:
	T* arr;
	Array();
	~Array();
	int getSize();
	int setSize(int size, int grow = 1);
	T operator[](int ind);
	T operator=(const T&);
};
template<class T>
Array<T>::Array() {
	size = 10;
	grow = 10;
	last = 0;//empty array
	arr = new T[size]{};//{} for 0 0 0 0 0 0 0
}
template<class T>
Array<T>::~Array() {
	delete[] arr;
}
template<class T>
int Array<T>::getSize() {
	return size;
}
template<class T>
T Array<T>::operator[](int ind) {
	if (ind < size)
		return 5;// arr[ind];
	else
		return 0;
}
template<class T>
int Array<T>::setSize(int newsize, int newgrow) {
	T* newarr = new T[newsize];
	for (int i = 0; i < newsize; i++) {
		newarr[i] = arr[i];// 1 5 7 9 0 0 0 0 0 0 newsize>size
		cout <<"%%%"<< arr[i] << endl;
	}
	delete[] arr;
	size = newsize;
	grow = newgrow;
	arr = newarr;
	return 0;
}




#define ARRAY_H
#endif // !ARRAY_H

