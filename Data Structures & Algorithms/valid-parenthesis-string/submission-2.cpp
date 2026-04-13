class Solution {
public:
    vector<vector<int>> dp;
    bool checkValidString(string s) {
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return helper(s,0,0);
    }
    bool helper(string &s, int open, int i){
        if(i == s.size() && open == 0) return true;
        if(i == s.size() && open > 0) return false;
        if(open < 0) return false;
        if(dp[open][i] != -1) return dp[open][i];
        if(s[i] == '(')
            return dp[open][i] = helper(s,open+1,i+1);
        else if(s[i] == ')')
            return dp[open][i] = helper(s,open-1,i+1);
        else 
            return dp[open][i] = helper(s,open+1,i+1) || helper(s,open-1,i+1) || helper(s,open,i+1);
    }
};
