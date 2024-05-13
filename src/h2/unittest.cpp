// Created by Tiemen Molenaar in 2023
#include <iostream>
using namespace std;

void check(int expression, int expected) {
	if (expression == expected)
		cout << expression << " == " << expected << " \x1B[1;32mSUCCESS\x1b[0;0m" << endl;
	else
		cout << expression << " != " << expected << " \x1B[1;31mFAILED\x1b[0;0m" << endl;
}

void vrg2_12_1main() {
	check(10 / 2 * 5, 25);
	check(4 / 5 * 2, 0);
	check(2 * 4 / 5, 1);
}