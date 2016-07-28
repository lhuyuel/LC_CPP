/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    void prepStack(TreeNode *cur) {
        while (cur) {
            toVisit.push(cur);
            cur = cur->left;
        }
    }

    BSTIterator(TreeNode *root) {
        
        TreeNode *cur = root;
        prepStack(cur);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        // if the stack is empty, there is no more elements in the tree need to visit
        return !toVisit.empty();
    }

    /** @return the next smallest number */
    int next() {
        if (hasNext()) {
            TreeNode *tmp = toVisit.top();
            toVisit.pop();
            prepStack(tmp->right);
            return tmp->val;
        }
        else throw exception();
    }

    private:
    stack<TreeNode*> toVisit;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */