#include <iostream>
#include <vector>
#include <stdexcept>

std::vector<int> BrCifara(std::vector<long long int> v) {
	std::vector<int> a;
	for (int i = 0; i < v.size(); i++) {
		long long int x = v.at(i);
		if (x < 0) throw std::domain_error("Negativan broj");
		int brojac = 0;
		while (x != 0) {
			x /= 10;
			brojac++;
		}
		a.push_back(brojac);
	}

	return a;
}

int main() {
	int m = 0;
	std::cout << "Unesite velicinu vektora: ";
	std::cin >> m;

	std::vector<long long int> A;
	for (int i = 0; i < m; i++) {
		long long int x = 0;
		std::cin >> x;
		A.push_back(x);
	}

	try {
		std::vector<int> a = BrCifara(A);
		for (auto x : a) std::cout << x << " ";
	}
	catch (const std::range_error& e) {
		std::cout << e.what();
	}

	return 0;
}
