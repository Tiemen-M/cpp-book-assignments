// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.7 N.B.: Dit programma werkt niet wegens ambiguïteit (gefixt)
#include <string>
#include <iostream>
using namespace std;

#define VERHELP_AMBUGÏTEIT 1

namespace vb_7 {
	class Moeder {
	protected:
		string identiteit;
	public:
		Moeder() : identiteit("Ik ben de moeder") {}
		void spreek() const { cout << identiteit << endl; }
	};

	class Vader {
	protected:
		string identiteit;
	public:
		Vader() : identiteit("Ik ben de vader") {}
		void spreek() const { cout << identiteit << endl; }
	};

	class Kind : public Moeder, public Vader {
#if VERHELP_AMBUGÏTEIT == 1
	private:
		string identiteit;
	public:
		void spreek()  const {
			cout << "Mijn moeder zegt: " << Moeder::identiteit << endl;
			cout << "Mijn vader zegt: ";
			this->Vader::spreek();
			cout << "Ik als hun kind zeg: ";
			cout << identiteit << endl;
		}
#endif
	public:
		Kind() : identiteit("En ik ben hun kind") {}
	};
}

using namespace vb_7;

void main_vb_7() {
	Vader pa;
	Moeder ma;
	Kind k;

	pa.spreek();
	ma.spreek();
	k.spreek();
}