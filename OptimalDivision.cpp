//brutal force
class T {
public:
    float minVal;
    float maxVal;
    string minStr;
    string maxStr;
};

T optimal(vector<int>& nums, int start, int end){
    T t;
    if(start == end){
        t.minVal = nums[start];
        t.maxVal = nums[start];
        t.minStr = to_string(nums[start]);
        t.maxStr = to_string(nums[start]); 
        return t;
    }
    t.minVal = INT_MAX;
    t.maxVal = INT_MIN;
    for(int i=start; i<end; i++){
        T left = optimal(nums, start, i);
        T right = optimal(nums, i+1, end);
        if(t.minVal > (left.minVal/right.maxVal)){
            t.minVal = left.minVal/right.maxVal;
            if(end == i+1){
                t.minStr = left.minStr + "/" + right.maxStr;
            }
            else{
                t.minStr = left.minStr + "/(" + right.maxStr + ")"; 
            }
        }
        if(t.maxVal < (left.maxVal/right.minVal)){
            t.maxVal = (left.maxVal/right.minVal);
            if(end == i+1){
                t.maxStr = left.maxStr + "/" + right.minStr;
            }
            else{
                t.maxStr = left.maxStr + "/(" + right.minStr + ")"; 
            }
        }
    }
    return t;
}

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        T t = optimal(nums, 0, nums.size()-1);
        cout << t.maxVal;
        return t.maxStr;
    }
};