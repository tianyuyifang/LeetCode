class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return 0;
        TreeNode* head = new TreeNode(preorder[0]);
        int len = 0;
        int i = 0;
        for(; i<inorder.size(); i++){
            if(inorder[i] == preorder[0]) break;
        }
        vector<int> leftPre(preorder.begin()+1, preorder.begin()+i+1);
        vector<int> rightPre(preorder.begin()+i+1, preorder.end());
        vector<int> leftIn(inorder.begin(), inorder.begin()+i);
        vector<int> rightIn(inorder.begin()+i+1, inorder.end());
        
        head->left = buildTree(leftPre, leftIn);
        head->right = buildTree(rightPre, rightIn);
        return head;        
    }
};

// iterative

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0) return 0;
        unordered_map<int, TreeNode*> map;
        int i = 0;
        TreeNode* root = new TreeNode(preorder[0]);
        map[preorder[0]] = root;
        TreeNode* p = root;
        int j = 0;
        while(i < preorder.size()-1){
            while(preorder[i] != inorder[j]){
                i++;
                p->left = new TreeNode(preorder[i]);
                p = p->left;
                map[preorder[i]] = p;
            }
            while(map.find(inorder[j]) != map.end()){
                j++;
            }
            j--;
            if(i<preorder.size()-1){
                TreeNode* right = new TreeNode(preorder[++i]);
                map[inorder[j]]->right = right;
                p = right;
                map[preorder[i]] = p;
                j++;
            }
        }
        return root;
    }
};
