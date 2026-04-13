class Solution {
public:
    bool isHappy(int n) {
        set<int> s;
        while(true){
            if(n == 1) return true;
            if(s.find(n) != s.end()) return false;
            s.insert(n);
            n = helper(n);
        }
        return false;
    }
    int helper(int a){
        int s = 0;
        while(a>0){
            s += (a%10)*(a%10);
            a /= 10;
        }
        return s;
    }
};
