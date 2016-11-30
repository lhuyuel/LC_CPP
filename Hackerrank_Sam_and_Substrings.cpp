// https://www.hackerrank.com/challenges/sam-and-substrings
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define MOD 1000000007

using namespace std;
/*
            Frequency in substrings at positions
    Digit   Unit    Ten     Hundred     Thousand        Sum
    6       1       1       1           1           = 6*1*1111
    7       2       2       2                       = 7*2*111
    8       3       3                               = 8*3*11
    9       4                                       = 9*4*1
*/
long long int subSum(string num) {
    int n = num.size();
    if (n == 0) return 0;
    //vector<vector<int>> dp(n,vector<int>(n,0));
    long long int sum = 0;
    //for (int i = 0; i < n; ++i) dp[i][i] = num[i] - '0';

    long long int f = 1;
    for(int i = n-1; i >= 0; i--) {
        sum = (sum + (num[i]-'0') * f * (i+1)) % MOD;
        f = (f*10+1) % MOD;
    }
    return sum;
}

int main() {
    string num;
    cin >> num;
    long long int result = subSum(num);
    cout << result;
    return 0;
}
