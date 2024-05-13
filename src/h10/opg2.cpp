// Created by Tiemen Molenaar in 2023
// opgave 2 - verbeterde versie van int
#include <iostream>
#include <limits>
using namespace std;

namespace opg_2 {
	class Integer {
	private:
		int integer;

		void my_overflow_error(double value) const {
			if (value > static_cast<double>(INT_MAX) || value < static_cast<double>(INT_MIN)) {
				cout << "Integer overflow!" << endl;
				exit(1);
			}
		}
	public:
		Integer(int i = 0) : integer(i) {
			cout << "My Integer constructor is ussed." << endl;
		}
		// operator functies Integer, Integer
		friend Integer operator+(const Integer& l,const Integer& r) {
			l.my_overflow_error(static_cast<double>(l.integer) + r.integer);
			return Integer(l.integer + r.integer);
		}

		friend Integer operator-(const Integer& l,const Integer& r) {
			l.my_overflow_error(static_cast<double>(l.integer) - r.integer);
			return Integer(l.integer - r.integer);
		}

		friend Integer operator*(const Integer& l, const Integer& r) {
			cout << "My operator*(Integer,Integer) functie is used" << endl;
			l.my_overflow_error(static_cast<double>(l.integer) * r.integer);
			return Integer(l.integer * r.integer);
		}

		friend Integer operator/(const Integer& l, const Integer& r) {
			l.my_overflow_error(static_cast<double>(l.integer) / r.integer);
			return Integer(l.integer / r.integer);
		}

		// operator functies int,Integer
		friend Integer operator+(int l, const Integer& r) {
			r.my_overflow_error(static_cast<double>(l) + r.integer);
			return Integer(l + r.integer);
		}

		friend Integer operator-(int l, const Integer& r) {
			r.my_overflow_error(static_cast<double>(l) - r.integer);
			return Integer(l - r.integer);
		}

		friend Integer operator*(int l, const Integer& r) {
			cout << "My operator*(int,Integer) functie is used" << endl;
			r.my_overflow_error(static_cast<double>(l) * r.integer);
			return Integer(l * r.integer);
		}

		friend Integer operator/(int l, const Integer& r) {
			r.my_overflow_error(static_cast<double>(l) / r.integer);
			return Integer(l / r.integer);
		}

		// zorgt ervoor dat je de functie direct in een stream kan zetten
		friend ostream& operator<<(ostream & l, const Integer & r) {
			return l << r.integer;
		}
	};
}

using namespace opg_2;

void main_opg_2() {
	Integer a = 10, b = 30, c;
	cout << "a=" << a << endl;
	cout << "b=" << b << endl;
	cout << "c=" << c << endl;

	c = a * 10;
	cout << "c=a*10 dus c=" << c << endl;

	c = 10 * a;
	cout << "c=10*a dus c=" << c << endl;

	c = INT_MAX + a;
	cout << "c = INT_MAX + a= dus c=" << c << endl;
}