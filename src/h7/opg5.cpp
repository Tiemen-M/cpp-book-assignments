// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void keerom(vector<int>& v);

void main_opg_5() {
	vector<int> v;
	for (int i = 1; i <= 10; i++)
		v.push_back(i);

	auto print = [](const vector<int> v) -> void {
		for (int i = 0; i < v.size(); i++)
			cout << setw(5) << left << v[i] << " ";
		cout << endl;
	};

	print(v);

	keerom(v);

	print(v);

}

void keerom(vector<int>& v) {
	register int reg;
	vector<int>::iterator begin = v.begin(), eind = v.end() - 1;
	while (begin < eind) {
		reg = *begin;
		*begin = *eind;
		*eind = reg;
		begin++;
		eind--;
	}
}