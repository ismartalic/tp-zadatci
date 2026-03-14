#include <iostream>

// ZSR1 Z16
// Neka je 𝑛 prirodan broj, i neka je 𝑛  proizvod cifara broja 𝑛, 𝑛  proizvod cifara broja 𝑛 , 𝑛  proizvod cifara broja 𝑛  itd. 
// Najmanji broj   za koji vrijedi da je 𝑛  jednocifren broj u teoriji brojeva se naziva multiplikativna otpornost broja 𝑛. 
// Na primjer, multiplikativna otpornost broja 6788 iznosi 6, 
// jer je: 𝑛    6 ∙ 7 ∙ 8 ∙ 8   2688 𝑛    2 ∙ 6 ∙ 8 ∙ 8   768 𝑛    7 ∙ 6 ∙ 8   336 𝑛    3 ∙ 3 ∙ 6   54 𝑛    5 ∙ 4   20 𝑛    2 ∙ 0   0 
// Napišite funkciju “MultOtpornost” koja kao parametar prima prirodan broj 𝑛 a vraća kao rezultat njegovu multiplikativnu otpornost. 
// Napisanu funkciju trebate demonstrirati na kratkom testnom programu koji će ispisati sve brojeve u opsegu od 𝑎 do 𝑏 uključivo koji 
// imaju zadanu multiplikativnu otpornost   pri cemu se vrijednosti 𝑎, 𝑏 i   zadaju putem tastature. Na primjer, ukoliko se za 𝑎, 𝑏 i   
// unesu vrijednosti 9985, 10002 i 3, treba da se ispišu brojevi 9987, 9988, 9989, 9992, 9993, 9994, 9995, 9998 i 9999, jer ti brojevi u 
// zadanom intervalu imaju multiplikativnu otpornost 3. Napomena: Za sve razumne vrijednosti 𝑛, multiplikativna otpornost ima uglavnom 
// jednocifrenu vrijednost, pa o tome vodite računa kada budete testirali program. Brojevi koji imaju multiplikativnu otpornost veću od 9 
// izrazito su rijetki  

int MultOtpornost(int n) {
	int k = 0;
	while (n > 9) {
		int x = n;
		int z = 1;
		while (x != 0) {
			z *= (x % 10);
			x /= 10;
		}
		k++;
		n = z;
	}

	return k;
}

int main() {
	int a = 0, b = 0, k = 0;
	std::cout << "Unesite interval od a do b >> ";
	std::cin >> a >> b;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite k >> ";
	std::cin >> k;

	for (int i = a; i <= b; i++) {
		if (MultOtpornost(i) == k) std::cout << i << std::endl;
	}

	return 0;
}
