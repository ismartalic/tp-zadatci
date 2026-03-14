#include <iostream>

// zsr1 z25
//Napišite program koji ce prvo tražiti od korisnika da unese prirodan broj N, 
// a zatim N realnih brojeva 𝑎 , 𝑎 , ..., 𝑎 . Nakon toga, program treba da izračuna i ispiše vrijednost izraza  
// suma reciprocnih suma koeficijenata

int main() {
	int n = 0;
	std::cout << "Unesite n: ";
	std::cin >> n;

	double suma_br = 0;
	double suma = 0;
	for (int i = 0; i < n; i++) {
		double a = 0;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite a: ";
		std::cin >> a;

		suma_br += a;
		suma += 1 / suma_br;
	}

	std::cout << "Suma = " << suma << std::endl;

	return 0;
}
