// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.1 De standaard stream-objecten cin en cout
#include <iostream>
using namespace std;

void main_vb_1() {
	char c;
	int i;
	double d;
	
	cin >> c;
	cin >> i;
	cin >> d;
	cin.get();

	cout << c << endl;
	cout << i << endl;
	cout << d << endl;
}