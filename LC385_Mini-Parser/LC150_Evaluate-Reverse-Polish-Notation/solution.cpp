    int evalRPN(vector<string>& tokens) {
        if (tokens.size() == 0) return 0;
        stack<int> stk;

        int left, right;
        for (int i = 0; i < tokens.size(); ++i) {
            // if tokens[i] is an opertator
            if (tokens[i].size() == 1 && (tokens[i][0] < '0' || tokens[i][0] > '9') ) {
                right = stk.top();
                stk.pop();
                left = stk.top();
                stk.pop();
                
                switch (tokens[i][0]){
                    case '+': stk.push(left + right); break;
                    case '-': stk.push(left - right); break;
                    case '*': stk.push(left * right); break;
                    case '/': stk.push(left / right); break;
                }
            }
            else
                stk.push(stoi(tokens[i]));
        }
        return stk.top();
    }
