#include <iostream> 

//Napišite program koji za prirodan broj 𝑛 unesen sa tastature nalazi i ispisuje 𝑛-ti po redu prost broj. 
//Na primjer, ukoliko se unese 𝑛 = 30, program treba da ispiše 113, jer je 113 trideseti po redu prost broj. 

int main() {
	int n = 0;
	std::cout << "Unesite broj: ";
	std::cin >> n;

	int prost = 0;
	int j = 1;
	while (prost < n) {
		int brojac = 0;
		for (int i = 1; i <= j; i++)
			if (j % i == 0) brojac++;
		if (brojac == 2) prost++;
		if (prost == n) {
			std::cout << j;
			break;
		}
		j++;
	}

	return 0;
}
