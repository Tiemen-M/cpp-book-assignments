// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.8_extra lijst zonder fiend en met een destructor
#include <iostream>
using namespace std;

namespace vb_8_extra {
	class IntNode {
	private:
		int x;
		IntNode* p;
	public:
		// Constructor
		IntNode(int n = 0, IntNode* volgende = NULL)
			: x(n), p(volgende) {
		}
		
		// getter functions
		IntNode*& getNextNode() {
			return p;
		}

		int& getValue() {
			return x;
		}
	};

	class Lijst {
	private:
		IntNode* kop;
	public:
		Lijst()
			: kop(NULL) {
		}

		// destructor
		~Lijst() {
			IntNode* volgende = kop;
			while (kop != NULL) {
				volgende = kop->getNextNode();
				cout << "Knoop met getal " << kop->getValue() << " is vernietigd." << endl;
				delete kop;
				kop = volgende;
			}
		}

		void voegtoe(int x) {
			kop = new IntNode(x, kop);
		}

		void print() {
			IntNode* wijzer = kop;
			while (wijzer != NULL) {
				cout << wijzer->getValue() << endl;
				wijzer = wijzer->getNextNode();
			}
		}
	};
}

using namespace vb_8_extra;

void main_vb_8_extra() {
	// Begin met een lege lijst
	Lijst lijst;

	// Voeg er drie Nodes aan toe
	lijst.voegtoe(1);
	lijst.voegtoe(2);
	lijst.voegtoe(3);

	// Toon de inhoud van de lijst
	lijst.print();
}