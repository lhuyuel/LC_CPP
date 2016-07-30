class Solution {
public:

    // f(n) = f(0)*f(n-1) + f(1) *f(n-2) +...+ f(n-1)*f(0)
    // f(0) = 1, f(1) = 1
    // f(2) = 1*1 + 1*1 = 2
    // test case: n =3:
    //   k = 2
    // catlan[2] = 2
    // c[3] = c[0]*c[2] =2             c[3] = 2 + c[1]*c[1] =3      c[3] = 3 + c[2]*c[0] = 5
    
    
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