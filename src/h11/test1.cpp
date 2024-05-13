// Created by Tiemen Molenaar in 2023
// Test 1 :	Hoe werkt een union met klassen?
// Hypyothese: Klasse moet een default constructor hebben om in een union gebruikt te
//			    kunnen worden.
#include <iostream>
using namespace std;

namespace test_1 {
	string test = string("Hallo A");

	class A {
	private:
		string *a;
	public:
		A() : a(&test) {}
		string toString() const {
			return *a;
		}
	};

	class B {
	private:
		int b;
	public:
		B() {}
	};
	
	union Item {
		A a;
		B b;
		Item() : a() {}
	};
}

using namespace test_1;

void main_test_1() {
	Item i;
	cout << i.a.toString() << endl;;
}

/*
Na vragen aan chatbot bing over of je een klasse type variablen in union mag hebben heb ik
de volgende antwoord gekregen:
Ja, een union kan variabelen hebben die als type een klasse hebben in C++, maar er zijn enkele beperkingen. Een union kan geen klassevariabelen hebben die:
een niet-triviale constructor, destructor, kopie- of verplaatsingsoperator hebben12
een virtuele functie of een basisklasse hebben1
een referentietype zijn

Dus Ik kan alleen een klasse in een union gebruiken als de klase voldoet aan het volgende:
1. De klasse moet een default constructor heben.
2. De klasse mag geen virtuale functies of basisklasse hebben.
3. De klasse mag geen lidvariablen hebben die referencties zijn zoals string.
*/