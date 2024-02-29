#include <iostream>
#include <string>
#include <vector>
#include <sstream>

std::vector<std::string> splitString(const std::string& input) {
    std::vector<std::string> result;
    std::stringstream ss(input);
    std::string word;

    while (ss >> word) {
        result.push_back(word);
    }

    return result;
}

int main() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    // Удаление повторяющихся пробелов
    std::string cleanedInput;
    for (size_t i = 0; i < input.size(); ++i) {
        if (input[i] != ' ' || (i > 0 && input[i - 1] != ' ')) {
            cleanedInput += input[i];
        }
    }

    std::vector<std::string> cleanedWords = splitString(cleanedInput);

    // Вывод результата
    std::cout << "Разделенные слова: " << std::endl;
    for (const auto& word : cleanedWords) {
        std::cout << word << std::endl;
    }

    return 0;
}
