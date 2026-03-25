#include <iostream>
#include <vector>

// Napišite funkciju koja kao parametar prima neki prirodan broj i koja vraća logičku vrijednost 
// “tačno” ili “netačno” u ovisnosti da li u broju koji je proslijeđen kao parametar ima jednakih 
// cifara ili ne (možete se osloniti na to da će broj biti prirodan, odnosno da se funkciji neće 
// prenositi negativni brojevi). Napišite i kratki testni program u kojem ćete demonstrirati kako se 
// poziva napisana funkcija i kako se može iskoristiti njen rezultat. 

bool Provjera(int n) {
	std::vector<int> v;
	int brojac = 0; 
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
		for (int i = 0; i < v.size() - 1; i++) if (v[brojac] == v[i]) return true;
		brojac++;
	}

	return false;
}

int main() {

	std::cout << std::boolalpha << Provjera(23345) << std::endl;
	std::cout << std::boolalpha << Provjera(12345) << std::endl;
	std::cout << std::boolalpha << Provjera(12) << std::endl;
	std::cout << std::boolalpha << Provjera(12222) << std::endl;
	std::cout << std::boolalpha << Provjera(10000) << std::endl;

	return 0;
}
