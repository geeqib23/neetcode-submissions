class Solution {
public:
    int N;
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        N = cost.size();
        dp.resize(N,-1);
        return min(helper(0,cost),helper(1,cost));
    }
    int helper(int i,vector<int> &cost){
        if(i == N) return 0;
        if(i > N-1) return INT_MAX;
        if(dp[i] != -1) return dp[i];
        return dp[i] = cost[i]+min(helper(i+1,cost),helper(i+2,cost));
    }
};
