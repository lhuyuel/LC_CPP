class Solution {
public:
// "Hello World    "

    int lengthOfLastWord(string s) {
        //string lastword = "";
        int i = s.size()-1;
        if (i == -1) return 0;
        // find the first non-space char
        while (i > -1 && s[i] == ' ') --i;
        
        if (i < 0 ) return 0;
        
        int count = 0;
        while (i > -1 && s[i]!= ' ') {--i, ++count;}
      
        return count;
    }
};