class Solution {
public:
    string convert(string s, int numRows) {
        int len = s.size();
        if (numRows == 1) return s;
        vector<string> rows(numRows,"");
        for (int i = 0; i < len; ) {
            int j = 0;
            while (j < numRows-1 && i < len) 
                rows[j++] += s[i++];
            j = numRows - 1;
            while (j > 0 && i < len)
                rows[j--] += s[i++];
        }
        
        // cat all the rows
        string result = "";
        for (auto row : rows) 
            result += row;
        return result;
    }
};