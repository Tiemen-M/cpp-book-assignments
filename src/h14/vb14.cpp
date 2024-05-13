// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.14 Whitespace niet overslaan
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void main_vb_14() {
	ifstream in("C:\\Users\\Tiemen Molenaar\\Documents\\dos\\PX3\\AUTOEXEC.BAT");
	in >> noskipws;

	copy(istream_iterator<char>(in), istream_iterator<char>(), ostream_iterator<char>(cout));
	in.close();
}