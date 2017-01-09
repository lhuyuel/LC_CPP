    int lengthOfLongestSubstringKDistinct(string s, int k) {
        if (k < 1) return 0;
        if (s.length() <= k) return s.length();
        
        unordered_map<char, int> countTable;
        int maxLen = 0;
        for (int left = 0, right = 0; right < s.length(); ++right) {
            ++countTable[s[right]];
  
            // if size of the table > k, shrink window size
            while (left < right && countTable.size() > k) {
                --countTable[s[left]];
                if (countTable[s[left]] == 0)
                    countTable.erase(s[left]);
                    ++left;
            }
            maxLen = max(right - left + 1, maxLen); // update maxLen
        }
        return maxLen;
    }
