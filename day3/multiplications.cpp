#include <iostream>
#include <fstream>
#include <string>
#include <regex>

using namespace std;

int sum(const string& input) {
    regex validMulPattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
    smatch match;
    string::const_iterator searchStart(input.cbegin());
    int totalSum = 0;

    while (regex_search(searchStart, input.cend(), match, validMulPattern)) {
        int x = stoi(match[1].str());
        int y = stoi(match[2].str());
        totalSum += x * y;
        searchStart = match.suffix().first;
    }

    return totalSum;
}

int main() {
    ifstream inputFile("day3/input_day3.txt");
    if (!inputFile.is_open()) {
        cerr << "Error" << endl;
        return 1;
    }

    string input;
    getline(inputFile, input);
    inputFile.close();

    int res = sum(input);
    cout << res << endl;

    return 0;
}
