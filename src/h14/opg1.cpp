// Created by Tiemen Molenaar in 2023
// UItwerking opgave 14.12.1
// Doel: Eigen broncode printen
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

void main_opg_1() {
	ifstream in("opg1.cpp");
	in >> noskipws;
	copy(istream_iterator<char>(in), istream_iterator<char>(), ostream_iterator<char>(cout));
	in.close();
}