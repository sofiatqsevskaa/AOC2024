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

    int br=0;
    int res=0;
    for(int i=0;i<a.size();i++){
        for(int j=br; b[j]<=a[i]; j++){
            if(a[i]==b[j]){
                res+=a[i];
                br++;
            }
        }
    }
    cout<<res<<endl;
    return 0;
}