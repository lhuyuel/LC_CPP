class Solution {
public:
/*
n -> 1
    if (n%2 == 0) f(n) = f(n/2) + 1
    else f(n) = min(f((n-1)/2), f((n+1)/2) + 2;
*/

/*
    int integerReplacement(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[1] = dp[0] = 0;
        int cur = INT_MAX;
        for (int i = 2; i <= n; ++i)
            dp[i] = (i%2 == 0) ?  dp[i>>1] + 1 : min(dp[(i-1)/2], dp[(i+1)/2]) + 2;
        return dp[n];
    }
*/
    int helper(int n, int step) {
        if (n == 1) return step;
        //int tmpStep = 0;
        if (n%2 == 0) {
            step = helper(n/2, ++step);
        } else{
            step = min(helper(n-1,step+1), helper((n+1), step+1));
        }
        return step;
    }

    int integerReplacement(int n) {
        int step = 0;
        return helper(n,step);
    }
};