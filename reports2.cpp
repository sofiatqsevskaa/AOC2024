#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile("input_day2.txt");
    if (!inputFile) {
        cerr << "?";
        return 1;
    }

    int ct = 0;
    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) continue;

        stringstream ss(line);
        vector<int> a;
        int num;

        while (ss >> num)
            a.push_back(num);

        if (a.size() == 1) {
            ct++;
            continue;
        }

        auto isGoodSequence = [&](const vector<int>& seq) {
            bool decreasing = seq[1] < seq[0];
            if (abs(seq[1] - seq[0]) > 3 || seq[1] == seq[0]) return false;

            for (size_t i = 2; i < seq.size(); ++i) {
                if (abs(seq[i] - seq[i - 1]) > 3 || seq[i] == seq[i - 1] || 
                    (decreasing && seq[i] > seq[i - 1]) || 
                    (!decreasing && seq[i] < seq[i - 1])) {
                    return false;
                }
            }

            return true;
        };

        if (isGoodSequence(a)) {
            ct++;
            continue;
        }

        bool iCanFixHer = false;
        for (size_t i = 0; i < a.size(); ++i) {
            vector<int> temp = a;
            temp.erase(temp.begin() + i);
            if (isGoodSequence(temp)) {
                iCanFixHer = true;
                break;
            }
        }

        if (iCanFixHer) ct++;
    }

    inputFile.close();
    cout << ct << endl;
    return 0;
}
