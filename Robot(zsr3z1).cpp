#include <iostream>
#include <string>
#include <array>

// Položaj zamišljenog robota koji može da se kreće kroz koordinatni sistem sa cjelobrojnim koordinatama 
// opisuje se pomoću tri promjenljive “x”, “y” i “orijentacija”. Promjenljive “x” i “y” su tipa “int” i one čuvaju 𝑥 odnosno 𝑦 koordinatu 
// pozicije na kojoj se robot trenutno nalazi. Promjenljiva “orijentacija” je tipa “Pravci”, koji predstavlja pobrojani tip definiran kao   
// enum Pravci {Sjever, Istok, Jug, Zapad};   Ova promjenljiva sadrži informaciju o pravcu u kojem robot trenutno gleda. 
// Potrebno je napraviti program koji korisniku nudi sljedeće opcije za upravljanje robotom: L − Nalijevo; D − Nadesno;  
// I − Idi; K − Kraj. Opcije L odnosno D obrću robota nalijevo odnosno nadesno za 90°. Opcija I treba da pita korisnika za broj koraka, 
// a nakon toga pomjera robota zadani broj koraka u pravcu u kojem robot trenutno gleda. Opcija K završava program. Sve druge opcije su ilegalne, 
// i trebaju dovesti do prijave greške i ponovnog izbora opcije. Na početku rada, robot se nalazi na poziciji (0,0) i gleda na sjever. 
// Dijalog između programa i korisnika mogao bi izgledati poput sljedećeg: 

int main() {
	enum Pravci {Sjever, Istok, Jug, Zapad};
	int x = 0, y = 0;
	Pravci orijentacija = Sjever;

	std::array<std::string, 4> strane{ "Sjever", "Istok", "Jug", "Zapad" };

	for (;;) {
		char izbor;
		std::cout << "Robot se nalazi na pozicij (" << x << "," << y << ") i gleda na " << strane[orijentacija] << std::endl;
		std::cout << "Unesi komandu (L - Nalijevo, D - Nadesno, I - Idi, K - Kraj): ";
		std::cin >> izbor;

		if (izbor == 'K') {
			std::cout << "Dovidjenja!";
			return 0;
		}
		else if (izbor == 'L') {
			int i = orijentacija;
			orijentacija = (orijentacija == 0) ? orijentacija = Pravci(3) : orijentacija = Pravci(--i);
		}
		else if (izbor == 'D') {
			int i = orijentacija;
			orijentacija = (orijentacija == 3) ? orijentacija = Pravci(0) : orijentacija = Pravci(++i);
		}
		else if (izbor == 'I') {
			int br_koraka = 0;
			std::cout << "Unesi broj koraka: ";
			std::cin >> br_koraka;

			if (orijentacija == 0) y += br_koraka;
			else if (orijentacija == 1) x += br_koraka;
			else if (orijentacija == 2) y -= br_koraka;
			else if (orijentacija == 3) x -= br_koraka;
		}
		else std::cout << "Pogresna komanda!" << std::endl;

	}

	return 0;
}
