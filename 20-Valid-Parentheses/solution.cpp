class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (stk.empty() && (s[i] == ')' || s[i] == '}' || s[i] == ']') )
                return false;
            if (s[i] == ')') 
                if (stk.top() == '(') stk.pop();
                else stk.push(s[i]);
            else if (s[i] == ']') 
                if (stk.top() == '[' ) stk.pop();
                else stk.push(']');
            else if (s[i] == '}') 
                if (stk.top() == '{' ) stk.pop();
                else stk.push('}');
            else if (s[i] == '(' || s[i] == '[' || s[i] == '{' )
                stk.push(s[i]);
        }
        return stk.empty();
    }
};