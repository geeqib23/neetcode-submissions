class Solution {
public:
    vector<vector<int>> dp;
    int minDistance(string s1, string s2) {
        dp.assign(s1.size()+1,vector<int>(s2.size()+1,-1));
        return helper(0,0,s1,s2);
    }
    int helper(int i1,int i2,string &s1,string &s2){
        if(i1 == s1.size() && i2 == s2.size())
            return 0;
        if(dp[i1][i2] != -1) return dp[i1][i2];
        if(i1 == s1.size()) return dp[i1][i2] = s2.size()-i2;
        if(i2 == s2.size()) return dp[i1][i2] = s1.size()-i1;
        if(s1[i1] == s2[i2])
            return dp[i1][i2] = helper(i1+1,i2+1,s1,s2);
        else{
            return dp[i1][i2] = 1+min({helper(i1,i2+1,s1,s2), helper(i1+1,i2,s1,s2), helper(i1+1,i2+1,s1,s2)});
        }
    }
};
