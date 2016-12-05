    /*  f(i,k) 表示前i个house，以颜色Ck为结尾的最小cost
        f(i, k) = min ( f(i-1, (k+1)%3),  f(i-1, (k+2)%3) ) + costs[i][k]      // 除了颜色k以外的两种颜色
        观察递推公式，发现只与前一个房子的两个颜色值有关，因此可以优化空间至O(1).
    */
    int minCost(vector<vector<int>>& costs) {
        if (costs.size() == 0) return 0;
        vector<int> pre(3,0);
        vector<int> cur(3); // store current value
        for (int i = 0; i < costs.size(); ++i) {
            cur[0] = min(pre[1], pre[2]) + costs[i][0];
            cur[1] = min(pre[0], pre[2]) + costs[i][1];
            cur[2] = min(pre[0], pre[1]) + costs[i][2];
            swap(pre, cur); // 直接交换vector
        }
        
        auto it = min_element(pre.begin(), pre.begin()+3); 
        return *it;
    }
