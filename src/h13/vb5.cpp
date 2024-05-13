// Created by Tiemen Molenaar in 2023
// Voorbeeld 13.5 klasse-template
#include <iostream>
#include <string>
using namespace std;

namespace vb_5 {
	template<typename T> class Persoon {
	private:
		string naam;
		T informatie;
	public:
		// constructor met template argument T
		Persoon(const string& naam, const T& info);

		// pre: type T kan met operator<< op scherm worden gezet
		void print() const;
	};
}

using namespace vb_5;

void main_vb_5() {
	Persoon<int> p1("Rutger", 189);
	Persoon<string> p2("Eva", "vrouw van Adam");
	p1.print();
	p2.print();
}

// Implementatie
template<typename T>
Persoon<T>::Persoon(const string& naam, const T& info)
	: naam(naam), informatie(info) {
}

template<typename T>
void Persoon<T>::print() const {
	cout << naam << '\t' << informatie << endl;
}