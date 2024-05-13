// Created by Tiemen Molenaar in 2023
#pragma once
namespace vb_2 {
	class IntArray {
	private:
		unsigned aantal;
		int* p;
	public:
		IntArray(unsigned n = 1);
		~IntArray();
		void invoer();
		double gemiddelde() const;
	};
}