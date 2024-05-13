// Created by Tiemen Molenaar in 2023
#pragma once
namespace vb_4 {
	class Figuur {
	protected:
		char symbool;
	public:
		Figuur(char symbool = '*')
			: symbool(symbool) {
		}

		void setSymbool(char sym) {
			symbool = sym;
		}

		virtual void teken() const = 0; // zuiver virtuele functie
	};

	class Rechthoek : public Figuur {
	protected:
		int breedte, hoogte;
	public:
		Rechthoek(int breedte, int hoogte)
			: breedte(breedte), hoogte(hoogte) {
		}
		virtual void teken() const;
	};

	class Driehoek : public Figuur {
	private:
		int grote;
	public:
		Driehoek(int grote)
			: grote(grote) {
		}
		virtual void teken() const;
	};
}