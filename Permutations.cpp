//dfs
void dfs(vector<vector<int>>& res, unordered_set<int> set, vector<int>& vec){
    if(set.empty()){
        res.push_back(vec);
        return;
    }
    for(int n : set){
        vec.push_back(n);
        unordered_set<int> newSet(set);
        newSet.erase(n);
        dfs(res, newSet, vec);
        vec.pop_back();
    }
    return;
}
class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> vec;
        dfs(res, set, vec);
        return res;
    }
};

//recursive
void rcsv(vector<vector<int>>& res, int begin, vector<int>& nums){
    if(begin == nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i=begin; i<nums.size(); i++){
        swap(nums[begin], nums[i]);
        rcsv(res, begin+1, nums);
        swap(nums[begin], nums[i]);
    }
    return;
}
class Solution {
    public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        rcsv(res, 0, nums);
        return res;
    }
};