class Solution {
public:
//instead of fixing a,b , fix a and find b and c . 
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        for(int i = 0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i];
            int l = i+1,r = n-1;
            while(l<r){
                if(l>i+1 && nums[l] == nums[l-1]){
                    l++;
                    continue;
                }
                if(r<n-1 && nums[r] == nums[r+1]){
                    r--;
                    continue;
                }
                if(nums[l]+nums[r] == target){
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    l++;
                    r--;
                }
                else if(nums[l]+nums[r] > target)
                    r--;
                else
                    l++;
            }
        }
        return res;
    }
    // -4,2,2
    // [-1,-2,3] = 1 2 -3 [-2 -2 4] 2 -4
    // -1,-2,-2,-2,3,4
};
