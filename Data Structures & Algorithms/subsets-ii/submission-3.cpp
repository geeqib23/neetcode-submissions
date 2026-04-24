class Solution {
public:
//Better solution to remove ordering(of numbers, not index)
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,vector<int>{},nums, false);
        return res;
    }
    void backtrack(int i,vector<int> temp, vector<int> &nums, bool prevUsed){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        backtrack(i+1,temp,nums, false);
        if(i>0 && nums[i] == nums[i-1] && !prevUsed){
            return;
        }
        temp.push_back(nums[i]);
        backtrack(i+1,temp,nums, true);
    }
};