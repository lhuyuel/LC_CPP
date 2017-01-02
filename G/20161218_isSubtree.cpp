bool areIdentical(TreeNode* t1, TreeNode* t2) {
    if (!t1 && !t2) return true;
    else if (!t1 || !t2) return false;
    return (t1->val == t2->val && areIdentical(t1->left, t2->left)
            && areIdentical(t1->right, t2->right));
}


// return true if s is subtree of t
bool isSubtree(TreeNode* t, TreeNode* s) {
    if (!s) return true;
    if (!t) return false;
    
    if (areIdentical(t,s))
        return true;
    else
        return isSubtree(t->left, s) || isSubtree(t->right, s);
        
}
