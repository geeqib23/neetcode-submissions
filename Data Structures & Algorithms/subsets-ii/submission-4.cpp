class Solution {
public:
//Better solution to remove ordering(of numbers, not index)
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,vector<int>{},nums);
        return res;
    }
    void backtrack(int i,vector<int> temp, vector<int> &nums){
        if(i == nums.size()){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[i]);
        backtrack(i+1,temp,nums);
        temp.pop_back();
        int k = i+1;
        while(k< nums.size() && nums[k] == nums[i]){
            k++;
        }
        backtrack(k,temp,nums);
    }
};