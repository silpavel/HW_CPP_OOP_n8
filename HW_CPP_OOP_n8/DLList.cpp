#include "DLList.h"
#include <iostream>
using namespace std;
List::List() {
	head = tail = 0;
	count = 0;
}
List::List(const List &L) {
	head = tail = 0;
	count = 0;
	Elem* tmp=L.head;
	while (tmp) {//copy list
		addTail(tmp->data);
		tmp = tmp->next;
	}
}
void List::addHead(int data) {
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
void List::addTail(int data) {
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
void List::insert(int pos) {
	if (pos == 0) {
		cout << "pos= ";
		cin >> pos;
	}
	if (pos<1 || pos>count + 1) {
		cout << "Err:pos" << pos << endl;
		return;
	}
	if (pos == count + 1) {
		int data;
		cout << "data= ";
		cin >> data;
		addTail(data);
		return;
	}
	else if (pos == 1) {
		int data;
		cout << "data= ";
		cin >> data;
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
	cout << "data= ";
	cin >> temp->data;
	if (prevIns && count != 1)
		prevIns->next = temp;
	temp->next = ins;
	temp->prev = prevIns;
	ins->prev = temp;
	count++;
}
void List::del(int pos) {
	if (pos == 0) {
		cout << "pos= ";
		cin >> pos;
	}
	if (pos<1 || pos>count + 1) {
		cout << "Err:pos" << pos << endl;
		return;
	}
	int i = 0;
	Elem *del = head;
	while (i < pos) {
		del = del->next;
		i++;
	}
	Elem *prevDel = del->prev;
	Elem *afterDel = del->next;
	if (prevDel != 0 && count != 1)
		prevDel->next = afterDel;
	if (afterDel && count != 1)
		afterDel->prev = prevDel;
	if (pos == 1)
		head = afterDel;
	if (pos == count)
		tail = prevDel;
	delete del;
	count--;
}
void List::print(int pos) {
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
	cout <<pos<< ", elem= " << temp->data;
}
void List::print() {
	if (count != 0) {
		Elem *temp = head;
		cout << "( ";
		while (temp->next != 0) {
			cout << temp->data << ", ";
			temp = temp->next;
		}
		cout << temp->data << " )\n";
	}
}
List& List::operator=(const List &L) {
	//возвращается копия списка
	if (this == &L)//K=K сам себя присваивает
		return *this;
	this->~List();//del current list
	Elem *temp = L.head;
	while (temp) {
		addTail(temp->data);
		temp = temp->next;
	}
	return *this;
}
List List::operator+(const List &L) {
	List resault(*this);
	Elem*temp = L.head;
	while (temp) {
		resault.addTail(temp->data);
		temp = temp->next;
	}
	return resault;
}
bool List::operator==(const List &L) {
	//if equals count and each elem
	if (count != L.count)
		return false;
	Elem *e1, *e2;
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
bool List::operator!=(const List &L) {
	return !(*this == L);
}
bool List::operator>=(const List &L) {
	if (count > L.count)
		return true;
	if (*this == L)
		return true;
	return false;
}
bool List::operator<=(const List &L) {
	if (count < L.count)
		return true;
	if (*this == L)
		return true;
	return false;
}
bool List::operator>(const List &L) {
	if (count > L.count)
		return true;
	return false;
}
bool List::operator<(const List &L) {
	if (count < L.count)
		return true;
	return false;
}
List List::operator-() {
	List resault;
	Elem *temp = head;
	while (temp != 0) {
		resault.addHead(temp->data);
		temp = temp->next;
	}
	return resault;
}
////////////////////////////////////-------------
/*
template<class T>
T TestClass<T>::getT() {
	return nt;
}
*/
