#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
    max diff sum
    https://www.hackerrank.com/challenges/stockmax
    
*/

long long maxProfit(const vector<int> &nums, const int &n) {
    int curMax = nums[n-1];
    long long profit = 0;  
    for (int i = n-1; i >= 0; --i) {
        if (curMax > nums[i]) 
            profit += curMax - nums[i];
        else if (curMax < nums[i])
            curMax = nums[i];
    }
    return profit;
}

int main() {
    int testNum;
    cin >> testNum;
    for (int i = 0; i < testNum; ++i) {
        int n;
        cin >> n;
        vector<int> nums;
        int tmp;
        for (int j = 0; j < n; ++j) {
            cin >> tmp;
            nums.push_back(tmp);
        }
        long long result = maxProfit(nums, n);
        cout << result << endl; 
    }
    return 0;
}
