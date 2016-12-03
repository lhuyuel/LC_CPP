class Solution {
public:

   // [7, 6, 4, 3, 1]  size = 5 //[7, 1, 5, 3, 6, 4]
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int min = INT_MAX;
        int profit = INT_MIN;
        for (int i = 0; i < prices.size()-1; ) {
            while (i < prices.size()-1 && prices[i] >= prices[i+1] ) ++i;
            if (prices[i] < min) min = prices[i];
            while (i< prices.size()-1 && prices[i] <= prices[i+1]) ++i;
            if (prices[i] - min > profit)
                profit = prices[i] - min;
        }
        return profit;
    }
};