#include <iostream>

// Još je Heronu prije 2000 godina bio poznat sljedeći postupak (algoritam) za računanje kvadratnog korijena proizvoljnog broja  : 
// formira se niz brojeva 𝑎 , 𝑎 , 𝑎  itd. po sljedećem pravilu: 𝑎  = 1;     𝑎    = (𝑎  +  /𝑎 )/2  za    > 0 
// Ovaj niz konvergira vrlo brzo ka korijenu iz  . U praksi je dovoljno izračunati samo nekoliko elemenata ovog niza, 
// jer se vrlo brzo elementi počinju praktično ponavljati (sa onolikom tačnošću koliku dopušta realni tip podataka). 
// Tada postupak možemo obustaviti, i posljednju izračunatu vrijednost 𝑎  proglasiti traženim korijenom. 
// Napišite funkciju “korijen” koja računa korijen svog argumenta Heronovim postupkom (postupak prekinite 
// kada razlika između dvije susjedne izračunate vrijednosti padne ispod vrijednosti ε ∙ |   | 
// gdje je ε neka vrlo mala relativna tolerancija, recimo ε = 10   ) . Za realizaciju funkcije ne koristiti nizove. 
// Napisanu funkciju testirajte u glavnom programu koji za argument unesen sa tastature ispisuje 
// vrijednosti korijena korištenjem funkcije “korijen” kao i korištenjem ugrađene funkcije “sqrt” (naravno, rezultati treba da budu isti). 

double korijen(double x) {
	if (x == 0.) return 0;

	const double eps = 1e-12;
	double x_staro = 1;

	for (;;) {
		double x_novo = (x_staro + x / x_staro) / 2;
		if (std::fabs(x_novo - x_staro) < eps * std::fabs(x_novo)) return x_novo;
		x_staro = x_novo;
	}
}

int main() {
	double x = 0;
	std::cout << "Unesite x: ";
	std::cin >> x;

	std::cout << "Izracunat korijen: " << korijen(x) << std::endl;
	std::cout << "Sqrt korijen: " << std::sqrt(x) << std::endl;

	return 0;
}
