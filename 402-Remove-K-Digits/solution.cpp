class Solution {
public:
    // if 1st digit x followed by 0, remove digit 1, which will reduce 2 digits
    // iterate through the num, check for decrease point
    // do this recursively
    string removeKdigits(string num, int k) {
        if (k == 0) return num;
        int n = num.length();
        if (n <= k) return "0";
        if (n >= 2) { //  check for 2nd digit
            if (num[1] == '0') {
                num.erase(num.begin(),num.begin()+2);
                // check for "000"s
                int i = 0;
                while(i < num.length()) {
                    if (num[i] == '0') ++i;
                }
                if (i == num.length()) return "0";
                else 
                    return removeKdigits(num, k-1);
            }
        }
        int i = 0;
        while (i < n-1 && num[i] < num[i+1]) ++i;
        num.erase(num.begin()+i);
        return removeKdigits(num,k-1);
    }// = =...
};