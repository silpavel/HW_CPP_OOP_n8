#include <iostream>
#include "DLList.h"
#include "DLListTmplt.h"
#include "Array.h"
using namespace std;
void testList();
void testListT();

int main() {
	//testListT();
	//testList();
	Array a1(10);
	a1.show();
	cout << a1.getUpperBound() << endl;
	cout << a1.isEmpty() << endl;
	
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
void testListT() {
	ListT<int> Li;
	ListT<double> Ld;
	ListT<char> Lc;
	const int n = 10;
	int ai[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	double ad[n] = {0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	char ac[n] = {'a','b','c', 'd','e','f','g','h','i','j'};
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			Li.addHead(ai[i]);
		else
			Li.addTail(ai[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			Ld.addHead(ad[i]);
		else
			Ld.addTail(ad[i]);
	}
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0)
			Lc.addHead(ac[i]);
		else
			Lc.addTail(ac[i]);
	}
	Li.print();
	Ld.print();
	Lc.print();
	Li.insert();
	Li.print();
	Ld.insert();
	Ld.print();
	Lc.insert();
	Lc.print();
	Li.print(1);
	Ld.print(8);
	Lc.print(10);
	cout << endl;
	ListT<int> Ti;
	ListT<double> Td;
	ListT<char> Tc;
	Ti = Li;
	Td = Ld;
	Tc = Lc;
	Ti.print();
	Td.print();
	Tc.print();
	ListT<int> Si = -Li + Ti;
	ListT<double> Sd = -Ld + Td;
	ListT<char> Sc = -Lc + Tc;
	Si.print();
	Sd.print();
	Sc.print();
	
	


}