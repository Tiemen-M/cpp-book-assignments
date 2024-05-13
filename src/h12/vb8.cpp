// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.8 Klassen voor lineaire lijst met getallen
#include <iostream>
using namespace std;

namespace vb_8 {
	class IntNode {
	private:
		int x;
		IntNode* p;
	public:
		// Constructor
		IntNode(int n = 0, IntNode* volgende = NULL)
			: x(n), p(volgende) {
		}
		friend class Lijst;
	};

	class Lijst {
	private:
		IntNode* kop;
	public:
		Lijst()
			: kop(NULL) {
		}

		void voegtoe(int x) {
			kop = new IntNode(x, kop);
		}

		void print() {
			IntNode* wijzer = kop;
			while (wijzer != NULL) {
				cout << wijzer->x << endl;
				wijzer = wijzer->p;
			}
		}
	};
}

using namespace vb_8;

void main_vb_8() {
	// Begin met een lege lijst
	Lijst lijst;

	// Voeg er drie Nodes aan toe
	lijst.voegtoe(1);
	lijst.voegtoe(2);
	lijst.voegtoe(3);

	// Toon de inhoud van de lijst
	lijst.print();
}