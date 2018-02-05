// recursive method
bool outOfRange(vector<int> &nums, int target) {
    int sum = 0;
    for(int i=0; i<nums.size(); i++) {
        sum += nums[i];
    }
    if (target <= sum && target >= -1*sum) return false;
    else return true;
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        if(outOfRange(nums, S)) return 0;
        else {
            if (nums.size() == 1) {              //when n = 1
                int count = 0;
                if(nums[0] == S) count++;
                if(nums[0] + S == 0) count++;
                return count;
            }
            else {
                int last = nums[nums.size()-1];
                vector<int> newVec(nums.begin(), nums.end()-1);
                return findTargetSumWays(newVec, S+last) + findTargetSumWays(newVec, S-last);
            }
        }
        
    }
};

// dfs
void dfs(vector<int>& nums, int target, int level, int &cnt) {
    if(level == nums.size()) {
        if (target == 0) cnt++;
        return;
    }
    
    else {
        dfs(nums, target+nums[level], level+1, cnt);
        dfs(nums, target-nums[level], level+1, cnt);
    }
}
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0;
        dfs(nums, S, 0, cnt);
        return cnt;
    }
};
