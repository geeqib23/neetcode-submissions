class Solution {
public:
    vector<int> dp;
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return maxRob(0,nums);
    }
    int maxRob(int i, vector<int> nums){
        if(i >= nums.size()) return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = max(nums[i]+maxRob(i+2,nums),maxRob(i+1,nums));
    }
};
