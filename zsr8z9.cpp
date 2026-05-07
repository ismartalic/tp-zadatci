#include <iostream>
#include <complex>
#include <list>

struct Kompleksni {
	double re, im;
	Kompleksni* sljedeci;
};

Kompleksni* KreirajListu(std::list<std::complex<double>> &l) {
	Kompleksni* pocetak = nullptr, *prethodni = nullptr;
	try {
		for (auto it = l.begin(); it != l.end(); it++) {
			double re = real(*it);
			double im = imag(*it);
			Kompleksni* novi = new Kompleksni{ re, im, nullptr };
			if (!pocetak) pocetak = novi;
			else prethodni->sljedeci = novi;
			prethodni = novi;
		}
	}
	catch (...) {
		while (pocetak != nullptr) {
			auto temp = pocetak;
			pocetak = pocetak->sljedeci;
			delete temp;
		}
	}
	return pocetak;
}

int main() {
	std::list<std::complex<double>> l{ {2.4,3.}, {5.,6.2}, {2.3, 4.5}, {2.3, 4.} };

	Kompleksni* pocetak = KreirajListu(l);

	for (auto p = pocetak; p != nullptr; p = p->sljedeci) {
		std::cout << p->re << " " << p->im << std::endl;
	}

	while (pocetak != nullptr) {
		auto temp = pocetak;
		pocetak = pocetak->sljedeci;
		delete temp;
	}

	return 0;
}
