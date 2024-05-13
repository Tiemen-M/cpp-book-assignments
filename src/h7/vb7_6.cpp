// Created by Tiemen Molenaar in 2023
// voorbeeld 7.6, string iterator
#include <iostream>
#include <string>

using namespace std;

void main_7_6() {
	string s = "abcd";
	string::iterator pos;

	for (pos = s.begin(); pos != s.end(); ++pos) {
		cout << *pos << endl;
	}
}