/*
=============================
Problem: Two Strings
=============================
Given two strings,  and , determine if they share a common substring.

Input Format

The first line contains a single integer, , denoting the number of  pairs you must check. 
Each pair is defined over two lines:

The first line contains string .
The second line contains string .
Constraints

 and  consist of lowercase English letters only.
Output Format

For each  pair of strings, print YES on a new line if the two strings share a common substring; if no such common substring exists, print NO on a new line.

Sample Input

2
hello
world
hi
world
Sample Output

YES
NO

*/



// 这个题乍一看以为是要KMP，但本题只要有common char就可以认为是有common substring的。如果没有common substring则肯定没有common char，两个命题是等价的。

bool hasCommonSub(string s1, string s2) {
    //int len1 = s1.size(), len2 = s2.size();
    vector<bool> occr_1(26,false), occr_2(26,false);
    for (char c : s1) 
        occr_1[c - 'a'] = true;
    for (char c : s2)
        occr_2[c - 'a'] = true;
    
    for (int i = 0; i < occr_1.size(); ++i) {
        if (occr_1[i] && occr_2[i])
            return true;
    }
    return false;
}
