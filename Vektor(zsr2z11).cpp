#include <iostream>
#include <array>
#include <vector>

// Napišite funkciju koja ima dva parametra, od kojih je prvi niz realnih brojeva, a drugi broj elemenata u nizu. 
// Funkcija treba da kreira vektor realnih brojeva koji sadrži isti broj elemenata kao i zadani niz, 
// da prepiše sve elemente niza u kreirani vektor u obrnutom poretku (tj. prvi element niza treba da 
// postane posljednji element vektora, drugi element niza treba da postane pretposljednji element vektora, itd.), 
// i da vrati tako popunjeni vektor kao rezultat. Napisanu funkciju demonstrirajte u glavnom programu koji prvo sa 
// tastature unosi elemente niza kapaciteta 10 elemenata. Nakon toga, program poziva napisanu funkciju sa ciljem 
// generiranja vektora čiji su elementi u obrnutom poretku u odnosu na elemente unesenog niza. Na kraju, program 
// ispisuje elemente generiranog vektora na ekran (međusobno razdvojene razmakom). 

std::vector<double> Vektor(std::array<double, 10> &a, int n) {
	std::vector<double> v;
	for (int i = n - 1; i >= 0; i--)
		v.push_back(a[i]);

	return v;
}

int main() {
	int n = 0;
	std::cout << "Unesite broj el niza: ";
	std::cin >> n;

	std::array<double, 10> niz;
	std::vector<double> v;

	for (int i = 0; i < n; i++)
		std::cin >> niz[i];

	v = Vektor(niz, n);

	for (double x : v) std::cout << x << " ";


	return 0;
}
