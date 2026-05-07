#include <iostream>
#include <deque>
#include <cmath>

struct Cvor {
	unsigned int broj;
	Cvor* veza;
};

bool Prost(unsigned int broj) {
	if (broj < 2) return false;
	for (int i = 2; i <= std::sqrt(broj); i++)
		if (broj % i == 0) return false;
	return true;
}

void ObrisiListu(Cvor* pocetak) {
	while (pocetak != nullptr) {
		auto temp = pocetak;
		pocetak = pocetak->veza;
		delete temp;
	}
}

Cvor* KreirajListu(std::deque<unsigned int> d) {
	Cvor* pocetak = nullptr, *prethodni = nullptr;
	try {
		for (int i = 0; i < d.size(); i++) {
			Cvor* novi = new Cvor{ d.at(i), nullptr };
			if (!pocetak) pocetak = novi;
			else prethodni->veza = novi;
			prethodni = novi;
		}
	}
	catch (...) {
		ObrisiListu(pocetak);
		throw;
	}
	return pocetak;
}

int BrojProstih(Cvor* pocetak) {
	int brojac = 0;
	while (pocetak != nullptr) {
		int br = pocetak->broj;
		if (Prost(br)) brojac++;
		pocetak = pocetak->veza;
	}
	return brojac;
}

int main() {
	int n = 0;
	std::cout << "Koliko elemenata zelite unijeti: ";
	std::cin >> n;
	std::deque<unsigned int> d(n);
	for (int i = 0; i < n; i++)
		std::cin >> d.at(i);
	Cvor* pocetak = nullptr;
	try {
		pocetak = KreirajListu(d);
	}
	catch (...) {
		ObrisiListu(pocetak);
		return 1;
	}
	int broj_prostih = BrojProstih(pocetak);

	std::cout << std::endl;
	std::cout << "Broj prostih brojeva je: " << broj_prostih << std::endl;

	ObrisiListu(pocetak);
	return 0;
}
