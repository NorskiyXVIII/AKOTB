#include <iostream>
#include <cmath>
#include <locale.h>

namespace math {
    double poluperimetr(double P) {
        return P / 2;
    }
    double mpoluperimetr(double P) {
        const double res = P / 2;
        std::cout << "p = Pосн. / 2 = " << P << " / " << 2 << " = " << res << " см" << std::endl;
        return res;
    }

    double round_to_one_decimal(double num) {
        return std::round(num * 10.0) / 10.0;
    }

    double geron(double P, double a, double b, double c) {
        return round_to_one_decimal(::sqrt(P * (P - a) * (P - b) * (P - c)));
    }
    double mgeron(double P, double a, double b, double c) {
        double ger = geron(P, a, b, c);
        // ладно, задолбала —++ std::cout и std::cin, выбесили мен€
        std::printf("Sосн = ?p(p - a)(p - b)(p - c) = ?%g(%g - %g)(%g - %g)(%g - %g) = %g см2 \n", P, P, a, P, b, P, c, ger);
        return ger;
    }

    namespace prisma {
        // P осн.
        double POsn(double a, double b, double c) {
            return a + b + c;
        }

        double mPOsn(double a, double b, double c) {
            const double res = POsn(a, b, c);
            std::cout << "Pосн. = AB + BC + AC = " << a << " + " << b << " + " << c << " = " << res << " см" << std::endl;
            return res;
        }

        double Sbok(double P, double h) {
            return P * h;
        }

        double mSbok(double P, double h) {
            const double res = Sbok(P, h);
            std::cout << "Sбок = Pосн * AA1 = " << P << " * " << h << " = " << res << " см2" << std::endl; 
            return res;
        }

        double mSosn(double P, double a, double b, double c) {
            return 0;
        }

        double Spoln(double Sbok, double Sosn) {
            return Sbok + 2 * Sosn;
        }

        double mSpoln(double Sbok, double Sosn) {
            double res = Spoln(Sbok, Sosn);
            std::cout << "Sполн = Sбок + 2 * Sосн = " << Sbok << " + 2 * " << Sosn << " = " << res  << " см2" << std::endl;
            return res;
        }

        double v(double Sosn, double h) {
            return Sosn * h;
        }
        double mV(double Sosn, double h) {
            double res = v(Sosn, h);
            std::printf("V = Sосн. * H = %g * %g = %g см3\n", Sosn, h, res);
            return res;
        }

        struct treug_prisma {
            double a, b, c, h;
        };

        void get_prisma(treug_prisma* prisma) {
            std::cout << "¬ведите AB: ";
            std::cin >> prisma->a;
            std::cout << "¬ведите BC: ";
            std::cin >> prisma->b;
            std::cout << "¬ведите AC: ";
            std::cin >> prisma->c;
            std::cout << "¬ведите AA1(высоту): ";
            std::cin >> prisma->h;
        }

        void print_prisma(const treug_prisma& prisma) {
            std::cout << "AB = " << prisma.a << " см"<< std::endl
            << "AC = "   << prisma.b << " см" << std::endl
            << "BC = "   << prisma.c << " см" << std::endl
            << "AA1 = "  << prisma.h << " см" << std::endl;
        }


        // лень. “реугольников хватит
        struct chetireh_prisma {
            double a, b, c, d, h;
        };
    }
}

namespace resheniya {
    void reshit_prisma_treug(double a, double b, double c, double h) {
        math::prisma::treug_prisma prisma{a, b, c, h};
        math::prisma::get_prisma(&prisma);

        std::cout << "–ешение Sбок: \n";
        double Posn = math::prisma::mPOsn(prisma.a, prisma.b, prisma.c);
        double Sbok = math::prisma::mSbok(Posn, prisma.h);
        std::cout << "–ешение Sполн: \n";
        double Sosn = math::mgeron(math::mpoluperimetr(Posn), prisma.a, prisma.b, prisma.c);
        double mSpoln = math::prisma::mSpoln(Sbok, Sosn);
        std::cout << "–ешение V: \n";
        double v = math::prisma::mV(Sosn, prisma.h);
    }
};

int main() {
    setlocale(LC_ALL, "Rus");
    resheniya::reshit_prisma_treug(1.5, 2.5, 3, 2.5);
    return 0;
}

