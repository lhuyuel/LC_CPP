class Solution {
public:
/*
s = "loveleetcode",
return 2.
*/
    int firstUniqChar(string s) {
        vector<int> indxTable(26,-1);
        for (int i = 0; i < s.size(); ++i) {
            if (indxTable[s[i]-'a'] == -1) 
                indxTable[s[i]-'a'] = i;
            else if ( indxTable[s[i]-'a'] >= 0 )
                indxTable[s[i] - 'a'] = -2;
        }
        
        int minIdx = INT_MAX;
        for (int i = 0; i < indxTable.size(); ++i) {
            if (indxTable[i] >= 0 && indxTable[i] < minIdx)
                minIdx = indxTable[i];
        }
        return minIdx == INT_MAX ? -1 : minIdx;
    }
};