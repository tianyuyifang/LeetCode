// multiple of each prime with the ugly sequence is still a subsequence of ugly numbers
// each prime is corresponding such a subsequence, they are moving forward step by step,
// the next ugly number must be among the fronts of these subsequence.

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int size = primes.size();
        vector<int> ugly(n,INT_MAX), index(size, 0);
        ugly[0] = 1;
        for(int i=1; i<n; i++) {
            for(int j=0; j<size; j++) {
                ugly[i] = min(ugly[i], ugly[index[j]]*primes[j]);
            }
            for(int j=0; j<size; j++) {
                if(ugly[i] == ugly[index[j]]*primes[j]) index[j]++;
            }
        }
        return ugly[n-1];
    }
};
