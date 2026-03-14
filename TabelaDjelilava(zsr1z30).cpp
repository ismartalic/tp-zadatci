#include <iostream>
#include <iomanip>

// Napišite program koji traži da se sa tastature unesu prirodni brojevi 𝑛  i 𝑛 , 
// a koji će zatim ispisati tabelu sa dvije kolone, od kojih prva kolona sadrži prirodne brojeve od 𝑛  do 𝑛  uključivo, 
// a druga kolona sumu svih djelilaca odgovarajućih brojeva iz prve kolone. Na primjer, ukoliko je u prvoj koloni broj 10, 
// u drugoj koloni treba da bude broj 18, jer djelioci broja 10 glase 1, 2, 5 i 10, a njihova suma je 1 + 2 + 5 + 10 = 18). 
// Tablicu formatirajte po vlastitom izboru, ali tako da ispisani brojevi budu lijepo poravnati uz desnu ivicu.

int main() {
	int a = 0, b = 0;
	std::cout << "Unesite dva broja: ";
	std::cin >> a >> b;

	std::cout << "+-----+-----+" << std::endl;
	for (int i = a; i <= b; i++) {
		std::cout << "|" << std::setw(4) << std::right << i << " |";
		int suma = 0;
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) suma += j;
		}
		std::cout << std::setw(4) << std::right << suma << " |" << std::endl;
		std::cout << "+-----+-----+" << std::endl;
	}
	

	return 0;
}
