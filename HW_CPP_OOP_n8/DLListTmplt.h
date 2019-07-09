#pragma once
#include <iostream>
#include <typeinfo>
using namespace std;
#ifndef DLLISTTMPLT_H
#define DLLISTTMPLT_H
template<class T>
class ListT {
	struct Elem {
		T data;
		Elem* next, * prev;
	} *head, * tail;
	int count;
public:
	ListT();
	ListT(const ListT &);
	//~List();
	//Elem* getElem(int);
	void del(int pos = 0);
	void insert(int pos = 0);
	void addTail(T data);
	void addHead(T data);
	void print(int pos);
	void print();
	ListT& operator=(const ListT&);
	ListT operator+(const ListT&);
	bool operator==(const ListT&);//равенство списков
	bool operator!=(const ListT&);//по кол-ву
	bool operator<=(const ListT&);//too
	bool operator>=(const ListT&);//too
	bool operator<(const ListT&);//too
	bool operator>(const ListT&);//too
	ListT operator-();
};
template<class T>
ListT<T>::ListT() {
		head = tail = 0;
		count = 0;
	}
template<class T>
ListT<T>::ListT(const ListT<T> &L) {
	head = tail = 0;
	count = 0;
	Elem* tmp = L.head;
	while (tmp) {//copy list
		addTail(tmp->data);
		tmp = tmp->next;
	}
	cout << typeid(T).name() << " CopyConstructor\n";
}
template<class T>
void ListT<T>::addHead(T data) {
	Elem* tmp = new Elem;
	tmp->prev = 0;//1
	tmp->data = data;
	tmp->next = head;//2
	if (head)//not empty list
		head->prev = tmp;
	if (count == 0)
		head = tail = tmp;
	else
		head = tmp;
	count++;
}
template<class T>
void ListT<T>::addTail(T data) {
	Elem* tmp = new Elem;
	tmp->next = 0;//1
	tmp->data = data;
	tmp->prev = tail;//2
	if (tail) {
		tail->next = tmp;
	}
	if (count == 0)
		head = tail = tmp;
	else
		tail = tmp;
	count++;
}
template<class T>
void ListT<T>::print(int pos) {
	if (pos<1 || pos>count) {
		cout << "Err:pos" << pos << endl;
		return;
	}
	Elem* temp;
	if (pos <= count / 2) {
		int i = 1;
		temp = head;
		while (i < pos) {
			temp = temp->next;
			i++;
		}
	}
	else {
		int i = 1;
		temp = tail;
		while (i <= count - pos) {
			temp - temp->prev;
			i++;
		}
	}
	cout << pos << ", elem= " << temp->data;
}
template<class T>
void ListT<T>::print() {
	if (count != 0) {
		Elem* temp = head;
		cout << "( ";
		while (temp->next != 0) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}
template<class T>
void ListT<T>::insert(int pos) {
	if (pos == 0) {
		cout <<typeid(T).name()<< " pos= ";
		cin >> pos;
	}
	if (pos<1 || pos>count + 1) {
		cout << "Err:pos" << pos << endl;
		return;
	}
	T data;
	cout << typeid(T).name() << " data= ";
	cin >> data;
	if (pos == count + 1) {
		addTail(data);
		return;
	}
	else if (pos == 1) {
		addHead(data);
		return;
	}
	int i = 1;
	Elem* ins = head;//iterator
	while (i < pos) {
		ins = ins->next;
		i++;
	}
	Elem* prevIns = ins->prev;
	Elem* temp = new Elem;
	temp->data=data;
	if (prevIns && count != 1)
		prevIns->next = temp;
	temp->next = ins;
	temp->prev = prevIns;
	ins->prev = temp;
	count++;
}
template<class T>
ListT<T>& ListT<T>::operator=(const ListT<T> & L) {
	//возвращается копия списка
	if (this == &L)//K=K сам себя присваивает
		return *this;
	this->~ListT();//del current list
	Elem* temp = L.head;
	while (temp) {
		addTail(temp->data);
		temp = temp->next;
	}
	return *this;
}
template<class T>
ListT<T> ListT<T>::operator+(const ListT<T>& L) {
	ListT<T> resault(*this);
	Elem* temp = L.head;
	while (temp) {
		resault.addTail(temp->data);
		temp = temp->next;
	}
	return resault;
}
template<class T>
bool ListT<T>::operator==(const ListT<T>& L) {
	//if equals count and each elem
	if (count != L.count)
		return false;
	Elem* e1, * e2;
	e1 = head;
	e2 = L.head;
	while (e1) {
		if (e1->data != e2->data)
			return false;
		e1 = e1->next;
		e2 = e2->next;
	}
	return true;
}
template<class T>
bool ListT<T>::operator!=(const ListT<T>& L) {
	return !(*this == L);
}
template<class T>
bool ListT<T>::operator>=(const ListT<T>& L) {
	if (count > L.count)
		return true;
	if (*this == L)
		return true;
	return false;
}
template<class T>
bool ListT<T>::operator<=(const ListT<T>& L) {
	if (count < L.count)
		return true;
	if (*this == L)
		return true;
	return false;
}
template<class T>
bool ListT<T>::operator>(const ListT<T>& L) {
	return count > L.count;
}
template<class T>
bool ListT<T>::operator<(const ListT<T>& L) {
	return count < L.count;
}
template<class T>
ListT<T> ListT<T>::operator-() {
	ListT<T> resault;
	Elem* temp = head;
	while (temp != 0) {
		resault.addHead(temp->data);
		temp = temp->next;
	}
	return resault;
}
#endif // DLLISTTMPLT_H