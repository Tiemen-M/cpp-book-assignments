// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void voegsamen(vector<int>& v, const vector<int>& w);
void print(const char *msg, const vector<int>& v);

void main_opg_6() {
	vector<int> a, b;
	for (int i = 1; i <= 5; i++) {
		a.push_back(i);
	}

	for (int i = 10; i >= 6; i--) {
		b.push_back(i);
	}

	print("a", a);
	print("b", b);

	voegsamen(a, b);
	print("a+b", a);
}

void voegsamen(vector<int>& v, const vector<int>& w) {
	for (vector<int>::const_iterator item = w.begin(); item < w.end(); item++) {
		v.push_back(*item);
	}
}

void print(const char* msg, const vector<int>& v) {
	cout << msg << " : ";
	for (vector<int>::const_iterator i = v.begin(); i < v.end(); i++)
		cout << setw(5) << left << *i << " ";
	cout << endl;
}