#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
    int N = 10;
    std::vector<int> S = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    // Сортировка вектора
    std::sort(S.begin(), S.end());

    // Расчет суммы всех элементов
    int total_sum = std::accumulate(S.begin(), S.end(), 0);

    // Векторы для групп
    std::vector<int> first_group, second_group, third_group;

    // Текущая сумма для групп
    int current_sum = 0;

    // Разделение вектора на группы
    for (int number : S) {
        if (current_sum + number <= total_sum / 3) {
            first_group.push_back(number);
            current_sum += number;
        } else if (current_sum + number <= total_sum * 2 / 3) {
            second_group.push_back(number);
            current_sum += number;
        } else {
            third_group.push_back(number);
        }
    }

    // Вывод результатов
    for (int number : first_group) std::cout << number << ' ';
    std::cout << std::endl;

    for (int number : second_group) std::cout << number << ' ';
    std::cout << std::endl;

    for (int number : third_group) std::cout << number << ' ';
    std::cout << std::endl;

    return 0;
}
