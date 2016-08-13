class Solution {
public:
    //  DP
    int numSquares(int n) {
        vector<int> squares;
        for (int i = 1; i*i <= n; ++i)
            squares.push_back(i*i);
        static vector<int> dp{0};
        dp.resize(n+1, INT_MAX); 
        // dp(n) = min(dp(n-squares[i]),....,) + 1
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < squares.size() && i>= squares[j] ; ++j) {
                dp[i] = min(dp[i-squares[j]], dp[i]);
            }
            ++dp[i];
        }
        return dp[n];
    }
};