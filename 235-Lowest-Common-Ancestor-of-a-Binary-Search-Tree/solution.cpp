/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode * cur = root;
        while(1){
            // 在区间里
            if(  (cur->val >= p->val && cur->val <= q->val)  || 
                 (cur->val >= q->val && cur->val <= p->val) )
                return cur;
                
            // 向区间靠拢
            if( cur->val > p->val)
                cur = cur->left;
            else
                cur = cur->right;
       }
    }
};