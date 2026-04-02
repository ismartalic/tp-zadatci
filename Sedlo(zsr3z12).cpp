#include <iostream>
#include <vector>
#include <stdexcept>
#include <Climits>

int Maximum(std::vector<int> v) {
	int max = INT_MIN;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) > max) max = v.at(i);
	}

	return max;
}

int Minimum(std::vector<int> v) {
	int min = INT_MAX;
	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) < min) min = v.at(i);
	}

	return min;
}

int sedlo(std::vector<std::vector<int>> v) {
	for (int i = 1; i < v.size(); i++) {
		if (v.at(0).size() != v.at(i).size()) throw std::domain_error("Nije proslijednja validna matrica");
	}
	int sedlo = 0;
	for (int i = 0; i < v.size(); i++) {
		int max_red = Maximum(v.at(i));
		int min_red = Minimum(v.at(i));
		int min_col = INT_MAX;
		int max_col = INT_MIN;
		for (int j = 0; j < v.at(i).size(); j++) {
			if (v.at(i).at(j) < min_col) min_col = v.at(j).at(i);
			if (v.at(i).at(j) > max_col) max_col = v.at(j).at(i);
		}
		if (max_red == min_col) sedlo++;
		else if (min_red == max_col) sedlo++;
	}

	return sedlo;
}

int main() {
	int m = 0, n = 0;
	std::cout << "UInesite dim mat: ";
	std::cin >> m >> n;

	std::vector<std::vector<int>> v(m, std::vector<int>(n, 0));
	std::cout << "Unesite el mat: " << std::endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> v.at(i).at(j);
		}
	}

	int rez = sedlo(v);

	std::cout << "Sedlo: " << rez << std::endl;
	
	return 0;
}
