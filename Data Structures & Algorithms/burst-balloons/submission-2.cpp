class Solution {
public:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        dp.assign(nums.size(),vector<int>(nums.size(),-1));
        return helper(0,nums.size()-1,nums);
    }
    int helper(int l,int r, vector<int> &nums){
        if(l>r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        int res = 0;
        for(int i=l; i<=r; i++){
            int pop = nums[i]*((l-1>=0) ? nums[l-1]:1) * ((r+1<nums.size()) ? nums[r+1]:1);
            res = max(res, pop+ helper(l,i-1,nums)+helper(i+1,r,nums));
        }
        return dp[l][r] = res;
    }
};
