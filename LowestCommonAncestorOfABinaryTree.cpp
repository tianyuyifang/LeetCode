void setParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& map){
    queue<TreeNode *> q;
    q.push(root);
    TreeNode *cur;
    while(!q.empty()){
        cur = q.front();
        q.pop();
        if(cur->left){
            q.push(cur->left);
            map[cur->left] = cur;
        }
        if(cur->right){
            q.push(cur->right);
            map[cur->right] = cur;
        }
    }
    return;
}

vector<TreeNode*> findAllAncestors(TreeNode*& node, TreeNode*& root, unordered_map<TreeNode*, TreeNode*>& map){
    vector<TreeNode*> res;
    res.push_back(node);
    while(node!=root){
        node = map[node];
        res.push_back(node);
    }
    return res;
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> map;
        setParent(root, map);
        vector<TreeNode*> pAncestors = findAllAncestors(p, root, map);
        vector<TreeNode*> qAncestors = findAllAncestors(q, root, map);
        int i=pAncestors.size()-1, j=qAncestors.size()-1;
        while(i>=0 && j>=0 && pAncestors[i] == qAncestors[j]){
            i--;
            j--;
        }
        return pAncestors[i+1];
    }
};

//
bool findAll(TreeNode* root, TreeNode* node, vector<TreeNode*>& res){
    if(!root) return false;
    if(root == node) return true;
    bool left = findAll(root->left, node, res);
    bool right = findAll(root->right, node, res);
    if(left || right){
        res.push_back(root);
        return true;
    }
    return false;  
}

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> pAncestors;
        vector<TreeNode*> qAncestors;
        if(findAll(root, p, pAncestors)) pAncestors.insert(pAncestors.begin(), p);
        if(findAll(root, q, qAncestors)) qAncestors.insert(qAncestors.begin(), q);
        int i=pAncestors.size()-1, j=qAncestors.size()-1;
        while(i>=0 && j>=0 && pAncestors[i] == qAncestors[j]){
            i--;
            j--;
        }
        return pAncestors[i+1];
    }
};

//
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root==p || root==q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left && right) return root;
        else if(left && !right) return left;
        else if(right && !left) return right;
        else return 0;
    }
};

//