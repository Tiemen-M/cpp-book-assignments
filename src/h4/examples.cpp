// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

#include <stdio.h>

void add(int& x, int y) {
	x = x + y;
}

void to_2(int& x) {
	x = 2;
}

void to_3(int* x) {
	*x = 3;
}

int main2() {
	int i = 0;
	to_2(i);
	cout << i << endl;

	to_3(&i);
	cout << i << endl;

	int x = 5;
	add(x, 5);
	printf("x = %d\n", x);
	return 0;
}

void fb1() {
	cout << setw(5) << "x";
	cout << setw(15) << "sqrt(x)";
	cout << setw(10) << "sin(x)";
	cout << setw(15) << "sin(sqrt(x)" << endl << endl;

	cout << setprecision(2) << fixed << showpoint;

	double x = 0.;
	while (x < 3.3) {
		cout << setw(5) << x;
		cout << setw(15) << sqrt(x);
		cout << setw(10) << sin(x);
		cout << setw(15) << sin(sqrt(x)) << endl;
		x += 0.2;
	}
}


