#include <iostream>
#include <vector>
#include <cmath>

// Napišite funkciju koja kao parametar prima vektor cijelih brojeva, a koja vraća logičku vrijednost 
// “tačno” ili “netačno”, u ovisnosti da li u vektoru ima potpunih kvadrata (tj. brojeva koji se mogu 
// napisati kao kvadrati nekog drugog prirodnog broja) ili ne. Napisanu funkciju demonstrirajte u 
// testnom programu u kojem se sa tastature unosi prirodan broj 𝑛 a zatim 𝑛 cijelih brojeva, koji se unose u vektor. 
// Nakon unosa, program treba pozvati napisanu funkciju sa ciljem da utvrdi ima li među unesenim brojevima 
// potpunih kvadrata ili ne i ispisati odgovarajuću poruku, ovisno od rezultata funkcije. 

bool PotpuniKvadrati(std::vector<int> v) {
	for (int i = 0; i < v.size(); i++) {
		double r = std::sqrt(v[i]);
		if (std::fabs(r - std::round(r)) < 1e-10) return true;
	}
	return false;
}

int main() {
	std::vector<int> v;
	int n = 0;

	std::cout << "Unesite br elemenata: ";
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		int x = 0;
		std::cin >> x;
		v.push_back(x);
	}

	std::cout << std::boolalpha << PotpuniKvadrati(v) << std::endl;

	return 0;
}
