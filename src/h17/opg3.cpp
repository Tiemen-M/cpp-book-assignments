// Created by Tiemen Molenaar in 2023
// Uitwerking opgave 17.11.3
// Doel: Gebruikerinvoer met excepties. Invoeren van postcodes
#pragma warning(disable : 4290)
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <string>
using namespace std;

namespace opg_3 {
	struct Postcode {
		string code;
	};
	class PostcodeException {
	protected:
		int pos;
	public:
		PostcodeException(int pos = 0) : pos(pos) {}
		virtual void what(int opschuiving = 0) = 0;
	protected:
		void spaceRight(int opschuiving) {
			for (int i = 0; i < opschuiving; ++i)
				cout << ' ';
		}
		void error_at() {
			spaceRight(pos - 1);
			cout << '^' << endl;
		}
	};

	class VerwachtGetal : public PostcodeException {
	public:
		VerwachtGetal(int pos) : PostcodeException(pos) {}
		virtual void what(int opschuiving) {
			spaceRight(opschuiving);
			PostcodeException::error_at();
			cerr << "Error : Verwacht een cijfer op die plek." << endl;
		}
	};

	class VerwachtSpatie : public PostcodeException {
	public:
		VerwachtSpatie(int pos) : PostcodeException(pos) {}
		virtual void what(int opschuiving) {
			spaceRight(opschuiving);
			PostcodeException::error_at();
			cerr << "Error : Verwacht een spatie op die plek." << endl;
		}
	};

	class VerwachtLetter : public PostcodeException {
	public:
		VerwachtLetter(int pos) : PostcodeException(pos) {}
		virtual void what(int opschuiving) {
			spaceRight(opschuiving);
			PostcodeException::error_at();
			cerr << "Error : Verwacht een hoofd Letter op die plek." << endl;
		}
	};

	class VerwachtInvoer : public PostcodeException {
	public:
		VerwachtInvoer(int pos) : PostcodeException(pos) {}
		virtual void what(int opschuiving) {
			spaceRight(opschuiving);
			PostcodeException::error_at();
			cerr << "Error : Je hebt niets ingevoerd!" << endl;
		}
	};

	class VerwachtEinde : public PostcodeException {
	public:
		VerwachtEinde(int pos) : PostcodeException(pos) {}
		virtual void what(int opschuiving) {
			spaceRight(opschuiving);
			PostcodeException::error_at();
			cerr << "Error : Verwacht geen verdere invoer!" << endl;
		}
	};

	template<typename InsertIterator>
	void EnterPostcode(istream& in, InsertIterator vec) throw(PostcodeException&) {
		ostringstream os;
		istringstream sin;
		string str;
		char ch;

		// Vraag gebruiker om invoer
		getline(in, str);
		sin.str(str);

		sin.seekg(ios::beg);
		// check of gebruiker iets heeft ingevoerd
		if (sin.peek() == EOF)
			throw VerwachtInvoer(1);

		// vier getallen
		for (int i = 0; i < 4; ++i) {
			if (!(sin >> ch) || !isdigit(ch) || isblank(ch))
				throw VerwachtGetal(i + 1);
			os << ch;
		}

		// 1 spatie
		sin >> noskipws;
		sin >> ch;
		if (!isspace(ch))
			throw VerwachtSpatie(5);
		os << ch;
		sin >> skipws;

		// 2 letters
		for (int i = 0; i < 2; ++i) {
			if (!(sin >> ch) || !isupper(ch))
				throw VerwachtLetter(6+i);
			os << ch;
		}

		// check of postcode op tijd eindigd
		if (sin.peek() != EOF)
			throw VerwachtEinde(8);

		// add post code to vector
		*(vec++) = Postcode({ os.str() });
	}
}
using namespace opg_3;

void main_opg_3() {
	vector<Postcode> v;
	string label;

	cout << "Voer drie postcodes in de vorm \"CCCC HH\" (\"C\"=1-9 en \"H\"=A-Z) in:" << endl;
	for(int i = 0; i<3;) {
		// Vraag gebruiker om drie postcode
		try {
			(label = "") += string("Postcode ") += to_string(i) += string(" : ");
			cout << label;
			EnterPostcode(cin, back_inserter(v));
			++i;
		}
		catch (PostcodeException& exc) {
			exc.what(static_cast<int>(label.length()));
		}
	}

	// Print de input terug op scherm
	cout << "Je hebt de volgende postcodes ingetypt:" << endl;
	vector<Postcode>::iterator pos;
	for (pos = v.begin(); pos != v.end(); ++pos) {
		cout << pos->code << endl;
	}
}

