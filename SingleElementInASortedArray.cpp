class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r = nums.size();
        int l = 1;
        int mid;
        while(l<r){
            mid = (l+r)/2;
            if((nums[mid-1] != nums[mid]) && (nums[mid-2] != nums[mid-1])){
                return nums[mid-1];
            }
            if((mid-l+1)%2 == 1){
                if(nums[mid-1] == nums[mid]){
                    l = mid+2;
                }
                else{
                    r = mid;
                }
            }
            else{
                if(nums[mid-1] == nums[mid]){
                    r = mid-1;
                }
                else{
                    l = mid+1;
                }
            }
        }
        return nums[l-1];
    }
};
