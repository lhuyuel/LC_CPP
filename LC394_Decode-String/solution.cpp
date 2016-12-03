class Solution {
public:
    /* would be much easier to solve in Python*/
    // Test case: 3[a]2[bc]
    
    // 还是递归好了
    string decode(string s, int &i) {
        string result = "";
        while (i < s.length() && s[i] != ']') {
            // pure chars
            if (!isdigit(s[i])) result += s[i++];
            
            else {
                // get the count
                int count = 0;
                while (i < s.length() && isdigit(s[i]))
                    count = count*10 + s[i++] - '0';
                // at this point, s[i] should be '[', skip it
                ++i;
                // get the content
                string content = decode(s,i);
                // after decode, s[i] should be ']'
                ++i;
                //append the content to result
                while (count-- > 0) result += content;
            }
        }
        return result;
    }
    
    string decodeString(string s) {
        int i = 0;
        string result = decode(s,i);
        return result;
    }
};