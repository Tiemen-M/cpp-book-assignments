// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 16.14.1 : print eigen broncode naar scherm
#include <iostream>
#include <fstream>
using namespace std;

void main_opg_1() {
	ifstream("opg1.cpp") >> cout.rdbuf();
}