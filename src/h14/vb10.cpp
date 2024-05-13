// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.10 Functie-object met een attribuut
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

namespace vb_10 {
	void print(double x) {
		cout << setprecision(2) << showpoint << fixed << x << " ";
	}

	class PrintInclusiefBTW {
	private:
		double factor;
	public:
		PrintInclusiefBTW(double perc)
			: factor(1 + perc / 100) {}

		void operator()(double x) const {
			print(x * factor);
		}
	};
}

using namespace vb_10;

void main_vb_10() {
	double prijzen[] = { 20.00,40.00,100.0,150.50,200.00 };
	int arraylengte = sizeof(prijzen) / sizeof(double);
	vector<double> v(prijzen, prijzen + arraylengte);

	for_each(v.begin(), v.end(), print);
	cout << endl;
	for_each(v.begin(), v.end(), PrintInclusiefBTW(21));
	cout << endl;
}