#include <iostream>
#include <vector>

// Napišite funkciju “Podbroj” sa dva parametra “n” i “parnost”, od kojih je prvi cjelobrojnog a drugi logičkog tipa. 
// Ukoliko parametar “parnost” ima vrijednost “true”, funkcija treba da kao rezultat vrati broj koji se sastoji samo 
// od parnih cifara broja “n” (uzetih u istom poretku), a ukoliko parametar “parnost” ima vrijednost “false”, 
// funkcija treba da kao rezultat vrati broj koji se sastoji samo od neparnih cifara broja “n”.

int Podbroj(int n, bool parnost) {
	if (parnost) {
		std::vector<int> v1;
		while (n != 0) {
			int x = n % 10;
			if (x % 2 == 0) v1.push_back(n % 10);
			n /= 10;
		}

		std::vector<int> parni;
		for (int i = v1.size() - 1; i >= 0; i--) parni.push_back(v1[i]);

		int broj = 0;
		for (int x : parni) broj = broj * 10 + x;

		return broj;
	}
	else {
		std::vector<int> v2;
		while (n != 0) {
			int x = n % 10;
			if (x % 2 != 0) v2.push_back(n % 10);
			n /= 10;
		}

		std::vector<int> neparni;
		for (int i = v2.size() - 1; i >= 0; i--) neparni.push_back(v2[i]);

		int broj = 0;
		for (int x : neparni) broj = broj * 10 + x;

		return broj;
	}
}

int main() {

	std::cout << Podbroj(3427816, true) << std::endl;
	std::cout << Podbroj(3427816, false) << std::endl;

	return 0;
}
