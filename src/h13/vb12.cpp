// Created by Tiemen Molenaar in 2023
// Vorbeeld 13.12 Queue
#include <queue>
#include <iostream>
using namespace std;

void main_vb_12() {
	queue<int> q;
	q.push(100);
	q.push(200);
	q.push(300);

	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}
}