/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void deleteNodeHelper(TreeNode*& node){
    TreeNode *del = node;
    if(node->left == 0){
        node = node->right;
    }
    else if(node->right == 0){
        node = node->left;
    }
    else{
        TreeNode* candidate = node->left;
        TreeNode* parentOfCandidate = node;
        while(candidate->right != 0){
            parentOfCandidate = candidate;
            candidate = candidate->right;
        }
        if(parentOfCandidate == node){
            node->left->right = node->right;
            node = candidate;
        }
        else{
            parentOfCandidate->right = candidate->left;
            candidate->left = node->left;
            candidate->right = node->right;
            node = candidate;
        }
    }
    delete del;
    return;
}

class Solution {
public:
    TreeNode* deleteNode(TreeNode*& root, int key) {
        TreeNode *node = root;
        TreeNode *prev;
        while(node != 0){
            if(node->val == key) break;
            else if(node->val > key) {
                prev = node;
                node=node->left;
            }
            else{
                prev = node;
                node=node->right;
            }
        }
        if(node == 0) return root;         //key not found!
        else if(node == root) deleteNodeHelper(root);
        else if(prev->left == node) deleteNodeHelper(prev->left);
        else deleteNodeHelper(prev->right);
        return root;
    }
};
