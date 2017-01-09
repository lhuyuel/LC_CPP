    // 题目抽象出来其实是求两个数组大差值
    // 先sort，然后再用Binary search找到最近的heater的距离，然后取最大值
    
    // find closest heater
    int binarySearch(int x, const vector<int> &heaters) {
        int n = heaters.size();
        int left = 0, right = n-1, mid = 0;
        while (left <= right) {
            mid = left + (right - left)/2;
            if (x == heaters[mid]) return 0;
            else if (x < heaters[mid])
                right = mid - 1;
            else 
                left = mid + 1;
        }
        if (right < 0) return abs(heaters[0] - x);
        else if (left > n - 1) return abs(heaters[n-1] - x);
        return min(abs(heaters[left] - x), abs(heaters[right] - x));
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        int maxDist = 0;
        sort(heaters.begin(), heaters.end());
        for (int i = 0; i < houses.size(); ++i) {
            maxDist = max(binarySearch(houses[i], heaters), maxDist);
        }
        return maxDist;
    }
