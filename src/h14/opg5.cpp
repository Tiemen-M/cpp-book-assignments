// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 14.12.5
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

namespace opg_5 {
	template<typename InputIterator>
	bool controleerHaakjes(InputIterator first, InputIterator last) {
		stack<char> s;
		for (InputIterator pos = first; pos != last; ++pos) {
			switch (*pos) {
				// Voeg alle openings haakjes toe aan de stack
			case '{':
			case '[':
			case '(':
				s.push(*pos);
				break;
				// Worden de haakjes goed gesloten?
			case '}':
				if (s.empty() || s.top() != '{')
					return false;
				s.pop();
				break;
			case ']':
				if (s.empty() || s.top() != '[')
					return false;
				s.pop();
				break;
			case ')':
				if (s.empty() || s.top() != '(')
					return false;
				s.pop();
				break;
			}
		}
		// als de stack leeg is zijn alle haakjes geloten
		return s.empty();
	}

	void checkIt(const string& in) {
		bool good = controleerHaakjes(in.begin(), in.end());
		cout << "Haakjes zijn " << (good ? "juist" : "onjuist") << " in " << in << endl;
	}
}

using namespace opg_5;

void main_opg_5() {
	vector<string> test;
	test.push_back(string("{ad(ac)([(()a)d[(a){b}]]r)a}"));
	test.push_back(string("ad(ac)([(()a)d[(a){b}]]r)a}"));
	test.push_back(string("{ad(ac) "));
	test.push_back(string("{ad(ac] }"));
	for_each(test.begin(), test.end(), checkIt);

	// Test eigen source code
	ifstream in("opg5.cpp");
	bool sourcecode = controleerHaakjes(istream_iterator<char>(in), istream_iterator<char>());
	cout << "De haakjes zijn in de source code van dit programma " << (sourcecode ? "goed" : "fout") << " gezet." << endl;
	in.close();
	// het algoritme houd geen rekening dat soms de haakjes niet gelden als haakje!

	in = ifstream("opg1.cpp");
	sourcecode = controleerHaakjes(istream_iterator<char>(in), istream_iterator<char>());
	cout << "De haakjes zijn in de source code van opg1.cpp " << (sourcecode ? "goed" : "fout") << " gezet." << endl;
	in.close();
}