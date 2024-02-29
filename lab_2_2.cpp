#include <iostream>
#include <vector>

// Функция для вычисления среднего значения
double calculateAverage(const std::vector<int>& temperatures) {
    int sum = 0;
    for (int temp : temperatures) {
        sum += temp;
    }
    return static_cast<double>(sum) / temperatures.size();
}

// Функция для поиска позиций значений вектора, которые превосходят заданное значение
std::vector<int> findTemperaturesAboveAverage(const std::vector<int>& temperatures, double average) {
    std::vector<int> positions;
    for (int i = 0; i < temperatures.size(); ++i) {
        if (temperatures.at(i) > average) {
            positions.push_back(i);
        }
    }
    return positions;
}

int main() {
    int N;
    std::cout << "Enter the number of days: ";
    std::cin >> N;

    std::vector<int> temperatures(N);
    std::cout << "Enter temperatures for " << N << " days:\n";
    for (int i = 0; i < N; ++i) {
        std::cin >> temperatures[i];
    }

    double average = calculateAverage(temperatures);
    std::vector<int> positionsAboveAverage = findTemperaturesAboveAverage(temperatures, average);

    std::cout << "Days with temperature above average (" << average << "):\n";
    for (int pos : positionsAboveAverage) {
        std::cout << pos << " ";
    }
    std::cout << "\nCount: " << positionsAboveAverage.size() << std::endl;

    return 0;
}
