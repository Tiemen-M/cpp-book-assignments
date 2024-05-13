// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.13 Deque
#include <deque>
#include <iostream>
using namespace std;

void main_vb_13() {
	deque<int> d;
	d.push_back(100);
	d.push_back(200);
	d.push_front(300);
	d.push_front(400);

	deque<int>::iterator pos, einde = d.end();

	for (pos = d.begin(); pos != einde; ++pos)
		cout << *pos << " ";
	cout << endl;

	d[0] = 500;
	d[1] = 600;

	cout << "Na wijziging:" << endl;
	while (!d.empty()) {
		cout << d.front() << " ";
		d.pop_front();
	}
}