// Created by Tiemen Molenaar in 2023
// Uiterking opdracht 13.11.2
#include <iostream>
#include "vb6.h"
using namespace std;
using namespace vb_6;

namespace opd_2 {
	template<typename T>
	class LijstIterator {
	private:
		Node<T>* p;
	public:
		LijstIterator(Node<T>* init = NULL)
			: p(init) {
		}
		T operator*() {
			return p->getData();
		}
		LijstIterator<T>& operator++() {
			p = p->getVolgende();
			return *this;
		}
		bool operator!=(const LijstIterator<T>& rechts) {
			return p != rechts.p;
		}
	};

	template<typename T>
	class LijstMetIterator : public Lijst<T> {
	public:
		LijstMetIterator()
			: Lijst<T>() {
		}
		typedef LijstIterator<T> iterator;

		iterator begin() {
			return iterator(Lijst<T>::kop);
		}

		iterator end() {
			return iterator();
		}
	};
}

using namespace opd_2;

void main_opd_2() {
	LijstMetIterator<int> l;
	for (int i = 0; i < 10; i++)
		l.voegtoe(i);

	LijstMetIterator<int>::iterator pos, eind=l.end();
	for (pos = l.begin(); pos != eind; ++pos)
		cout << *pos << endl;
}