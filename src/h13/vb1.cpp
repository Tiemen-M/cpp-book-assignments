// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.1 Functie voor de grootste van twee int-waarden
#include <iostream>
#include <iomanip>
using namespace std;

namespace vb_1 {
	int maximum(int a, int b);
	double maximum(double a, double b);
	string maximum(string a, string b);
}

using namespace vb_1;

void main_vb_1() {
	int i = 13, j = 4711;
	double x = 3.14, y = 2.5;
	string s = "koffie", t = "thee";

	cout << setw(40) << left << "Grootste int:" << maximum(i, j) << endl;
	cout << setw(40) << left << "Grootste double:" << maximum(x, y) << endl;
	cout << setw(40) << left << "Alfabetisch laatste string:" << maximum(s, t) << endl;
}

// implementatie globale functies
int vb_1::maximum(int a, int b) {
	return a > b ? a : b;
}

double vb_1::maximum(double a, double b) {
	return a > b ? a : b;
}

string vb_1::maximum(string a, string b) {
	return a > b ? a : b;
}