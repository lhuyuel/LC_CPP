/*
	lmax是左边已经经过的最高的bar，rmax是右边已经经过的最高的bar
*/    

int trap(vector<int>& height) {
        int lmax = 0, rmax= 0;
        int water = 0;
        for (int l = 0, r = height.size() - 1; l < r; ) {
            if (height[l] < height[r]) {
                lmax = max(height[l],lmax);
                water += (lmax - height[l++]);
            }
            else {
                rmax = max(height[r], rmax);
                water += (rmax - height[r--]);
            }
        }
        return water;
    }
