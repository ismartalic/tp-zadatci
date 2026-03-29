#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

double Izraz(std::vector<double> v) {
	if (v.empty()) throw std::domain_error("Prazan vektor");

	double rez = v.at(v.size() - 1);
	for (int i = v.size() - 2; i >= 0; i--) {
		if (rez < 0) throw std::domain_error("Dijeljenje sa nulom");
		rez = 1 / rez;
		rez += v.at(i);
	}

	return rez;
}

int main() {
	int n = 0;
	std::cout << "Unesite velicinu vektora: ";
	std::cin >> n;

	std::vector<double> v;
	std::cout << "Unesite elemente vektora: ";
	for (int i = 0; i < n; i++) {
		double x = 0;
		std::cin >> x;
		v.push_back(x);
	}

	try {
		std::cout << Izraz(v);
	}
	catch (const std::domain_error& e) {
		std::cout << e.what();
	}
	


	return 0;
}
