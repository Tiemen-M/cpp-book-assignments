// Created by Tiemen Molenaar in 2023
// Opdracht 3 histogram
#include <iostream>
#include <iomanip>
#include "opd_1_en_2.h"
using namespace std;
using namespace opd_1_en_2;

namespace opd_3 {
	class Histogram : public Container {
	private:
		int* value;
		int* occurence;
		unsigned set_size;
	public:
		Histogram(unsigned size = 10);
		~Histogram();
		void print_histogram() const;
		void voegtoe(int a);
	};
}

using namespace opd_3;

void main_opd_3() {
	// array maken en vullen met data
	Histogram h(30);
	h.voegtoe(1);
	h.voegtoe(3);
	h.voegtoe(2);
	h.voegtoe(4);
	h.voegtoe(7);
	h.voegtoe(5);
	h.voegtoe(1);
	h.voegtoe(1);
	h.voegtoe(5);
	h.voegtoe(5);
	h.voegtoe(3);
	h.voegtoe(6);

	// print histogram
	h.print();
	h.print_histogram();
}

// Implementatie van Histogram
Histogram::Histogram(unsigned size)
	: Container(size), 
	set_size(0), 
	value(new int[size]), 
	occurence(new int[size]) {
}

Histogram::~Histogram() {
	// Onderzoek of ook de destructor van Container wordt aangeroepen
	delete[] value, occurence;
	cout << "Destructor van Histogram" << endl;
}

void Histogram::voegtoe(int a) {
	// voeg item toe aan container
	if (aantal > maxAantal) {
		cout << "Container is vol!" << endl;
		return;
	}
	Container::voegtoe(a);
	// Zoek of item al is opgenomen in de histogram
	bool found = false;
	for (unsigned index = set_size - 1; index >= 0; index--) {
		if (value[index] == a) { // gevonden, dus occurence bijwerken.
			occurence[index]++;
			found = true;
			break;
		}
		else if (value[index] < a) { // niet gevonden dus het is een nieuwe value
			break;
		}
	}

	// voeg nieuwe item toe als het niet in het histogram staat
	if (!found) {
		// voeg nieuwe item aan het begin
		value[set_size] = a;
		occurence[set_size] = 1;
		set_size++;
		// laat nieuwe item zinken
		for (unsigned index = set_size - 1; index > 1; index--) {
			// aliasen
			int& value_new = value[index];
			int& occurence_new = occurence[index];
			int& value_left = value[index - 1];
			int& occurence_left = occurence[index - 1];
			int value_swap, occurence_swap;
			// nieuwe item naar links schuiven of stoppen als links kleiner is.
			if (value_new < value_left) {
				// swap
				value_swap = value_new;
				occurence_swap = occurence_new;
				value_new = value_left;
				occurence_new = occurence_left;
				value_left = value_swap;
				occurence_left = occurence_swap;
			}
			else break;
		}
	}
}

void Histogram::print_histogram() const {
	for (unsigned index = 0; index < set_size; index++)
		cout
		<< setw(3) << left << value[index]
		<< setfill('x') << setw(occurence[index]) << "x" << endl
		<< setfill(' ');
}