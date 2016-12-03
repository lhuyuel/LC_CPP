class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> tb_val_freq;
        for (auto num : nums)
            ++tb_val_freq[num];
        
        vector<int> result;
        priority_queue<pair<int,int>> hp_freq_val;
        for (auto it = tb_val_freq.begin(); it != tb_val_freq.end(); ++it) {
            hp_freq_val.push({it->second, it->first});
            if (hp_freq_val.size() > tb_val_freq.size() - k) {
                result.push_back(hp_freq_val.top().second);
                hp_freq_val.pop();
            }
        }
        return result;
    }
};