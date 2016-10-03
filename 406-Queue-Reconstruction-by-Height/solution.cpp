class Solution {
public:
    struct comp {
        bool operator() (const pair<int, int> left, const pair<int, int> right) const { 
           return left.first < right.first;
        }
    };
    
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
        vector<pair<int,int>> result = vector<pair<int,int>>(n,{INT_MIN,0});
        sort(people.begin(), people.end(), comp());
        for (int i = 0; i < n; ++i) {
            int count = 0; // count # that is higher or equal to people[i].first
            int j = 0;
            for(; j < n; ++j) {
                // 把需要留给后面更高的people的位置空出来
                if (count == people[i].second) break;
                if (result[j].first == people[i].first || result[j].first == INT_MIN)
                    count++;
            }
            // find the first empty position
            while(result[j].first != INT_MIN) ++j;
            result[j] = people[i];
        }
        return result;
    }
};