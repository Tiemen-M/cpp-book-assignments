// Created by Tiemen Molenaar in 2023
// Voorbeeld 12.6 Dynamische objecten
#include <iostream>
using namespace std;

namespace vb_6 {
	class Persoon {
	private:
		string naam;
		double salaris;
	public:
		Persoon()
			: naam(""), salaris(0.0) {
		}
		Persoon(const string& naam)
			: naam(naam), salaris(0.0) {
		}
		Persoon(const string& naam, double sal)
			: naam(naam), salaris(sal) {
		}
		void print() const {
			cout << naam << ":" << salaris << endl;
		}
		friend ostream& operator<<(ostream& uit, const Persoon& in) {
			return uit << in.naam << ":" << in.salaris;
		}
	};
}

using namespace vb_6;

void main_vb_6() {
	Persoon* p1, * p2, * p3;
	p1 = new Persoon();
	p2 = new Persoon("Tiemen");
	p3 = new Persoon("Rutger", 5000);
	cout << *p1 << endl;
	cout << *p2 << endl;
	cout << *p3 << endl;
}