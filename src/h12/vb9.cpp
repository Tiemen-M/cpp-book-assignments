// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.9 Lineaire lijst met iterator
#include <iostream>
using namespace std;

namespace vb_9 {
	class IntNode {
	private:
		int x;
		IntNode* p;
	public:
		// constructor
		IntNode(int n = 0, IntNode* volgende = NULL)
			: x(n), p(volgende) {
		}
		int& getInt() {
			return x;
		}
		IntNode*& getVolgende() {
			return p;
		}
	};

	class LijstIterator {
	private:
		IntNode* wijzer;
	public:
		LijstIterator(IntNode* init = NULL)
			: wijzer(init) {
		}

		int& operator*() const {
			return wijzer->getInt();
		}

		LijstIterator& operator++() {
			wijzer = wijzer->getVolgende();
			return *this;
		}

		bool operator!=(const LijstIterator& liter) const {
			return wijzer != liter.wijzer;
		}
	};

	class Lijst {
	private:
		IntNode* kop;
	public:
		// typedef
		typedef LijstIterator iterator;
		// constructor
		Lijst()
			: kop(NULL) {
		}
		// destructor
		~Lijst() {
			IntNode* wijzer = kop, * pVolgende;
			while (wijzer != NULL) {
				pVolgende = wijzer->getVolgende();
				delete wijzer;
				wijzer = pVolgende;
			}
		}

		void voegtoe(int x) {
			kop = new IntNode(x, kop);
		}

		iterator begin() {
			return iterator(kop);
		}

		iterator end() {
			return iterator();
		}
	};
}

using namespace vb_9;

void main_vb_9() {
	Lijst lijst;
	lijst.voegtoe(1);
	lijst.voegtoe(2);
	lijst.voegtoe(3);

	Lijst::iterator pos,
		einde = lijst.end();

	for (pos = lijst.begin(); pos != einde; ++pos)
		cout << *pos << endl;

	pos = lijst.begin();
	*pos = 44;

	for (pos = lijst.begin(); pos != einde; ++pos)
		cout << *pos << endl;
}