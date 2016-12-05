/*
	时间复杂度看起来是exponential的，prune优化了一点时间
*/
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        // do some pruning
        if (s1.size() != s2.size()) return false;
        string tmp1 = s1;
        string tmp2 = s2;
        sort(tmp1.begin(), tmp1.end());
        sort(tmp2.begin(), tmp2.end());
        if (tmp1 != tmp2) return false;
        
        // try every split
        int len = s1.size();
        for (int i = 1; i < len; ++i) {
            string s1_left = s1.substr(0,i);
            string s1_right = s1.substr(i);
            string s2_left = s2.substr(0,i);
            string s2_right = s2.substr(i);
            if (isScramble(s1_left, s2_left) && isScramble(s1_right, s2_right)) 
                return true;
            // split from right
            s2_left = s2.substr(0, len - i);
            s2_right = s2.substr(len-i);
            if (isScramble(s1_left, s2_right) && isScramble(s1_right, s2_left)) 
                return true;
        }
        return false;
    }
