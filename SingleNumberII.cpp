class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int count[32] = {0};
        int res = 0;
        for(int i=0;i<32;i++){
            for(int j=0; j<nums.size(); j++){
                if(nums[j]>>i & 1){
                    count[i]++;
                }
            }
            res |= ((count[i]%3)<<i);
        }
        return res;
    }
};
// x1 and x2 together record the counts of ones that occur at this position
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x1=0, x2=0, mask=0;
        for(auto i:nums){
            x2 ^= x1 & i;
            x1 ^= i;
            mask = ~(x1 & x2);
            x1 &= mask;
            x2 &= mask;
        }
        return x1;
    }
};
// ones twos together record the counts of ones that occur at this position (0,0)-(1,0)-(0,1)-(0,0)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ones=0, twos=0, tmp=0;
        for(auto i:nums){
            ones = (~twos) & (ones^i);
            twos = (~ones) & (twos^i);
        }
        return ones;
    }
};
