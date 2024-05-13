// Created by Tiemen Molenaar in 2023
// eigen implementatie van IntArray met iterator
#include <iostream>
using namespace std;

namespace vragen_8_en_9 {
	class IntArrayIterator;

	class IntArray {
	private:
		unsigned size;
		int* array;
	public:
		typedef IntArrayIterator iterator;
		IntArray(unsigned size=10);
		~IntArray();
		int& operator[](unsigned index) const;
		unsigned getSize() const;
		void apply(int (*func)(unsigned index, int value));

		IntArrayIterator end();
		IntArrayIterator begin();
	};

	class IntArrayIterator {
	private:
		int* wijzer;
	public:
		IntArrayIterator(int* wijzer = NULL);
		int& operator*() const;
		IntArrayIterator& operator++();
		bool operator!=(const IntArrayIterator& rechts) const;
	};
}

// main program
using namespace vragen_8_en_9;

int indexer(unsigned index, int value) {
	return index;
}

int double_it(unsigned index, int value) {
	return value * 2;
}

void main_vragen_8_en_9() {
	int x{ 10 };
	IntArray array;
	array.apply(indexer);
	array.apply(double_it);
	array[4] = 2023;

	IntArray::iterator pos, end = array.end();

	for (pos = array.begin(); pos != end; ++pos)
		cout << *pos << endl;
}

// implementatie IntArray
IntArray::IntArray(unsigned size)
	: size(size) {
	array = new int[size];
}
IntArray::~IntArray() {
	delete[] array;
}

int& IntArray::operator[](unsigned index) const {
	return array[index];
}

unsigned IntArray::getSize() const {
	return size;
}

void IntArray::apply(int (*func)(unsigned index,int value)) {
	for (unsigned index = 0; index < size; index++)
		array[index] = func(index, array[index]);
}

IntArrayIterator IntArray::begin() {
	return iterator(array);
}

IntArrayIterator IntArray::end() {
	return iterator(array+size);
}

// Implementatie IntArrayIterator
IntArrayIterator::IntArrayIterator(int* wijzer)
	: wijzer(wijzer) {
}

int& IntArrayIterator::operator*() const {
	return *wijzer;
}

IntArrayIterator& IntArrayIterator::operator++() {
	++wijzer;
	return *this;
}

bool IntArrayIterator::operator!=(const IntArrayIterator& rechts) const {
	return wijzer != rechts.wijzer;
}