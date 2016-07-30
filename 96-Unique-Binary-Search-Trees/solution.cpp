class Solution {
public:

    // DP
    // f(n) = f(0)*f(n-1) + f(1) *f(n-2) +...+ f(n-1)*f(0)
    
    int numTrees(int n) {
        vector<int> catlan(n+1,0);
        catlan[0] = catlan[1] = 1;
        
        for(int k = 2; k <= n; ++k) {
            for (int i = 0; i < k; ++i) {
                catlan[k] += (catlan[i] * catlan[k-i-1]);
            }
        }
        return catlan[n];
    }
};