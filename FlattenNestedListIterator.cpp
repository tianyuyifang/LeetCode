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
        for(auto it=nestedList.rbegin(); it!=nestedList.rend(); ++it){
            s.push(*it);
        }
    }
    int next() {
        int next;
        if(!s.empty()){
            next = s.top().getInteger();
            s.pop();
            return next;
        }
    }

    bool hasNext() {
        while(!s.empty() && !s.top().isInteger()){
            vector<NestedInteger> curList = s.top().getList();
            s.pop();
            for(auto it=curList.rbegin(); it!=curList.rend(); ++it){
                s.push(*it);
            }
        }
        if(!s.empty()) return true;
        else return false;
    }
private:
    stack<NestedInteger> s;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */