// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>

using namespace std;

void main_7_5() {
	string s("kroonprins");

	string kopieVanS(s);
	s.replace(s.find("k"), 1, "d");
	s.replace(s.find("n"), 1, "m");
	s += "es";

	cout << kopieVanS << " heeft lengte " << kopieVanS.length() << endl;
	cout << s << " heeft lengte " << s.length() << endl;
}