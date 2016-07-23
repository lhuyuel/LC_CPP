class Solution {
public:
    string sayit(string s) {
        string tmp = "";
        for (int i = 0; i < s.size(); ++i) {
                int count = 1;
                while (i < s.size()-1 && s[i] == s[i+1] ) {
                    ++count;
                    ++i;
                }
                tmp += (to_string(count) + s[i]);
        }
        return tmp;
    }

    string countAndSay(int n) {
        string cur = "1";
        while (n > 1) {
            cur = sayit(cur);
            --n;
        }
        return cur;
    }
};