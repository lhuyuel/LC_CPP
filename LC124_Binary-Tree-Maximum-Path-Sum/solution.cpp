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
    // case1: is leftBranch (not include node itself)
    // case2: is rightBranch
    // case3: node->val
    // case4:  max(left+node->val, right+node->val, left+right +node->val)
    //      = max( max(left,right) +node->val, left+right +node->val)
    
    // result.first = max(left,right), result.second = max(node->val, case4)
    // result.first 是 左边path 和右边path取最大值
    // result.second 是 node本身，left+node, right+node, left+rihgt+node 之间的最大值
    
    /*
      -1
      / \
    -2   3
    /\
   5  4
    */
    
     int getMax(TreeNode *root, int &maxSum){
        if( !root ) return 0;
        int left = getMax(root->left, maxSum);   
        //返回包含root->left的path，更新maxSum为 max（之前的maxSum，当前左右联通的值）
        
        int right = getMax(root->right, maxSum);
        int sum  = root->val;        
        if(left > 0) sum += left;
        if(right > 0) sum += right; // sum 表示 max(root->val, root->val + left, root->val + right, root->val + left +right)
        maxSum = max(maxSum, sum);
        return max(left, right) > 0 ? max(left, right) + root->val : root->val; // max (root->val, max(left,right)+ root->val)
    }

    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        getMax(root, maxSum);
        return maxSum;
    }

    
};