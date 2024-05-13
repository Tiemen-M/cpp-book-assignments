// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.6 Meervoudige overerving
#include <iostream>
using namespace std;

namespace vb_6 {
	class A {
	protected:
		int a;
	public:
		A() : a(1) { cout << "Default-constructor van class A. (ik zet a = 1)" << endl; }
		void print() const {
			cout << "De waarde van a = " << a << endl;
		}
	};

	class B {
	protected:
		int b;
	public:
		B() : b(2) { cout << "Default-constructor van class B. (ik zet b = 2)" << endl; }
		void print() const {
			cout << "De waarde van b = " << b << endl;
		}
	};

	class X : public B, public A {
	public:
		X() { cout << "Default-constructor van class X. (ik doe niets)" << endl; }
		void print() const {
			cout << "Voor objecten van klasse X geldt: " << endl;
			A::print();
			B::print();
			//cout << "a = " << a << " en b = " << b << endl;
		}
	};
}

using namespace vb_6;

void main_vb_6() {
	X objX;
	objX.print();
	objX.A::print();
}