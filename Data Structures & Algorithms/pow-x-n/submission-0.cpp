class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;
        if(n<0) x = 1/x;
        for(int i = 0;i<abs(n);i++){
            res *= x;
        }
        return res;
    }
};
