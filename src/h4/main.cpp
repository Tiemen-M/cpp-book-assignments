// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>
#include "vragen_en_oefeningen.h"
#include "opdrachten.h"

using namespace std;

int main() {
	cout << discriminant() << endl;

	cout << right;
	for(char c = 'a'; c<='z'; c++)
		cout << setw(3) << c << setw(3) << alpha_shift(c) << endl;

	for (int i = 1; i <= 10; i++)
		cout << setw(3) << i << setw(10) << macht(2, i) << endl;

	opdrachten_main();
}