class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int i = 0;
        while( i < citations.size() && citations[i] > i) ++i;
        return i;
    }
};