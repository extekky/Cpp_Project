#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream file("lab_6_1_input_file.txt");
    int N, M;
    if (file >> N >> M) {
        file.ignore(); // Пропускаем перевод строки после чтения N и M
        for (int i = 0; i < N; ++i) {
            string line;
            getline(file, line);
            stringstream ss(line);
            for (int j = 0; j < M; ++j) {
                int value;
                ss >> value;
                cout << setw(10) << value;
                if (j < M - 1) {
                    cout << " "; // Добавляем пробел между ячейками
                    ss.ignore(); // Пропускаем запятую в CSV
                }
            }
            if (i < N - 1) {
                cout << endl; // Добавляем перевод строки между строками таблицы
            }
        }
    }

    cout << endl;
    
    return 0;
}
