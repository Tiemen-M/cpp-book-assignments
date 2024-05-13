// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
using namespace std;

void main_7_9() {
	vector<int> v;

	for (int i = 0; i < 10; ++i)
		v.push_back(i * 10);

	vector<int>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos)
		cout << *pos << "  ";
	cout << endl;

	for (int i = 0; i < v.size(); i++)
		cout << v[i] << "  ";
	cout << endl;

	vector<int> w(v.begin() + 2, v.end() - 2);
	for (int i = 0; i < w.size(); i++)
		cout << w[i] << "  ";
	cout << endl;
}