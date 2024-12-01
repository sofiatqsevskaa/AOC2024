#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream inputFile("input.txt"); 
    if (!inputFile) { 
        cerr << "Error: Could not open file." << endl;
        return 1;
    }

    vector<int> a;
    vector<int> b;
    int x, y;

    while (inputFile >> x >> y) {
        a.push_back(x);
        b.push_back(y);
    }
    inputFile.close();

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    int dist = 0;
    for (int i = 0; i < a.size(); i++) {
        dist += abs(a[i] - b[i]);
    }
    cout << dist << endl;

    return 0;
}
