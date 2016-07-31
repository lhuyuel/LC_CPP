/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
// Encodes a tree to a single string.
string serialize(TreeNode* root) {
    string result = "";
    queue<TreeNode*> toVisit;
    toVisit.push(root);
    
    while (!toVisit.empty()) {
        TreeNode *tmp = toVisit.front();
        toVisit.pop_front();
        
        if (tmp) {
            result += (to_string(tmp->val) + " ");
            toVisit.push(tmp->left);
            toVisit.push(tmp->right);
        }
        else {
            result += "null ";
        }
    }
    return result;
}


// Decodes your encoded data to tree.
TreeNode* deserialize(string data) {
    vector<TreeNode*> nodes;
    istringstream in(data);
    string tmp;
    while (in >> tmp) {
        if (tmp != "null") nodes.push_back(new TreeNode(stoi(tmp)));
        else nodes.push_back(nullptr);
    }
    
    int cur = 0, i = 1;
    while (i < nodes.size()) {
        if (nodes[cur]) {
            nodes[cur]->left = nodes[i++];
            if (i < nodes.size())
                nodes[cur]->right = nodes[i++];
        }
        ++cur;
    }
    
    return nodes[0];
}
 
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));