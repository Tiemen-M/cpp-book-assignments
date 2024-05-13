// Created by Tiemen Molenaar in 2023
// UItwerking opdracht 13.11.4 codeer bericht
#include <iostream>
#include <stack>
#include <deque>
#include <string>
using namespace std;

namespace opd_4 {
	string codeer(string::iterator first, string::iterator last) {
		// fase A
		stack<char> s;
		deque<char> d;
		string::iterator wijzer = first;
		while (wijzer != last) {
			switch (*wijzer) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				while (!s.empty()) {
					d.push_back(s.top());
					s.pop();
				}
				d.push_back(*wijzer);
				break;
			default:
				s.push(*wijzer);
				break;
			}
			++wijzer;
		}
		while (!s.empty()) {
			d.push_back(s.top());
			s.pop();
		}

		// fase B
		string result;
		bool front = true;
		while (!d.empty()) {
			if (front) {
				result += d.front();
				d.pop_front();
			}
			else {
				result += d.back();
				d.pop_back();
			}
			front = !front;
		}

		return result;
	}
}

using namespace opd_4;

void main_opd_4() {
	string text = "groningen";
	string::iterator begin = text.begin(), end = text.end();

	cout << codeer(begin,end) << endl;
}