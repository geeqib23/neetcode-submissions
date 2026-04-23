class Solution {
public:
    set<vector<int>> hs;
    vector<vector<int>> res;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        backtrack(0,vector<int>{},nums);
        return res;
    }
    void backtrack(int i,vector<int> temp, vector<int> &nums){
        if(i == nums.size()){
            sort(temp.begin(),temp.end());
            if(hs.count(temp)) return;
            hs.insert(temp);
            res.push_back(temp);
            return;
        }
        backtrack(i+1,temp,nums);
        temp.push_back(nums[i]);
        backtrack(i+1,temp,nums);
    }
};
