class Solution {
public:
    // 这题和isomophic string很像
    bool wordPattern(string pattern, string str) {
        vector<int> tb_p(26, -1);
        unordered_map<string,int> tb_str;
        istringstream input(str);
        string word;
        for (int i = 0; i < pattern.size(); ++i) {
            input >> word;
            if (word == "") return false;
            // word is not in the table
            if (tb_str.find(word) == tb_str.end()) {
                 if (tb_p[pattern[i]-'a'] != -1 ) 
                    return false;
            }
            
            // word is in the table
            else {
                if (tb_p[pattern[i]-'a'] != tb_str[word]) 
                    return false;
            }
            tb_p[pattern[i]-'a'] = tb_str[word] = i;
        }
        ;
        return !(input >> word);
    }
};