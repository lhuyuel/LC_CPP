class Solution {
public:
    int compute(int left, int right, char op) {
        switch(op){
        case '+' : return left + right;
        case '-' : return left - right;
        case '*' : return left * right;
        }
        return INT_MAX;
    }
    
    vector<int> diffWaysToCompute(string input) {
        vector<int> result;
        int i = 0;
        for ( ;i < input.size(); ++i) {
            if (input[i] == '+' || input[i] == '-' || input[i] == '*') {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (auto l : left)
                    for (auto r: right) {
                        result.push_back(compute(l,r,input[i]));
                    }
            }
        }
        
        // indicates pure number, return itself
        if (result.size() == 0) result.push_back(stoi(input));
        return result;
    }
};