// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.4 Algoritme die een Persoon zoekt
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

namespace vb_4 {
	class Persoon {
	private:
		string naam;
		int nummer;
	public:
		Persoon(const string& n = "", int nr = 0)
			: naam(n), nummer(nr) {
		}

		bool operator==(const Persoon& p) {
			return naam == p.naam && nummer == p.nummer;
		}

		bool operator!=(const Persoon& p) {
			return !(*this == p);
		}

		friend ostream& operator<<(ostream& uit, const Persoon& p) {
			return uit << p.nummer << ", " << p.naam;
		}
	};

	template<typename Iterator, typename T>
	Iterator zoek6(Iterator first, Iterator last, const T& waarde) {
		Iterator pos = first;
		while (pos != last && *pos != waarde) ++pos;
		return pos;
	}
}

using namespace vb_4;

void main_vb_4() {
	list<Persoon> lijst;
	Persoon p1("Natasja", 1), p2("olga", 2), p3("Susan", 3);
	lijst.push_back(p1);
	lijst.push_back(p2);
	lijst.push_back(p3);

	Persoon x = p2;
	list<Persoon>::iterator pos = zoek6(lijst.begin(), lijst.end(), x);

	if (pos != lijst.end())
		cout << "Gevonden: " << *pos << endl;
	else
		cout << "Niet gevonden." << endl;

	list<Persoon>::iterator pos2 = find(lijst.begin(), lijst.end(), x);
	if (pos2 != lijst.end())
		cout << "Gevonden: " << *pos2 << endl;
	else
		cout << "Niet gevonden." << endl;
}