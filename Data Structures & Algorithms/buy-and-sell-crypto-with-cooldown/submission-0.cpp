class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(1002,-1));
        return helper(0,1001,prices);
    }
    int helper(int i,int buyAt,vector<int> &prices){
        if(i >= prices.size()) return 0;
        if(dp[i][buyAt] != -1) return dp[i][buyAt];
        if(buyAt != 1001)
            return dp[i][buyAt] = max(prices[i]-buyAt+helper(i+2,1001,prices),helper(i+1,buyAt,prices));
        else
            return dp[i][buyAt] = max(helper(i+1,prices[i],prices),helper(i+1,1001,prices));
    }
};
