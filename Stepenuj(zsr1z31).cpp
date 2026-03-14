#include <iostream>

// Napišite funkciju “stepen” sa dva parametra   i 𝑛 koja računa i vraća kao rezultat    
// bez korištenja funkcije “pow” pri čemu su   i 𝑛 cijeli brojevi proizvoljnog znaka (posebno obratite pažnju da 𝑛 može biti i negativan). 
// Drugim riječima, napišite funkciju koja radi slično kao funkcija “pow” iz biblioteke “cmath” samo za cijele brojeve, 
// bez upotrebe ijedne funkcije iz biblioteke “cmath”. 

double Stepenuj(int x, int n) {
	if (n > 0) {
		int baza = x;
		for (int i = 1; i < n; i++) x *= baza;
	}
	else if (n < 0) {
		n = -n;
		int baza = x;
		for (int i = 1; i < n; i++) x *= baza;
		return 1. / x;
	}
	else if (n == 0) return 1;

	return x;
}

int main() {
	int x = 0, n = 0;
	std::cout << "Unesite x i n: ";
	std::cin >> x >> n;

	std::cout << Stepenuj(x, n) << std::endl;

	return 0;
}
