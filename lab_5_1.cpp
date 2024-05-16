#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct IP {
private:
    vector<int> ip;

public:
    explicit IP(const string& ip_) {
        stringstream ss(ip_);
        int octet;
        char dot;
        bool isValid = true;

        for (int i = 0; i < 4; ++i) {
            if (!(ss >> octet)) {
                isValid = false;
                break;
            }
            if (octet < 0 || octet > 255) {
                isValid = false;
                break;
            }
            ip.push_back(octet);
            if (i < 3 && !(ss >> dot && dot == '.')) {
                isValid = false;
                break;
            }
        }

        if (!isValid || !ss.eof()) {
            ip = {0, 0, 0, 0};
        }
    }

    void Print() {
        for (int i = 0; i < ip.size(); ++i) {
            cout << ip[i];
            if (i < ip.size() - 1) {
                cout << ".";
            }
        }
        cout << endl;
    }
};


int main() {
    IP a("0.0.0.0");
    a.Print();

    IP b("255.255.255.252");
    b.Print();

    IP c("1000.2.2.2");
    c.Print();

    return 0;
}
