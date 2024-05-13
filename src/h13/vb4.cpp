// Created by Tiemen Molenaar in 2023
//Voorbeeld 13.4 Functie-template met twee template-argumenten
#include <iostream>
using namespace std;

namespace vb_4 {
	template<typename A, class B>
	void print(A a, B b) {
		cout << a << '\t' << b << endl;
	}
}

using namespace vb_4;

void main_vb_4() {
	print(1, 2.3456789);
	print(string("Eva"), "tekst");
	print(-1, 'a');
}