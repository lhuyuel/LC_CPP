class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int i = citations.size()-1, count = 0;
        while( i >=0 && citations[i] > count) --i, ++count;
        return count;
    }
};