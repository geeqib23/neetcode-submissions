class Solution {
public:
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        dp.assign(n, -1);
        return dfs(0, nums);
    }
    bool dfs(int i,vector<int> &nums){
        if(i == nums.size()-1) return true;
        if(dp[i] != -1) return dp[i] == 1 ? true : false;
        bool res = false;
        for(int j = i+1;j<=i+nums[i] && j<nums.size();j++){
            res = res || dfs(j,nums);
        }
        dp[i] = res == true ? 1 : 0;
        return res;
    }
};
