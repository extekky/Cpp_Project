#include <iostream>
#include <map>
#include <set>
#include <string>

int main() {
    int Q;
    std::cin >> Q;
    std::map<std::string, std::set<std::string>> synonyms;

    for (int i = 0; i < Q; ++i) {
        std::string operation, word1, word2;
        std::cin >> operation;
        if (operation == "ADD") {
            std::cin >> word1 >> word2;
            synonyms[word1].insert(word2);
            synonyms[word2].insert(word1);
        } else if (operation == "COUNT") {
            std::cin >> word1;
            std::cout << synonyms[word1].size() << std::endl;
        } else if (operation == "CHECK") {
            std::cin >> word1 >> word2;
            if (synonyms[word1].find(word2) != synonyms[word1].end()) {
                std::cout << "YES" << std::endl;
            } else {
                std::cout << "NO" << std::endl;
            }
        }
    }
    return 0;
}
