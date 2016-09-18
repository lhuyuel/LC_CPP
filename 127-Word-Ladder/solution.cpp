class Solution {
public:
    // BFS
    
    // Find all the strings in the dictionary that can reach by only change one letter in the stirng cur
    vector<stirng> findNeighbor(string cur, unordered_set<string> & wordList) {
        vector<string> neighbors;
        for (size_t i = 0; i < cur.size(); ++i) {
            for (int j = 0; j < 26; ++j) {
                string tmp = cur;
                if (tmp[i] == 'a' + j) continue;
                tmp[i] = 'a' + j;
                if (wordList.count(tmp)) {
                    neighbors.push_back(tmp);
                    wordList.erase(tmp);
                }
            }
        }
        return neighbors;
    }
    
    
    /*
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]
    */
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordList) {
        queue<string> q;
        q.emplace(beginWord);
        int pathLen = 1, levelLen = 1;
        int count = 0;
        while (!q.empty()) {
            string cur = q.front();
            if (cur == endWord) return pathLen;
            
            vector<string> neighbors = findNeighbor(cur, wordList);
            for (auto n : neighbors) q.emplace(n);
            q.pop();
            ++count;
            if (count == levelLen) {
                levelLen = q.size();
                count = 0;
                ++pathLen;
            }
        }
        return 0;
    }
};