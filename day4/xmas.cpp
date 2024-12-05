#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    vector<vector<char>> matrix;
    string line;
    ifstream inputFile("day4/input_day4.txt");
    if (!inputFile) {
        cerr << "Error" << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        vector<char> row(line.begin(), line.end());
        matrix.push_back(row);
    }
    inputFile.close();

    const int directions[8][2] = {
        {0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}
    };
    const string word = "XMAS";
    int n = matrix.size();
    int m = matrix[0].size();
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int dir = 0; dir < 8; dir++) {
                bool match = true;
                for (int k = 0; k < word.size(); k++) {
                    int newRow = i + k * directions[dir][0];
                    int newCol = j + k * directions[dir][1];
                    if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= m || matrix[newRow][newCol] != word[k]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;
    return 0;
}
