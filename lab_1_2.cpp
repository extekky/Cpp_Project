#include <iostream>
#include <bitset>
#include <climits>

int main() 
{
    unsigned int N;
    std::cin >> N;

    // Находим первый значащий бит с конца
    int shift = sizeof(N) * CHAR_BIT - 1; 
    while (shift >= 0 && !(N & (1 << shift))) 
    {
        --shift;
    }

    // Выводим двоичное представление числа начиная с первого значащего бита
    for (int i = shift; i >= 0; --i) 
    {
        std::cout << ((N >> i) & 1);
    }
    std::cout << std::endl;

    return 0;
}
