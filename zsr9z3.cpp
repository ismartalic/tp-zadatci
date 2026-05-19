#include <iostream>
#include <cmath>

class Tacka {
	double x = 0., y = 0.;
public:
	void Postavi(double x, double y) { Tacka::x = x; Tacka::y = y; }
	void PostaviPolarno(double ro, double theta);
	double DajX() const { return x; }
	double DajY() const { return y; }
	double DajRo() const { return std::sqrt(x * x + y * y); }
	double DajTheta() const { return std::atan2(y, x); }
	void PostaviX(double x) { Tacka::x = x; }
	void PostaviY(double y) { Tacka::y = y; }
	bool DaLiJeKoordinatniPocetak() const { return x == 0. && y == 0.; }
	void Transliraj(double delta_x, double delta_y) { x += delta_x; y += delta_y; }
	void Rotiraj(double alpha);
	void Rotiraj(double alpha, const Tacka &centar);
	friend bool DaLiSuIdenticne(const Tacka& t1, const Tacka& t2);
	friend double Rastojanje(const Tacka& t1, const Tacka& t2);
};

void Tacka::PostaviPolarno(double ro, double theta) {
	x = ro * std::cos(theta);
	y = ro * std::sin(theta);
}

void Tacka::Rotiraj(double alpha, const Tacka& centar) {
	double xc = centar.DajX(); double yc = centar.DajY();
	double x_rez = xc + (DajX() - xc) * std::cos(alpha) - (DajY() - yc) * std::sin(alpha);
	double y_rez = yc + (DajX() - xc) * std::sin(alpha) + (DajY() - yc) * std::cos(alpha);
	x = x_rez; y = y_rez;
}

void Tacka::Rotiraj(double alpha) {
	Tacka t1;
	t1.Postavi(0, 0);
	Rotiraj(alpha, t1);
}

bool DaLiSuIdenticne(const Tacka& t1, const Tacka& t2) {
	return t1.DajX() == t2.DajX() && t1.DajY() == t2.DajY();
}

double Rastojanje(const Tacka& t1, const Tacka& t2) {
	return std::sqrt(std::pow((t2.DajX() - t1.DajX()), 2) + std::pow((t2.DajY() - t1.DajY()), 2));
}

int main() {
    const double PI = 4 * atan(1);

    Tacka t1, t2, t3;

    std::cout << "===== TEST POSTAVI =====\n";
    t1.Postavi(3, 4);
    std::cout << "t1 = (" << t1.DajX() << ", " << t1.DajY() << ")\n";

    std::cout << "\n===== TEST POLARNIH KOORDINATA =====\n";
    t2.PostaviPolarno(5, PI / 2);
    std::cout << "t2 = (" << t2.DajX() << ", " << t2.DajY() << ")\n";

    std::cout << "\n===== TEST DajRo I DajTheta =====\n";
    std::cout << "Ro(t1) = " << t1.DajRo() << "\n";
    std::cout << "Theta(t1) = " << t1.DajTheta() << "\n";

    std::cout << "\n===== TEST PostaviX / PostaviY =====\n";
    t1.PostaviX(10);
    t1.PostaviY(-2);
    std::cout << "t1 = (" << t1.DajX() << ", " << t1.DajY() << ")\n";

    std::cout << "\n===== TEST KOORDINATNOG POCETKA =====\n";
    t3.Postavi(0, 0);

    if (t3.DaLiJeKoordinatniPocetak())
        std::cout << "t3 je u koordinatnom pocetku\n";
    else
        std::cout << "t3 NIJE u koordinatnom pocetku\n";

    std::cout << "\n===== TEST TRANSLACIJE =====\n";
    t3.Transliraj(5, -3);
    std::cout << "t3 = (" << t3.DajX() << ", " << t3.DajY() << ")\n";

    std::cout << "\n===== TEST ROTACIJE OKO KOORDINATNOG POCETKA =====\n";

    Tacka t4;
    t4.Postavi(1, 0);

    t4.Rotiraj(PI / 2);

    std::cout << "Rotacija tacke (1,0) za 90 stepeni:\n";
    std::cout << "t4 = (" << t4.DajX() << ", " << t4.DajY() << ")\n";

    std::cout << "\n===== TEST ROTACIJE OKO DRUGE TACKE =====\n";

    Tacka centar;
    centar.Postavi(1, 1);

    Tacka t5;
    t5.Postavi(2, 1);

    t5.Rotiraj(PI / 2, centar);

    std::cout << "Rotacija tacke (2,1) oko (1,1) za 90 stepeni:\n";
    std::cout << "t5 = (" << t5.DajX() << ", " << t5.DajY() << ")\n";

    std::cout << "\n===== TEST IDENTICNOSTI =====\n";

    Tacka a, b;

    a.Postavi(2, 3);
    b.Postavi(2, 3);

    if (DaLiSuIdenticne(a, b))
        std::cout << "a i b su identicne\n";
    else
        std::cout << "a i b nisu identicne\n";

    b.Postavi(7, 8);

    if (DaLiSuIdenticne(a, b))
        std::cout << "a i b su identicne\n";
    else
        std::cout << "a i b nisu identicne\n";

    std::cout << "\n===== TEST RASTOJANJA =====\n";

    Tacka p1, p2;

    p1.Postavi(0, 0);
    p2.Postavi(3, 4);

    std::cout << "Rastojanje = "
        << Rastojanje(p1, p2) << "\n";

    std::cout << "\n===== EDGE CASEOVI =====\n";

    Tacka e1;

    e1.PostaviPolarno(0, PI / 3);

    std::cout << "Polarno sa ro = 0:\n";
    std::cout << "(" << e1.DajX() << ", "
        << e1.DajY() << ")\n";

    Tacka e2;

    e2.Postavi(-5, -5);

    std::cout << "Theta za tacku u III kvadrantu:\n";
    std::cout << e2.DajTheta() << "\n";

    Tacka e3;

    e3.Postavi(1, 1);

    e3.Rotiraj(2 * PI);

    std::cout << "Rotacija za 360 stepeni:\n";
    std::cout << "(" << e3.DajX() << ", "
        << e3.DajY() << ")\n";

    return 0;
}
