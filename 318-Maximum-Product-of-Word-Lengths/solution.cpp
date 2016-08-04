class Solution {
public:
    // Brute Force解法：O(n^2)
    // 双重循环，isNoCommon(string word1, string word2)
    
    int maxProduct(vector<string>& words) {
        
        // Construct bit table. 'a'则把第一位标1
        vector<int> bitWord(words.size(),0);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = 0; j < words[i].size(); ++j)
                bitWord[i] |= ( 1 << (words[i][j])-'a');
        }
        
        int maxProduct = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i+1; j < words.size(); ++j) {
                if (!(bitWord[i] & bitWord[j]))
                    maxProduct = max(maxProduct, (int) (words[i].length()* words[j].length()));
            }
        }
        return maxProduct;
    }
};