#include <cmath>
#include <vector>
#include <iostream>

int main() 
{
    double A, B, C;
    std::cin >> A >> B >> C;

    if (A == 0) 
    {
        if(B != 0)
        {
            std::cout << -C / B << std::endl;  // Линейное уравнение
        }
        // Если B тоже равно 0, корней нет.
    } 
    else 
    {
        double D = B*B - 4*A*C;  // Дискриминант
        if (D > 0)
        {
            double x1 = (-B + std::sqrt(D)) / (2*A);
            double x2 = (-B - std::sqrt(D)) / (2*A);
            std::cout << x1 << " " << x2 << std::endl;  // Два различных корня
        } else if (D == 0) 
        {
            std::cout << -B / (2*A) << std::endl;  // Один корень
        }
        // Если D < 0, действительных корней нет.
    }
    return 0;
}
