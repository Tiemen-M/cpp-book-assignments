// Created by Tiemen Molenaar in 2023
// Voorbeeld 14.7 Binair predikaat en sort
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

namespace vb_7 {
	class Persoon {
	private:
		string naam;
		int nummer;
		double salaris;
	public:
		Persoon(const string& n = "", int nr = 0, double sal = 0.0)
			: naam(n), nummer(nr), salaris(sal) {
		}

		string getNaam() const {
			return naam;
		}

		int getNummer() const {
			return nummer;
		}

		double getSalaris() const {
			return salaris;
		}
	};

	// print functie voor for_each
	void print(const Persoon& p) {
		cout << p.getNummer() << ". "
			<< p.getNaam() << ", "
			<< p.getSalaris() << endl;
	}

	// Binair predikaat
	bool vergelijkSalaris(const Persoon& p1, const Persoon& p2) {
		return p1.getSalaris() < p2.getSalaris();
	}
}

using namespace vb_7;

void main_vb_7() {
	vector<Persoon> v; 
	v.push_back(Persoon("Adam", 1, 2000.0));
	v.push_back(Persoon("Noa", 2, 1800.0));
	v.push_back(Persoon("Eva", 3, 2300.0));
	v.push_back(Persoon("Zoe", 4, 1900.0));

	cout << "Voor het sorteren:" << endl;
	for_each(v.begin(), v.end(), print);

	sort(v.begin(), v.end(), vergelijkSalaris);

	cout << "Na sorteren op salaris:" << endl;
	for_each(v.begin(), v.end(), print);
}