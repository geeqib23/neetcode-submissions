class Solution {
public:
    vector<int> dp;
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(amount+1,-2);
        return minCoins(amount,coins);
    }
    int minCoins(int amount, vector<int> &coins){
        if(amount == 0) return 0;
        if(dp[amount] != -2) return dp[amount];
        int res = INT_MAX;
        for(int i =0;i<coins.size();i++){
            if(amount-coins[i] >= 0 && minCoins(amount-coins[i],coins) != -1)
                res = min(res,1+minCoins(amount-coins[i],coins));
        }
        return dp[amount] = (res == INT_MAX) ? -1 : res;
    }
};
