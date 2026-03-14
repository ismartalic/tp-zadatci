#include <iostream>
#include <iomanip>

//Napišite program koji traži da se sa tastature unesu cijeli brojevi 𝑛 i 𝑚, 
// a koji zatim iscrtava na ekranu pravougaonik sastavljen od zvjezdica čije su dužine stranica respektivno 𝑛 i 𝑚. 
// Na primjer, za 𝑛 = 15 i 𝑚 = 6, ispis na ekranu treba da izgleda kao   
// ***************  
// *             *  
// *             *  
// *             *  
// *             *  
// *************** 

int main() {
	int n = 0, m = 0;
	std::cout << "Unesite dimenzije: ";
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) std::cout << "*";
	std::cout << std::endl;
	for (int i = 0; i < (m - 2); i++) std::cout << "*" << std::setw(n - 1) << std::right << "*" << std::endl;
	for (int i = 0; i < n; i++) std::cout << "*";
 
	return 0;
}
