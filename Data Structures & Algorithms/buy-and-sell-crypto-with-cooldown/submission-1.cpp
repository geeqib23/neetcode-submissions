class Solution {
public:
    vector<vector<int>> dp;
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return helper(0,1,prices);
    }
    int helper(int i,int isBuy,vector<int> &prices){
        if(i >= prices.size()) return 0;
        if(dp[i][isBuy] != -1) return dp[i][isBuy];
        if(isBuy == 0)
            return dp[i][isBuy] = max(prices[i]+helper(i+2,1,prices),helper(i+1,isBuy,prices));
        else
            return dp[i][isBuy] = max(-prices[i]+helper(i+1,0,prices),helper(i+1,isBuy,prices));
    }
};
