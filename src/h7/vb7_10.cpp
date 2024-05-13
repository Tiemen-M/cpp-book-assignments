// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <vector>

using namespace std;

// post: zet de elementen van int-vector op het scherm
//  gescheiden door komma's
void print( const vector<int>& v);

void main_7_10() {
	vector<int> rij(10);

	for (unsigned int i = 0; i < 10; i++)
		rij[i] = 2 * i;

	cout << "Inhoud: ";
	print(rij);
	cin.get();
}

void print(const vector<int>& v) {
	vector<int>::const_iterator pos,
		einde = v.end();

	for (pos = v.begin(); pos != einde - 1; ++pos)
		cout << *pos << ", ";
	cout << endl;
}