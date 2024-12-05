#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    ifstream f_in("day3/input_day3.txt");
    if (!f_in.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }

    string line;
    long long res = 0;
    bool dont = false;

    while (getline(f_in, line)) {
        for (int i = 0; i < line.length() - 6; i++) {
            if (line[i] == 'd' && line[i + 1] == 'o' && line[i + 2] == 'n' && line[i + 3] == '\'' 
                && line[i + 4] == 't' && line[i + 5] == '(' && line[i + 6] == ')') {
                dont = true;
            }
            else if (line[i] == 'd' && line[i + 1] == 'o' && line[i + 2] == '(' && line[i + 3] == ')') {
                dont = false;
            }

            if (line[i] == 'm' && line[i + 1] == 'u' && line[i + 2] == 'l' && line[i + 3] == '(' && !dont) {
                i += 4;
                bool scnd = false;
                int a = 0, b = 0;

                while (true) {
                    if (line[i] == ',') {
                        scnd = true;
                        i++;
                        continue;
                    } else if (line[i] == ')' && scnd) {
                        res += a * b;
                        break;
                    } else if (!isdigit(line[i])) {
                        break;
                    }

                    if (scnd) {
                        b = b * 10 + (line[i] - '0');
                    } else {
                        a = a * 10 + (line[i] - '0');
                    }

                    i++;
                }
            }
        }
    }

    cout << res << '\n';

    f_in.close();

    return 0;
}
