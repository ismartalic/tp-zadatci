#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<double> Funkcija(std::vector<double> a, std::vector<int> b) {
	std::vector<double> c;
	for (int i = 0; i < b.size(); i++) {
		try {
			c.push_back(a.at(b.at(i)));
		}
		catch (const std::out_of_range& e) {
			throw std::range_error("Greska u indeksacij");
		}
	}

	return c;
}

int main() {
	int m = 0, n = 0;
	std::cout << "Unesite velicinu prvog vektora: ";
	std::cin >> m;

	std::vector<double> A;
	for (int i = 0; i < m; i++) {
		double x = 0;
		std::cin >> x;
		A.push_back(x);
	}

	std::cout << "Unesite velicinu drugog vektora: ";
	std::cin >> n;

	std::vector<int> B;
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		B.push_back(x);
	}

	try {
		std::vector<double> c = Funkcija(A, B);

		for (auto x : c) std::cout << x << " ";
	}
	catch (const std::range_error& e) {
		std::cout << e.what();
	}

	return 0;
}
