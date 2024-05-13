// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.1 Deel 1: dire klassen met een print()-functie
#include <iostream>
using namespace std;

namespace vb_1 {
	class Persoon {
	private:
		string naam;
	public:
		Persoon();
		string getNaam() const;
		virtual void print() const;
	};

	// Afgeleide klasse van persoon
	class Student : public Persoon {
	private:
		string studie;
	public:
		Student();
		void print() const;
	};

	// Nog een afgeleide klasse van Persoon
	class Werknemer : public Persoon {
	private:
		string afdeling;
	public:
		Werknemer();
		void print() const;
	};
}

using namespace vb_1;

void main_vb_1() {
	Persoon* p, * s, * w;

	cout << "Invoer:" << endl;
	p = new Persoon;
	s = new Student;
	w = new Werknemer;

	cout << "Uitvoer:" << endl;
	p->print();
	s->print();
	w->print();
}

Persoon::Persoon() {
	cout << "Voer naam in: ";
	cin >> naam;
}

string Persoon::getNaam() const {
	return naam;
}

Student::Student() {
	cout << "Welke studie?: ";
	cin >> studie;
}

Werknemer::Werknemer() {
	cout << "Voer afdeling in: ";
	cin >> afdeling;
}

void Persoon::print() const {
	cout << "Deze persoon heet: " << naam << endl;
}

void Student::print() const {
	cout << getNaam() << " studeert " << studie << endl;
}

void Werknemer::print() const {
	cout << getNaam() << " werkt op afdeling " << afdeling << endl;
}