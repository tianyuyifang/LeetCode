/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int size(TreeNode* root){
    if(!root) return 0;
    else{
        return (size(root->left) + size(root->right) + 1);    
    }
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(k == size(root->left) + 1) return root->val;
        else if(k < size(root->left) + 1) return kthSmallest(root->left, k);
        else return kthSmallest(root->right, k-(size(root->left) + 1));
    }
};

//inorder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void inorder(TreeNode* root, int& find, int& k){
    if(!root) return;
    inorder(root->left, find, k);
    if(k<1) return;
    if(k == 1){
        find = root->val;
    }
    k--;
    inorder(root->right, find, k);
    return;
}
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int find;
        inorder(root, find, k);
        return find;
    }
};
//iterative inorder
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* p = root;
        while(p || !s.empty()){
            while(p){
                s.push(p);
                p = p->left;
            }
            p = s.top();
            if (k==1) return p->val;
            k--;
            s.pop();
            p = p->right;
        }
        return -1;
    }
};
