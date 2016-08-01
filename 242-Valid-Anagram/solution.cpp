class Solution {
public:
    // 如果可以用extra space就可以使用hashtable
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s == t;
    }
};