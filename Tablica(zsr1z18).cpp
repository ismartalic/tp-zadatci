#include <iostream>
#include <iomanip>

// Napišite program koji za prirodan broj 𝑛 unesen sa tastature ispisuje na ekran formatiranu tablicu množenja za sve brojeve
// od 1 do 𝑛 uključivo. Na primjer, ukoliko se unese 𝑛 = 5, ispis na ekran bi trebao izgledati poput sljedećeg:   
// +-----+-----+-----+-----+-----+  
// |   1 |   2 |   3 |   4 |   5 |  
// +-----+-----+-----+-----+-----+  
// |   2 |   4 |   6 |   8 |  10 |  
// +-----+-----+-----+-----+-----+  
// |   3 |   6 |   9 |  12 |  15 |  
// +-----+-----+-----+-----+-----+  
// |   4 |   8 |  12 |  16 |  20 |  
// +-----+-----+-----+-----+-----+  
// |   5 |  10 |  15 |  20 |  25 |  
// +-----+-----+-----+-----+-----+   
// Pretpostavite da je 𝑛 takav da će čitava tablica stati na ekran i da niti jedan produkt neće imati više od 3 cifre. 
// Za ispis koristite objekat izlaznog toka “cout”, a za prilagođavanje širine ispisa manipulator “setw”. 

void Linija(int n) {
	for (int i = 0; i < n; i++) std::cout << "+-----";
	std::cout << "+";

}

int main() {
	int n = 0;
	std::cout << "Unesite broj: ";
	std::cin >> n;

	Linija(n);

	for (int i = 1; i <= n; i++) {
		std::cout << std::endl;
		for (int j = 1; j <= n; j++) {
			std::cout << "| " << std::setw(3) << j * i << " ";
		}
		std::cout << "|" << std::endl;
		Linija(n);
	}
 
	return 0;
}
