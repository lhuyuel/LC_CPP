/*
====================================================
Problem: Divisible Sum Pairs
===================================================
You are given an array of  integers, , and a positive integer, . Find and print the number of  pairs where  and  +  is evenly divisible by .

Input Format

The first line contains  space-separated integers,  and , respectively. 
The second line contains  space-separated integers describing the respective values of .

Constraints

Output Format

Print the number of  pairs where  and  +  is evenly divisible by .

Sample Input

6 3
1 3 2 6 1 2
Sample Output
5

-------------------
因为如果a = x % k, b = y % k, 那么(x+y)%k = (a+b)%k

*/

#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int pairNum(vector<int> nums, int k) {
    int n = nums.size();
    vector<int> modTable(k);   // stores list of indexes with same mod
    for (int i = 0; i < n; ++i)
        ++modTable[nums[i]%k];
    
    int count = 0;
    // could  pick two from mod = 0 set
    count += (modTable[0] * (modTable[0] -1)) >> 1;
    for (int i = 1; i < k-i; ++i) {
        count += modTable[i] * modTable[k-i];
    }
    
    if (k % 2 == 0) count += (modTable[k/2]* (modTable[k/2]-1)) >> 1;
    return count;
}

int main(){
    int n;
    int k;
    cin >> n >> k;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    cout << pairNum(a, k);
    return 0;
}

