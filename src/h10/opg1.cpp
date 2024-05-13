// Created by Tiemen Molenaar in 2023
// opgave 1
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

namespace opg_1 {
	class Tijd {
	private:
		int uren, minuten, seconden;

		// telt twee tijden bij elkaar op
		void tel_op_tijden(
			int& u, int& m, int& s,
			const int& u_add, const int& m_add, const int& s_add) const {
			// seconden
			s += s_add;
			m += s / 60;
			s %= 60;

			// minuten
			m += m_add;
			u += m / 60;
			m %= 60;

			// uren
			u += u_add;
		}
	public:
		// default-constructor
		explicit Tijd(int uren = 0, int minuten = 0, int seconden = 0) :
			uren(uren), minuten(minuten), seconden(seconden) {}

		// om tijd object te printen als string
		string toString() const {
			ostringstream os;
			os << setw(4) << setfill('0') << uren
				<< ":" << setw(2) << minuten
				<< ":" << setw(2) << seconden;
			return os.str();
		}
		// om tijd object in een tream te printen
		friend ostream& operator<<(ostream& uit, Tijd tijd) {
			return uit << tijd.toString();
		}

		// binair +
		Tijd operator+(const Tijd& rechts) const {
			int u = uren, m = minuten , s = seconden;
			
			tel_op_tijden(u, m, s, rechts.uren, rechts.minuten, rechts.seconden);
			
			return Tijd(u, m, s);
		}

		Tijd operator+(int s_in) const {
			const int
				MINUUT_IN_SECONDEN = 60,
				UUR_IN_SECONDEN = 60 * 60;

			int u = uren, m = minuten, s = seconden;

			int to_u = s_in / UUR_IN_SECONDEN;
			int to_m = s_in / MINUUT_IN_SECONDEN;
			int to_s = s_in % 60;

			tel_op_tijden(u, m, s, to_u, to_m, to_s);

			return Tijd(u, m, s);
		}

		// +=
		Tijd& operator+=(const Tijd& r) {
			tel_op_tijden(uren, minuten, seconden, r.uren, r.minuten, r.seconden);
			return *this;
		}

	};
}

using namespace opg_1;

void main_opg_1() {
	Tijd t1(1, 23, 10), t2(12, 0, 0), t3;

	cout << setw(20) << left << "t1 : " << t1 << endl;
	cout << setw(20) << left << "t2 : " << t2 << endl;

	t3 = t1 + t2;
	cout << setw(20) << left << "t3 = t1 + t2 : " << t3 << endl;

	t1 += t2;
	cout << setw(20) << left << "t1 += t2 : " << t1 << endl;

	t1 = t2 + 172;
	cout << setw(20) << left << "t1 = t2 + 172 : " << t1 << endl;
}