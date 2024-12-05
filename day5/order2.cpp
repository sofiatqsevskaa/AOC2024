#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("day5/input_day5.txt");
    if (!inputFile) {
        cerr << "Error" << endl;
        return 1;
    }

    string line;
    vector<pair<int, int>> pairs;
    vector<vector<int>> l;

    while (getline(inputFile, line)) {
        if (line.empty()) break;
        stringstream ss(line);
        int a, b;
        char d;
        ss >> a >> d >> b;
        pairs.push_back(make_pair(a, b));
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

    for (auto& list : l) {
        bool valid = true;

        for (const auto& p : pairs) {
            int first = p.first;
            int second = p.second;

            int indexFirst = -1;
            int indexSecond = -1;

            for (size_t i = 0; i < list.size(); ++i) {
                if (list[i] == first) indexFirst = i;
                if (list[i] == second) indexSecond = i;
            }

            if (indexFirst != -1 && indexSecond != -1 && indexFirst > indexSecond) {
                valid = false;
                break;
            }
        }

        if (!valid) {
            sort(list.begin(), list.end(), [&pairs](int a, int b) {
                for (const auto& pair : pairs) {
                    if (pair.first == a && pair.second == b) {
                        return true;
                    }
                }
                return false;
            });
        }

        int middleIndex = list.size() / 2;
        if (!valid) resultSum += list[middleIndex];
    }

    cout << resultSum << endl;

    return 0;
}
