/*
https://www.hackerrank.com/challenges/cut-the-tree
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

int minDiff(vector<int> &nodeVals, unordered_map<int, vector<int>> &adjList, 
            int curNode, int sum, int &curMinDiff, vector<bool> &isVisited) {
    // check adjList
    isVisited[curNode] = true;
    int curSum = nodeVals[curNode]; // current node's val
    
    for (int i = 0; i < adjList[curNode].size(); ++i) {
        if (!isVisited[adjList[curNode][i]]) {
            // try this cut
            int subSum = minDiff(nodeVals, adjList, adjList[curNode][i], sum, curMinDiff, isVisited);
            int curDiff = abs(sum - 2*subSum);
            if ( curDiff < curMinDiff) 
                curMinDiff = curDiff;
            curSum += subSum; 
        }     
    }
    return curSum;
}

int main() {
    int nodeNum;
    cin >> nodeNum;
    vector<int> nodeVals;
    int val, sum = 0;
    for (int i = 0; i < nodeNum; ++i) {
        cin >> val;
        nodeVals.push_back(val);
        sum += val;
    }
    
    // build adjList
    unordered_map<int, vector<int>> adjList;
    int a, b;
    for (int i = 0; i < nodeNum - 1; ++i) {
        cin >> a >> b;
        adjList[a-1].push_back(b-1); // minus one to match value table
        adjList[b-1].push_back(a-1); // bidirectional
    }
    
    vector<bool> isVisited(nodeNum, false);
    int curMinDiff = sum;
    minDiff(nodeVals,adjList,0, sum, curMinDiff, isVisited);
    cout << curMinDiff << endl;
    return 0;
}

