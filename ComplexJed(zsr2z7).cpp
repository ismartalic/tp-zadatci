#include <iostream>
#include <complex>
#include <cmath>

int main() {
	std::complex<double> a, b, c;
	std::cout << "Unesite koeficijente kvadratne jednacine: ";
	std::cin >> a >> b >> c;

	if (a.real() == 0 && a.imag() == 0) {
		std::complex<double> x(-c / b);
		
		if (x.imag() == 0 && x.real() != 0) std::cout << "X = " << x.real() << std::endl;
		else if (x.real() == 0 && x.imag() != 0) std::cout << "X = " << ((x.imag() > 0) ? " + " : " - ") << std::fabs(x.imag()) << "i" << std::endl;
		else std::cout << "X = " << x.real() << ((x.imag() > 0) ? " + " : " - ") << std::fabs(x.imag()) << "i" << std::endl;

		return 0;
	}

	std::complex<double> d(b * b - 4. * a * c);
	
	std::complex<double> x1((-b + std::sqrt(d)) / (2. * a));
	std::complex<double> x2((-b - std::sqrt(d)) / (2. * a));

	if (x1.imag() == 0 && x1.real() != 0) std::cout << "X1 = " << x1.real() << std::endl;
	else if (x1.real() == 0 && x1.imag() != 0) std::cout << "X1 = " << ((x1.imag() > 0) ? " + " : " - ") << std::fabs(x1.imag()) << "i" << std::endl;
	else std::cout << "X1 = " << x1.real() << ((x1.imag() > 0) ? " + " : " - ") << std::fabs(x1.imag()) << "i" << std::endl;

	if (x2.imag() == 0 && x2.real() != 0) std::cout << "X2 = " << x2.real() << std::endl;
	else if (x2.real() == 0 && x2.imag() != 0) std::cout << "X2 = " << ((x2.imag() > 0) ? " + " : " - ") << std::fabs(x2.imag()) << "i" << std::endl;
	else std::cout << "X2 = " << x2.real() << ((x2.imag() > 0) ? " + " : " - ") << std::fabs(x2.imag()) << "i" << std::endl;



	return 0;
}
