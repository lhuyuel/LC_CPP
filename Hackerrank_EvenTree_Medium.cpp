/*
https://www.hackerrank.com/challenges/even-tree

You are given a tree (a simple connected graph with no cycles). The tree has  nodes numbered from  to  and is rooted at node 1. Find the maximum number of edges you can remove from the tree to get a forest such that each connected component of the forest contains an even number of vertices.

这个题通过观察，我们可以发现，只要子树的node总数是even的我们就可以断开那一条edge，然后recersive 地处理每一棵子树。
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
};

int processTree(TreeNode* root, int &countTotal) {
    if (!root) return 0;
    int nodeCount = 0;
    for (auto ch : root->children) {
        int tmp = processTree(ch, countTotal);
        if (tmp > 0 && tmp % 2 == 0) ++countTotal;
        nodeCount += tmp;
        //cout << "NodeCount: " << nodeCount << endl;
    }
    return nodeCount + 1;
}

int main() {
    int n;
    cin >> n;
    vector<TreeNode*> nodes;
    for (int i = 0; i < n; ++i) {
        TreeNode *tmp = new TreeNode;
        nodes.push_back(tmp);
    }
    int edges;
    cin >> edges;
    for (int i = 0; i < edges; ++i) {
        int child, parent;
        cin >> child >> parent;
        nodes[parent-1]->children.push_back(nodes[child-1]);
    }
    int count = 0;
    processTree(nodes[0], count);
    cout << count;
    return 0;
}
