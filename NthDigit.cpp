//not accepted
int digits(int n) {
    int carry = 0;
    while(n > 0){
        carry++;
        n = n/10;
    }
    return carry;
}

int kthDigitOfN(int k, int n) {
    if (k == digits(n)) return n%10;
    return kthDigitOfN(k, n/10);
}
class Solution {
public:
    int findNthDigit(int n) {
        vector<pair<int,int>> ans;
        ans.emplace_back(1,1);
        for(int i=2; i<=n; i++) {
            int k = ans.back().first;
            int n = ans.back().second;
            if(k == digits(n)) ans.emplace_back(1, n+1);
            else ans.emplace_back(k+1, n);
        }
        int k = ans.back().first;
        int nn = ans.back().second;
        return kthDigitOfN(k, nn);
    }
};

//accepted solution
class Solution {
public:
    int findNthDigit(int n) {
        long digits=1, range=1;
        while(n > digits*9*range){
            n = n-digits*9*range;
            range = range*10;
            digits++;
        }
        int k = n%digits;       //nth digit is the kth digit in number m
        int m = n/digits;
        if(k == 0) k = digits;
        else m++;
        m = range-1+m;
        for(int i=1; i<digits+1-k; i++){
            m = m/10;
        }
        return m%10;
    }
};