// Created by Tiemen Molenaar in 2023
// Uitwerking vraag 13.10.1
#include <iostream>
using namespace std;

namespace vr_1 {
	template<typename T>
	void wissel(T& a, T& b) {
		T c = a;
		a = b;
		b = c;
	}

	/*
	* vraag 13.10.2
	templates lijkt sterk op de functie zoek en vervang omdat de compiler de opgegeven argumenten van
	een functie aanroep gebruikt om te bepalen welke type de typenames moeten zijn. Vervolgens zoekt
	de compiler in de functie definitie die typenames op en vervang ze met de juiste type zodat de
	functie werkt.

	* vraag 13.10.3
	* Als T de naam is van een tamplate-argument dan is de template prefix het volgende
	template<typename T>
	*/
}

using namespace vr_1;

void main_vr_1() {
	double x = 1.5, y = 2.6;
	cout << "x = " << x << " en y = " << y << endl;
	wissel(x, y);
	cout << "Na wissel: x = " << x << " en y = " << y << endl;

	int i = 1, j = 2;
	cout << "i = " << i << " en j = " << j << endl;
	wissel(i, j);
	cout << "Na wissel: i = " << i << " en j = " << j << endl;

	string s = "een", t = "twee";
	cout << "s = " << s << " en t = " << t << endl;
	wissel(s, t);
	cout << "Na wissel: s = " << s << " en t = " << t << endl;
}