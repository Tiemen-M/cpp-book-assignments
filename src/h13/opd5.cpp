// Created by Tiemen Molenaar in 2023
// Uitwerking opdracht 13.11.5 decoderen van bericht
#include <iostream>
#include <iomanip>
#include <stack>
#include <deque>
#include <queue>
#include <string>
using namespace std;

namespace opd_5 {
	string decodeer(string::iterator first, string::iterator last) {
		// fase A
		queue<char> q;
		stack<char> s;
		bool inQueue = true;
		for (string::iterator i = first; i != last; ++i) {
			if (inQueue) {
				q.push(*i);
			}
			else {
				s.push(*i);
			}
			inQueue = !inQueue;
		}
		while (!s.empty()) {
			q.push(s.top());
			s.pop();
		}

		// fase B
		s = stack<char>();
		string result;
		while (!q.empty()) {
			char i = q.front();
			q.pop();
			switch (i) {
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
			case 'y':
				while (!s.empty()) {
					result += s.top();
					s.pop();
				}
				result += i;
				break;
			default:
				s.push(i);
				break;
			}
		}
		while (!s.empty()) {
			result += s.top();
			s.pop();
		}

		return result;
	}
}

using namespace opd_5;
namespace opd_4 {
	string codeer(string::iterator first, string::iterator last);
}
using namespace opd_4;

void main_opd_5() {
	string bericht = "rakmoioxrapwnti wm usonri ltlree-nmdaalxe";

	cout << decodeer(bericht.begin(), bericht.end()) << endl;

	string bericht2 = "Minecraft is de beste video spel ooit gecreerd!";
	cout << setw(20) << left << "Plain text:" << bericht2 << endl;
	string bericht3 = codeer(bericht2.begin(), bericht2.end());
	cout << setw(20) << left << "cijfer text:" << bericht3 << endl;
	string bericht4 = decodeer(bericht3.begin(), bericht3.end());
	cout << setw(20) << left << "decoded text:" << bericht4 << endl;
}