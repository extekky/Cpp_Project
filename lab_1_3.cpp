#include <iostream>
#include <algorithm>
#include <string>

int main() 
{
    std::string str;
    std::getline(std::cin, str);  // Считываем строку с пробелами

    // Удаляем все пробелы из строки
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    // Проверяем, является ли строка палиндромом
    std::string reversed_str = str;
    std::reverse(reversed_str.begin(), reversed_str.end());

    if (str == reversed_str) 
    {
        std::cout << "Yes" << std::endl;
    } else 
    {
        std::cout << "No" << std::endl;
    }

    return 0;
}
