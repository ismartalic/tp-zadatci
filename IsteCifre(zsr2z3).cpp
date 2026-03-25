#include <iostream>
#include <vector>

 // Napišite funkciju koja prima neki cijeli broj kao parametar i koja vraća logičku vrijednost 
 // “tačno” ili “netačno”, ovisno od toga da li se u broju koji joj se prosljeđuje kao parametar 
 // nalaze barem dvije iste cifre jedna za drugom (kao recimo u broju 355241) ili ne. Funkcija treba 
 // da radi korektno i za pozitivne i za negativne brojeve. 

bool Provjera(int n) {
	std::vector<int> v;
	int brojac = 0; 
	while (n != 0) {
		v.push_back(n % 10);
		n /= 10;
		for (int i = 0; i < v.size() - 1; i++) if (v[brojac] == v[brojac - 1]) return true;
		brojac++;
	}

	return false;
}

int main() {

	std::cout << std::boolalpha << Provjera(-23345) << std::endl;
	std::cout << std::boolalpha << Provjera(12345) << std::endl;
	std::cout << std::boolalpha << Provjera(12) << std::endl;
	std::cout << std::boolalpha << Provjera(12222) << std::endl;
	std::cout << std::boolalpha << Provjera(10000) << std::endl;

	return 0;
}
