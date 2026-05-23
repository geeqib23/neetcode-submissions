class Solution {
public:
    vector<vector<int>> dp;
    int numDistinct(string s, string t) {
        dp.assign(s.size(),vector<int>(t.size(),-1));
        return helper(0,0,s,t);
    }
    int helper(int i,int j, string &s,string &t){
        if(j == t.size()) return 1;
        if(i == s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] == t[j])
            return dp[i][j] = helper(i+1,j+1,s,t) + helper(i+1,j,s,t);
        else
            return dp[i][j] = helper(i+1,j,s,t);
    }
};
