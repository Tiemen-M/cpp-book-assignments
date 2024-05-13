// Created by Tiemen Molenaar in 2023
// UIterking vraag 13.10.9
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

void main_vr_9() {
	stack<int> s;
	
	// Doe getallen van 1 tot 100 op de stack
	for (int i = 1; i <= 100; i++)
		s.push(i);

	// verplaats de getallen vanaf de stack naar de queue
	queue<int> q;
	while (!s.empty()) {
		q.push(s.top());
		s.pop();
	}

	// print de inhoud van de queue
	while (!q.empty()) {
		cout << q.front() << endl;
		q.pop();
	}

	// ik verwacht dat hij begint met 100 te printen en dan gaat hij naar beneden.
	// omdat (stack) LIFO + (queue) FIFO = LIFO
}