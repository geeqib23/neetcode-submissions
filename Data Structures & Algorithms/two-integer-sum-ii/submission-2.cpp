class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int searchVal = target-nums[i];
            if(searchVal == nums[i]){
                if(i+1 < n && nums[i+1] == nums[i])
                    return vector<int>{i+1,i+2};
                else if(i-1 >= 0 && nums[i-1] == nums[i])
                    return vector<int>{i,i+1};
            }
            else if(searchVal > nums[i]){
                auto it = lower_bound(nums.begin()+i+1,nums.end(),searchVal);
                if(*it != searchVal) continue;
                int ind = it-nums.begin();
                return vector<int>{i+1,ind+1};
            }
            // else if(searchVal < nums[i]){
            //     auto it = lower_bound(nums.begin(),nums.begin()+i,searchVal);
            //     if(*it != searchVal) continue;
            //     int ind = it-nums.begin();
            //     return vector<int>{ind+1,i+1};
            // }
        }
        return vector<int>{};
    }
};
