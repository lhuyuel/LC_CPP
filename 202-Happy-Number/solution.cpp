class Solution {
public:
    /*
    尝试几个数字之后可以发现，如果不是happy number，最终都会进入一个
    循环(42->20->4->16->37->58->8->145->42)，如此往复。因此只要落入这
    个循环的都不是happy number，由于这个loop不是很长，我们可以任取其
    中一个数作为终点（如果很长可以做成一个map，来方便查找）*/
    bool isHappy(int n) {
        if (n == 1) return true;
        else if (n == 0) return false;
        
        int sum = 0;
        while (sum != 1) {
            while (n) {
                sum += pow((n%10), 2);
                n /= 10;
            }
            if (sum == 42) return false;
            n = sum;
        }
        return true;
    }
};