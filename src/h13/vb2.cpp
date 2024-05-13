// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.2 Een tamplate voor maximum()
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_2 {
	template<typename T>
	T maximum(T a, T b);
}

using namespace vb_2;

void main_vb_2() {
	int i = 13, j = 4711;
	double x = 3.14, y = 2.5;
	string s = "koffie", t = "thee";

	cout << setw(40) << left << "Grootste int:" << maximum(i, j) << endl;
	cout << setw(40) << left << "Grootste double:" << maximum(x, y) << endl;
	cout << setw(40) << left << "Alfabetisch laatste string:" << maximum(s, t) << endl;
}

// implementatie globale functies
template<typename T>
T vb_2::maximum(T a, T b) {
	return a > b ? a : b;
}