#include <iostream>
#include <string>
#include <map>

std::string Sifriranje(const std::string& s, const std::map<char, char> &mapa) {
	std::string rez;
	for (auto it = s.begin(); it != s.end(); it++) {
		auto pronadjen = mapa.find(*it);
		if (pronadjen != mapa.end()) rez += pronadjen->second;
		else rez += *it;
	}

	return rez;
}

int main() {
	std::map<char, char> sifre = {
		{'a', 'x'}, {'b', 'c'}, {'c', 'a'}
	};

	std::string s = "abcbcaccbac";

	std::string rez = Sifriranje(s, sifre);

	std::cout << rez << std::endl;

	return 0;
}
