// Created by Tiemen Molenaar in 2023
// voorbeeld 7.8 string omkeren
#include <iostream>
#include <string>

using namespace std;

void keerOm(string& s);
void verwissel(char& a, char& b);

void main_7_8() {
	string tekst = "Olympische Spelen 2012";

	cout << tekst << endl;
	keerOm(tekst);
	cout << tekst << endl;
}

void keerOm(string& s) {
	/*
	string::iterator eerste = s.begin(),
		laatste = s.end() -1;

	while (eerste < laatste) {
		verwissel(*eerste++, *laatste--);
		//++eerste;
		//--laatste;
	}
	*/
	for (
		string::iterator eerste = s.begin(), laatste = s.end() - 1; 
		eerste < laatste; 
		verwissel(*eerste++, *laatste--)
		);
}

void verwissel(char& a, char& b) {
	char hulp = a;
	a = b;
	b = hulp;
}