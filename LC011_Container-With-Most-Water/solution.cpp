class Solution {
public:
    // if (left < right) ∀ j<right, S(left,j) < S(left,right)；
    // 因为min(j,right) <= min(left,right),且right-j < right - left.
    // 也就是说，如果left < right, 对于所有以left为左边界的container的
    // 容积不可能比S(left,right)大了，于是我们右移left边界。
    // 反之如果right < left，则左移right
    
    int maxArea(vector<int>& height) {
        int maxA = 0, i = 0, j = height.size()-1;
        while (i < j) {
            maxA = max(min(height[i],height[j])*(j-i), maxA);
            (height[i] < height[j]) ? ++i : --j;
        }
        return maxA;
    }
};