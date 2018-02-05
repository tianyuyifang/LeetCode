//method 1
void swap(vector<int> &vec, int i, int j){
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
    return;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        stack<int> s;      
        stack<int> q;
        s.push(n-1);
        for(int i=n-2; i>=0; i--){
            while(!s.empty() && nums[i] >= nums[s.top()]){
                q.push(s.top());
                s.pop();
            }
            if(s.empty()) {
                s.push(i);
                while(!q.empty()) {
                    s.push(q.top());
                    q.pop();
                }
            }
            else {
                swap(nums, i, s.top());
                sort(nums.begin()+i+1, nums.end());
                return;
            }
        }

        reverse(nums.begin(), nums.end());
        return;
    }
};
// method 2
void swap(vector<int> &vec, int i, int j){
    int tmp = vec[i];
    vec[i] = vec[j];
    vec[j] = tmp;
    return;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return;
        int i = n-2;
        while(nums[i] >= nums[i+1] && i >= 0) {
            i--;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        int j = i+1;
        while(nums[i] < nums[j] && j < n){
            j++;
        }
        j--;
        swap(nums, i, j);
        reverse(nums.begin()+i+1, nums.end());
        return;
    }
};