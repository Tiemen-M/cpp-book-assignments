// Created by Tiemen Molenaar in 2023
#pragma once
namespace opd_1_en_2 {
	class Container {
	protected:
		unsigned maxAantal;
		unsigned aantal;
		int* p;
	public:
		Container(int max = 10);
		~Container();
		void voegtoe(int a);
		int zoek(int a) const;
		void print(int width = 3) const;
		// opdracht 2
		Container(const Container&); // copy constructor
		Container& operator=(const Container&); // asignmentoperator 
	};
}