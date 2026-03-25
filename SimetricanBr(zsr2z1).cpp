#include <iostream>
#include <vector>

// Napišite funkciju koja ima jedan cjelobrojni parametar. 
// Funkcija treba da vrati kao rezultat logičku vrijednost “true” ukoliko je broj simetričan, 
// odnosno ukoliko se isto čita sa obje strane (na primjer, broj 13431 je simetričan). 
// U suprotnom, funkcija vraća kao rezultat logičku vrijednost “false”. 
// Napisanu funkciju trebate demonstrirati u kratkom testnom programu na brojevima koji se unose sa tastature. 
// Program za svaki uneseni broj treba da ispise da li je simetričan ili nije. 

bool Simetrican(int n) {
	std::vector<int> v1, v2;

	int x = n;
	int vel = 0;
	while (x != 0) {
		x /= 10;
		vel++;
	}

	for (int i = 0; i < vel / 2; i++) {
		v2.push_back(n % 10);
		n /= 10;
	}

	if (vel % 2 != 0) n /= 10;
	for (int i = 0; i < vel / 2; i++) {
		v1.push_back(n % 10);
		n /= 10;
	}

	std::vector<int> obrnuti;
	for (int i = v1.size() - 1; i >= 0; i--) {
		obrnuti.push_back(v1[i]);
	}

	if (obrnuti == v2) return true;

	return false;
}

int main() {
	int n;
	std::cout << "Unesite broj: ";
	std::cin >> n;

	std::cout << std::boolalpha << Simetrican(n) << std::endl;


	return 0;
}
