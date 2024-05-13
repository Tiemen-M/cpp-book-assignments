// Created by Tiemen Molenaar in 2023
#pragma once
#include <iostream>
using namespace std;
namespace vb_6 {
	// Template-klassen
	template<typename T>
	class Node {
	private:
		T data;
		Node<T>* p;
	public:
		// Constructor
		Node(const T& n = T(), Node<T>* volgende = NULL)
			: data(n), p(volgende) {
		}

		T& getData() {
			return data;
		}

		Node<T>*& getVolgende() {
			return p;
		}
	};

	template<typename T>
	class Lijst {
	protected:
		Node<T>* kop;
	public:
		// Constructor
		Lijst()
			: kop(NULL) {
		}

		// Destructor
		~Lijst() {
			Node<T>* wijzer = kop, * pVolgende;
			while (wijzer != NULL) {
				pVolgende = wijzer->getVolgende();
				delete wijzer;
				wijzer = pVolgende;
			}

		}

		// Lidfuncties
		void voegtoe(T x) {
			kop = new Node<T>(x, kop);
		}

		void print() const {
			// pre: operator<< is correct gedefinieerd voor type T
			Node<T>* wijzer = kop;
			while (wijzer != NULL) {
				cout << wijzer->getData() << endl;
				wijzer = wijzer->getVolgende();
			}
		}
	};
}