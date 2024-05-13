// Created by Tiemen Molenaar in 2023
// programma: bewijs dat de copy constructie wordt aangeroepen bij een call by value
#include <iostream>
#include <string>
using namespace std;

namespace oef_2 {
	class Test {
	private:
		string naam;
	public:
		// getter
		const string& getNaam() const {
			return naam;
		}

		// default-constructor
		Test(string naam) :
			naam(naam) {
			cout << "Nieuw object aangemaakt " << naam << endl;
		}
		// copy constructor
		Test(Test& test) {
			naam = test.getNaam();
			cout << "Object " << naam << " gekopiëerd." << endl;
		}
	};
}

using namespace oef_2;

void call_by_value(Test x) {}
void call_by_reference(Test& x) {}

void main_oef_2() {
	Test t1("test 1");

	cout << "void call_by_value(Test x) roept copy_constructor aan:" << endl;
	call_by_value(t1);

	cout << "void call_by_reference(Test& x) roept geen enkele constructoraan:" << endl;
	call_by_reference(t1);
}