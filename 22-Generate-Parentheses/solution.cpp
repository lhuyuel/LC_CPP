class Solution {
public:


// n = 1 , ()
// n = 2, ()(), (())
// n = 3, () + n(2) , ( n(2) ), n(2) + ()  ; ()()(), ()(()), (()()), ((())), ()()(), (())()
// n = 4, () + n(3), ( n(3) ), n(3) + ()

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