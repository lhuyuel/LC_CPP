class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;
        int digit_a; 
        int digit_b;
        while( i >= 0 || j >= 0 || carry == 1 ){
            digit_a = digit_b = 0;
            if( i >= 0 ) digit_a = a[i--] - '0';
            if( j >= 0 ) digit_b = b[j--] - '0';
            
            result = (char)('0' + (digit_a + digit_b + carry) % 2 )+ result;
            carry = digit_a + digit_b + carry > 1 ? 1 : 0;
        }

        return result;
    
    }
};