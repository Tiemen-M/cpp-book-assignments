// Created by Tiemen Molenaar in 2023
// Voorbeeld 15.2 Late binding dynamische binding
#include <iostream>
using namespace std;

namespace vb_2 {
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

using namespace vb_2;

void main_vb_2() {
	Persoon* p = NULL;
	char ch;

	cout << "s = student" << endl;
	cout << "w = werknemer" << endl;
	cout << "s of w ?" << endl;
	cin >> ch;
	switch (ch) {
	case 's':
		p = new Student;
		break;
	case 'w':
		p = new Werknemer;
		break;
	}

	cout << endl;
	if (p != NULL)
		p->print();
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