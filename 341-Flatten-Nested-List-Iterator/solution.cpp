/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:

    NestedIterator(vector<NestedInteger> &nestedList) {
        prepStack(nestedList);
    }

    void prepStack(vector<NestedInteger> &nList) {
        for (int i = nList.size()-1; i >= 0; --i)
            stk.push(nList[i]);
    }
    
    int next() {
        if (hasNext()) {
            NestedInteger tmp = stk.top();
            stk.pop();
            return tmp.getInteger();
        }
        return INT_MAX;
    }

    bool hasNext() {
        while (!stk.empty()) {
            NestedInteger tmp = stk.top();
            if (tmp.isInteger()) return true; 
            stk.pop();
            prepStack(tmp.getList());
        }
        return false;
    }
private:
    stack<NestedInteger> stk;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */