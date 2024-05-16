#include <iostream>
using namespace std;


struct Fraction {
public:
    explicit Fraction(const int& p_, const int& q_) {
        if (q_ != 0) {
            int nod = NOD(p_, q_);
            p = p_ / nod;
            q = q_ / nod;
        } else {
            p = 0;
            q = 1;
        }
    }

    void Sum(const Fraction& right) {
        Fraction result(p * right.q + q * right.p, q * right.q);
        result.Print();
    }

    void Subtraction(const Fraction& right) {
        Fraction result(p * right.q - q * right.p, q * right.q);
        result.Print();
    }

    void Composition(const Fraction& right) {
        Fraction result(p * right.p, q * right.q);
        result.Print();
    }

    void Print() {
        cout << p << "/" << q << endl;
    }

    int NOD() {
        return NOD(p, q);
    }

private:
    int p; // Числитель
    int q; // Знаменатель

    static int NOD(int a, int b) {
        return b == 0 ? a : NOD(b, a % b);
    }
};


int main() {
    Fraction a(1, 2), b(3, 4);
    
    a.Print(); // Выведет: 1/2
    b.Print(); // Выведет: 3/4

    // Суммирование
    a.Sum(b); // Выведет: 5/4
    // Разность
    a.Subtraction(b); // Выведет: -1/4
    // Произведение
    a.Composition(b); // Выведет: 3/8

    return 0;
}
