class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(int i : nums){
            sum ^= i;
        }
        int pos = 0;
        while(true){
            if(sum & 1) break;
            else{
                pos++;
                sum >>= 1;
            }
        }
        vector<int> res(2,0);
        for(int i : nums){
            res[0] ^= ((i>>pos)&1) ? i:0;
            res[1] ^= ((i>>pos)&1) ? 0:i;
        }
        return res;
    }
};