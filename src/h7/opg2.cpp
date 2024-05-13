// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>
#include <vector>

using namespace std;

string voegsamen(const vector<string>& v);

void main_opg_2() {
	string arr[] = { "aap","beer","cobra" };
	vector<string> vs(arr, arr + sizeof(arr) / sizeof(string));
	cout << voegsamen(vs) << ".";
}

string voegsamen(const vector<string>& v) {
	string samenvoeging = "";
	vector<string>::const_iterator pos, eind = v.end();;

	for (pos = v.begin(); pos != eind; pos++) {
		samenvoeging += *pos;
		if (pos != eind - 1)
			samenvoeging += "-";
	}

	return samenvoeging;
}
