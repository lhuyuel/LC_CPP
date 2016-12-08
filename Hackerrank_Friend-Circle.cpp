/*
There are  students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature, i.e., if  is friend of  and  is friend of , then  is also friend of . A friend circle is a group of students who are directly or indirectly friends.

You are given a   which consists of characters Y or N. If , then  and students are friends with each other, otherwise not. You have to print the total number of friend circles in the class.

Input Format 
First line of the input contains an integer  - (size of the matrix), followed by N lines each having N characters.

Output Format 
Print the maximum number of friend circles.

Constraints 
 
Each element of matrix friends will be Y or N. 
Number of rows and columns will be equal in the matrix.

, where  
 = , where 

Sample Input#00

4
YYNN
YYYN
NYYN
NNNY
Sample Output

2
Explanation: There are two pairs of friends  and . So  is also a pair of friends by transitivity. So first friend circle contains , and second friend circle contains only student .

Sample Input#01

5
YNNNN
NYNNN
NNYNN
NNNYN
NNNNY
Sample Output#01

5
Explanation: No students are friends with each other. So each friend circle will contain of only one student .
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

void dfs (vector<string> &grid, int &cur, vector<bool> &visited) {
    visited[cur] = true;
    // find neighbors
    for (int i = cur +1; i < grid.size(); ++i) {
        if (grid[cur][i] == 'Y') {
            dfs(grid, i, visited);
        }
    }
}

int countUnion(vector<string> &grid, vector<bool> &visited) {
    int n = grid.size(), m = grid[0].size();
    int count = 0; // count unoins

    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
          dfs(grid,i, visited);  
          ++count;
        } 
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    string row;
    vector<string> grid;
    vector<bool> visited(n, false); 
    while (n--) {
        cin >> row;
        grid.push_back(row);
    }
    cout << countUnion(grid, visited);
    return 0;
}
