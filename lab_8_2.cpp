#include <iostream>
#include <stdexcept>
#include <numeric> // для std::gcd

using namespace std;

class Rational {
public:
    Rational() : numerator(0), denominator(1) {}

    Rational(int numerator, int denominator) {
        if (denominator == 0) {
            throw invalid_argument("Denominator cannot be zero");
        }
        int gcd = std::gcd(numerator, denominator);
        this->numerator = numerator / gcd;
        this->denominator = denominator / gcd;
        if (this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
    }

    int Numerator() const {
        return numerator;
    }

    int Denominator() const {
        return denominator;
    }

private:
    int numerator;
    int denominator;
};

Rational operator / (const Rational& lhs, const Rational& rhs) {
    if (rhs.Numerator() == 0) {
        throw domain_error("Division by zero");
    }
    return Rational(lhs.Numerator() * rhs.Denominator(), lhs.Denominator() * rhs.Numerator());
}

int main() {
    try {
        Rational r(1, 0);
        cout << "Doesn't throw in case of zero denominator" << endl;
        return 1;
    } catch (invalid_argument& e) {
        cout << "Caught invalid_argument: " << e.what() << endl;
    }

    try {
        auto x = Rational(1, 2) / Rational(0, 1);
        cout << "Doesn't throw in case of division by zero" << endl;
        return 2;
    }
    catch (domain_error& e) {
        cout << "Caught domain_error: " << e.what() << endl;
    }

    cout << "OK" << endl;
    return 0;
}
