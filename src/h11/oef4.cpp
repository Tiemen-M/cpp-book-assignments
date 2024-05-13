// Created by Tiemen Molenaar in 2023
// bewijzen bij het creëeren van een object van een afgeleide klasse ook de default-constructor
//	van de basis klasse wordt aangeroepen, tenzij je een andere constructor uit de basisklasse
//	aanroept
#include <iostream>
using namespace std;

namespace oef_4 {
	class A {
	private:
		int a;
	public:
		A() {
			cout << "A: default-constructor aanroep. a = " << a << endl;
		}
		A(int a)
			: a(a) {
			cout << "A: normale constructor aanroep. a = " << a << endl;
		}
	};

	class B : public A {
	private:
		int b;
	public:
		B() {
			cout << "B: default-constructor aanroep. b = " << b << endl;
		}
		B(int a, int b)
			: A(a), b(b) {
			cout << "B: normale constructor aanroep. b = " << b << endl;
		}
	};
}

using namespace oef_4;

void main_oef_4() {
	cout << "Object van klasse B zonder argumenten aangemaakt:" << endl;
	B b1;
	cout << endl;

	cout << "Object van klasse B met argumenten a=2,b=4 aangemaakt:" << endl;
	B b2(2, 4);
	cout << endl;

	cout << "Dus als de constructor van B niet expliciet de constructor van A aanroept, " << endl;
	cout << " dan zal de compiler automatisch de default-constructor van klasse A aanroepen bij " << endl;
	cout << " het creeëren van object B" << endl;
}