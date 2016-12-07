#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
/*
    DFS
*/
vector<vector<int>> directs = {{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1-1}};

void dfs(int x, int y, vector<vector<int>> &grid, int &count) {
    int n = grid.size(); // rows
    int m = grid[0].size(); // cols
    
    // try each direction
    for (int i = 0; i < 8; ++i) {
        int nxt_x = x + directs[i][0];
        int nxt_y = y + directs[i][1];
        if (nxt_x >= 0 &&nxt_x < n && nxt_y >= 0 && nxt_y < m) {
            if(grid[nxt_x][nxt_y] == 1) {
                ++count;
                grid[nxt_x][nxt_y] = -1; // mark as visited
                dfs(nxt_x, nxt_y, grid, count);
            }
        }
    }
}

int maxConnected(vector<vector<int>> &grid) {
    int curMax = 0, n = grid.size(), m = grid[0].size();
    vector<int> q;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            // do a DFS
            if (grid[i][j] == 1) {
                int count = 0;
                dfs(i,j,grid, count);
                curMax = max(curMax, count);
            }
    }
    return curMax;
}

int main() {
    int n, m, tmp;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> tmp;
            grid[i][j]  = tmp;
        }
    cout << maxConnected(grid);
    return 0;
}
