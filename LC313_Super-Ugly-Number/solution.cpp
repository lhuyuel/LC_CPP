class Solution {
public:
    // 类似merge multiple sorted arrays
    // 1*2    2*2    3*2    4*2    5*2    6*2   7*2 ...   *2
    // 1*3    2*3    3*3    4*3    5*3    6*3   7*3  ...  *3
    // 1*5    2*5    3*5    4*5    5*5    6*5   7*5   ... *5
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ug(n+1,INT_MAX);
        ug[1] = 1;
        vector<int> idxTable(primes.size(),0);
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j < primes.size(); ++j) {
                if (ug[idxTable[j]+1]*primes[j] < ug[i])
                    ug[i] = ug[idxTable[j]+1]*primes[j];
            }
            
            for (int j = 0; j < primes.size(); ++j) {
                if (ug[i] == ug[idxTable[j]+1] * primes[j])
                    ++idxTable[j];
            }
         }
         return ug[n];
    }
};