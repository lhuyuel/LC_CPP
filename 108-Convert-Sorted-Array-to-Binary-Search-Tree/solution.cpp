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
    TreeNode *arrayToBSTHelper(vector<int> &nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = start + (end - start)/2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = arrayToBSTHelper(nums, start, mid - 1);
        node->right = arrayToBSTHelper(nums, mid + 1, end);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return nullptr;
        return arrayToBSTHelper(nums, 0, n-1);
    }
};