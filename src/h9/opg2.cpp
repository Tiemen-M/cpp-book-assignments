// Created by Tiemen Molenaar in 2023
#include <iostream>
#include <iomanip>

using namespace std;

namespace opg_2 {
	class Tijd {
	private:
		int uren, minuten, seconden;
	public:
		Tijd(int uren = 0, int minuten = 0, int seconden = 0)
			: uren(uren), minuten(minuten), seconden(seconden) {}
		void print() const {
			cout << setw(2) << setfill('0') << uren << ":"
				<< setw(2) << minuten << ":"
				<< setw(2) << seconden << setw(1) << setfill(' ') << endl;
		}
		void plus(const Tijd& obj) {
			seconden += obj.seconden;
			minuten += seconden / 60;
			seconden %= 60;

			minuten += obj.minuten;
			uren += minuten / 60;
			minuten %= 60;

			uren += obj.uren;
		}
	};
}

using namespace opg_2;

void main_opg_2() {
	Tijd t1(10, 30), t2(10, 30, 40), t3;
	cout << setw(15) << left << "t1: ";
	t1.print();
	cout << setw(15) << left << "t2: ";
	t2.print();
	cout << setw(15) << left << "t3: ";
	t3.print();

	cout << setw(15) << left << "t1+t2: ";
	t1.plus(t2);
	t1.print();
}