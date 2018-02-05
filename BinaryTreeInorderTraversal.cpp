class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(true){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            cout << p->val << endl;
            res.push_back(p->val);
            p = p->right;
            if(p){
                st.push(p);
                p = p->left;
            }

            if(st.empty()) break;
        }
        return res;
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        stack<TreeNode *> st;
        TreeNode *p = root;
        while(p || !st.empty()){
            while(p){
                st.push(p);
                p = p->left;
            }
            p = st.top();
            st.pop();
            cout << p->val << endl;
            res.push_back(p->val);
            p = p->right;

        }
        return res;
    }
};