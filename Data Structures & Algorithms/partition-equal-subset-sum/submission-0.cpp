class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto &n:nums){
            sum += n;
        }        
        if(sum&1) return false;
        return helper(0,nums,sum/2);
    }
    bool helper(int i,vector<int> &nums,int sum){
        if(sum == 0) return true;
        if(sum < 0) return false;
        if(i >= nums.size())
            return false;
        return helper(i+1,nums,sum-nums[i]) || helper(i+1,nums,sum); 
    }
};
