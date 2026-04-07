#include <iostream>
#include <vector>
#include <iomanip>

std::vector<std::vector<double>> ProizvodMat(std::vector<std::vector<double>> A) {
	int n = A.size();
	std::vector<std::vector<double>> B = A;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int suma = 0;
			for (int k = 0; k < n; k++) {
				suma += B.at(i).at(k) * B.at(k).at(j);
			}
			A.at(i).at(j) = suma;
		}

	}
	return A;
}

bool Indepotentna(std::vector<std::vector<double>> A) {
	return ProizvodMat(A) == A;
}

int main() {
	int n = 0;
	std::cout << "Unesite dim mat: ";
	std::cin >> n;

	std::cout << "Unesite matricu: " << std::endl;
	std::vector<std::vector<double>> mat(n, std::vector<double>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> mat.at(i).at(j);
		}
	}

	std::cout << std::boolalpha << Indepotentna(mat) << std::endl;

	return 0;
}
