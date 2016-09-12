class Solution {
public:
    char findTheDifference(string s, string t) {
        char result = 0;
        for (auto c : s) result ^= c;
        for (auto c : t) result ^= c;
        return result;
    }
};