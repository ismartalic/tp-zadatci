#include <iostream>
#include <vector>

bool Nkvadrat(std::vector<std::vector<int>> v) {
	int n = v.size();
	int brojac = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 1; k <= n * n; k++) {
				if (k == v.at(i).at(j)) {
					brojac++;
					break;
				}
			}
		}
	}

	return brojac == n * n;
}

bool ZbirRedova(std::vector<std::vector<int>> v) {
	int n = v.size();
	std::vector<int> suma;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v.at(i).at(j);
		}
		suma.push_back(sum);
	}

	for (int i = 1; i < suma.size(); i++) {
		if (suma.at(0) != suma.at(i)) return false;
	}

	return true;
}

bool ZbirKol(std::vector<std::vector<int>> v) {
	int n = v.size();
	std::vector<int> suma;
	for (int i = 0; i < n; i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			sum += v.at(j).at(i);
		}
		suma.push_back(sum);
	}

	for (int i = 1; i < suma.size(); i++) {
		if (suma.at(i) != suma.at(0)) return false;
	}

	return true;
}

bool ZbirDijagonala(std::vector<std::vector<int>> v) {
	int n = v.size();
	int suma_gl = 0;
	for (int i = 0; i < n; i++) {
		suma_gl += v.at(i).at(i);
	}

	int suma_spored = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i + j == n - 1)
				suma_spored += v.at(i).at(j);
		}
	}

	return suma_gl == suma_spored;
}


bool MagicniKvadrat(std::vector<std::vector<int>> v) {
	int n = v.size();
	for (int i = 0; i < n; i++)
		if (v.at(i).size() != v.at(0).size()) return false;

	if (v.at(0).size() != n) return false;

	return Nkvadrat(v) && ZbirKol(v) && ZbirRedova(v) && ZbirDijagonala(v);
}


int main() {
	int n = 0;
	std::cout << "Unesite dim mat: ";
	std::cin >> n;

	std::cout << "Unesite elemente matrice: " << std::endl;
	std::vector<std::vector<int>> v(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> v.at(i).at(j);
		}
	}

	std::cout << std::boolalpha << MagicniKvadrat(v) << std::endl;

	return 0;
}
