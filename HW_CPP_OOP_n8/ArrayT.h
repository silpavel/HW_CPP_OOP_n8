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
	~TestClass();
	void set(int);
	int get();
};
template<class T>
class ArrayT {
	bool T_is_class;
	class Adapter {//for pointers array
	public:
		T* t;
		Adapter();
		~Adapter();
	};
	T* data;
	Adapter* dataA;
	int size;//size array
	int grow;//grow step if array is filled
	int upperBound;// 1 7 4 6 0 0 0 index=3 size=7
public:
	//cons  & dest
	ArrayT(int size, int grow=1);
	~ArrayT();
	//methods
	int add(T value);//return upper bound
	//operators
};

//ArrayT methods
template<class T>
ArrayT<T>::ArrayT(int size, int grow) {
	T_is_class = strstr(typeid(T).name(), "class");
	this->size = size;
	this->grow = grow;
	this->upperBound = -1;//empty array
	if(T_is_class)
		dataA = new Adapter[size];//new TestClass[] 0x0 0x0 0x0
	else
		data = new T[size];//new int[] 0 0 0 0 0 0
#ifdef TEST
	cout << "new ArrayT " << typeid(T).name() << " " << (int)this << endl;
#endif //TEST
}
template<class T>
ArrayT<T>::~ArrayT() {
	if(data)
		delete[] data;
	if (dataA)
		delete[] dataA;
#ifdef TEST
	cout << "free ArrayT " << typeid(T).name() << " " << (int)this << endl;
#endif //TEST
}
template<class T>
int ArrayT<T>::add(T value) {//return upper bound
	if (upperBound == size - 1)//array is filled
		setSize(size + grow, grow);
	if(T_is_class)
		//data[++upperBound] = value;
	else
		data[++upperBound] = value;
	return upperBound;
}

//Adapter
template<class T>
ArrayT<T>::Adapter::Adapter(){
#ifdef TEST
	t = 0;
	cout << "new Adapter " << (int)this <<  " to "<< typeid(T).name()   << endl;
#endif //TEST
}
template<class T>
ArrayT<T>::Adapter::~Adapter() {
#ifdef TEST
	cout << "free Adapter " << (int)this << " to " << typeid(T).name() << endl;
#endif //TEST
}
//TestClass methods
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