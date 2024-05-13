// Created by Tiemen Molenaar in 2023
// UItwerking vraag 16.13.4: open alfabet.txt en voor aantal lees acties uit.
#include <iostream>
#include <fstream>
using namespace std;

void main_vr_4() {
	// Pre: het bestand alfabet.txt is aangemaakt met de programma uit vr3.cpp
	ifstream abc("alfabet.txt");

	// Ik verwacht dat de letter D wordt geprint naar het scherm
	// D is de op de 3 positie van het bestand
	char ch;
	abc.seekg(3);
	abc >> ch;
	cout << ch;

	// ik verwacht dat de letter op positie 4+2 wordt geprint dus letter G
	abc.seekg(2, ios::cur);
	abc >> ch;
	cout << ch;

	// Ik verwacht dat de laatste letter wordt gelezen dus letter Z
	// !was een G toen hij abc.seekg(-1,ios::end); was. Dit komt omdat bestand eindigd met een newline
	abc.seekg(-3, ios::end);
	abc >> ch;
	cout << ch;

	// Dus ik verwacht dat het volgende wordt geprint: DGZ
}