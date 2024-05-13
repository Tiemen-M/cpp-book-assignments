// Created by Tiemen Molenaar in 2023
// Uitwerking vraag 14.11.1
#include <iostream>
#include <algorithm>
using namespace std;

void main_vr_1() {
	string s = "Mango";

	copy(s.begin(), s.end(), ostream_iterator<char>(cout, "\n"));
}

/*
vraag 2 welke operatoren moeten voor goed functioneren van een iterator zijn gedefineerd?
	Minimaal moeten de volgende zijn gedefineerd: opertor!=, operator* en operator++
vraag 3 Wat is een input-iterator, output-iterator en een const-iterator?
	Een input-iterator is een type argument uit de standaard library waarbij de iterator
		alleen wordt gebruikt om de elementen in de container of stream te lezen, en de
		elementen worden niet gewijzigd.
	Een output-iterator is een type argument uit standaard library waarbij de iterator
		wordt gebruikt om de elementen te wijzigen, of elementen toe te voegen aan de container
		of stream.
	Een const-iterator is een iterator waarbij de element waar de iterator naar toewijst niet
		gewijzigd kan worden maar wel gelezen.
vraag 4 Wat is een predikaat? Wat is een unair predikaat en wat is een binair predikaat?
	Een pedikaat is een functie die een boolean waarde terug geeft. Als een pedikaat één argument
		verwacht dan is het een unair predikaat, als hij twee argumenten verwacht is het een binair 
		predikaat
vraag 5 Wat is een functie-object?
	Een functie-object is een object van een klasse waar de lidfunctie operator()() {...} is
		gedefinieerd waardoor je het object kan aanroepen alsof het een functie is.
*/