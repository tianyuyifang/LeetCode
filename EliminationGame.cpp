class Solution {
public:
    int lastRemaining(int n) {
        return leftRemaining(n);
    }
    int rightRemaining(int n) {
        if(n == 1) return 1;
        else if(n%2 == 1) return 2*leftRemaining(n/2);
        else return (2*leftRemaining(n/2) - 1);
    }
    int leftRemaining(int n) {
        if(n == 1) return 1;
        else return 2*rightRemaining(n/2);
    }
};