class Solution {
public:
    // map<pair<int,int>,int> dp;
    vector<vector<int>> dp;
    int sum;
    int findTargetSumWays(vector<int>& nums, int target) {
        sum = accumulate(nums.begin(),nums.end(),0);
        if (abs(target) > sum) return 0;
        dp.assign(nums.size(),vector<int>(2*sum+1,-1));
        return helper(0,0,target,nums);
    }
    int helper(int i, int total, int target, vector<int> &nums){
        if(i == nums.size()){
            if(total == target) return 1;
            else return 0;
        }
        // if(dp.count({i,target})) return dp[{i,target}];
        if(dp[i][total+sum] != -1) return dp[i][total+sum];
        return dp[i][total+sum] = helper(i+1,total+nums[i],target, nums)+helper(i+1,total-nums[i],target,nums);
    }
};