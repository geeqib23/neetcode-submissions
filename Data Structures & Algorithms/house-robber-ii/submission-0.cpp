class Solution {
public:
    vector<vector<int>> dp;
    int rob(vector<int>& nums) {
        dp.assign(nums.size(),vector<int>(2,-1));
        return max(helper(1,0,nums),nums[0]+helper(2,1,nums));
    }
    int helper(int i, int flag,vector<int> &nums){
        if(i >= nums.size()) return 0;
        if(dp[i][flag] != -1) return dp[i][flag];
        if(flag == 1 && i == nums.size()-1) return 0;
        int res = max(nums[i]+helper(i+2,flag,nums), helper(i+1,flag,nums));
        return dp[i][flag] = res;
    }
};
