#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;
#ifndef ARRAYA_H
#define ARRAYA_H
#define TEST "ON"
template<class T>
class ArrayA {
	
public:
	//cons  & dest
	ArrayA(int size, int grow);
	ArrayA(const ArrayA&);
	~ArrayA() {};
	// methods
	int getSize();
	int getUpperBound()const;
	bool isEmpty();
	void setSize(int size, int grow = 1);
	void show(bool ubON = 1);
	T getAt(int index);//return T
	void setAt(T value, int index);//T value
	int add(T value);//return upper bound
	void freeExtra();
	void removeAll();
	T* getData();//T*
	ArrayA& append(const ArrayA&, const ArrayA&);
	// operators
	T& operator[](int);//return T&
	ArrayA<T>& operator=(const ArrayA<T>&);//T T
};
template<class T>
ArrayA<T>::ArrayA(int size, int grow) {
	const char* type = typeid(T).name();

}
#endif //ARRAYA_H