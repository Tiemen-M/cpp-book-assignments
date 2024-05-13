// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.8 Ambiguïteit bij twee maal inderecte overerving
#include <iostream>
using namespace std;

namespace vb_8 {
	class A {
	protected:
		int a;
	public:
		A() : a(1) {}
		void print() const { cout << a << endl; }
	};

	class B : public A{
	protected:
		int b;
	public:
		B() : b(2) {}
		void print() const { cout << b << endl; }
	};

	class C : public A {
	protected:
		int c;
	public:
		C() : c(3) {}
		void print() const { cout << c << endl; }
	};

	class X : public B,public C {
	protected:
		int x;
	public:
		X() : x(4) {}
		void print() const {
			// cout << "a = " << a << endl; // ambigu
			cout << "a = " << B::a << endl; // niet ambigu
			cout << "a = " << C::a << endl; // niet ambigu
			cout << "b = " << b << endl;
			cout << "c = " << c << endl;
			cout << "x = " << x << endl;
		}
	};
}

using namespace vb_8;

void main_vb_8() {
	X objX;
	objX.print();
}