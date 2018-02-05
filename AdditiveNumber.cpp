class Solution {
public:
    bool isAdditiveNumber(string s) {
        int n = s.length();
        for(int i=0; i<(n-1)/2; i++){
            for(int j=i+1; 2*j<=n+i-1 && n-2>=i+j; j++){
                if(isAdditiveNumber(s.substr(0,i+1), s.substr(i+1,j-i), s.substr(j+1))) return true;
            }
        }
        return false;
    }
    
    bool isAdditiveNumber(string num1, string num2, string num) {
        if(num1.size()>1 && num1[0]=='0' || num2.size()>1 && num2[0]=='0') return false;  //if there are leading zeros
        string sum = add(num1, num2);
        if(num.size() >= sum.size() && sum == num.substr(0,sum.size())){
            if(sum.size() == num.size()) return true;
            else return isAdditiveNumber(num2, sum, num.substr(sum.size())); 
        } 
        return false;
    }
    
    string add(string num1, string num2){
        string res;
        int n1 = num1.size()-1;
        int n2 = num2.size()-1;
        int carry = 0;
        int sum = 0;
        while(n1>=0 || n2>=0){
            sum = carry + (n1>=0 ? (num1[n1]-'0') : 0) + (n2>=0 ? (num2[n2]-'0'):0);
            carry = sum/10;
            sum = sum%10;
            n1--;
            n2--;
            res.push_back((char)('0'+sum));
        }
        if(carry != 0) res.push_back((char)('0'+carry));
        reverse(res.begin(), res.end());
        return res;        
    }
};
