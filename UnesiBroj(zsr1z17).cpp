#include <iostream>

// Napišite funkciju “UnesiBroj” bez parametara, koja od korisnika očekuje da unese neki realni broj. 
// Ukoliko je zaista unesen realan broj, funkcija treba da ga vrati kao rezultat iz funkcije. Ukoliko nije unesen broj, 
// funkcija treba ispisati “Neispravan unos. Molimo, pokušajte ponovo.” i ponovo tražiti broj, 
// sve dok se zaista ne unese ispravan broj (prema tome, funkcija ne završava dok se ne unese ispravan broj). 
// Napisanu funkciju iskoristite u programu koji traži da se unesu koeficijenti 𝑎, 𝑏 i 𝑐 linearne jednačine 𝑎   + 𝑏 = 𝑐, 
// a koji zatim nalazi i ispisuje njeno rješenje, pod uvjetom da ono postoji, ili odgovarajuću poruku u suprotnom. 

int UnesiBroj(void) {
	double n = 1;
	
	while (!(std::cin >> n)) {
		std::cout << "Neispravan unos. Molimo, pokušajte ponovo. ";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
	std::cin.clear();				//zbog unosa tipa 123xy 
	std::cin.ignore(10000, '\n');   //ciscenje ulaznog toka

	return n;
}

int main() {
	std::cout << "Unesite a ";
	double a = UnesiBroj();
	std::cout << "Unesite b ";
	double b = UnesiBroj();
	std::cout << "Unesite c ";
	double c = UnesiBroj();

	if (a == 0) {
		std::cout << "Jednacina nema rjesenja!";
		return 0;
	}

	double x = (c - b) / a;

	std::cout << "Rjesenje jednacine je " << x << std::endl;
 
	return 0;
}
