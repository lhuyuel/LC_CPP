#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


struct coord {
    int x;
    int y;
    coord(){}
    coord (int x1, int y1) : x(x1), y(y1)
    {}
};

vector<vector<int>> directs = {{-1,0},{0,1},{1,0},{0,-1}};

bool isValid(const coord &a, const vector<string> &grid) {
    int n = grid.size(), m = grid[0].size();
    return  (a.x >= 0 && a.x < n && a.y >= 0 && a.y < m
       && grid[a.x][a.y] != 'X' && grid[a.x][a.y] != 'M');   
}

// do a DFS
void countMulti(vector<string> &grid, const coord &s, const coord &e, int &tmpCount, int &finalCount) {    
    
    // terminate condition
    if (s.x == e.x && s.y == e.y) {
        finalCount = tmpCount;
        return;
    }
    
    // check neighbors
    vector<coord> toVisit;
    for (int i = 0; i < directs.size(); ++i) {
        coord nxt(s.x + directs[i][0], s.y + directs[i][1]);
        if (isValid(nxt, grid))
            toVisit.push_back(nxt);
    }
    if (toVisit.size() > 1) ++tmpCount;
    
    for (int i = 0; i < toVisit.size(); ++i) {
        coord st = toVisit[i];
        grid[st.x][st.y] = 'X'; // mark as visited
        countMulti(grid, st, e, tmpCount, finalCount);
        grid[st.x][st.y] = '.'; // reset
    }

    if (toVisit.size() > 1) --tmpCount; // If the path is not part of solution reset tmpCount
}


int main() {
    int testNum;
    cin >> testNum;
    while (testNum--) {
        int k, n, m; // k is number of waves(guess), n and m are dementions 
        string row;
        cin >> n >> m; 
        vector<string> grid(n);
        coord s, e; // remember the start pos and end pos
        for (int i = 0; i < n; ++i) {
            cin >> row;
            grid[i] = row;
            for (int j = 0; j < m; ++j) {
                if (row[j] == 'M')
                    s.x = i, s.y = j;
                else if (row[j] == '*')
                    e.x = i, e.y = j;
            }
        }
        cin >> k;
        int tmp = 0, count = 0;
        countMulti(grid, s, e, tmp, count);
        //cout << "Result: "<< count << endl;
        if (k == count ) 
            cout << "Impressed" << endl;
        else 
            cout << "Oops!" <<endl;
    }
    return 0;
}

