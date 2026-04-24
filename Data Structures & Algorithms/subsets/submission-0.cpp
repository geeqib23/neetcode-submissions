class Solution {
public:
vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,vector<int>{},nums);
        return res;
    }
    void backtrack(int i,vector<int> temp,vector<int> &nums){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        backtrack(i+1,temp,nums);
        temp.push_back(nums[i]);
        backtrack(i+1,temp,nums);
    }

};
