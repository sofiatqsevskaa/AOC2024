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
            ++ct;
            continue;
        }
        
        bool decreasing = a[1] < a[0];
        if (abs(a[1] - a[0]) > 3 || a[1] == a[0]) continue;
        
        bool isValid = true;
        for (size_t i = 2; i < a.size(); ++i) {
            if (abs(a[i] - a[i - 1]) > 3 || a[i] == a[i - 1] || 
                (decreasing && a[i] > a[i - 1]) || 
                (!decreasing && a[i] < a[i - 1])) {
                isValid = false;
                break;
            }
        }
        
        if (isValid) ++ct;
    }
    
    inputFile.close();
    cout << ct << endl;
    return 0;
}
