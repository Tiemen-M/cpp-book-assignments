// Created by Tiemen Molenaar in 2023
// Vraag 2 : vroege vs late binding
#include <iostream>
using namespace std;

namespace vr_2 {
	class Super_vroeg {
	private:
		string bericht;
	public:
		Super_vroeg()
			: bericht("basis klasse Vroege binding") {
		}
		void print() const {
			cout << bericht << endl;
		}
	};

	class Sub1_vroeg : public Super_vroeg {
	private:
		string bericht2;
	public:
		Sub1_vroeg() : Super_vroeg(), bericht2("sub1 klasse vroege binding") {
		}
		void print() const {
			Super_vroeg::print();
			cout << bericht2 << endl;
		}
	};

	class Sub2_vroeg : public Super_vroeg {
	private:
		string bericht2;
	public:
		Sub2_vroeg() : Super_vroeg(), bericht2("sub2 klasse vroege binding") {
		}
		void print() const {
			Super_vroeg::print();
			cout << bericht2 << endl;
		}
	};

	class Super_laat {
	private:
		string bericht;
	public:
		Super_laat()
			: bericht("basis klasse late binding") {
		}
		virtual void print() const {
			cout << bericht << endl;
		}
	};

	class Sub1_laat : public Super_laat {
	private:
		string bericht2;
	public:
		Sub1_laat() : Super_laat(), bericht2("sub1 klasse late binding") {
		}
		void print() const {
			Super_laat::print();
			cout << bericht2 << endl;
		}
	};

	class Sub2_laat : public Super_laat {
	private:
		string bericht2;
	public:
		Sub2_laat() : Super_laat(), bericht2("sub2 klasse late binding") {
		}
		void print() const {
			Super_laat::print();
			cout << bericht2 << endl;
		}
	};
}

using namespace vr_2;

void main_vr_2() {
	cout << "Vroege bindning:" << endl;
	Super_vroeg vr1;
	vr1.print();

	Sub1_vroeg vr2;
	vr2.print();

	Sub2_vroeg vr3;
	vr3.print();

	cout << "Late binding:" << endl;
	Super_laat* lt[] = { new Super_laat, new Sub1_laat, new Sub2_laat};
	int length = sizeof(lt) / sizeof(Super_laat*);
	for (int i = 0; i < length; ++i) {
		lt[i]->print();
		delete lt[i];
	}
}