class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char map_s[128] = {0};
        char map_t[128] = {0};
        int len = s.size(); 
        for(int i=0; i < len; ++i){
            if (map_s[s[i]] != map_t[t[i]])
                return false;
            // record last occurence pos
            map_s[s[i]] = map_t[t[i]] = i+1;
        }
        return true;
        
    }
};