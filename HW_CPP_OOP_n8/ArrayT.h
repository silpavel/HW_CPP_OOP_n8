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




///TestClass methods
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