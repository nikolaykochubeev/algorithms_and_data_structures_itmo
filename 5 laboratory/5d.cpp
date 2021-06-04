#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <sstream>

using namespace std;

class Quack {
private:
    uint16_t registers[26]{};
    queue<uint16_t> q;
    vector<pair<string, int>> labels;

public:
    Quack() {
        for (auto item : registers) {
            item = 0;
        }
    }

    void plus() {
        uint16_t x = q.front();
        q.pop();
        uint16_t y = q.front();
        q.pop();
        uint16_t result = x + y;
        q.push(result);
    }

    void minus() {
        uint16_t x = q.front();
        q.pop();
        uint16_t y = q.front();
        q.pop();
        uint16_t result = x - y;
        q.push(result);
    }

    void multiply() {
        uint16_t x = q.front();
        q.pop();
        uint16_t y = q.front();
        q.pop();
        uint16_t result = x * y;
        q.push(result);
    }

    void div() {
        uint16_t x = q.front();
        q.pop();
        uint16_t y = q.front();
        q.pop();
        if (y == 0) {
            q.push(0);
            return;
        }

        uint16_t result = x / y;
        q.push(result);
    }

    void mod() {
        uint16_t x = q.front();
        q.pop();
        uint16_t y = q.front();
        q.pop();

        if (y == 0) {
            q.push(0);
            return;
        }

        uint16_t result = x % y;
        q.push(result);
    }

    void set_register(char r) {
        uint16_t x = q.front();
        q.pop();
        registers[r - 'a'] = x;
    }

    void get_register(char r) {
        uint16_t res = registers[r - 'a'];
        q.push(res);
    }

    uint16_t print() {
        uint16_t x = q.front();
        q.pop();
        return x;
    }

    uint16_t print_register(char r) {
        return registers[r - 'a'];
    }

    char print_char() {
        uint16_t x = q.front() % 256;
        q.pop();
        return (char)x;
    }

    char print_register_char(char r) {
        return (char)registers[r - 'a'];
    }

    void add_label(string s, int i) {
        labels.emplace_back(s, i);
    }

    int jump_label(const string& s){
        for (const auto& item : labels) {
            if (item.first == s) {
                return item.second;
            }
        }
        cout << "label not found" << endl;
        return INT32_MAX;
    }

    void put(uint16_t x){
        q.push(x);
    }

};

vector<string> v;

int main() {
    freopen("quack.in", "r", stdin);
    freopen("quack.out", "w", stdout);

    string str;
    while (cin >> str) {
        v.push_back(str);
    }

    Quack quack;

    int i = 0;
    while (i < v.size()) {
        str = v[i];
        if (str[0] == ':') {
            str = str.erase(0, 1);
            quack.add_label(str, i);
        }
        i++;
    }

    i = 0;

    while (i < v.size()) {
        str = v[i];
//        cout << str << endl;
        switch (str[0]) {
            case '+':
                quack.plus();
                break;

            case '-':
                quack.minus();
                break;

            case '*':
                quack.multiply();
                break;

            case '/':
                quack.div();
                break;

            case '%':
                quack.mod();
                break;

            case '>':
                quack.set_register(str[1]);
                break;

            case '<':
                quack.get_register(str[1]);
                break;

            case 'P':
                if (str.length() > 1) {
                    cout << quack.print_register(str[1]) << endl;
                } else {
                    cout << quack.print() << endl;
                }
                break;

            case 'C':
                if (str.length() > 1) {
                    cout << quack.print_register_char(str[1]);
                } else {
                    cout << quack.print_char();
                }
                break;

            case ':':
                str = str.erase(0, 1);
                quack.add_label(str, i);
                break;

            case 'J':
                str = str.erase(0, 1);
                i = quack.jump_label(str);
                break;

            case 'Z':
                if (quack.print_register(str[1]) == 0) {
                    str = str.erase(0, 2);
                    i = quack.jump_label(str);
                }
                break;

            case 'E':
                if (quack.print_register(str[1]) == quack.print_register(str[2])) {
                    str = str.erase(0, 3);
                    i = quack.jump_label(str);
                }
                break;

            case 'G':
                if (quack.print_register(str[1]) > quack.print_register(str[2])) {
                    str = str.erase(0, 3);
                    i = quack.jump_label(str);
                }
                break;

            case 'Q':
                i = v.size();
                break;

            default:
                quack.put(stoi(str));
        }

        i++;
    }

    return 0;
}