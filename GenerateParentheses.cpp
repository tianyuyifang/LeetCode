class node {
public:
    int open;
    int close;
    node *left;
    node *right;
    node(int o, int c, node *l = 0, node *r = 0): open(o), close(c), left(l), right(r) {}
};


vector<string> buildAndUseTree(int n) {
    node *head = new node(1, 0);
    queue<node *> s;
    queue<string> ss;
    s.push(head);
    ss.push("(");
    while(!s.empty()){
        node *cur = s.front();
        if (cur->close == n) break;      // cur->close == n indicates the tree is already fully grown;
        s.pop();
        string curStr = ss.front();
        ss.pop();
        if (cur->open > cur->close) {
            cur->left = new node(cur->open, cur->close + 1);
            s.push(cur->left);
            
            string newStr = curStr + ")";
            ss.push(newStr);
        }
        if (cur->open < n) {
            cur->right = new node(cur->open + 1, cur->close);
            s.push(cur->right);
            
            string newStr = curStr + "(";
            ss.push(newStr);
        }
    }
    vector<string> res;
    while(!ss.empty()) {
        res.push_back(ss.front());
        ss.pop();
    }
    return res;
}

class Solution {
public:

    vector<string> generateParenthesis(int n) {
        vector<string> ans = buildAndUseTree(n);
        return ans;
    }
};
