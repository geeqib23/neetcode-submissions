class Solution {
public:
    vector<vector<int>> dp;
    int uniquePaths(int m, int n) {
        dp.assign(m+1,vector<int>(n+1,-1));
        return helper(m,n);
    }
    int helper(int i,int j){
        if(i < 1 || j < 1) return 0;
        if(i == 1 || j == 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = helper(i-1,j)+helper(i,j-1);   
    }
};
