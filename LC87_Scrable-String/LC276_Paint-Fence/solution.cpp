/*
	第i个fence可以有两种情况：
	1. 与第i-1个fence颜色一样（那么i-1个fence就不能和第i-2个fense一样，即应与第i-1的diff相同）
	2. 与第i-2个fence颜色不同，那么就有前面total种刷法*第i个fence的k-1个选择种。
	两种情况的总和即为所求。
-----------------------------------------
递推关系化简：
令c[t] = c1[t], c[t-1] = c2[t]，则我们有c[t] = (k-1)c[t-1] + (k-1)c[t-2]
int numWays(int n, int k) {
    if (n <= 0 || k == 0) return 0;
    if (k == 1) return n<3;

    double root = (k-1)*(k-1)/4.0+k-1;
    double a = (k-1)/2.0 + sqrt(root);
    double b = (k-1)/2.0 - sqrt(root);

    int c1 = round((pow(a, n) - pow(b, n))*k/(a-b));
    int c2 = round((pow(a, n-1) - pow(b, n-1))*k/(a-b));
    return (c1+c2);
}

*/
    int numWays(int n, int k) {
        if (k == 0 || n == 0) return 0;
        int total = 0, same = 0, diff = k;
        for (int i = 2; i <= n; ++i) {
            total = same + diff;
            same = diff;
            diff = total * (k-1); // only need to be different from previous fence
        }
        return same + diff;
    }
