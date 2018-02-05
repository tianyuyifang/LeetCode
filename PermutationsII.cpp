void dfs(vector<vector<int>>& res, vector<int>& nums, int begin){
    if(begin == nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i=begin; i<nums.size(); i++){
        bool distinct = true;
        for(int j=begin; j<i; j++){
            if(nums[j] == nums[i]){
                distinct = false;
                break;
            }
        }
        if(distinct){
            swap(nums[begin], nums[i]);
            dfs(res, nums, begin+1);
            swap(nums[begin], nums[i]);
        }
    }
    return;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        int begin = 0;
        dfs(res, nums, begin);
        return res;
    }
};

void dfs(vector<vector<int>>& res, vector<int> nums, int begin){
    if(begin == nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i=begin; i<nums.size(); i++){
        if((i!=begin) && (nums[i]==nums[begin])) continue;
        swap(nums[begin], nums[i]);
        dfs(res, nums, begin+1);
    }
    return;
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int begin = 0;
        dfs(res, nums, begin);
        return res;
    }
};
// next permutation
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while(1){
            int i = nums.size()-1;
            for(; i>=1; i--){
                if(nums[i] > nums[i-1]) break;
            }
            if(i == 0) break;    //iteration is done;
            int j=i;
            for(; j<nums.size(); j++){
                if(nums[i-1] >= nums[j]) break;
            }
            swap(nums[i-1], nums[j-1]);
            reverse(nums.begin()+i, nums.end());
            res.push_back(nums);
        }
        return res;
    }
};