// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.8 Ambiguïteit bij twee maal inderecte overerving
#include <iostream>
using namespace std;

namespace vb_9 {
	class A {
	protected:
		int a;
	public:
		A() : a(1) {}
		void print() const { cout << a << endl; }
	};

	class B : public virtual A {
	protected:
		int b;
	public:
		B() : b(2) {}
		void print() const { cout << b << endl; }
	};

	class C : public virtual A {
	protected:
		int c;
	public:
		C() : c(3) {}
		void print() const { cout << c << endl; }
	};

	class X : public B, public C {
	protected:
		int x;
	public:
		X() : x(4) {}
		void print() const {
		    cout << "a = " << a << endl; // is niet meer ambigu door virtual A
			//cout << "a = " << B::a << endl; // niet ambigu
			//cout << "a = " << C::a << endl; // niet ambigu
			cout << "b = " << b << endl;
			cout << "c = " << c << endl;
			cout << "x = " << x << endl;
		}
	};
}

using namespace vb_9;

void main_vb_9() {
	X objX;
	objX.print();
}