class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(0,vector<int>(nums.size(),INT_MAX),nums);
        return res;
    }
    void backtrack(int i,vector<int> temp,vector<int> &nums){
        if(i == nums.size())
            res.push_back(temp);
        for(int j = 0;j<temp.size();j++){
            if(temp[j] == INT_MAX){
                temp[j] = nums[i]; 
                backtrack(i+1,temp,nums);
                temp[j] = INT_MAX;
            }
        }
    }
};
