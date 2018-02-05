//dfs
bool dfs(vector<int>& sidesLen, vector<int>& nums, int index, int target){
    if(index == nums.size()){
        return (sidesLen[0] == sidesLen[1] && sidesLen[1] == sidesLen[2] && sidesLen[2] == sidesLen[3]);
    }
    for(int i=0; i<4; i++){
        if(sidesLen[i] + nums[index] > target) continue;
        int j=i-1;         //compare sidesLen[i] with sidesLen[0:i], if it coincides with someone, there no need to go further.
        while(j>=0){
            if(sidesLen[i] == sidesLen[j]) break;
            j--;
        }
        if(j >= 0) continue;
        sidesLen[i] += nums[index];
        if(dfs(sidesLen, nums, index+1, target)) return true;
        else{
            sidesLen[i] -= nums[index]; 
        } 
    }
    return false;
}

class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        int target = 0;
        target = accumulate(nums.begin(), nums.end(), 0);
        if(target%4 != 0) return false;
        target = target/4;
        sort(nums.begin(), nums.end(), [](const int& a, const int& b){return a > b;});   //sort from large to small
        vector<int> sidesLen(4,0);
        return dfs(sidesLen, nums, 0, target);
    }
};

//bitmask
class Solution {
public:
    bool makesquare(vector<int>& nums) {
        if(nums.size() < 4) return false;
        long sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 4) {
            cout << "here" <<endl;
            return false;
        }
        sum = sum/4;
        
        int n = nums.size();
        int all = (1<<n) - 1;
        vector<int> usedMasks;
        vector<bool> validHalves(1<<n, false);
        
        for(int mask=1; mask<=all; mask++){
            int subSum = 0;            //calculate the subset sum for this mask;
            for(int i=0; i<32; i++){
                if((mask>>i) & 1){
                    subSum += nums[i];
                }
            }
            // the subset for this mask can form a side;
            if(subSum == sum){
                
                for(int usedMask : usedMasks){
                    if((usedMask & mask) == 0){         //two subsets has no overlap;
                        int half = (usedMask | mask);
                        if(validHalves[all^half]) return true;
                        validHalves[half] = true;
                    }
                }
                usedMasks.push_back(mask);
            }
        }
        return false;
    }
};