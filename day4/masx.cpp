#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

int main() {
    vector<vector<char>> a;
    string line;

    ifstream inputFile("day4/input_day4.txt");
    if (!inputFile) {
        cerr << "Error" << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        vector<char> row(line.begin(), line.end());
        a.push_back(row);
    }
    inputFile.close();

    int n = a.size();
    int m = a[0].size();
    int ct = 0;


    for (int i = 0; i < n - 2; i++) {
        for (int j = 0; j < m - 2; j++) {

            if (i + 2 < n && j + 2 < m) {
                bool masPattern = a[i][j] == 'M' &&
                                  a[i][j + 2] == 'M' &&
                                  a[i + 1][j + 1] == 'A' &&
                                  a[i + 2][j] == 'S' &&
                                  a[i + 2][j + 2] == 'S';

                bool samPattern = a[i][j] == 'S' &&
                                  a[i][j + 2] == 'S' &&
                                  a[i + 1][j + 1] == 'A' &&
                                  a[i + 2][j] == 'M' &&
                                  a[i + 2][j + 2] == 'M';

                bool masSamPattern = a[i][j] == 'M' &&
                                     a[i + 1][j + 1] == 'A' &&
                                     a[i + 2][j] == 'M' &&
                                     a[i][j + 2] == 'S' &&
                                     a[i + 2][j + 2] == 'S';

                bool samMasPattern = a[i][j] == 'S' &&
                                     a[i + 1][j + 1] == 'A' &&
                                     a[i + 2][j] == 'S' &&
                                     a[i][j + 2] == 'M' &&
                                     a[i + 2][j + 2] == 'M';


                if (masPattern || samPattern || masSamPattern || samMasPattern) {
                    ct++;
                }
            }
        }
    }

    cout << ct << endl;

    return 0;
}
