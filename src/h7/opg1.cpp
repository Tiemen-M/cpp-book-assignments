// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
using namespace std;

void vervang(string& s, char bron, char doel);
void vervang2(string& s, char bron, char doel);

void main_opg_1() {
	string str;
	
	str = "staal";
	vervang(str, 'a', 'e');
	cout << str << endl;

	str = "staal";
	vervang2(str, 'a', 'e');
	cout << str << endl;
}

void vervang(string& s, char bron, char doel) {
	for (string::iterator pos = s.begin(); pos != s.end(); pos++) {
		if (*pos == bron)
			*pos = doel;
	}
}

void vervang2(string& s, char bron, char doel) {
	string::size_type pos = 0;
	while ((pos = s.find(bron, pos)) != string::npos)
		s.replace(pos, 1,1,doel);
}