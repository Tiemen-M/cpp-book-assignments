// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.7
// Niet generieke afgeleide klasse van template-klasse
#include <iostream>
using namespace std;

namespace vb_7 {
	// declaratie van templates
	template<typename T>
	class Node {
	private:
		T data;
		Node<T>* p;
	public:
		// Constructor
		Node(const T& n = T(), Node<T>* volgende = NULL);
		// Lidfuncties
		T& getData();
		Node<T>*& getVolgende();

		void setVolgende(Node<T>*& p);
	};

	template<typename T>
	class Lijst {
	protected:
		Node<T>* kop;
	public:
		// Constructor
		Lijst();
		// Destructor
		~Lijst();
		// Lidfunctie
		void voegtoe(T x);
	};

	// Klasse Datum
	class Datum {
	private:
		int dag, maand, jaar;
	public:
		Datum(int d = 0, int m = 0, int j = 0);
		void print() const;
		// declareer operator== zodat LijstMetVerwijder::verwijder(..) werkt
		bool operator==(const Datum& d);
	};

	// Declaratie van generieke lijst met verwijder functie
	template<typename N>
	class LijstMetVerwijder : public Lijst<N> {
	public:
		LijstMetVerwijder();
		void verwijder(const N& d);
	};

	// afgeleide klasse
	class DatumLijst : public LijstMetVerwijder<Datum> {
	public:
		DatumLijst();
		void print() const;
	};

	// afgeleide klasse om een intlijst te printen
	class Getal {
	private:
		int waarde;
	public:
		Getal(int waarde);
		void print() const;
		bool operator==(const Getal& rechts) const;
	};
	
	class GetalLijst : public LijstMetVerwijder<Getal> {
	public:
		GetalLijst();
		void print() const;
	};
}

using namespace vb_7;

void main_vb_7() {
	DatumLijst dlijst;
	dlijst.voegtoe(Datum(31, 1, 1950));
	dlijst.voegtoe(Datum(19, 12, 1897));
	dlijst.voegtoe(Datum(10, 10, 2020));
	dlijst.verwijder(Datum(19, 12, 1897));
	dlijst.print();

	// test LijstMetVerwijder
	GetalLijst v;
	for (int i = 1; i <= 10; i++)
		v.voegtoe(Getal(i));
	v.verwijder(5);
	v.verwijder(2);
	v.print();
	

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

// Implementatie afgeleide klasse DatumLijst
DatumLijst::DatumLijst() 
	: LijstMetVerwijder<Datum>()  {
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
	Node<N>* pos, *prev = NULL;
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