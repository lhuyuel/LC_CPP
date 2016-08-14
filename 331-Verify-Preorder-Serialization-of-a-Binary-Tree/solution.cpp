class Solution {
public:
    // "9,3,4,#,#,1,#,#,2,#,6,#,#"
    // use stack 
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
        int i = 0;
        stack<bool> stk; // true = regular node;flase = null node
        while (i < n) {
            // read node value
            string node_val = "";
            while (preorder[i] != ',' && i < n) {
                node_val += preorder[i++];
            }
            if (node_val != "#") stk.push(true);
            else {
                while (!stk.empty() && stk.top() == false) {
                    stk.pop(); // pop the last #
                    
                    if (!stk.empty())
                        stk.pop(); // pop the parent node
                    else return false;
                }
                if (!stk.empty() ) {
                    if (stk.top()) stk.push(false);
                }
                else 
                    if (i < n-1) return false;
                
            }
            node_val = "";
            ++i;
        }
        return (stk.empty());
    }
};