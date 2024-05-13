// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 17.11.1 Verbeterde Int klasse met exceptions
#pragma warning( disable : 4290 )
#include <iostream>
#include <cctype>
#include <iomanip>
using namespace std;

namespace opg_1 {
	class IntExceptie;
	class TeGroot;
	class TeKlein;
	class DeelDoorNul;
	class OngeldigeWaarde;

	class Int {
	private:
		int value;
	public:
		// lid functies
		Int(int value = 0);
		Int(const char* value) throw(OngeldigeWaarde);
		Int operator+(const Int&) const throw(TeGroot, TeKlein);
		Int operator-(const Int&) const throw(TeGroot, TeKlein);
		Int operator*(const Int&) const throw(TeGroot, TeKlein);
		Int operator/(const Int&) const throw(DeelDoorNul);
		Int& operator=(const Int&);
		operator int() const;
		friend ostream& operator<<(ostream& out, const Int&);
	};

	// exceptie types
	const int MAXINT = numeric_limits<int>::max();
	const int MININT = numeric_limits<int>::min();

	class IntExceptie {
	protected:
		int x, y;
	public:
		IntExceptie(int x = 0, int y = 0)
			: x(x), y(y) {}
		virtual void what() const = 0;
	};

	class TeGroot : public IntExceptie {
	private:
		char bewerking;
	public:
		TeGroot(char bewerking, int x, int y);
		virtual void what() const;
	};

	class TeKlein : public IntExceptie {
	private:
		char bewerking;
	public:
		TeKlein(char bewerking, int x, int y);
		virtual void what() const;
	};

	class DeelDoorNul : public IntExceptie {
	public:
		DeelDoorNul(int x, int y);
		virtual void what() const;
	};

	class OngeldigeWaarde : public IntExceptie {
	private:
		string waarde;
	public:
		OngeldigeWaarde(const string& waarde);
		virtual void what() const;
	};

	struct TestRecord {
		Int a;
		char bewerking;
		Int b;
	};
}
using namespace opg_1;

void main_opg_1() {
	TestRecord test_script[] = {
		// overflow, underflow en delen door null
		{MAXINT,'+',1},
		{MININT,'+',-1},
		{MAXINT,'-',-1},
		{MININT,'-',1},
		{MAXINT,'*',2},
		{MININT,'*',2},
		{1,'/',0},
		// Testen of binnen de grensen alles wel werkt
		{MAXINT,'+',-1},
		{MININT,'+',1},
		{MAXINT,'-',1},
		{MININT,'-',-1},
		{-1,'*',MAXINT},
		{MAXINT,'*',-1},
		{MAXINT,'*',1},
		{MININT,'*',-1},
		{MAXINT,'/',MININT},
		// Gewoon wat einde jaars sommen
		{2023,'+',"1"},
		{"1012",'*',"2"},
		{4048,'/',"2"},
		{"2038",'-',14},
	};
	int size = sizeof(test_script) / sizeof(TestRecord);
	// Test
	Int x,y, uitkomst;
	for (int i = 0; i < size; i++) {
		x = test_script[i].a;
		y = test_script[i].b;
		try {
			switch (test_script[i].bewerking) {
			case '+':
					uitkomst = x + y;
					break;
			case '-':
				uitkomst = x - y;
				break;
			case '*':
				uitkomst = x * y;
				break;
			case '/':
				uitkomst = x / y;
				break;
			}
			cout << x << " " << test_script[i].bewerking << " " << y << " = " << uitkomst << endl;
		}
		catch (IntExceptie& exc) {
			exc.what();
		}
	}
}

// Implementatie klasse Int
Int::Int(int value)
	: value(value) {
}

Int::Int(const char* value) throw(OngeldigeWaarde) {
	const char* p = value;
	do {
		if (!isdigit(*p))
			throw OngeldigeWaarde(value);
	} while (*(++p) != '\0');
	
	Int::value = atoi(value);
}

Int Int::operator+(const Int& right) const throw(TeGroot, TeKlein) {
	const int& a = value, & b = right.value;
	
	// Bovengrens
	if (b > 0 && a > MAXINT - b)
		throw TeGroot('+', a, b);
	// ondergrens
	if (b < 0 && a < MININT - b)
		throw TeKlein('+', a, b);
	
	return Int(a + b);
}

Int Int::operator-(const Int& right) const throw(TeGroot, TeKlein) {
	const int& a = value, & b = right.value;

	// bovengrens
	if (a > 0 && -b > MAXINT - a)
		throw TeGroot('-', a, b);
	// ondergrens
	if (a < 0 && -b < MININT - a)
		throw TeKlein('-', a, b);

	return Int(a - b);
}

Int Int::operator*(const Int& right) const throw(TeGroot, TeKlein) {
	const int& a = value, & b = right.value;

	// bovengrens check
	if (b > 0 && a > (MAXINT / b))
		throw TeGroot('*', a, b);
	// ondergrens check
	if (b > 0 && a < (MININT / b))
		throw TeKlein('*', a, b);

	return Int(a * b);
}

Int Int::operator/(const Int& right) const throw(DeelDoorNul) {
	const int& a = value, & b = right.value;

	// deel door nul check
	if (b == 0)
		throw DeelDoorNul(a,b);

	return Int(a / b);
}

Int& Int::operator=(const Int& right) {
	value = right.value;
	return *this;
}

Int::operator int() const {
	return value;
}

ostream& opg_1::operator<<(ostream& out,const Int& x) {
	return out << x.value;
}

// Implementatie van de exceptie types
TeGroot::TeGroot(char bewerking, int x, int y)
	: IntExceptie(x, y), bewerking(bewerking) {
}

void TeGroot::what() const {
	cerr << "Fout: De bewerking " << x 
		<< ' ' << bewerking << ' ' 
		<< y << " overschrijd bovengrens " << MAXINT << endl;
}

TeKlein::TeKlein(char bewerking, int x, int y)
	: IntExceptie(x, y), bewerking(bewerking) {
}

void TeKlein::what() const {
	cerr << "Fout: De bewerking " << x
		<< ' ' << bewerking << ' '
		<< y << " overschrijd ondergrens " << -MAXINT-1 << endl;
}

DeelDoorNul::DeelDoorNul(int x, int y)
	: IntExceptie(x, y) {
}

void DeelDoorNul::what() const {
	cerr << "Fout: " << x << " kan niet door " << y << " gedeeld worden." << endl;
}

OngeldigeWaarde::OngeldigeWaarde(const string& waarde)
	: IntExceptie(), waarde(waarde) {
}

void OngeldigeWaarde::what() const {
	cerr << "De waarde \"" << waarde << "\" is geen integer." << endl;
}