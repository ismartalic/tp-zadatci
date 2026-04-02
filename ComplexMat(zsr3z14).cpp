#include <iostream>
#include <vector>
#include <complex>
#include <stdexcept>
#include <climits>
#include <iomanip>

std::complex<double> TransformMat(std::vector<std::vector<std::complex<double>>>& v) {
	for (int i = 1; i < v.size(); i++) {
		if (v.at(i).size() != v.at(0).size()) throw std::domain_error("Neispravan format matrice");
	}


	double min = 1000000;
	double max = -1000000;
	int min_index = INT_MAX;
	int max_index = INT_MIN;

	for (int i = 0; i < v.size(); i++) {
		std::complex<double> col_proizvod(1, 0);
		for (int j = 0; j < v.at(i).size(); j++) {
			col_proizvod *= v.at(j).at(i);
		}
		double col = std::abs(col_proizvod);
		if (col > max) {
			max = col;
			max_index = i;
		}
		if (col < min) {
			min = col;
			min_index = i;
		}
	}

	for (int i = 0; i < v.size(); i++) {
		std::complex<double> temp(v.at(i).at(min_index));
		v.at(i).at(min_index) = v.at(i).at(max_index);
		v.at(i).at(max_index) = temp;
	}

	std::complex<double> rez(min, max);

	return rez;
}

int main() {
	try {
		int m = 0, n = 0;
		std::cout << "Unesite dim mat: ";
		std::cin >> m >> n;
		std::vector<std::vector<std::complex<double>>> mat(m, std::vector<std::complex<double>>(n, 0));

		std::cout << "Unesite el mat: " << std::endl;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> mat.at(i).at(j);
			}
		}

		std::complex<double> rez(TransformMat(mat));

		std::cout << "Rezultat je: " << rez << std::endl;

		for (int i = 0; i < mat.size(); i++) {
			for (int j = 0; j < mat.at(i).size(); j++) {
				std::cout << std::setw(5) << mat.at(i).at(j);
			}
			std::cout << std::endl;
		}
	}
	catch (const std::domain_error& e) {
		std::cout << "GRESKA: " << e.what() << std::endl;
	}
	

	return 0;
}
