// Created by Tiemen Molenaar in 2023
double discriminant(double a = 1.0, double b = 1.0, double c = 1.) {
	return b * b - 4 * a * c;
}

char alpha_shift(char in) {
	const char BEGIN = 97, END = 123;
	return BEGIN + ((in-BEGIN) + 1) % (END - BEGIN);
}

double macht(double grondgetal, unsigned int exponent) {
	double antwoord=grondgetal;
	while (--exponent > 0)
		antwoord *= grondgetal;
	return antwoord;
}