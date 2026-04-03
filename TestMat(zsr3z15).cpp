#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

void TestIspravnostiMat(std::vector<std::vector<double>> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v.at(i).size() != v.at(0).size()) throw std::domain_error("Nesipravna matrica!");
	}
}

double ForbeniusovaNorma(std::vector<std::vector<double>> v) {
	TestIspravnostiMat(v);
	double suma = 0;
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.at(i).size(); j++) {
			double el = v.at(i).at(j);
			suma += (el * el);
		}
	}

	return std::sqrt(suma);
}

bool DaLiJeDonjaTrougaona(std::vector<std::vector<double>> v) {
	TestIspravnostiMat(v);
	for (int i = 0; i < v.size(); i++) {
		for (int j = i + 1; j < v.at(i).size(); j++) {
			if (v.at(i).at(j) != 0) return false;
		}
	}
	return true;
}


int main() {
	try {
		int n = 0;
		std::cout << "Unesite dim mat: ";
		std::cin >> n;

		std::vector<std::vector<double>> mat(n, std::vector<double>(n, 0));

		std::cout << "Unesite elemente matrice: " << std::endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> mat.at(i).at(j);
			}
		}

		double norma = ForbeniusovaNorma(mat);
		std::cout << "Norma je: " << norma << std::endl;

		std::cout << std::boolalpha << DaLiJeDonjaTrougaona(mat);
	}
	catch (const std::domain_error& e) {
		std::cout << "GRESKA: " << e.what() << std::endl;
	}
	

	return 0;
}
