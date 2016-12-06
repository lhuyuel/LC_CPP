#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
    f(i,j) represents the max score can get start form nums[i] to nums[j]
    f(i,j) = max(f'(i+1,j) + nums[i], 
                 f'(i+2,j) + nums[i] + nums[i+1],
                 f'(i+3,j) + nums[i] + nums[i+1], + nums[i+2])
    f'(i,j) represent the status after player2 has chosen bricks
    f'(i,j) = sum(i,j) - f(i,j)  // sum(i,j) is the sum from nums[i] to the end, f(i,j) is max score play2 can get
    by observation, f(i,j) is actually sum(i,j) - max(f(i+1,j), f(i+2,j), f(i+3,j))
*/
long int maxScore(vector<long int> &nums) {
    int n = nums.size();
    vector<long int> sumN(n,0);
    sumN[n-1] = nums[n-1];
    for (int i = n-2; i >= 0; --i ) {
        sumN[i] = sumN[i+1] + nums[i];  
    }
    
    vector<long int> dp(n, 0);
    for (int i = n-1; i > n-4; --i) dp[i] = sumN[i];
    
    for (int i = n-4; i >= 0; --i) {
        for (int j = 1; j <= 3; ++j) {
            dp[i] = max(dp[i], sumN[i] - dp[i+j]); 
        }
    }
    return dp[0];
}


int main() {
    int testNum;
    cin >> testNum;
    while (testNum--) {
        int n, tmp;
        cin >> n;
        vector<long int> nums;
        while (n--) {
            cin >> tmp;
            nums.push_back(tmp);
        }
        cout << maxScore(nums) << endl;
    }
    return 0;
}

