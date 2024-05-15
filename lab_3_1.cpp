#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main() 
{
    std::string operation;
    std::vector<bool> queue;
    int Q, i, k;

    std::cin >> Q; // Считываем количество операций
    
    for (int q = 0; q < Q; ++q) 
    {
        std::cin >> oper
    for (int q = 0; q < Q; ++q) ation;
        if (operation == "WORRY") 
        {
            std::cin >> i;
            queue[i] = true; // Помечаем i-го человека как беспокоящегося
        } 
        else if (operation == "QUIET") 
        {
            std::cin >> i;
            queue[i] = false; // Помечаем i-го человека как успокоившегося
        } 
        else if (operation == "COME") 
        {
            std::cin >> k;
            if (k > 0) 
            {
                queue.insert(queue.end(), k, false); // Добавляем k спокойных людей в конец
            } 
            else if (k < 0) 
            {
                queue.erase(queue.end() + k, queue.end()); // Убираем k человек из конца
            }
        } 
        else if (operation == "WORRY_COUNT") 
        {
            std::cout << std::count(queue.begin(), queue.end(), true) << std::endl; // Выводим количество беспокоящихся
        }
    }
    return 0;
}
