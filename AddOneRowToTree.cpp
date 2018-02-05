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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if(d == 1){
            TreeNode* newAdd = new TreeNode(v);
            newAdd->left = root;
            return newAdd;
        }
        queue<TreeNode *> qNode;
        qNode.push(root);
        for(int i=2; i<d; i++){
            qNode.push(NULL);
            while(qNode.front() != NULL){
                TreeNode* node = qNode.front();
                qNode.pop();
                if(node->left) qNode.push(node->left);
                if(node->right) qNode.push(node->right);
            }
            qNode.pop();
        }
        if(!qNode.front()) qNode.pop();
        while(!qNode.empty()){
            TreeNode* cur = qNode.front();
            qNode.pop();
            cout << cur->val << endl;
            
            TreeNode* newAddLeft = new TreeNode(v);
            newAddLeft->left = cur->left;
            cur->left = newAddLeft;
            
            TreeNode* newAddRight = new TreeNode(v);
            newAddRight->right = cur->right;
            cur->right = newAddRight;
            
            
        }
        return root;
    }
};

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
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        else if (d == 0) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->right = root;
            return newRoot;
        }
        if (!root) {
            return nullptr;
        }
        else if (d == 2) {
            root->left  = addOneRow(root->left,  v, 1);
            root->right = addOneRow(root->right, v, 0);
            return root;
        }
        else if (d > 2) {
            root->left  = addOneRow(root->left,  v, d - 1);
            root->right = addOneRow(root->right, v, d - 1);
        }
        return root;
    }
};
