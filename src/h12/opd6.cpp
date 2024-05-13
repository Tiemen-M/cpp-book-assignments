// Created by Tiemen Molenaar in 2023
// Opdracht 6 double linked list
#include <iostream>
#include <iomanip>
using namespace std;

namespace opd_6 {
	class DNode {
		friend class DLijst;
		friend class DLijstIterator;
	private:
		DNode* vorige;
		DNode* volgende;
		int waarde;
	public:
		DNode(DNode* vorige, DNode* volgende, int waarde);
	};

	class DLijst {
	private:
		DNode* eerste, *laatste;
	public:
		typedef DLijstIterator iterator;
		DLijst();
		~DLijst();
		void push(int k);
		void push_back(int k);
		iterator begin();
		iterator end();

	};

	class DLijstIterator {
	private:
		DNode* p;
	public:
		DLijstIterator(DNode* p = NULL);
		DLijstIterator& operator++();
		DLijstIterator& operator--();
		int& operator*();
		bool operator!=(const DLijstIterator&);
	};
}

using namespace opd_6;

// ----------------------- main
void main_opd_6() {
	DLijst l;
	for (int i = 1; i < 100; i*=2)
		l.push(i);

	DLijst::iterator pos;
	for (pos = l.begin(); pos != NULL; ++pos)
		cout << setw(3) << *pos;
	cout << endl;

	for (pos = l.end(); pos != NULL; --pos)
		cout << setw(3) << *pos;
	cout << endl;
}

// Implementatie DNode
DNode::DNode(DNode* vorige, DNode* volgende, int waarde)
	: vorige(vorige), volgende(volgende), waarde(waarde) {
}

// Implementatie DLijst
DLijst::DLijst()
	: eerste(NULL), laatste(NULL) {
}

DLijst::~DLijst() {
	DNode* pos=eerste;
	while (pos != NULL) {
		pos = eerste->volgende;
		delete eerste;
		eerste = pos;
	}
}

void DLijst::push(int k) { // voeg aan het einde toe
	// creëer nieuwe node
	DNode* node = new DNode(laatste, NULL, k);
	// link de nieuwe node aan de achterste node
	if(laatste != NULL)
		laatste->volgende = node;
	// laat de wijzer nu naar de nieuw laatste node wijzen
	laatste = node;
	// als de eerste node wijzer nog niet naar een node wijst wijs naar die node
	if (eerste == NULL)
		eerste = node;
}

void DLijst::push_back(int k) { // voeg aan het begin toe
	// Creeëer nieuwe node
	DNode* node = new DNode(NULL, eerste, k);
	// Link nieuwe node met voorste node
	if(eerste != NULL)
		eerste->vorige = node;
	// laat de wijzer naar de nieuwe voorste wijzen
	eerste = node;
	// als er geen laatste node is dan wordt dit de laatste ook
	if (laatste == NULL)
		laatste = node;
}

DLijst::iterator DLijst::begin() {
	return eerste;
}

DLijst::iterator DLijst::end() {
	return laatste;
}

// Implementatie DLijstIterator
DLijstIterator::DLijstIterator(DNode* p)
	: p(p) {
}

DLijstIterator& DLijstIterator::operator++() {
	p = p->volgende;
	return *this;
}

DLijstIterator& DLijstIterator::operator--() {
	p = p->vorige;
	return *this;
}

int& DLijstIterator::operator*() {
	return p->waarde;
}

bool DLijstIterator::operator!=(const DLijstIterator& x) {
	return p != x.p;
}