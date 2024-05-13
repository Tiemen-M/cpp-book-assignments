// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.6 Template voor een lineaire lijst
#include <iostream>
using namespace std;

#include "vb6.h"
using namespace vb_6;

void main_vb_6() {
	Lijst<int> lijst;
	lijst.voegtoe(1);
	lijst.voegtoe(2);
	lijst.voegtoe(3);
	lijst.print();

	Lijst<string> lijst2;
	lijst2.voegtoe("zon");
	lijst2.voegtoe("zee");
	lijst2.print();
}