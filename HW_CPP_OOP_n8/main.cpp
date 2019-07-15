#include <iostream>
#include "DLList.h"
#include "DLListTmplt.h"
#include "Array.h"
#include "ArrayT.h"
using namespace std;
void testList();
void testListT();
void testArray();//for int only
void f(Array arr);
int main() {
	//testListT();
	//testList();
	//testArray();
	{
		//ArrayT<int> a1i(3,3),a2i(3,3);
		ArrayT<TestClass> a1tk(2, 2),a2tk(2,2);
		//ArrayT<TestClass*> a1tk_p(5, 5);
		TestClass tk1(2), tk2(4),tk3(6),tk4(8);
		a1tk.add(tk1);
		a1tk.add(tk2);
		a1tk.show();
		a2tk.add(tk3);
		a2tk.add(tk4);
		a2tk.show();
		
		a2tk = a1tk;
		a2tk.show();
		
		
		
	}
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
void f(Array arr) {
	cout << "INNER\n";
	cout << "pDATA: " << (int)arr.getData() << endl;
	cout << "UB: " << arr.getUpperBound() << endl;

	arr.show();
	arr.show(0);
}
void testArray() {
	for (int i = 0; i < 1; i++)//check
	{
		Array a1(5, 5);
		a1.add(1);
		a1.add(3);
		a1.add(5);
		//a1.show();
		//a1.show(0);
		//cout << "pDATA: " << (int)a1.getData() << endl;
		Array a2(3, 3);
		a2.add(2);
		a2.add(4);
		//a2.show();
		//a2.show(0);
		//cout << "pDATA: " << (int)a2.getData() << endl;
		Array* pa = new Array(1, 1);
		//cout << "undo pDATA: " << (int)pa->getData() << endl;
		pa->append(a1, a2);
		//pa->show();
		//pa->show(0);
		//cout << "pDATA: " << (int)pa->getData() << endl;
		Array a4(1, 1);
		//cout << "undo pDATA: " << (int)a4.getData() << endl;
		a4 = *pa;
		delete pa;
		a4.show();
		a4.show(0);
		cout << "pDATA: " << (int)a4.getData() << endl;
		cout << "UB: " << a4.getUpperBound() << endl;
		f(a4);
	}
}