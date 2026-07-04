class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(0,0,vector<int>{},target,candidates);
        return res;
    }
    void helper(int i,int sum,vector<int> temp, int target,vector<int> &nums){
        if(sum == target){
            res.push_back(temp);
            return;
        }
        if(sum > target) return;
        if(i == nums.size()) return;
        temp.push_back(nums[i]);
        helper(i+1,sum+nums[i],temp,target,nums);
        temp.pop_back();

        int k = i+1;
        while(k<nums.size() && nums[k] == nums[i]) k++;
        helper(k,sum,temp,target,nums);
    }
};
