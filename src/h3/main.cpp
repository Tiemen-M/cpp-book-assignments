// Created by Tiemen Molenaar in 2023
﻿#include <iostream>
#include <iomanip>

using namespace std;

void main1();
void main2();
void alfabet();
void opdracht1();
void opdracht2();
void opdracht3();
void opdracht4();
void opdracht5();
void opdracht6();

int main() {
	opdracht6();
	//opdracht1();
	//if(-1)
	//	cout << "waar" << endl;
	//alfabet();
	//main2();
	return 0;
}

void main1() {
	cout << setfill(' ');
	cout << oct;
	for (int i = 1; i <= 5; i++) {
		if (i % 2)
			cout << left;
		else
			cout << right;
		cout << setw(10) << i;
		cout << setw(30) << i * i << endl;
	}
	cout << setfill(' ');
}

void main2() {
	double i = 6. / 9.;
	cout << i << endl;
	cout << setprecision(3);
	cout << i << endl;
	cout << showpoint;
	cout << i << endl;
	cout << fixed;
	cout << i << endl;

	bool q = true;
	cout << q << endl;
	cout << boolalpha;
	cout << q << endl;
}

void alfabet() {
	for (char c = 'a'; c <= 'z'; c++)
		cout << setw(2) << c;
	cout << endl;
}

void opdracht1() {
	cout << left;
	cout << setw(5) << "x" << setw(5) << "x^2" << setw(5) << "x^3" << endl;
	for (int number = 1; number <= 10; number++) {
		cout << setw(5) << number << setw(5) << number*number << setw(5) << number*number*number << endl;
	}
}

void opdracht2() {
	cout << left;
	for (int c = 1; c <= 10; c++) {
		cout << setw(3) << c 
			<< setw(3) << "*" 
			<< setw(3) << 13 
			<< setw(3) << "=" 
			<< setw(3) << (c * 13) 
			<< endl;
	}
}

void opdracht3() {
	for (int c = 1; c <= 10; c++) {
		cout << setw(2) << c 
			<< "/7="
			<< setw(10) << showpoint << setprecision(10) << static_cast<double>(c) / 7
			<< endl;
	}
}

void opdracht4() {
	int sum = 0;
	for (int i = 2; i <= 24; i++)
		if (i % 2 == 0) {
			cout << i << endl;
			sum += i;
		}
	
	cout << "som = " << sum << endl;
}

void opdracht5() {
	for (double prijs = 10.00; prijs <= 12.50; prijs += 0.25)
		cout << setprecision(2) << fixed << prijs << endl;
}

double power(double x, int p) {
	double old_x = x;
	for (int i = 1; i < p; i++) {
		x *= old_x;
	}
	return x;
}

void opdracht6() {
	cout << left << fixed;
	cout << setw(15) << "x" << setw(15) << "kwadraat" << setw(15) << "derde macht" << endl;
	for (double x = 1.0; x <= 7.50; x += 0.50) {
		cout << setw(15) << setprecision(2) << x
			<< setw(15) << setprecision(2) << power(x, 2)
			<< setw(15) << setprecision(2) << power(x,3) << endl;
	}
}