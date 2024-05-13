// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>

using namespace std;

void maakBufferLeeg();

void main_7_4() {
	int leeftijd;
	cout << "Voor leeftijd in: ";
	cin >> leeftijd;
	maakBufferLeeg();

	string naam;
	cout << "voer een naam in: ";
	getline(cin, naam);
	cout << naam << " is " << leeftijd << " jaar" << endl;
	cin.get();
}

void maakBufferLeeg() {
	string temp;
	getline(cin, temp);
}