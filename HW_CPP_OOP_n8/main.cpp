#include <iostream>
#include "DLList.h"
using namespace std;
void testList();

int main() {
	//testList();
	TestClass<int> i(10);
	cout << i.getT() << endl;
	TestClass<double> d(10);
	cout << d.getT() << endl;

	system("pause");
	return 0;
}
void testList() {
	List L;
	const int n = 10;
	int a[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			L.addHead(i);
		else
			L.addTail(i);
	}
	L.print();
	L.insert();
	L.print();
	L.print(2);
	L.print(8);
	List T;
	T = L;
	T.print();
	List S = -L + T;
	S.print();

}