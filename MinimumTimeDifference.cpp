int stringToNumber(string t){
    return ((t[0]-'0')*10 + (t[1]-'0'))*60 + ((t[3]-'0')*10 + (t[4]-'0'));
}
int diffBtw(string t1, string t2){
    int n1 = stringToNumber(t1);
    int n2 = stringToNumber(t2);
    return (n2 >= n1) ? (n2-n1) : (24*60-(n1-n2));
}

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(), timePoints.end());
        int min = INT_MAX;
        int n = timePoints.size();
        for(int i=0; i<n; i++){
            int diff = diffBtw(timePoints[i], timePoints[(i+1)%n]);
            if(min > diff) min = diff;
        }
        return min;
    }
};