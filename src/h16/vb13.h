// Created by Tiemen Molenaar in 2023
#pragma once
#include <iostream>
using namespace std;

namespace vb_13 {
	class Punt {
	private:
		int x, y;
	public:
		Punt(int x = 0, int y = 0);
		friend ostream& operator<<(ostream& uit, const Punt& p);
	};
}