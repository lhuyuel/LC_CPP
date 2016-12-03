class Solution {
public:
    // use array to store char freq
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> freqTable(26,0);
        for (auto c : magazine) {
            ++freqTable[c-'a'];
        }
        
        // check the target string
        for (auto c : ransomNote) {
            if (freqTable[c-'a'] == 0)
                return false;
            else 
                --freqTable[c-'a'];
        }
        return true;
    }
};