#include <iostream>
#include <vector>
#include <stdexcept>
#include <cmath>

std::vector<bool> JeKub(std::vector<int> a) {
	std::vector<bool> b;
	for (int i = 0; i < a.size(); i++) {
		int x = a.at(i);
		if (x < 0) throw std::domain_error("Negativan broj");
		double korijen = std::cbrt(x);
		if (korijen * korijen * korijen == double(x)) b.push_back(true);
		else b.push_back(false);
	}

	return b;
}

int main() {
	int n = 0;
	std::cout << "Unesite vel vektora: ";
	std::cin >> n;

	std::cout << "Unesite elemente vektora: " << std::endl;
	std::vector<int> v;
	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		v.push_back(x);
	}

	try {
		std::vector<bool> b = JeKub(v);
		for (auto x : b) std::cout << std::boolalpha << x << " ";
	}
	catch (const std::domain_error& e) {
		std::cout << e.what();
	}



	return 0;
}
