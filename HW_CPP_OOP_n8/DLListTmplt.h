#pragma once
#ifndef DLLISTTMPLT_H
#define DLLISTTMPLT_H
template<class T>
class List {
	struct Elem {
		T data;
		Elem* next, * prev;
	} *head, * tail;
	int count;
public:
	List();
	List(const List&);
	//~List();
	//Elem* getElem(int);
	void del(int pos = 0);
	void insert(int pos = 0);
	void addTail(int data);
	void addHead(int data);
	void print(int pos);
	void print();
	List& operator=(const List&);
	List operator+(const List&);
	bool operator==(const List&);//равенство списков
	bool operator!=(const List&);//по кол-ву
	bool operator<=(const List&);//too
	bool operator>=(const List&);//too
	bool operator<(const List&);//too
	bool operator>(const List&);//too
	List operator-();
};
#endif // DLLISTTMPLT_H