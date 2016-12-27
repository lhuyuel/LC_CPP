/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    //Given s = "[123,[456,[789]]]"
    NestedInteger deserialize(string s) {
        NestedInteger result;
        // pure integer starts
        if (s[0] != '[') return NestedInteger(stoi(s));

        // empty string or "[]"
        if (s.empty() || s.length() == 2) return result;
        
        // every time strip a pair of "[]"
        int start = 1, depth = 0; 
        for (int i = 1; i < s.length(); ++i) {
            // reach the end of the the integer or
            if (depth == 0 && ( s[i] == ',' || i == s.length()-1)) {
                string content = s.substr(start,i-start);
                result.add(deserialize(content)); 
                start = i + 1;
           }
           else if (s[i] == '[') ++depth;
           else if (s[i] == ']') --depth;
        }
        
        return result;
    }
};
