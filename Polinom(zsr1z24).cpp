#include <iostream>

//Napišite program koji će prvo tražiti od korisnika da unese realan broj   i stepen polinoma N, 
// a zatim koeficijente polinoma 𝑎 , 𝑎   , 𝑎   , ... 𝑎 , 𝑎 , 𝑎  (počev od koeficijenta uz najveći stepen). 
// Nakon toga, program treba da izračuna i ispiše vrijednost polinoma   P( ) = 𝑎     + 𝑎         + 𝑎         + ... + 𝑎     + 𝑎    + 𝑎    
// U programu ne treba koristiti nizove, s obzirom da se vrijednost polinoma može lako izračunati u “hodu” 
// (tj. bez potrebe za pamćenjem koeficijenata). Najboljim rješenjem će se smatrati rješenje koje ne koristi ni 
// funkciju za stepenovanje, s obzirom da se polinom P( ) može veoma jednostavno izračunati bez stepenovanja pomoću Hornerove sheme:   
// P( ) = ((...((𝑎    + 𝑎   )   + 𝑎   )   + ... + 𝑎 )   + 𝑎 )   + 𝑎  

int main() {
	double x = 0;
	int N = 0;
	std::cout << "Unesite x: ";
	std::cin >> x;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	std::cout << "Unesite stepen polinoma: ";
	std::cin >> N;
	std::cin.clear();
	std::cin.ignore(10000, '\n');
	int an = 0;
	std::cout << "Unesite koeficijent polinoma: ";
	std::cin >> an;
	

	double rez = an * x;
	for (int i = N - 1; i > -1; i--) {
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		std::cout << "Unesite koeficijent polinoma: ";
		std::cin >> an;

		rez += an;
		if (i == 0) break;
		rez *= x;
	}

	std::cout << "Rezultat polinoma je " << rez << std::endl;

	return 0;
}
