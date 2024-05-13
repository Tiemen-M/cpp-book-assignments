// Created by Tiemen Molenaar in 2023
#include <iostream>

using namespace std;

int vb2_13main();
void vb2_15main();
void vb2_22main();
void vrg2_12_1main();

void overflow() {
	int i = 2147483647;
	cout << "i = " << i << endl;
	cout << "i + 1 = " << ++i << endl;
}

// vraag maandsalaris en bereken jaar salaris
void opgave1(bool bereken_vakantie_geld) {
	const char AANTAL_MAANDEN_PER_JAAR = 12;
	const float VAKANTIEGELD_PERCENTAGE = 0.08F;
	float maandsalaris, jaarsalaris;

	cout << "Voer de maandsalaris in:" << endl;
	cin >> maandsalaris;
	cin.get();

	jaarsalaris = maandsalaris * AANTAL_MAANDEN_PER_JAAR;
	if (bereken_vakantie_geld)
		jaarsalaris *= 1 + VAKANTIEGELD_PERCENTAGE;
	cout << "Het jaar salaris is " << jaarsalaris << " Euro" 
		<< " (" 
		<< ((bereken_vakantie_geld) ? "inclusief" : "exclusief") 
		<< " vakantie geld)" << endl;
}

void opgave3() {
	
}

int main() {
	//opgave1(false);
	opgave1(true);
	//overflow();
	//vrg2_12_1main();
	//vb2_22main();
	//vb2_15main();
	// vb2_13main();
	return 0;
}