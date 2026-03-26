#include <iostream>
#include <vector>

// Napišite funkcije “SviElementiSuJednaki” i “SviElementiSuRazliciti”. 
// Obje funkcije primaju kao parametar jedan vektor realnih brojeva, a vraćaju kao rezultat logičku vrijednost 
// (tj. vrijednost tipa “bool”). Funkcija “SviElementiSuJednaki” vraća vrijednost “true” ako i samo  ako su svi 
// elementi vektora međusobno identični, a u suprotnom vraća “false”. Funkcija “SviElementiSuRazliciti” vraća vrijednost 
// “true” ako i samo ako su svi elementi vektora međusobno različiti (tj. ukoliko nikoja dva elementa nisu međusobno jednaka), 
// a u suprotnom vraća “false”. Napisane funkcije testirajte u glavnom programu (“main” funkciji) u kojem se prvo sa tastature 
// unosi prirodan broj 𝑛 i 𝑛 elemenata vektora, a nakon toga pozivaju napisane funkcije sa ciljem da se utvrdi da li su 
// svi elementi vektora jednaki odnosno različiti (naravno, rezultate obavljene analize treba prikazati na ekranu u vidu odgovarajućih poruka). 

bool SviElementiSuJednaki(std::vector<double> v) {
	for (double x : v) {
		for (int i = 0; i < v.size(); i++) {
			if (x != v[i]) return false;
		}
	}

	return true;
}

bool SviElementiSuRazliciti(std::vector<double> v) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < i; j++) {
			if (v[i] == v[j]) return false;
		}
	}

	return true;
}

int main() {
	std::vector<double> v;

	int n = 0;
	std::cout << "Unesite broj elemenata: ";
	std::cin >> n;

	for (int i = 0; i < n; i++) {
		double x = 0;
		std::cin >> x;
		v.push_back(x);
	}

	std::cout << std::boolalpha << SviElementiSuJednaki(v) << std::endl;
	std::cout << std::boolalpha << SviElementiSuRazliciti(v) << std::endl;

	return 0;
}
