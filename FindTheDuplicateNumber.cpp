// this solution is Nlog(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1;
        int r = nums.size()-1;
        int mid, count;
        while (l < r) {
            mid = (l + r)/2;
            count = 0;
            for(int i=0; i<nums.size(); i++) {
                if(nums[i] <= mid) {count++;}
            }
            if (count <= mid){l = mid+1;}
            else {r = mid;}
        }
        return l;
    }
};

// this solution is O(N), using linked list cycle

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //start from nums.size()-1 which is n;
        int slow = nums.size()-1, fast = nums.size()-1;
        do{
            slow = nums[slow]-1;
            fast = nums[nums[fast]-1]-1;
        } while(slow != fast);
        slow = nums.size()-1;
        while(slow != fast) {
            slow = nums[slow]-1;
            fast = nums[fast]-1;
        }
        return fast+1;
    }
};
