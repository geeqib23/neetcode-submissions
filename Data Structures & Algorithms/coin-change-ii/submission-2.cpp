class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint> dp(amount + 1, 0);
        dp[0] = 1;
        // By putting the coin loop on the outside, you are saying:
        // "I will first use only Coin A to see how many ways I can make all amounts.
        // Then, I will add Coin B to the mix, then Coin C..."
        // space optimized recursive solution ;take care of order of loops
        for (int i = coins.size() - 1; i >= 0; i--) {
            for (int a = 1; a <= amount; a++) {
                dp[a] = dp[a] + (coins[i] <= a ? dp[a - coins[i]] : 0);
            }
        }
        return dp[amount];
    }
};