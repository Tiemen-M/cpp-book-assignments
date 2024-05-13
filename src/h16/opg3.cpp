// Created by Tiemen Molenaar in 2023
// Uiterking opgave 16.14.3 : lijst Datum objecten naar een bestand schrijven
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;

#include "opg3.h"

using namespace opg_3;

void main_opg_3() {
	DatumLijst dlijst;
	dlijst.voegtoe(Datum(31, 1, 1950));
	dlijst.voegtoe(Datum(19, 12, 1897));
	dlijst.voegtoe(Datum(10, 10, 2020));
	dlijst.voegtoe(Datum(18, 12, 2023));
	
	// copy datums to a file
	ofstream bestand("datums.txt");

	if (!bestand) {
		cerr << "Kan bestand niet openen." << endl;
		exit(1);
	}

	DatumLijst::iterator pos, end = dlijst.end();
	for (pos = dlijst.begin(); pos != end; ++pos) {
		bestand << *pos << endl;
	}
	bestand.close();

	cout << "Bestand successvol gemaakt." << endl;

}

// Implementatie van Node<T>
template<typename T>
Node<T>::Node(const T& n, Node<T>* volgende)
	: data(n), p(volgende) {
}

template<typename T>
T& Node<T>::getData() {
	return data;
}

template<typename T>
Node<T>*& Node<T>::getVolgende() {
	return p;
}

template<typename T>
void Node<T>::setVolgende(Node<T>*& next) {
	p = next;
}

// Implementatie LijstIterator<T>
template<typename T>
LijstIterator<T>::LijstIterator(Node<T>* p) 
	: p(p) {
}

template<typename T>
LijstIterator<T>& LijstIterator<T>::operator++() {
	p = p->getVolgende();
	return *this;
}

template<typename T>
T& LijstIterator<T>::operator*() {
	return p->getData();
}

template<typename T>
bool LijstIterator<T>::operator!=(const LijstIterator<T>& right) {
	return p != right.p;
}

// Implementatie van Lijst<T>
template<typename T>
Lijst<T>::Lijst()
	: kop(NULL) {
}

template<typename T>
Lijst<T>::~Lijst() {
	Node<T>* wijzer = kop, * pVolgende;
	while (wijzer != NULL) {
		pVolgende = wijzer->getVolgende();
		delete wijzer;
		wijzer = pVolgende;
	}
}

template<typename T>
void Lijst<T>::voegtoe(T x) {
	kop = new Node<T>(x, kop);
}

template<typename T>
LijstIterator<T> Lijst<T>::begin() {
	return LijstIterator<T>(kop);
}

template<typename T>
LijstIterator<T> Lijst<T>::end() {
	return LijstIterator<T>();
}

// Implemantatie klasse Datum
Datum::Datum(int d, int m, int j)
	: dag(d), maand(m), jaar(j) {
}

void Datum::print() const {
	cout << dag << '-' << maand << '-' << jaar << endl;
}

bool Datum::operator==(const Datum& d) {
	return dag == d.dag && maand == d.maand && jaar == d.jaar;
}

ostream& opg_3::operator<<(ostream& uit, const Datum& d) {
	return uit << d.dag << '-' << d.maand << '-' << d.jaar;
}

istream& opg_3::operator>>(istream& in, Datum& d) {
	// Get the next datum string
	stringstream sdatum;
	in >> sdatum.rdbuf();

	// seperate the day, month and year from string
	char ch;
	int pos = 0;
	string number[3];
	while (sdatum >> ch) {
		if (ch != '-')
			number[pos] += ch;
		else {
			pos++;
		}
	}

	// put the day, month and year in datum object
	d.dag = stoi(number[0]);
	d.maand = stoi(number[1]);
	d.jaar = stoi(number[2]);

	return in;
}

// Implementatie afgeleide klasse DatumLijst
DatumLijst::DatumLijst()
	: LijstMetVerwijder<Datum>() {
}

void DatumLijst::print() const {
	Node<Datum>* wijzer = LijstMetVerwijder<Datum>::kop;
	while (wijzer != NULL) {
		(wijzer->getData()).print();
		wijzer = wijzer->getVolgende();
	}
}

// Implementatie van LijstMetVerwijder
template<typename N>
LijstMetVerwijder<N>::LijstMetVerwijder()
	: Lijst<N>() {
}

template<typename N>
void LijstMetVerwijder<N>::verwijder(const N& zoekterm) {
	Node<N>* pos, * prev = NULL;
	for (pos = Lijst<N>::kop; pos != NULL; pos = pos->getVolgende()) {
		if (pos->getData() == zoekterm) {
			if (prev == NULL) {
				Lijst<N>::kop = pos->getVolgende();
				delete pos;
			}
			else {
				prev->setVolgende(pos->getVolgende());
				delete pos;
			}
			return;
		}
		prev = pos;
	}
}

// Implementatie van klasse Getal
Getal::Getal(int waarde)
	: waarde(waarde) {

}

void Getal::print() const {
	cout << waarde << endl;
}

bool Getal::operator==(const Getal& rechts) const {
	return waarde == rechts.waarde;
}

// Implementatie van klasse GetalLijst
GetalLijst::GetalLijst()
	: LijstMetVerwijder<Getal>() {
}

void GetalLijst::print() const {
	Node<Getal>* wijzer = kop;
	while (wijzer != NULL) {
		(wijzer->getData()).print();
		wijzer = wijzer->getVolgende();
	}
}