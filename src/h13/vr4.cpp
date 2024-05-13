// Created by Tiemen Molenaar in 2023
// UIterking vraag 13.10.4
#include <iostream>
using namespace std;

namespace vr_4 {
	template<typename T>
	T minimum(const T& a, const T& b) {
		return a < b ? a : b;
	}
}

using namespace vr_4;

void main_vr_4() {
	int a = 10, b = 20;
	cout << "minimum(" << a << ", " << b << ") = " << minimum(a, b) << endl;
	double c = 3.14, d=2.71;
	cout << "minimum(" << c << ", " << d << ") = " << minimum(c, d) << endl;
	string s = "hallo", t = "wereld";
	cout << "minimum(" << s << ", " << t << ") = " << minimum(s, t) << endl;

	cout << "Hypothese: int x = int() geeft x=0" << endl;
	int x = int();
	cout << "Proef: x=" << x << " dus de hypothese " << (x == 0 ? "klopt" : "klopt niet") << endl;
}