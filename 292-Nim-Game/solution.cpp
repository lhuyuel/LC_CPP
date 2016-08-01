class Solution {
public:
    // 能被4整除就必输吧
    bool canWinNim(int n) {
        return (n%4 != 0);
    }
};