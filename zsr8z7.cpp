#include <iostream>
#include <string>
#include <iomanip>

struct Cvor {
	std::string lokacija;
	int cijena, kvadratura;
	Cvor* veza;
};

int main() {
	Cvor* pocetak = nullptr;
	try {
		for (;;) {
			std::string s;
			std::getline(std::cin, s);
			if (s.empty()) break;
			int cijena = 0, kvadratura = 0;
			std::cin >> cijena >> kvadratura;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
			Cvor* novi = new Cvor{ s, cijena, kvadratura, nullptr };

			if (pocetak == nullptr || cijena < pocetak->cijena || (cijena == pocetak->cijena && kvadratura > pocetak->kvadratura)) {
				novi->veza = pocetak;
				pocetak = novi;
			}
			else {
				Cvor* p = pocetak;
				while (p->veza != nullptr && (p->veza->cijena < cijena || (p->veza->cijena == cijena && p->veza->kvadratura >= kvadratura))) p = p->veza;
				novi->veza = p->veza;
				p->veza = novi;
			}
		}

		for (Cvor* p = pocetak; p != nullptr; p = p->veza) {
			std::cout<< "Lokacija: " << std::setw(15) << std::left << p->lokacija << std::setw(10) << std::right << "Cijena: "<< std::setw(10) << std::right << p->cijena << std::setw(15) <<"Kvadratura: " << std::right << std::setw(5) << p->kvadratura << std::endl;
		}

		while (pocetak != nullptr) {
			auto temp = pocetak;
			pocetak = pocetak->veza;
			delete temp;
		}
	}
	catch (...) {
		while (pocetak != nullptr) {
			auto temp = pocetak;
			pocetak = pocetak->veza;
			delete temp;
		}
	}

	return 0;
}
