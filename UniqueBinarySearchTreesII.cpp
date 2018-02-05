vector<TreeNode*> dfs(vector<int> nums){
    vector<TreeNode*> res;
    if(nums.size() == 0){
        res.push_back(0);
    }
    for(int i=0; i<nums.size(); i++){
        for(auto left : dfs(vector<int>(nums.begin(), nums.begin()+i))){
            for(auto right : dfs(vector<int>(nums.begin()+i+1, nums.end()))){
                TreeNode* head = new TreeNode(nums[i]);
                head->left = left;
                head->right = right;
                res.push_back(head);
            }
        }
    }
    return res;
}
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> vec(n,0);
        for(int i=0; i<n; i++){
            vec[i] = i+1;
        }
        
        vector<TreeNode*> res;
        if(n == 0) return res;
        res = dfs(vec);
        return res;
    }
};
