// use priority queue
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        if (nums1.empty() || nums2.empty() || k<=0) {
            return res;
        }
        int n1 = nums1.size();
        int n2 = nums2.size();
        auto comp = [&](const pair<int,int> &a, const pair<int,int> &b) {
            return nums1[a.first] + nums2[a.second] >= nums1[b.first] + nums2[b.second];
        };
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(comp)> pq(comp);
        
        pq.emplace(0,0);
        int cnt = 0;
        while(!pq.empty() && cnt<k) {
            pair<int,int> cur = pq.top();
            pq.pop();
            int f = cur.first;
            int s = cur.second;
            res.emplace_back(nums1[f], nums2[s]);
            if(f < n1-1) pq.emplace(f+1, s);
            if(f==0 && s < n2-1) pq.emplace(f, s+1);
            cnt++;
        }
        return res;
    }
};

// method without using priority queue
class Solution {
public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> index(n1,0);
        int size = min(k, n1*n2);
        while(size>0) {
            int t = INT_MAX, ind;
            int prev=index[0];
            for(int i=0; i<n1; i++){
                if(i != 0 && index[i] >= prev) continue;      //since nums2 is sorted;
                prev = index[i];                              //update previous index;
                if(index[i] < n2 && t > nums1[i]+nums2[index[i]]) {
                    t = nums1[i]+nums2[index[i]];
                    ind = i;
                }
            }
            res.emplace_back(nums1[ind], nums2[index[ind]++]);
            size--;
        }
        return res;
    }
};
