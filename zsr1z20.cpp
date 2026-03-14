#include <iostream>
#include <iomanip>

//Napišite program koji traži od korisnika da unese prirodne brojeve 𝑚 i 𝑛, pri čemu je 𝑚 > 𝑛. 
// Nakon toga, program treba da na ekranu iscrta figuru oblika “<–>” sastavljenu od zvjezdica, čija je širina 𝑚 a visina 𝑛 znakova. 
// Na primjer, za 𝑚 = 15 i 𝑛 = 7, prikaz na ekranu treba izgledati ovako: 

int main() {
	int m = 0, n = 0;
	do {
		std::cout << "Unesite dimenzije: ";
		std::cin >> m >> n;
	} while (m < n);

	int width = n / 2 + 1;
	for (int i = 0; i < n / 2; i++) {
		std::cout << std::setw(width) << std::right << "*";
		for (int j = 0; j < m - (width * 2); j++) std::cout << " ";
		std::cout << std::setw(width--) << std::left << "*" << std::endl;
	}
	for (int i = 0; i < m; i++) std::cout << "*";
	std::cout << std::endl;
	int width2 = 2;
	for (int i = 0; i < n / 2; i++) {
		std::cout << std::setw(width2) << std::right << "*";
		for (int j = 0; j < m - (width2 * 2); j++) std::cout << " ";
		std::cout << std::setw(width2++) << std::left << "*" << std::endl;
	}
	

	return 0;
}
