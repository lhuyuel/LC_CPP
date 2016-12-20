/*
https://www.hackerrank.com/challenges/game-of-stones-1
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool isWinConfig(int n) {
    if (n == 1) return false;
    else if (n <= 6) return true;
        
    vector<bool> wTable(n+1, false);
    wTable[2] = wTable[3] = wTable[4] = wTable[5] = true;
    for (int i = 6; i <= n; ++i) {
        wTable[i] = !(wTable[i-2] && wTable[i-3] && wTable[i-5]);
    }
    return wTable[n];
}

int main() {
    int tNum, n;
    cin >> tNum;
    while (tNum--) {
        cin >> n;
        if (isWinConfig(n)) 
            cout << "First"<< endl;
        else cout << "Second" << endl;
    }
    return 0;
}
