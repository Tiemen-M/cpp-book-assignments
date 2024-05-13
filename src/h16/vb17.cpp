// Created by Tiemen Molenaar in 2023
// Voorbeeld 16.17 Kopiëren van bestand naar scherm
#include <iostream>
#include <fstream>
using namespace std;

void main_vb_17() {
	ifstream in("bestand2.txt", ios::binary);
	cout << "Hier komt de inhoud van bestand2.txt:" << endl;
	//cout << in.rdbuf();
	in >> cout.rdbuf();
}