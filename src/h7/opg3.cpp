// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void verdubbel( vector<string>& v);
void print(const vector<string>& v);

void main_opg_3() {
	string s[] = { "Tiemen","uno", "zero" };
	vector<string> v(s, s + sizeof(s) / sizeof(string));
	
	cout << "Vector content before: " << endl;
	print(v);

	verdubbel(v);
	cout << "Vector content after verdubbel(v):" << endl;
	print(v);

}

void verdubbel(vector<string>& v) {
	for (vector<string>::iterator i = v.begin(); i < v.end(); i++) {
		*i += *i;
	}
}

void print(const vector<string>& v) {
	for (vector<string>::const_iterator p = v.begin(); p < v.end(); p++) {
		cout << "\t" << *p << endl;
	}
}
