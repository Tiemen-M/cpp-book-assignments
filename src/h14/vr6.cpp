// Created by Tiemen Molenaar in 2023
// Uitwerking vraag 14.11.6 Maak een functie-object die 
// de waarde van zijn int-argument verdubbeld
#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

namespace vr_6 {
	class Verdubbel {
	public:
		void operator()(int& x) const {
			x *= 2;
		}
	};

	class Print {
	public:
		void operator()(const int& x) const {
			cout << setw(4) << left << x << ", ";
		}
	};
}

using namespace vr_6;

void main_vr_6() {
	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };

	for_each(arr, arr + sizeof(arr) / sizeof(int), Print());
	cout << endl;

	for_each(arr, arr + sizeof(arr) / sizeof(int), Verdubbel());

	for_each(arr, arr + sizeof(arr) / sizeof(int), Print());
	cout << endl;
}