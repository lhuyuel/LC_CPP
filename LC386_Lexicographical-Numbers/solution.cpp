class Solution {
public:
    // Solution1: convert to string and sort, O(nlogn)
    
    /* Solution2:
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        for (int i = 1; i <= 9; ++i) {
            int tmp = i;
            int upper = tmp + 1;
            while (tmp <= n) {
                for (int j = tmp; j < upper; ++j) {
                    if (j <= n)
                        result.push_back(j);
                    else break;
                }
                upper = (tmp+1) * 10;
                tmp *= 10;
            }   
        }
        return result;
    }
    */
    
    vector<int> lexicalOrder(int n) {
        vector<int> result;
        int i = 1, j = 0, k = 0;
        while (1) {
            for (int k = 0; i*pow(10,k) <= n; ++k) 
                result.push_back(i*pow(10,k));
                
            for (j = result.back() + 1; j <= n && (j%10) != 0; ++j) {
                result.push_back(j);
            }
            
            if (j % 10 == 0) --j;
            else j /= 10;
            
            while (j%10 == 9) j /= 10;
            i = j + 1;
            if (result.size() >= n) break;
        }
        return result;
    }
    
};