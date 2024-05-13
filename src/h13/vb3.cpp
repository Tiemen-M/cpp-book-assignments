// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.3 Functie-template en selfgedefinieerde klasse
#include <iostream>
#include <string>
using namespace std;

namespace vb_3 {
	class Persoon {
	private:
		string naam;
		int lengte;
	public:
		Persoon(const string& naam, int lengte)
			: naam(naam), lengte(lengte) {}

		bool operator>(const Persoon& p) const {
			return lengte > p.lengte;
		}

		string getNaam() const {
			return naam;
		}

		int getLengte() const {
			return lengte;
		}
	};

	// Prototype functie-template
	//  pre: operator> is gedefinieerd voor type T
	template<typename T> T maximum(T a, T b);
}

using namespace vb_3;

void main_vb_3() {
	Persoon p1("Gerjan", 190),
		p2("Arjan", 188);

	cout << maximum(p1, p2).getNaam() << endl;
}

// Implementatie van de functie-template
template<typename T>
T vb_3::maximum(T a, T b) {
	return a > b ? a : b;
}