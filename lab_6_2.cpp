#include <iostream>
#include <vector>
#include <string>

struct Student {
    std::string name;
    std::string surname;
    int day;
    int month;
    int year;
};

int main() {
    int N; // Число студентов
    std::cin >> N;

    std::vector<Student> students(N); // Вектор структур "Студент"

    // Заполнение вектора данными о студентах
    for (int i = 0; i < N; ++i) {
        std::cin >> students[i].name >> students[i].surname;
        std::cin >> students[i].day >> students[i].month >> students[i].year;
    }

    int M; // Число запросов
    std::cin >> M;

    for (int i = 0; i < M; ++i) {
        std::string query;
        int K;
        std::cin >> query >> K;

        // Проверка корректности номера студента
        if (K < 1 || K > N) {
            std::cout << "bad request\n";
            continue;
        }

        // Обработка запросов
        if (query == "name" && K <= N) {
            std::cout << students[K - 1].name << " " << students[K - 1].surname << "\n";
        } else if (query == "date" && K <= N) {
            std::cout << students[K - 1].day << "." << students[K - 1].month << "." << students[K - 1].year << "\n";
        } else {
            std::cout << "bad request\n";
        }
    }

    return 0;
}
