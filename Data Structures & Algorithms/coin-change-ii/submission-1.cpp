class Solution {
public:
    vector<vector<int>> dp;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        dp.resize(n,vector<int>(amount+1,-1));
        return noOfWays(0,amount,coins);
    }
    int noOfWays(int i, int amount,vector<int> &coins){
        if(amount == 0) return 1;
        if(i == coins.size()) return 0;
        if(dp[i][amount] != -1) return dp[i][amount];
        if(amount-coins[i]>=0)
            return dp[i][amount] = noOfWays(i,amount-coins[i],coins)+noOfWays(i+1,amount,coins);
        else
            return dp[i][amount] = noOfWays(i+1,amount,coins);
    }
    // int noOfWays(int amount,vector<int> &coins){
    //     if(amount == 0) return 1;
    //     // if(amount < 0) return 0;
    //     int res = 0;
    //     for(int i = 0;i<coins.size();i++){
    //         if(amount-coins[i]>=0)
    //             res += noOfWays(amount-coins[i],coins);
    //         else
    //             break;
    //     }
    //     cout << amount << " " << res << endl;
    //     return res;
    // }
};
