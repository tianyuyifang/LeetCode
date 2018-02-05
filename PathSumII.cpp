//bfs
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(root == 0) return res;
        queue<TreeNode *> qNode;
        queue<vector<int>> qVec;
        qNode.push(root);
        vector<int> vec = {sum-(root->val)};
        qVec.push(vec);
        while(!qNode.empty()){
            TreeNode* node = qNode.front();
            qNode.pop();
            vector<int> cur = qVec.front();
            qVec.pop();
            if((cur.back()==0) && (node->left==0) && (node->right)==0) res.push_back(cur);
            else{
                if(node->left){
                    qNode.push(node->left);
                    vector<int> nextLeft = cur;
                    nextLeft.push_back(cur.back()-(node->left->val));
                    qVec.push(nextLeft);
                }
                if(node->right){
                    qNode.push(node->right);
                    vector<int> nextRight = cur;
                    nextRight.push_back(cur.back()-(node->right->val));
                    qVec.push(nextRight);                    
                }
            }
        }
        for(int i=0; i<res.size(); i++){
            for(int j=res[i].size()-1; j>=1; j--){
                res[i][j] = res[i][j-1]-res[i][j];
            }
            res[i][0] = sum-res[i][0];
        }
        return res;
    }
};

// dfs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void dfs(TreeNode* root, int sum, vector<int>& path, vector<vector<int>>& paths){
    if(root == 0) return;
    path.push_back(root->val);
    if((root->val == sum) && (root->right == 0) && (root->left == 0)) paths.push_back(path);
    dfs(root->left, sum-(root->val), path, paths);
    dfs(root->right, sum-(root->val), path, paths);
    path.pop_back();
    
}
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> paths;
        vector<int> path;
        dfs(root, sum, path, paths);
        return paths;
    }
};
