int charToNumber(char a){
    if(a == 'A') return 0;
    if(a == 'C') return 1;
    if(a == 'G') return 2;
    if(a == 'T') return 3;
}
int toNumber(string s) {
    int res = 0, base=1;
    for(int i=9; i>=0; i--){
        res = res + charToNumber(s[i])*base;
        base = base*4;
    }
    return res;
}

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.length();
        int hashmap[1048576] = {0};
        vector<string> res;
        if(n <= 10) return res;
        for(int i=0; i<=n-10; i++){
            if (hashmap[toNumber(s.substr(i,10))] == 1) {
                res.push_back(s.substr(i,10));
                hashmap[toNumber(s.substr(i,10))]++;
            }
            else hashmap[toNumber(s.substr(i,10))]++;
        }
        return res;
    }
};
