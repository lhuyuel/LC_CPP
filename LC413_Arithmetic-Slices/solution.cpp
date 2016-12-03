/*
    if A is arithmetic, all subarrays with len > 3 are valid slice
    f(i,j) is the number of valid slice f(i,j) = f(i,j-1) * 2 +1 if A[i,j] is arithmetic
*/

    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<int> dp(n, 0);
        int count = 0;
        for (int i = 2; i < n; ++i) {
            if (A[i] - A[i-1] == A[i-1] - A[i-2])
                dp[i] = dp[i-1] + 1;
            count += dp[i];
        }
        return count;
    }
