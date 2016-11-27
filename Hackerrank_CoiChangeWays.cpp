#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int target, n;
    cin >> target >> n;
    vector<int> coins(n);
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        coins[i]  = tmp;
    }
    
    /*
        f(i,j) is the number of ways that use first i coins to repersent value j
        f(i,j) = f(i-1,j) + f(i,j-coins[i])
        f(i,i) = 1 initialization
    */
    vector<long int> dp(target+1,0);
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
        for (int j = coins[i]; j <= target; ++j ) {
            dp[j] += dp[j-coins[i]]; 
        }
    }
    
    cout << dp[target];
    return 0;
}
