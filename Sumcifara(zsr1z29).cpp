#include <iostream>

//Napišite program koji traži da se sa tastature unesu dva prirodna broja 𝑎 i 𝑏, 
//i koji ispisuje broj brojeva u rasponu od 𝑎 i 𝑏 (uključujući i 𝑎 i 𝑏) koji su djeljivi sumom svojih cifara 
//(takav je, na primjer, broj 351, jer je djeljiv sa 3 + 5 + 1 = 9). 

int main() {
	int a = 0, b = 0;
	std::cout << "Unesite a i b: ";
	std::cin >> a >> b;

	int brojac = 0;
	for (int i = a; i <= b; i++) {
		int cifre = 0;
		int z = i;
		while (z != 0) {
			cifre += (z % 10);
			z /= 10;
		}
		if (i % cifre == 0) brojac++;
	}

	std::cout << brojac;

	return 0;
}
