#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;
#ifndef ARRAYT_H
#define ARRAYT_H
#define TEST "ON"
class TestClass {
	int i;
public:
	TestClass(int i);
	TestClass();
	TestClass(TestClass&);
	~TestClass();
	void set(int);
	int get();
};
template<class T>
class ArrayT {
	T* data;// T*
	int size;//size array
	int grow;//grow step if array is filled
	int upperBound;// 1 7 4 6 0 0 0 index=3 size=7
public:
	//cons  & dest
	ArrayT(int size, int grow);
	ArrayT(const ArrayT&);
	~ArrayT();
	// methods
	int getSize();
	int getUpperBound() const;
	bool isEmpty();
	void setSize(int size, int grow);
	void show(bool ubON = 1);
	T getAt(int index);//return T
	void setAt(T value, int index);//T value
	int add(T value);//return upper bound
	void freeExtra();
	void removeAll();
	T* getData();//T*
	ArrayT& append(const ArrayT&, const ArrayT&);
};
//ArrayT methods
template<class T>
int ArrayT<T>::getSize() {
	return size;
}
template<class T>
ArrayT<T>::ArrayT(int size, int grow) {
	if (size < 0) size = 10;
	else this->size = size;
	if (grow < 1) grow = 1;
	else this->grow = grow;
	this->upperBound = -1;//empty array
	data = new T[size];//new T[] 0 0 0 0 0 0
	cout << "new ArrayT: " << (int)this << endl;
}
template<class T>
ArrayT<T>::ArrayT(const ArrayT<T>& arr) {
	this->size = arr.size;
	this->data = new T[this->size];
	this->grow = arr.grow;
	this->upperBound = arr.upperBound;
	for (int i = 0; i <= (this->getUpperBound()); i++)
		this->data[i] = arr.data[i];

	cout << "new copy ArrayT: " << (int)this << endl;

}
template<class T>
ArrayT<T>::~ArrayT() {
	cout << "free ArrayT: " << (int)this << endl;
	delete[] data;
}


// TestClass methods
TestClass::TestClass(int i) :i(i) {
#ifdef TEST
	cout << "new TestClass i  " << (int)this << endl;
#endif //TEST
}
TestClass::TestClass() : i(0) {
#ifdef TEST
	cout << "new TestClass i=0  " << (int)this << endl;
#endif //TEST
}
TestClass::TestClass(TestClass& tc) {
	this->i = tc.i;
#ifdef TEST
	cout << "new copy TestClass " << (int)this << endl;
#endif //TEST
}
TestClass::~TestClass() {
#ifdef TEST
	cout << "free TestClass " << (int)this << endl;
#endif //TEST
}
void TestClass::set(int i) {
	this->i = i;
}
int TestClass::get() {
	return i;
}
#endif // !ARRAYT_H