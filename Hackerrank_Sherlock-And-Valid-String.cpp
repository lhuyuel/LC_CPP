/*
https://www.hackerrank.com/challenges/sherlock-and-valid-string
*/
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isValid(const string &s) {
    int n = s.size();
    vector<int> table(26,0);
    for (char c : s)
        ++table[c-'a'];
    
    unordered_map<int, int> freqTable;
    for (int i = 0 ; i < table.size(); ++i) {
        if (table[i]) {
            ++freqTable[table[i]];
        }
    }

    //cout << freqTable.size() << endl;
    if (freqTable.size() == 1) return true;
    else if (freqTable.size() > 2) return false;
    else {
        for (auto it = freqTable.begin(); it != freqTable.end(); ++it)
            if (it->second == 1) return true;
        return false;
    }
}

int main() {
    string s;
    cin >> s;
    if (isValid(s))
        cout << "YES";
    else cout << "NO";
    return 0;
}

