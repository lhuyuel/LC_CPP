class Solution {
public:
// 可以用一个map记录已经求过的解
// f(n) = ( f(0) )^f(n-1) ... (f(n-1))^f(0) 
    vector<string> generateParenthesis(int n) {
        if (n == 0) return vector<string> (1,"");
        else if (n == 1) return vector<string> (1,"()");
        vector<string> result;
        for (int i = 0; i < n; ++i) {
            for (auto left : generateParenthesis(i)) {
                for (auto right : generateParenthesis(n-i-1)) {
                    result.push_back( "("+ left +")" + right );
                }
            }
        }
        return result;
    }
};