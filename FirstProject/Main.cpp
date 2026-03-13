#include <iostream>

// Za neki broj kažemo da je palindroman ukoliko je jednak broju koji se dobije čitanjem 
// njegovih cifara u obrnutom poretku. Na primjer, broj 6574756 je palindroman broj. 
// Napisati program koji traži da se sa tastature unese cijeli broj 𝑛, 
// a zatim na ekran ispisuje da li je broj 𝑛 palindroman ili nije. 
// Za realizaciju programa ne koristiti nizove niti vektore. 

int main() {
	int x = 0;
	std::cout << "Unesite broj: ";
	std::cin >> x;

	int n = x;
	int vel = 0;
	while (n != 0) {
		n /= 10;
		vel++;
	}

	int obrnuti = 0;
	int z = x;
	for (int i = 0; i < vel; i++) {
		int cifra = z % 10;
		obrnuti = obrnuti * 10 + cifra;
		z /= 10;
	}

	if (obrnuti == x) std::cout << "Broj " << x << " je palindrom." << std::endl;
	else std::cout << "Broj " << x << " nije palindrom." << std::endl;

	return 0;
}