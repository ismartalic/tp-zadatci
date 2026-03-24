#include <iostream>
#include <vector>
#include <limits>

// Napišite program koji traži da se sa tastature unese prirodan broj 𝑛, 
// a nakon toga elementi kvadratne matrice formata 𝑛 x 𝑛 (matricu treba organizirati kao vektor vektôrā). 
// Program nakon toga treba da ispiše redni broj kolone sa najvećom sumom elemenata, redni broj reda sa 
// najmanjom sumom elemenata, kao i sumu elemenata na dijagonali. 

double MaxSum(std::vector<double> v) {
	double max = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) > max) max = v[i];
	}
	return max;
}

double MinSum(std::vector<double> v) {
	double min = std::numeric_limits<double>::max();
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) < min) min = v[i];
	}

	return min;
}

int main() {
	int n = 0;
	std::cout << "Unesite dimenziju matrice: ";
	std::cin >> n;

	std::vector<std::vector<double>> a(n, std::vector<double>(n)); // matrica dimenzija nxn

	// unos matrice
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> a[i][j];
		}
	}

	std::vector<double> sum_kol; // vektor za sume elemenata iz svake kolone

	// cuvanje suma elemenata svake kolone u vektor
	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[j][i];
		}
		sum_kol.push_back(sum);
	}

	// pronalazak najvece sume u vektoru
	double max_kol = MaxSum(sum_kol);

	// pronalazenje indexa najvece sume
	for (int i = 0; i < n; i++) {
		if (sum_kol[i] == max_kol) {
			std::cout << "Kolona sa najvecom sumom je " << i + 1 << ". kolona" << std::endl;
			break;
		}
	}

	std::vector<double> sum_red; // vektor za sume redova

	for (int i = 0; i < n; i++) {
		double sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[j][i];
		}
		sum_red.push_back(sum);
	}

	double min_red = MinSum(sum_red);

	for (int i = 0; i < n; i++) {
		if (sum_red[i] == min_red) {
			std::cout << "Red sa najmanjom sumom je " << i + 1 << ". red" << std::endl;
			break;
		}
	}

	// suma elemenata na dijagonali

	double Dsum = 0;
	for (int i = 0; i < n; i++) {
		Dsum += a.at(i).at(i);
	}

	std::cout << "Suma elemenata na dijagonali je: " << Dsum;

	return 0;
}
