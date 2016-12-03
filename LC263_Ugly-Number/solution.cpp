class Solution {
public:
    // 除掉所有的2，3，5看是否等于1
    bool isUgly(int num) {
        vector<int> factors = {2, 3, 5};
        if (num == 0) return false;
        for (auto factor : factors) 
            while (num%factor == 0) num /= factor;
            
        return num == 1;
    }
};