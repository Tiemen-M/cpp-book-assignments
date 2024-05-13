// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.7 Lineaire lijst met strings
#include <iostream>
using namespace std;

namespace vb_7 {
	class Node {
	private:
		string naam;
		Node* p;
	public:
		// constructor
		Node(const string& n = "", Node* volgende = NULL)
			: naam(n), p(volgende) {
		}
		// get functies
		string& getNaam() {
			return naam;
		}
		Node*& getVolgende() {
			return p;
		}
	};
}

using namespace vb_7;

void main_vb_7() {
	// Begin met een lege lijst
	Node* kop = NULL;

	// Voeg er drie Nodes aan toe
	kop = new Node("cecile", kop);
	kop = new Node("Babi", kop);
	kop = new Node("Anne", kop);

	// Laat nu de namen zien
	Node* wijzer = kop;
	while (wijzer != NULL) {
		cout << wijzer->getNaam() << endl;
		wijzer = wijzer->getVolgende();
	}
}