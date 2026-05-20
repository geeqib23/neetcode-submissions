class Solution {
public:
    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size()+1,vector<int>(nums.size()+1,-1));
        return helper(0,nums.size(),nums);
    }   
    int helper(int i,int j,vector<int> &nums){
        if(i == nums.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(j == nums.size() || nums[i] > nums[j])
            return dp[i][j] = max(1+helper(i+1,i,nums),helper(i+1,j,nums));
        else
            return dp[i][j] = helper(i+1,j,nums);
    }
};
