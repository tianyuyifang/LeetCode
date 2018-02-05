class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        int reverseInd = 0;
        int i=0, j=0;
        
        for(int i=0; i<s.length(); i++) {
            if(s[i] != ' ') {            //i points the begin of the word;
                if (reverseInd != 0) reverseInd++;
                j = i;
                while(s[j] != ' ' && j < s.length()) {
                    j++;
                }                        //j points the end of the word + 1 or s.end()
                reverse(s.begin() + reverseInd, s.begin() + j);
                reverseInd += j - i;
                i = j;
            }
        }
        s.erase(s.begin() + reverseInd, s.end());
    }
};