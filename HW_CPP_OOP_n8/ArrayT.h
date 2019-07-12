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
	bool T_is_class;
	class Adapter {//for pointers array
	public:
		T* t;
		Adapter();
		Adapter(Adapter&);
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
	ArrayT(const ArrayT&);
	//methods
	int add(T value);//return upper bound
	int getSize();
	int getUpperBound() const;
	bool isEmpty();
	void setSize(int size, int grow);
	void show(bool ubON = 1);
	T getAt(int index);
	void setAt(T value, int index);//T value
	void freeExtra();
	void removeAll();
	int* getData();//T?T
	ArrayT& append(const ArrayT&, const ArrayT&);
	//operators
	int& operator[](int);//return T&
	Array& operator=(const Array&);//T T
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
ArrayT<T>::ArrayT(const ArrayT& arr) {
	this->size = arr.size;
	this->grow = arr.grow;
	this->upperBound = arr.upperBound;
	if (T_is_class) {
		this->dataA = new Adapter[this->size];
		for (int i = 0; i <= (this->getUpperBound()); i++)
			this->dataA[i] = arr.dataA[i];//Adapter copy contructor
	}
	else {
		this->data = new T[this->size];
		for (int i = 0; i <= (this->getUpperBound()); i++)
			this->data[i] = arr.data[i];
	}
	
	

	cout << "new copy Array " << (int)this << endl;

}
template<class T>
int ArrayT<T>::add(T value) {//return upper bound
	if (upperBound == size - 1)//array is filled
		//setSize(size + grow, grow);
	if(T_is_class)
		dataA[++upperBound].t=new T(value);
	else
		data[++upperBound] = value;
	return upperBound;
}
template<class T>
int ArrayT<T>::getSize() {
	return size;
}
template<class T>
bool ArrayT<T>::isEmpty() {
	if (T_is_class)
		for (int i = 0; i <= upperBound; i++)
			delete dataA[i];//delete Test Class object
	return upperBound == -1;
}
template<class T>
void ArrayT<T>::setSize(int newsize, int newgrow) {
	grow = newgrow;
	if (size == newsize)
		return;
	if (T_is_class) {
		Adapter* newdataA = new Adapter[newsize];
		for (int i = 0; i < size && i < newsize; i++)
			newdataA[i] = dataA[i];
		//if newsize <= upperBound need free memory TestClass objects
		for (int i = newsize; i <= upperBound; i++)
			delete dataA[i];
		delete[] dataA;
		dataA = newdataA;
	}
	else {//for base type
		T* newdata = new T[newsize] {};//new T 0 0 0 0 
		for (int i = 0; i < size && i < newsize; i++)
			newdata[i] = data[i];
		delete[] data;
		data = newdata;
	}
	size = newsize;
	if (upperBound >= size)//size down
		upperBound = size - 1;
}

//Adapter
template<class T>
ArrayT<T>::Adapter::Adapter(){
#ifdef TEST
	cout << "new Adapter " << (int)this <<  " to "<< typeid(T).name()   << endl;
#endif //TEST
}
template<class T>
ArrayT<T>::Adapter::Adapter(Adapter &ad) {
	this->t = new T(*(ad.t));
#ifdef TEST
	cout << "new copy Adapter " << (int)this << " to " << typeid(T).name() << endl;
#endif //TEST
}
template<class T>
int ArrayT<T>::getUpperBound() const {
	return upperBound;
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