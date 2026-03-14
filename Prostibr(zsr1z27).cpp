#include <iostream>

//Napišite program koji traži da se sa tastature unesu dva prirodna broja 𝑛 i 𝑚, 
//a koji će zatim ispisati sve proste brojeve između 𝑛 i 𝑚 uključivo. 

int main() {
	int m = 0, n = 0;
	std::cout << "Unesite dva broja: ";
	std::cin >> m >> n;

	for (int i = m; i <= n; i++) {
		int brojac = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) brojac++;
		}
		if (brojac == 2) std::cout << i << std::endl;
	}

	return 0;
}
