// Created by Tiemen Molenaar in 2023
#include <iostream>

using namespace std;
#include <conio.h>

void vb2_22main() {
	char ch;
	cout << "Druk op een lettertoets" << endl;

	//cin >> ch;
	ch = cin.get();

	cout << "U heeft op de letter " << ch << " gedrukt." << endl;
	cin.get();
}