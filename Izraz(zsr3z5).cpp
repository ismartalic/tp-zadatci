#include <iostream>
#include <vector>
#include <cmath>ž
#include <stdexcept>

double Izraz(std::vector<double> v) {
	if (v.empty()) throw std::domain_error("Prazan vektor");

	double rez = v.at(v.size() - 1);
	if (rez < 0) throw std::domain_error("Negativna broj pod korijenom");
	rez = std::sqrt(rez);
	for (int i = v.size() - 2; i >= 0; i--) {
		double temp = v.at(i) + rez;
		rez = std::sqrt(temp);
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
