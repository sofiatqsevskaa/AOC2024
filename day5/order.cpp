#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("day5/input_day5.txt");
    if (!inputFile) {
        cerr << "Error" << endl;
        return 1;
    }

    string line;
    vector<pair<int, int>> p;
    vector<vector<int>> l;

    while (getline(inputFile, line)) {
        if (line.empty()) break;
        stringstream ss(line);
        int a, b;
        char d;
        ss >> a >> d >> b;
        p.push_back(make_pair(a, b));
    }

    while (getline(inputFile, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        vector<int> list;
        int number;
        char d;
        while (ss >> number) {
            list.push_back(number);
            ss >> d;
        }
        l.push_back(list);
    }

    int resultSum = 0;

    for (size_t i = 0; i < l.size(); ++i) {
        bool valid = true;
        for (size_t j = 0; j < p.size(); ++j) {
            int first = p[j].first;
            int second = p[j].second;
            int indexFirst = -1;
            int indexSecond = -1;

            for (size_t k = 0; k < l[i].size(); ++k) {
                if (l[i][k] == first) {
                    indexFirst = k;
                }
                if (l[i][k] == second) {
                    indexSecond = k;
                }
            }

            if (indexFirst != -1 && indexSecond != -1 && indexFirst > indexSecond) {
                valid = false;
            }
        }

        if (valid) {
            int middleIndex = l[i].size() / 2;
            resultSum += l[i][middleIndex];
        }
    }

    cout << resultSum << endl;

    return 0;
}
