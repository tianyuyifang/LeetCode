//dfs - TLE
class state {
public:
    int i;         //(i,j) records the position, stp records the steps;
    int j;
    int stp;
    state(int i0, int j0, int s0): i(i0), j(j0), stp(s0) {}
};

class Solution {
public:
    int findPaths(int m, int n, int N, int i, int j) {
        int cnt=0;
        queue<state> q;
        q.emplace(i,j,0);
        for(int step=0; step<N; step++) {
            while(q.front().stp <= step && !q.empty()){
                state cur = q.front();      
                q.pop();
                //turn left
                if(cur.i == 0) {
                    cnt++;   
                }
                else{
                    state next(cur.i-1, cur.j, step+1);
                    q.push(next);
                }
                //turn right
                if(cur.i == m-1) {
                    cnt++;
                }
                else {
                    state next(cur.i+1, cur.j, step+1);
                    q.push(next);
                }
                //turn up
                if(cur.j == 0) {
                    cnt++;
                }
                else {
                    state next(cur.i, cur.j-1, step+1);
                    q.push(next);
                }
                //turn down
                if(cur.j == n-1) {
                    cnt++;
                }
                else {
                    state next(cur.i, cur.j+1, step+1);
                    q.push(next);
                }
                cnt = cnt % 1000000007;
            }   
        }
        return cnt;
    }
};

// dp - accepted
class Solution {
public:
    int findPaths(int m, int n, int N, int x, int y) {
        size_t limit = 1000000007;
        vector<vector<vector<size_t>>> dp(N+1, vector<vector<size_t>>(m, vector<size_t>(n, 0)));
        // build the recursive relationship
        for(int stp=1; stp<=N; stp++){
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    //turn left
                    if(i == 0) dp[stp][i][j]++;
                    else dp[stp][i][j] += dp[stp-1][i-1][j];
                    //turn right
                    if(i == m-1) dp[stp][i][j]++;
                    else dp[stp][i][j] += dp[stp-1][i+1][j];
                    //turn up
                    if(j == 0) dp[stp][i][j]++;
                    else dp[stp][i][j] += dp[stp-1][i][j-1];
                    //turn down
                    if(j == n-1) dp[stp][i][j]++;
                    else dp[stp][i][j] += dp[stp-1][i][j+1];
                    dp[stp][i][j] %= limit;
                }    
            }
        }
        return dp[N][x][y];
    }
};