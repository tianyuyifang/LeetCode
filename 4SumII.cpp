//unordered_map
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> counter;
        int res = 0;
        for(auto a:A){
            for(auto b:B){
                if(counter.find(a+b) != counter.end()) counter[a+b]++;
                else counter[a+b] = 1;
            }
        }
        
        for(auto c:C){
            for(auto d:D){
                if(counter.find(0-c-d) != counter.end()) res += counter[0-c-d];
            }
        }
        return res;
    }
};
// without using unordered_map
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int n = A.size();
        int N = n*n;
        int res = 0;
        vector<int> AB(N,0), CD(N,0);
        int ind = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                AB[ind] = A[i]+B[j];
                CD[ind] = C[i]+D[j];
                ind++;
            }
        }
        
        sort(AB.begin(), AB.end());
        sort(CD.begin(), CD.end());
        
        int l=0, r=N-1;
        while(l<=N-1 && r>=0){
            if(AB[l] + CD[r] > 0){
                r--;
            }
            else if(AB[l] + CD[r] < 0){
                l++;
            }
            else{
                int prevl = l;
                int prevr = r;
                while(l+1<=N-1 && AB[l+1] == AB[l]){
                    l++;
                }
                while(r-1>=0 && CD[r-1] == CD[r]){
                    r--;
                }
                l++;
                r--;
                res += (l-prevl)*(prevr-r);
            }
        }
        return res;
    }
};