class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        backtrack(0,target,vector<int>{},nums);
        return res;
    }
    void backtrack(int i,int target,vector<int> temp,vector<int> nums){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(i == nums.size()) return;
        if(target - nums[i] >= 0){
            temp.push_back(nums[i]);
            backtrack(i,target-nums[i],temp,nums);
            temp.pop_back();
        }
        backtrack(i+1,target,temp,nums);
    }
};
