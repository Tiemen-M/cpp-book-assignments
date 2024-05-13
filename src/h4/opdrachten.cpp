// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
#include "opdrachten.h"

using namespace std;

void opdrachten_main() {
	double n1 = 203.209, n2 = 890.32, antwoord;
	max(n1, n2, antwoord);
	cout << setw(15) << n1;
	cout << setw(15) << n2;
	cout << setw(15) << antwoord << endl;

	cout << endl;
	
	unsigned long fac_antwoord;
	cout << left;
	for (int i = -2; i < 22; i++) {
		fac(i, fac_antwoord);
		cout << setw(5) << i << setw(50) << fac_antwoord << endl;
	}
}

void max(double a, double b, double& m) {
	m = (a > b) ? a : b;
}

void fac(int n, unsigned long& resultaat) {
	if (n < 0) {
		resultaat = 0;
		return;
	}

	resultaat = 1;
	for (int i = 2; i <= n; i++) {
		resultaat *= i;
	}
}