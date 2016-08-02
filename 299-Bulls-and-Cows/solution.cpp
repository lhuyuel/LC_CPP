class Solution {
public:
    // 这个不是mastermind吗？
    string getHint(string secret, string guess) {
        vector<int> tb(10,0);
        int countA = 0, countTotal = 0;
        for (int i = 0; i < secret.size(); ++i) {
            if (secret[i] == guess[i]) 
                ++countA;
            ++tb[secret[i]];
        }
        
        // count total matches
        for (int i = 0; i < guess.size(); ++i) {
            if (tb[guess[i]] > 0) {
                ++countTotal;
                --tb[guess[i]];
            }
        }
        return to_string(countA) + "A" + to_string(countTotal-countA) + "B";
    }
};