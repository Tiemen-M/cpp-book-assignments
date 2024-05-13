// Created by Tiemen Molenaar in 2023
// Opgave 13.11.1 klasse template dynamische array
#include <iostream>
#include <sstream>
using namespace std;

namespace opd_1 {
	template<typename T>
	class DynamicArray {
	private:
		unsigned aantal;
		T* array;
	public:
		DynamicArray(unsigned groote = 1);
		DynamicArray(const DynamicArray<T>&);
		~DynamicArray();
		DynamicArray<T>& operator=(const DynamicArray<T>&);
		T& operator[](int k);
	};

	class Test {
	private:
		int a, b;
	public:
		Test(int a=0, int b=0)
			: a(a),b(b) {}
		friend ostream& operator<<(ostream& uit, const Test& in) {
			return uit << "Test(" << in.a << ", " << in.b << ")";
		}
	};
}

using namespace opd_1;

// ------------------------------- Hoofdprogramma
void main_opd_1() {
	// test voor int
	DynamicArray<int> intArr(10);
	for (int i = 0; i < 10; i++)
		intArr[i] = i+1;
	for (int i = 0; i < 10; i++)
		cout << intArr[i] << " ";
	cout << endl;

	// test voor double
	DynamicArray<double> doubleArr(10);
	double j = 0;
	for (int i = 0; i < 10; i++,j+=3.14)
		doubleArr[i] = j;
	for (int i = 0; i < 10; i++)
		cout << doubleArr[i] << " ";
	cout << endl;

	// test voor mijn eigen geschreven test class
	DynamicArray<Test> testArr(10);
	for (int i = 0; i < 10; i++)
		testArr[i] = Test(i,i+1);
	for (int i = 0; i < 10; i++)
		cout << testArr[i] << " ";
	cout << endl;
}

// Implementatie DynamicArray =================================
template<typename T>
DynamicArray<T>::DynamicArray(unsigned groote)
	: aantal(groote), array(new T[groote]) {
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& in) {
	// delete old array
	delete[] array;
	// set new size
	aantal = in.aantal;
	// set up new array
	array = new T[aantal];
	// copy the elements to the new array
	for (unsigned i = 0; i < aantal; i++)
		array[i] = in.array[i];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
	delete[] array;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& in) {
	// delete old array
	delete[] array;
	// set new size
	aantal = in.aantal;
	// set up new array
	array = new T[aantal];
	// copy the elements to the new array
	for (unsigned i = 0; i < aantal; i++)
		array[i] = in.array[i];
	// it had a return so that it can be ussed in more complex expresions
	return *this;
}

template<typename T>
T& DynamicArray<T>::operator[](int k) {
	return array[k];
}
