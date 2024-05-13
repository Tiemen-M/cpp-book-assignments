// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <string>

using namespace std;

class Rechthoek {
private:
	int breedte;
	int hoogte;
private:
	void line(unsigned, string) const;
public:
	Rechthoek(int, int);
	void print() const;
};

void main_opg_1() {
	Rechthoek r1(5, 3);
	r1.print();
	Rechthoek r2(15, 5);
	r2.print();
}

Rechthoek::Rechthoek(int breedte = 0, int hoogte = 0) :
	breedte(breedte), hoogte(hoogte) {}

void Rechthoek::line(unsigned lengte,string element = "x  ") const {
	for (; lengte > 0; lengte--)
		cout << element;
}

void Rechthoek::print() const {
	line(breedte);
	cout << endl;
	for (int i = 0; i < hoogte - 2; i++) {
		cout << "x  ";
		line(breedte - 2, "   ");
		cout << "x  " << endl;
	}
	line(breedte);
	cout << endl;
}