class Solution {
public:
    map<pair<int,int>,int> dp;
    int findTargetSumWays(vector<int>& nums, int target) {
        return helper(0,target,nums);
    }
    int helper(int i, int target, vector<int> &nums){
        if(i == nums.size()){
            if(target == 0) return 1;
            else return 0;
        }
        if(dp.count({i,target})) return dp[{i,target}];
        return dp[{i,target}] = helper(i+1,target+nums[i],nums)+helper(i+1,target-nums[i],nums);
    }
};
