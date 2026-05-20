class Solution {
public:
//we optimise to 1d space, by sayind helper(i) means longes starting at i,
// earlier we took the max from the last and kept carrying it to dp[0];
    vector<int> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp.assign(nums.size(),-1);
        helper(0,nums);
        return *max_element(dp.begin(),dp.end());
    }   
    int helper(int i,vector<int> &nums){
        if(dp[i] != -1) return dp[i];
        int res = 1;
        for(int j = i+1;j<nums.size();j++){
            if(nums[j] > nums[i])
                res = max(res,1+helper(j,nums));
            else
                helper(j,nums);
        }
        return dp[i] = res;
    }
};
