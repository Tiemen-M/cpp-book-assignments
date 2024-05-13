// Created by Tiemen Molenaar in 2023
// Voorbeeld 11.5 inderecte basisklasse
#include <iostream>
using namespace std;

namespace vb_5 {
	class Veelhoek {
	private:
		int aantalHoeken;
	public:
		Veelhoek(int aantalHoeken)
			: aantalHoeken(aantalHoeken) {}
		void print() const {
			cout << "Aantal hoeken is: " << aantalHoeken << endl;
		}
	};

	class Rechthoek :public Veelhoek {
	private:
		int lengte;
		int breedte;
	public:
		Rechthoek(int lt = 0, int br = 0)
			: Veelhoek(4), lengte(lt), breedte(br) {};
		void print() const {
			cout << "Gegevens van deze rechthoek zijn: " << endl;
			Veelhoek::print();
			cout << "Lengte = " << lengte << endl;
			cout << "Breedte = " << breedte << endl;
		}
	};

	class Vierkant : public Rechthoek {
	public:	
		Vierkant(int zijde)
			: Rechthoek(zijde, zijde) {}
	};
}

using namespace vb_5;

void main_vb_5() {
	Vierkant vierkant(33);
	vierkant.print();
}