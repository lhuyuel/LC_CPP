class Solution {
public:
/* Brute force: calculate all possible sum, and find max, O(n^2)
    A = [4, 3, 2, 6]
  f(0)   0  1  2  3
    1    1  2  3  0
    2    2  3  0  1
    3    3  0  1  2 
    
    i = n-1
    F = F + sum - n * A[i];
    F(0) = 0 * A[0] + 1 * A[1] + ... + (n-1) * A[n-1]
    sum =      A[0] +     A[1] + ... +        A[n-1]
    tmpSum =F(0) + sum= 1*A[0] + 2*A[1] + ... +       n*A[n-1]
    F(1) = tmpSum - n*A[i] = 1*A[0] + 2*A[1] + ... +  0*A[n-1]
    F(2) = F(1) + sum
*/
    int maxRotateFunction(vector<int>& A) {
        int sum = 0, F = 0, n = A.size();
        if (n == 0) return 0;
        for (int i = 0; i < n; ++i) {
            sum += A[i];
            F += i * A[i];
        }
        int result = INT_MIN;
        for (int i = n - 1; i >= 0; --i) {
            F += (sum - n*A[i]);
            result = max(F,result);
        }
        return result;
    }
};