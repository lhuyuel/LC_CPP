/*
Problem:
There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature, i.e., if A is friend of B and B is friend of C, then A is also friend of C. A friend circle is a group of students who are directly or indirectly friends.

You are given a N×N−matrix M which consists of characters Y or N. If M[i][j]=Y, then ith and jth students are friends with each other, otherwise not. You have to print the total number of friend circles in the class.

Input Format 
First line of the input contains an integer N - (size of the matrix), followed by N lines each having N characters.

Output Format 
Print the maximum number of friend circles.

Constraints 
1≤N≤300 
Each element of matrix friends will be Y or N. 
Number of rows and columns will be equal in the matrix.

M[i][i]=Y, where 0≤i<N 
M[i][j] = M[j][i], where 0≤i<j<N
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
    It seems a union find problem, could do a DFS
*/
vector<vector<int>> directs {{-1,0},{0, 1},{1, 0},{0, -1}};

bool isValid(vector<string> &grid, const vector<int> &cur) {
    int n = grid.size(), m = grid[0].size();
    return (cur[0] >= 0 && cur[0] < n && cur[1] >= 0 && cur[1] < m
       && grid[cur[0]][cur[1]] == 'Y');  
}

void dfs (vector<string> &grid, const vector<int> &cur) {
    grid[cur[0]][cur[1]] = 'N'; // mark cur as visited
    for (int i = 0; i < directs.size(); ++i) {
        vector<int> nxt(2);
        nxt[0] =  cur[0] + directs[i][0], nxt[1] = cur[1] + directs[i][1];
        if (isValid(grid, nxt)) // check if the grid is valid
            dfs(grid, nxt);
    }
}

int countUnion(vector<string> &grid) {
    int n = grid.size(), m = grid[0].size();
    int count = 0; // count unoins
    vector<int> cur(2);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'Y') {
                cur[0] = i, cur[1] = j;
                dfs(grid, cur);
                ++count;
            }
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    string row;
    vector<string> grid;
    while (n--) {
        cin >> row;
        grid.push_back(row);
    }
    cout << countUnion(grid);
    return 0;
}

