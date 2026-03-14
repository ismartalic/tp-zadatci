#include <iostream>

// Napišite funkciju “IzbaciNule” koja ima kao parametar neki prirodan broj, 
//a koja daje kao rezultat isti taj broj, samo iz kojeg su izbačene sve cifre koje su nule. 
//Na primjer, ukoliko se kao parametar funkciji proslijedi broj 35020040, rezultat funkcije treba da bude 3524. 
//Ukoliko broj ne sadrži niti jednu nulu kao svoju cifru, onda je on sam ujedno i rezultat funkcije. 
//Napisanu funkciju trebate demonstrirati u kratkom testnom programu na brojevima koji se unose sa tastature. 
//Program treba da završi rad kada se kao broj unese 0. 

int IzbaciNule(int n) {
	int unazad = 0;

	while (n != 0) {
		if (n % 10 != 0) {
			int cifra = n % 10;
			unazad = unazad * 10 + cifra;
		}
		n /= 10;
	}

	int rjes = 0;
	while (unazad != 0) {
		int cifra = unazad % 10;
		rjes = rjes * 10 + cifra;
		unazad /= 10;
	}

	return rjes;
}

int main() {
	int n = 0;
	std::cout << "Unesite broj: ";
	std::cin >> n;

	n = IzbaciNule(n);

	std::cout << "Broj bez nula je: " << n << std::endl;

	return 0;
}
