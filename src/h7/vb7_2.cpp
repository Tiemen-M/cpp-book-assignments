// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>

using namespace std;

void main_7_2() {
	string s;
	cout << "Tik een string in" << endl;
	cin >> s;
	cout << "De ingetikte string is: " << s;
}

void main_7_3() {
	string s;
	cout << "Tik een string in" << endl;
	getline(cin, s);
	cout << "De ingetikte string is: " << s;
}