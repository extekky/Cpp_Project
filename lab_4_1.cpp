#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <locale>


// Функция для сравнения строк без учета регистра
bool caseInsensitiveCompare(const std::string &str1, const std::string &str2) 
{
    std::locale loc;
    for (std::string::size_type i = 0; i < str1.length() && i < str2.length(); ++i) 
    {
        if (std::tolower(str1[i], loc) != std::tolower(str2[i], loc))
            return std::tolower(str1[i], loc) < std::tolower(str2[i], loc);
    }
    return str1.length() < str2.length();
}

int main() 
{
    int N;
    std::cin >> N;
    std::vector<std::string> strings(N);

    for (int i = 0; i < N; ++i) 
    {
        std::cin >> strings[i];
    }

    std::sort(strings.begin(), strings.end(), caseInsensitiveCompare);

    for (const auto &str : strings) 
    {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
