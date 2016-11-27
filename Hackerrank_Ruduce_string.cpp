#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
题目：删除连续重复的一对字符，直到没有连续重复的字符。
*/
void reduceS(string &s) {
    int len = s.size();
    int i = 1, tail = 0;
    while (i < len) {
        if (s[i] == s[tail] ) {
            if (i + 1 < len)
                s[tail] = s[i+1];
            else s[tail] = '#'; // indicate the end of the new string
            i += 2;  // skip i+1
        }
        else
            s[++tail] = s[i++];
    }
    s = (s[tail] == '#') ? s.substr(0,tail) : s.substr(0,tail+1);
    if (s.empty()) s = "Empty String";
}

bool isValid(const string &s) {
    for (int i = 0; i < s.size() - 1; ++i) {
        if (s[i] == s[i+1]) return false;
    }
    return true;
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    string s; // number of test cases
    cin >> s;
    while (!isValid(s)) reduceS(s);
    cout << s;
    return 0;
}
