// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int som(const vector<int>& v);

void main_opg_4() {
	vector<int> nummers;

	cout << "Als je de volgende lijst getallen optelt:" << endl;
	for (int i = 1; i <= 10; i += 3) {
		nummers.push_back(i);
		cout << setw(10) << right << i << endl;
	}
	cout << "Dan is de som: " << som(nummers) << endl;
}

int som(const vector<int>& v) {
	int som = 0;
	vector<int>::const_iterator i = v.begin();
	while (i < v.end()) som += *i++;
	return som;
}