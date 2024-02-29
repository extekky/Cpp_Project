#include <iostream>

int factorial(int number)
{
    if (number <= 1)
    {
        return 1;
    }
    else
    {
        return  number * factorial(number - 1);
    }
}

int main ()
{
    int n;
    std::cin >> n;
    std::cout << factorial(n) << std::endl;
    return 0;
}