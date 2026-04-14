class Solution {
public:
    string s;
    int n;
    vector<int> dp;
    int numDecodings(string S) {
        s = S;
        n = s.size();
        dp.resize(n,-1);
        return recur(0);
    }
    int recur(int i){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i] != -1) return dp[i];
        int ret = 0;
        if(s[i] >= '1' && s[i] <= '9')
            ret += recur(i+1);
        if(i+1<n){
            if(s[i] == '1')
                ret += recur(i+2);
            if(s[i] == '2' && (s[i+1] >= '0' && s[i+1] <= '6'))
                ret += recur(i+2);
        }
        return dp[i] = ret;
    }
};
