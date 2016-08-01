class Solution {
public:
    // DP: f(n) = f(n/5) || f(n/3) || f(n/2)
    bool isUgly(int num) {
        vector<int> factors = {2, 3, 5}
        if (num == 0) return false;
        for (auto factor : factors) {
            if (num%factor == 0) 
                while (num) num /= factor;
        }
        return num == 1;
    }
};