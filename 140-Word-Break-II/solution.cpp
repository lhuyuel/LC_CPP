class Solution {
public:

    // breakable stores if the remaining part is breakable or not
    bool dfs(const string &s, int start, unordered_set<string>& wordDict, 
            vector<bool> &potential, vector<string> &result, string path) {
        // termination condition
        int n = s.size();
        if (start == n) {
            path.resize(path.size()-1);
            result.push_back(path);
            return true;
        }
        
        string word = "";
        bool breakable = false;
        for (int i = start; i < n; ++i) {
            word = s.substr(start,i - start + 1);
            if (wordDict.find(word) != wordDict.end() && potential[i+1]) {
                if (dfs(s,i+1, wordDict, potential, result, path + word + " "))
                    breakable =  true;
                else potential[i+1] = false;
            }
        }
        return breakable;
    }

    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
        int n = s.size();
        vector<bool> potential(n+1, true);
        vector<string> result;
        string path;
        dfs(s, 0, wordDict, potential, result, path);
        return result;
    }
};
