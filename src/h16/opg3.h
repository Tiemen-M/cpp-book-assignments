// Created by Tiemen Molenaar in 2023
#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
namespace opg_3 {
	// declaratie van templates
	template<typename T>
	class Node {
	private:
		T data;
		Node<T>* p;
	public:
		// Constructor
		Node(const T& n = T(), Node<T>* volgende = NULL);
		// Lidfuncties
		T& getData();
		Node<T>*& getVolgende();

		void setVolgende(Node<T>*& p);
	};

	template<typename T>
	class LijstIterator {
	private:
		Node<T>* p;
	public:
		LijstIterator(Node<T>* p = NULL);
		LijstIterator<T>& operator++();
		T& operator*();
		bool operator!=(const LijstIterator<T>& right);
	};

	template<typename T>
	class Lijst {
	protected:
		Node<T>* kop;
	public:
		// typedef
		typedef LijstIterator<T> iterator;

		// Constructor
		Lijst();
		// Destructor
		~Lijst();
		// Lidfunctie
		void voegtoe(T x);
		LijstIterator<T> begin();
		LijstIterator<T> end();
	};

	// Klasse Datum
	class Datum {
	private:
		int dag, maand, jaar;
	public:
		Datum(int d = 0, int m = 0, int j = 0);
		void print() const;
		// declareer operator== zodat LijstMetVerwijder::verwijder(..) werkt
		bool operator==(const Datum& d);
		// voor streams
		friend ostream& operator<<(ostream& uit, const Datum& d);
		friend istream& operator>>(istream& in, Datum& d);
	};

	// Declaratie van generieke lijst met verwijder functie
	template<typename N>
	class LijstMetVerwijder : public Lijst<N> {
	public:
		LijstMetVerwijder();
		void verwijder(const N& d);
	};

	// afgeleide klasse
	class DatumLijst : public LijstMetVerwijder<Datum> {
	public:
		DatumLijst();
		void print() const;
	};

	// afgeleide klasse om een intlijst te printen
	class Getal {
	private:
		int waarde;
	public:
		Getal(int waarde);
		void print() const;
		bool operator==(const Getal& rechts) const;
	};

	class GetalLijst : public LijstMetVerwijder<Getal> {
	public:
		GetalLijst();
		void print() const;
	};
}