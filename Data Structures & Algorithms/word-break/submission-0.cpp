class Solution {
public:
    vector<vector<int>> dp;
    bool wordBreak(string s, vector<string>& words) {
        set<string> hs;
        for(auto &w:words)
            hs.insert(w);
        dp.resize(s.size(),vector<int>(s.size(),-1));
        return helper(0,0,s,hs);
    }
    bool helper(int i, int j, string &s, set<string> &hs){
        if(i == s.size()) return true;
        if(j == s.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        if(hs.count(s.substr(i,j-i+1)))
            return dp[i][j] = helper(j+1,j+1,s,hs) || helper(i,j+1,s,hs);
        else
            return dp[i][j] = helper(i,j+1,s,hs);
    }
};
