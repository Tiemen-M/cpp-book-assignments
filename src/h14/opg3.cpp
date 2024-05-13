// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 14.12.3
#include <iostream>

using namespace std;

namespace opg_3 {
	template<typename InputIterator, typename OutputIterator>
	OutputIterator kopieer(InputIterator first, InputIterator last, OutputIterator result) {
		for (InputIterator pos = first; pos != last; ++pos) {
			*result = *pos;
			++result;
		}
		return result;
	}
}

using namespace opg_3;

void main_opg_3() {
	string s = "Dit is een test string die naar scherm wordt gekopiëeerd met zelf gemaakte kopieer functie";
	kopieer(s.begin(), s.end(), ostream_iterator<char>(cout));
	cout << endl;
}