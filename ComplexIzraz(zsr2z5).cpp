#include <iostream>
#include <complex>

// Napišite program koji traži da se sa tastature unese jedan kompleksan broj 𝑧 i dva realna broja 𝑥 i 𝑦, 
// a koji zatim računa i ispisuje vrijednost izraza 

int main() {
	std::complex<double> z;
	double x = 0, y = 0;

	std::cout << "unesite kompleksni broj: ";
	std::cin >> z;

	std::cout << "Unesite x i y: ";
	std::cin >> x >> y;

	std::complex<double> brojnik(0, 5);
	std::complex<double> korijen(x, -y);

	std::complex<double> rez = std::pow((x + (brojnik) / (std::pow(z, 3) * std::sqrt(korijen))), 2);

	std::cout << "Rezultat je: " << rez << std::endl;

	return 0;
}
